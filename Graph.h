#pragma once
#include <list>
#include <vector>
#include <glm\vec2.hpp>
class Graph
{
public:
	struct Node;
	struct Edge
	{
		Node *connection;
		float cost;
		// default constructor
		Edge() : connection(nullptr), cost(0) {}
		// overloaded constructor
		Edge(Node *a_connection) :
			connection(a_connection), cost(0) {}
		// overloaded constructor
		Edge(Node *a_connection, float a_cost) :
			connection(a_connection), cost(a_cost) {}
	};

	struct Node
	{
		glm::vec2 pos;
		float gScore;
		Node *parent;
		std::vector< Graph::Edge > connections;
		// default constructor
		Node() : pos(0, 0), gScore(0), parent(nullptr) {}
		// overloaded constructor
		Node(glm::vec2 a_pos) : pos(a_pos), gScore(0), parent(nullptr) {}
		// overloaded constructor
		Node(glm::vec2 a_pos, float a_gScore, Node *a_parent) :
			pos(a_pos), gScore(0), parent(a_parent) {}
	};

	Graph();
	virtual ~Graph();
	
	Node grid[10][10];

	Node *AddNode(int xPos, int yPos);

	void AddConnection(Node *n1, Node *n2);

	void FindShortestPath(Node *start, const std::list<Node *> &potentialEndNodes, std::list<Node *> &outPath);

	void FindNodesInRange(std::vector<Node *> &outNodes, float xPos, float yPos, float radius);
};
