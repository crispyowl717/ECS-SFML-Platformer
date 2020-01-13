#pragma once

/*
**********************************************************************;
*	Project      : ECS_SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This prefab creates an entity that has a large rectangle at the top
*	             : and text inside of it.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <entt/entity/registry.hpp>

#include "Public/GlobalSettings.h"
#include "Public/Components/CShapeTypeComponent.h"

struct PF_TopBox
{
public:
    void Create(entt::registry& Registry);
    inline void Draw(sf::RenderWindow& Window) { Window.draw(TopBoxText); }
private:
    sf::Font TopBoxFont;
    sf::Text TopBoxText;
};

inline void PF_TopBox::Create(entt::registry& Registry)
{
	// The top box itself
    const auto HeaderBoxEntity = Registry.create();
    const auto HeaderBox = std::unique_ptr<sf::RectangleShape>{ std::make_unique<sf::RectangleShape>
        (sf::RectangleShape(sf::Vector2f(_WindowSizes[_WindowSelectionID].x, _HeaderSize))) };
    HeaderBox->setPosition(0.f, 0.f);
    HeaderBox->setFillColor(sf::Color(12, 12, 12));
    Registry.assign<CShapeTypeComponent>(HeaderBoxEntity, *HeaderBox);

	// The font inside the top box
    if (!TopBoxFont.loadFromFile("SourceCode/Assets/Fonts/Oxygen/Oxygen.otf"))
        std::cout << "PF_TopBox.h Ln.30 - Missing Font B" << std::endl;

    TopBoxText.setFont(TopBoxFont);
    TopBoxText.setString("SFML ECS Platformer");
    TopBoxText.setFillColor(sf::Color(190, 235, 233));
    TopBoxText.setCharacterSize(50);
    TopBoxText.setOrigin(TopBoxText.getLocalBounds().width / 2, TopBoxText.getLocalBounds().height / 2);
    TopBoxText.setPosition(_WindowSizes[_WindowSelectionID].x / 2,
        (HeaderBox->getLocalBounds().height - TopBoxText.getLocalBounds().height) / 2);
}

