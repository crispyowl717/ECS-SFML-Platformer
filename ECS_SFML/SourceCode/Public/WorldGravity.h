#pragma once

/*
**********************************************************************;
*	Project      : ECS_SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This struct defines the global settings of gravity,
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

// Vertical Forces
inline constexpr float _AIR_RESISTANCE{ 1.f };
inline constexpr float _GRAVITY{ 9.8f };
inline constexpr float _VERTICAL_IMPULSE{ 800.0f };
inline constexpr float _TERMINAL_VELOCITY{ 250.f };
inline constexpr float _GRAVITY_SCALE{ 25.f };

// Horizontal Forces
inline constexpr float _DRAG{ 1.f };
inline constexpr float _FRICTION{ 2.5f };
inline constexpr float _ACCELERATION{ 800.0f };
inline constexpr float _MAX_SPEED = { 250.f };

