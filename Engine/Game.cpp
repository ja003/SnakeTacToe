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
#include "MainWindow.h"
#include "Game.h"
#include "Colors.h"


Game::Game(MainWindow& wnd)
	 :
	 wnd(wnd),
	 gfx(wnd),
	 table(5, 5, gfx),
	 player1("Adam", Colors::Red),
	 player2("Téra", Colors::Green),
	 activePlayer(&player1),
	 keyReleased(true)
{}

void Game::Go()
{
	 gfx.BeginFrame();
	 UpdateModel();
	 ComposeFrame();
	 gfx.EndFrame();
}

void Game::UpdateModel()
{
	 if(!wnd.kbd.ReadKey().IsPress())
	 {
		  return;
	 }

	 if(wnd.kbd.KeyIsPressed(VK_UP))
	 {
		  table.MoveSelectedCell(Up);
	 }
	 else if(wnd.kbd.KeyIsPressed(VK_DOWN))
	 {
		  table.MoveSelectedCell(Down);
	 }
	 else if(wnd.kbd.KeyIsPressed(VK_LEFT))
	 {
		  table.MoveSelectedCell(Left);
	 }
	 else if(wnd.kbd.KeyIsPressed(VK_RIGHT))
	 {
		  table.MoveSelectedCell(Right);
	 }

	 else if(wnd.kbd.KeyIsPressed(VK_SPACE))
	 {
		  table.Set(activePlayer->GetColor());
		  //swap players
		  activePlayer = activePlayer == &player1 ? &player2 : &player1;
	 }

	 //if(wnd.kbd.ReadKey().IsRelease)
}

void Game::ComposeFrame()
{
	 table.Draw();
}
