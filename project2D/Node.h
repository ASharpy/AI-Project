#pragma once
#include <vector>
#include "Edge.h"


class Node
{
public:
	Node();
	~Node();
	
	float getH();

	float getF();

	float posX;
	
	float posY;
	
	bool iswalkable;

	std::vector<Edge*> edgeList;

private:

	float f;

	float h;
};

