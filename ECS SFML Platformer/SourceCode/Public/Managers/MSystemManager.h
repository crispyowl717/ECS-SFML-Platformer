#pragma once

/*
**********************************************************************;
*	Project      : ECS SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This is the central class where all systems are ran and
*				 : entities are created.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <entt\entt.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Public/GlobalSettings.h"
#include "Public/Systems/SPhysicsSystem.h"
#include "Public/Systems/SRenderSystem.h"
#include "Public/Systems/SInputSystem.h"

#include "Public/Prefab/PF_MovingRectangle.h"
#include "Public/Prefab/PF_BottomBox.h"
#include "Public/Prefab/PF_TopBox.h"
#include "Public/Helper/HGrid.h"

class MSystemManager
{
public:
	void Activate();
	void Update(sf::RenderWindow& Window);
private:
	
	entt::registry Registry;

	// Systems
	SRenderSystem RenderSystem;
	SPhysicsSystem PhysicsSystem;
	SInputSystem InputSystem;

	// Game Settings
	sf::Vector2i CurrentWindowSize{_WindowSizes[_WindowSelectionID]};
	_ColorPalette CurrentPalette{_ColorPalette::NORMAL_PALETTE};
	_Languages CurrentLanguage{ _Languages::ENGLISH_LANGUAGE };
	_GameState CurrentGameState{ _GameState::MAINMENU_STATE };
};

