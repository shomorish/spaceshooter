#include "linear_quadtree.h"

#include <Windows.h>
#include <cmath>
#include <stdexcept>

#include "../common/bit.h"

namespace spaceshooter {

LinearQuadtree::LinearQuadtree(int partition_level, Vector2 topLeft, Vector2 bottomRight) {
    if (partition_level <= 0)
        throw std::invalid_argument("Partition level must be between 1 and 6.");

    if (partition_level > MAX_PARTITION_LEVEL) partition_level = MAX_PARTITION_LEVEL;

    // 空間の数を計算
    num_of_spaces_ = (std::pow(4, partition_level + 1) - 1) / 3;

    // 全ての空間のポインタを作成
    spaces_ = new Space*[num_of_spaces_];
    ZeroMemory(spaces_, sizeof(Space*) * num_of_spaces_);

    // 領域を設定
    left_ = topLeft.x;
    top_ = topLeft.y;
    right_ = bottomRight.x;
    bottom_ = bottomRight.y;
    width_ = right_ - left_;
    height_ = bottom_ - top_;
    unit_width_ = width_ / (1 << partition_level);
    unit_height_ = height_ / (1 << partition_level);

    // 分割レベルを設定
    partition_level_ = partition_level;
}

LinearQuadtree::~LinearQuadtree() {
    for (int i = 0; i < num_of_spaces_; i++) {
        if (spaces_[i] != NULL) {
            delete spaces_[i];
        }
    }
    delete[] spaces_;
}

unsigned int LinearQuadtree::GetMortonCode(unsigned int x, unsigned int y) {
    return (SeparateBit32(x) | (SeparateBit32(y) << 1));
}

void LinearQuadtree::CreateSpace(unsigned int index) {
    while (spaces_[index] == NULL) {
        spaces_[index] = new Space();
        // 親空間のインデックスにジャンプ
        index = (index - 1) >> 2;
        if (index >= num_of_spaces_) break;
    }
}

void LinearQuadtree::Regist(Collider* collider) {
    // 左上の頂点のモートンコードを計算
    auto topLeft = collider->GetTopLeft();
    unsigned int x = topLeft.x / unit_width_;
    unsigned int y = topLeft.y / unit_height_;
    auto tl_morton_code = GetMortonCode(x, y);

    // 右上の頂点のモートンコードを計算
    auto bottomRight = collider->GetBottomRight();
    x = bottomRight.x / unit_width_;
    y = bottomRight.y / unit_height_;
    auto br_morton_code = GetMortonCode(x, y);

    // 2つの頂点のモートンコードから所属している空間のモートンコードを計算
    auto exor = br_morton_code ^ tl_morton_code;
    unsigned int highlevel = 0;
    for (int i = 0; i < partition_level_; i++) {
        unsigned int v = (exor >> (2 * i)) & 0x3;
        if (v != 0) {
            highlevel = i + 1;
        }
    }
    unsigned int morton_code = br_morton_code >> (highlevel * 2);

    // 空間のモートンコードからインデックスを計算
    unsigned int offset = (std::pow(4, partition_level_ - highlevel) - 1) / 3;
    unsigned int index = morton_code + offset;

    // 空間にコライダーを追加
    if (index < num_of_spaces_) {
        // 空間が無ければ生成
        if (spaces_[index] == NULL) {
            CreateSpace(index);
        }
        spaces_[index]->Add(collider);
    }
}

unsigned int LinearQuadtree::GetAllCollisionList(CollisionList** list) {
    // ルート空間が存在するか確認
    if (spaces_[0] == NULL) return 0;

    // 衝突リストを作成
    std::list<Collider*> stack;
    GetCollisionList(0, stack);

    *list = &collision_list_;

    return (unsigned int)collision_list_.GetSize();
}

void LinearQuadtree::GetCollisionList(unsigned int index, std::list<Collider*>& stack) {
    std::list<Collider*>::iterator iter;

    Collider* collider = spaces_[index]->get_first();
    while (collider != NULL) {
        // 同じ空間に所属するコライダーとの衝突リストを作る
        Collider* next = collider->get_next();
        while (next != NULL) {
            collision_list_.Add(collider, next);
            next = next->get_next();
        }

        // 祖先の空間に所属するコライダーとの衝突リストを作る
        for (iter = stack.begin(); iter != stack.end(); iter++) {
            collision_list_.Add(collider, *iter);
        }

        collider = collider->get_next();
    }

    bool has_child_space = false;
    unsigned int num_of_colliders = 0;
    unsigned int child_space_index = 0;
    for (int i = 0; i < 4; i++) {
        child_space_index = index * 4 + 1 + i;
        // 子空間が存在するか確認
        if (child_space_index < num_of_spaces_ && spaces_[child_space_index]) {
            if (!has_child_space) {
                // 現在の空間に所属している全てのコライダーをスタックに追加
                collider = spaces_[index]->get_first();
                while (collider) {
                    stack.push_back(collider);
                    num_of_colliders += 1;
                    collider = collider->get_next();
                }
            }
            has_child_space = true;
            // 子空間のインデックスを使ってこの関数を再帰実行
            GetCollisionList(child_space_index, stack);
        }
    }

    // スタックに追加したコライダーを取り除く
    if (has_child_space) {
        for (int i = 0; i < num_of_colliders; i++) {
            stack.pop_back();
        }
    }
}

} // namespace spaceshooter