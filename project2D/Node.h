#pragma once
#include <vector>
#include "Edge.h"
#include <list>


class Node
{
public:
	Node();
	~Node();
	
	float gScore;

	float fScore;

	float hScore;

	void setHscore(float hNum);

	void setgScore(float gNum);

	void setfScore(float fNum);

	float posX;
	
	Node* camefrom;
	float posY;
	
	bool iswalkable;

	int index = 0;
	std::list<Edge*>edgelist;

private: 

	
};

