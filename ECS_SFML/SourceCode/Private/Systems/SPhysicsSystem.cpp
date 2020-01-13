#include "Public/Systems/SPhysicsSystem.h"

/*
 * Function:  Update
 * --------------------
 * This makes the entity be affected by forces.
 *
 * Registry: This list of all entities.
 * DeltaTime: This is the constant time half-step
 *
 */
void SPhysicsSystem::Update(entt::registry& registry, float DeltaTime)
{
	// For every entity with a Transform component and Collision component...
	registry.view<CTransformComponent,CCollisionComponent>().each([&](auto Entity, CTransformComponent& Transform, CCollisionComponent& Collision)
	{
		// The affects of gravity should only activate if the entity is dynamic.
		if(Collision.Type == _CollisionType::DYNAMIC)
		{
			// The velocity.x is pushed left by Drag and Friction
			Transform.Velocity.x -= DeltaTime * _DRAG * _FRICTION * Transform.Velocity.x;
			Transform.Velocity.x = std::clamp(Transform.Velocity.x, -_MAX_SPEED, _MAX_SPEED);
			Transform.Position.x += DeltaTime * Transform.Velocity.x;

			// The velocity.y should be pushing downward by Gravity.
			Transform.Velocity.y += DeltaTime * _GRAVITY * _GRAVITY_SCALE;
			Transform.Velocity.y -= DeltaTime * _AIR_RESISTANCE * Transform.Velocity.y;
			Transform.Velocity.y = std::clamp(Transform.Velocity.y, -_TERMINAL_VELOCITY, _TERMINAL_VELOCITY);
			Transform.Position.y += DeltaTime * Transform.Velocity.y;
		}

		// These restrict any movement to the regions inside the boxes and the screen.
		Transform.Position.x = std::clamp(Transform.Position.x, 0.f, _WindowRegion.width - Transform.Size.x);
		Transform.Position.y = std::clamp(Transform.Position.y,
			(_WindowRegion.top + (Transform.Size.y / 2.f)),
			(_WindowRegion.top + _WindowRegion.height) - (Transform.Size.y));
	});
}
