#pragma once

#include <list>

#include "../common/vector2.h"
#include "collision_list.h"
#include "space.h"

namespace spaceshooter {

static const int MAX_PARTITION_LEVEL = 6;

/// <summary>
/// 線形四分木空間管理クラス。
/// </summary>
class LinearQuadtree {
 public:
    LinearQuadtree();
    LinearQuadtree(int partition_level, Vector2 topLeft, Vector2 rightBottom);

    ~LinearQuadtree();

    void Init(int partition_level, Vector2 topLeft, Vector2 rightBottom);
    unsigned int GetMortonCode(unsigned int x, unsigned int y);
    void CreateSpace(unsigned int index);
    void Regist(Collider* collider);
    unsigned int GetAllCollisionList(CollisionList** list);
    void GetCollisionList(unsigned int index, std::list<Collider*>& stack);

 private:
    Space** spaces_;
    int num_of_spaces_;
    float left_;
    float top_;
    float right_;
    float bottom_;
    float width_;
    float height_;
    float unit_width_;
    float unit_height_;
    int partition_level_;
    CollisionList collision_list_;
};

} // namespace spaceshooter
