#include "Application2D.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

#include <glm\mat3x3.hpp>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

Graph graph;

Application2D::Application2D() 
{
	std::list<Graph::Node*> endNodes;
	endNodes.push_back(&graph.grid[9][9]);
	graph.FindShortestPath(&graph.grid[0][0], endNodes);
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 500, 500);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	for each (Graph::Node n in graph.grid)
	{
		m_spriteBatch->setSpriteColor(1, 1, 1, 1);
		if (n.tested){ m_spriteBatch->setSpriteColor(1, 0, 1, 1); }
		if (n.traversed){ m_spriteBatch->setSpriteColor(1, 0, 0, 1); }

		m_spriteBatch->drawSprite(m_texture, n.pos.x * 50 + 25, n.pos.y * 50 + 25, 10, 10);
		for each (Graph::Edge e in n.connections)
		{
			m_spriteBatch->setSpriteColor(1, 1, 1, 1);
			if (e.tested) { m_spriteBatch->setSpriteColor(1, 0, 1, 1); }
			if (e.traversed) { m_spriteBatch->setSpriteColor(1, 0, 0, 1); }

			m_spriteBatch->drawLine(n.pos.x * 50 + 25, n.pos.y * 50 + 25, e.connection->pos.x * 50 + 25, e.connection->pos.y * 50 + 25, 1, 1);
		}
	}

	//m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	//m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	//m_spriteBatch->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f);

	//m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	//m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	//m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);

	// done drawing sprites
	m_spriteBatch->end();	
}