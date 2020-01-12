#pragma once

#include <entt/entity/registry.hpp>
#include "Public/Components/CTransformComponent.h"
#include "Public/Components/CCollisionComponent.h"
#include "Public/WorldGravity.h"

class SPhysicsSystem
{
public:
	void Update(entt::registry& registry, float DeltaTime);

private:

};

