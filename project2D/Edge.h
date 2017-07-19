#pragma once

#include <cmath>

class Node;
class Edge
{
public:
	Edge();
	~Edge();

	Node *p1;
	Node *p2;

	float g;

	float distance;

};

