#pragma once

/*
**********************************************************************;
*	Project      : ECS SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This header is a global list of all shared game data.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

// Because the game is mostly flat colors, they can alter quickly to
// an alternative schemes.
enum class _ColorPalette {
    NORMAL_PALETTE,
    PROTANOPIA_PALETTE,
    TRITANOPIA_PALETTE,
    DEUTANANOPIA_PALETTE
};
enum class _Languages {
    ENGLISH_LANGUAGE,
    SPANISH_LANGUAGES,
    JAPANESE_LANGUAGES,
};

enum class _GameState {
    SPLASH_SCREEN_STATE,
    MAINMENU_STATE,
    GAMEPLAY_STATE,
    PAUSE_STATE
};

enum class _CollisionType {
    STATIC,
    DYNAMIC
};

inline const std::vector<sf::Vector2f> _WindowSizes
{
    sf::Vector2f(1366,768), // MY LAPTOP SCREEN
    sf::Vector2f(1024,576),
    sf::Vector2f(1152,648),
    sf::Vector2f(1280,720),
    sf::Vector2f(1366,768),
    sf::Vector2f(1600,900),
    sf::Vector2f(1920,1080),
    sf::Vector2f(2560,1440),
    sf::Vector2f(3840,2160)
};
inline std::int16_t _WindowSelectionID{1};

inline float _HeaderSize = _WindowSizes[_WindowSelectionID].y / 10.f; // These are the black bars on the top.
inline float _FooterBoxSize = _WindowSizes[_WindowSelectionID].y / 4.5f; // These are the black bars on the bottom.

inline sf::Rect<float> _WindowRegion{
	0.f, // Left Boundary
	_HeaderSize, // Top Boundary
	_WindowSizes[_WindowSelectionID].x, // Right Boundary
	_WindowSizes[_WindowSelectionID].y - (_HeaderSize + _FooterBoxSize) };  // Bottom Boundary