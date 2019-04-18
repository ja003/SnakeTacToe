/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"

Game::Game(MainWindow& wnd)
	 :
	 wnd(wnd),
	 gfx(wnd),
	 table(5, 5, gfx),
	 snake1("Adam", Colors::Red),
	 snake2("Téra", Colors::Green),
	 isPaused(false)
{
	 snake1.SetOponent(&snake2);
	 snake2.SetOponent(&snake1);

	 table.SetActiveSnake(&snake1);
}

void Game::Go()
{
	 //prevent multiple press 
	 isKeyPress = wnd.kbd.ReadKey().IsPress() ;
	 //check for PAUSE key	 
	 if(isKeyPress && wnd.kbd.KeyIsPressed(VK_DELETE))
	 {
		  isPaused = !isPaused;
	 }
	 if(isPaused)
		  return;

	 gfx.BeginFrame();
	 UpdateModel();
	 ComposeFrame();
	 gfx.EndFrame();
}

void Game::UpdateModel()
{
	 const float dt = ft.Mark();
	 gameTime += dt;
	 timeToNextStep -= dt;
	 if(timeToNextStep < 0)
	 {
		  timeToNextStep = STEP_FREQUENCY;
		  table.Move();
	 }

	 //dont do key action if key not pressed
	 if(!isKeyPress)
	 {
			return;
	 }


	 if(wnd.kbd.KeyIsPressed(VK_UP))
	 {
		  table.MoveDirection = Up;
	 }
	 else if(wnd.kbd.KeyIsPressed(VK_DOWN))
	 {
		  table.MoveDirection = Down;
	 }
	 else if(wnd.kbd.KeyIsPressed(VK_LEFT))
	 {
		  table.MoveDirection = Left;
	 }
	 else if(wnd.kbd.KeyIsPressed(VK_RIGHT))
	 {
		  table.MoveDirection = Right;
	 }

	 else if(wnd.kbd.KeyIsPressed(VK_SPACE))
	 {
		  table.MakeSymbol();
	 }

	 //if(wnd.kbd.ReadKey().IsRelease)
}

void Game::ComposeFrame()
{
	 table.Draw();
}
