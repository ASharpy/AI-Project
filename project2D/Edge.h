#pragma once

#include <cmath>

class Node;
class Edge
{
public:
	Edge();
	~Edge();

	//the node from where the edge is leaving
	Node *p1;

	//the node from where the edge is going to
	Node *p2;

	float g;

	float distance;

};

