#include "Public/Systems/SRenderSystem.h"

/*
 * Function:  Update
 * --------------------
 * This makes the shape object model itself after the transform component.  
 *
 * Registry: This list of all entities.
 *
 */
void SRenderSystem::Update(entt::registry &Registry)
{
	// This function only cares about entities with CShapeType and CTransform
    auto View = Registry.view<CShapeTypeComponent, CTransformComponent>();

    for (auto& Entity : View)
    {
        auto& Transform = Registry.get<CTransformComponent>(Entity);
        auto& Shape = Registry.get<CShapeTypeComponent>(Entity);

        Shape.Rectangle.setPosition(Transform.Position);
        Shape.Rectangle.setSize(Transform.Size);
        Shape.Rectangle.setRotation(Transform.Rotation);
    }
}

/*
 * Function:  Draw
 * --------------------
 * This draws every object with a shape component.
 *
 * Registry: This list of all entities.
 * Window: This is the window created in MSystemManager
 *
 */
void SRenderSystem::Draw(entt::registry& Registry, sf::RenderWindow& Window)
{
	// For every Shape, draw it.
	Registry.view<CShapeTypeComponent>().each([&](auto& Shape)
	{
	   Window.draw(Shape.Rectangle);
    });
}
