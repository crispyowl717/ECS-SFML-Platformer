#pragma once

/*
**********************************************************************;
*	Project      : ECS_SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This helper struct creates a grid to overlay the screen. 
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include "Public/GlobalSettings.h"
#include <SFML/Graphics.hpp>

struct HGrid
{
public:
	HGrid(uint32_t IterationCount);
	void Draw(sf::RenderWindow& Window);
private:
	std::vector<sf::VertexArray> LineList;

};

inline HGrid::HGrid(uint32_t IterationCount)
{
	// The grid lines should be evenly spaced apart;
    const int LineSpacing = static_cast<int>(_WindowRegion.width / IterationCount);
	
    for (uint32_t i = 0; i < IterationCount; i++)
    {
        sf::VertexArray VerticalLine(sf::LineStrip, 2);
        VerticalLine[0].position = sf::Vector2f(i * LineSpacing, _WindowRegion.top);
        VerticalLine[1].position = sf::Vector2f(i * LineSpacing, _WindowRegion.top + _WindowRegion.height);
        LineList.push_back(VerticalLine);

        sf::VertexArray HorizontalLine(sf::LineStrip, 2);
        HorizontalLine[0].position = sf::Vector2f(0, i * LineSpacing);
        HorizontalLine[1].position = sf::Vector2f(_WindowSizes[_WindowSelectionID].x, i * LineSpacing);
        LineList.push_back(HorizontalLine);
    }
}

inline void HGrid::Draw(sf::RenderWindow& Window)
{
    for (auto& CurrentLine : LineList)
        Window.draw(CurrentLine);
}
