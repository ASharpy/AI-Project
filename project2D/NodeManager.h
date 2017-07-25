#pragma once
#include "Node.h"
#include "Edge.h"
#include <list>

class NodeManager
{
public:

	void createNodes();

	Node *gameNodes; //2304;


	int index(int posX, int posY);

	NodeManager();
	~NodeManager();

	Edge *edges;
	
	void getEdges();

	float calcHeuristic(Node* node, Node* EndNode);
	
	float calcDistance(Node* node1, Node* node2 );

	std::list<Node*>aStar(Node* Start, Node* End);

};

