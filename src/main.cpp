#include "Application2D.h"
#include "Graph.h"
#include <iostream>
#include <list>

bool ReturnGScore(const Graph::Node & _nodea, const Graph::Node & _nodeb) {
	return _nodea.gScore < _nodeb.gScore;
}

int main() {

	//glm::vec2 temp = glm::vec2(1, 1);
	//glm::vec2 temp2 = glm::vec2(1, 2);
	//std::cout << glm::distance(temp, temp2)*(10);

	//std::list<Graph::Node> openList;
	//openList.push_front(Graph::Node(glm::vec2(1,4),13,nullptr));
	//openList.push_front(Graph::Node(glm::vec2(1, 4), 3, nullptr));
	//openList.push_front(Graph::Node(glm::vec2(1, 4), 123, nullptr));
	//for each (Graph::Node var in openList)
	//{
	//	std::cout << var.gScore << std::endl;
	//}

	BaseApplication* app = new Application2D();
	if (app->startup())
		app->run();
	app->shutdown();

	return 0;
}