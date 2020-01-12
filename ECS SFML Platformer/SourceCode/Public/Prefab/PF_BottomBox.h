#pragma once

/*
**********************************************************************;
*	Project      : ECS SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This prefab creates an entity that has a large rectangle at the bottom
*	             : and text inside of it.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <entt/entity/registry.hpp>

#include "Public/GlobalSettings.h"
#include "Public/Components/CTransformComponent.h"
#include "Public/Components/CShapeTypeComponent.h"

struct PF_BottomBox
{
public:
	void Create(entt::registry& Registry);
	const void Draw(sf::RenderWindow& Window) { Window.draw(BottomText); }
private:
	sf::Font BottomBoxFont;
	sf::Text BottomText;
};

inline void PF_BottomBox::Create(entt::registry& Registry)
{
	//The box itself.
	auto BottomBoxEntity = Registry.create();
	auto BottomBox = std::unique_ptr<sf::RectangleShape>{std::make_unique<sf::RectangleShape>()};
	BottomBox->setFillColor(sf::Color(12, 12, 12));
	Registry.assign<CShapeTypeComponent>(BottomBoxEntity, *BottomBox);
	Registry.assign<CTransformComponent>(BottomBoxEntity,
	                                     sf::Vector2f(0.f, (_WindowSizes[_WindowSelectionID].y - _FooterBoxSize)),
	                                     sf::Vector2f(0.f, 0.f),
	                                     sf::Vector2f(_WindowSizes[_WindowSelectionID].x, _FooterBoxSize),
	                                     0.f);

	// The text that accompanies the box on the bottom.
	if (!BottomBoxFont.loadFromFile("SourceCode/Assets/Fonts/Oxygen/Oxygen.otf"))
		std::cout << "PF_BottomBox Ln.31 - Missing Bottom Box Font" << std::endl;

	BottomText.setFont(BottomBoxFont);
	BottomText.setString("This is a test using SFML 2.5.1. EnTT, and C++ 17. \nI do intend for this to grow to be something fun.");
	BottomText.setFillColor(sf::Color(190, 235, 233));
	BottomText.setCharacterSize(18);
	BottomText.setOrigin(BottomText.getLocalBounds().width / 2, (BottomText.getLocalBounds().height / 2));
	BottomText.setPosition(_WindowSizes[_WindowSelectionID].x / 2,
	                       _WindowSizes[_WindowSelectionID].y - (BottomText.getLocalBounds().height + _FooterBoxSize) /
	                       2.f);
}
