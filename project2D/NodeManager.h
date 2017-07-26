#pragma once
#include "Node.h"
#include "Edge.h"
#include <list>

class NodeManager
{
public:

	void createNodes();

	Node *gameNodes; //2304;
	int TOTAL_NODES = 0;
	int TOTAL_EDGE = 0;


	int index(int posX, int posY);

	NodeManager();
	~NodeManager();

	

	Edge *edges;
	
	void getEdges();

	float calcHeuristic(Node* node, Node* EndNode);

	float calcDistance(Node* node1, Node* node2);
	bool CircleCheck(Node* node1, Node* node2, float Dist);

	std::list<Node*>aStar(Node* Start, Node* End);

	std::list<Node*>reconstructPath(Node* current);

	void findNeighbours(Node* node);
};

