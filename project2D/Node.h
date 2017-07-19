#pragma once
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

private:

	float f;

	float h;
};

