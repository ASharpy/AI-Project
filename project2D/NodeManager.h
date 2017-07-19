#pragma once
#include "Node.h"
#include "Edge.h"

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


};

