#pragma once
#include "Node.h"
#include "Edge.h"
#include <list>

class NodeManager
{
public:
	/*
	creates a grid of nodes 20 apart
	no return
	*/
	void createNodes();

	Node *gameNodes; //2304;

	int TOTAL_NODES = 0;
	int TOTAL_EDGE = 0;

	
	/*
	gets the index of a node from a position
	@param posX position X of an object
	@param posY position Y of an object
	returns what node the object is closest to
	*/
	int index(int posX, int posY);

	NodeManager();
	~NodeManager();

	

	Edge *edges;
	
	/*
	does a circle check around nodes and connects edges to nodes that are within the circle check
	no return
	*/
	void getEdges();

	/*
	calculates the heuristic using real distance
	@param node any node
	@param endnode the endnode
	returns a float of the distance from one node to the end node
	*/
	float calcHeuristic(Node* node, Node* EndNode);

	/*
	calculates distance between two nodes
	@param node1 any node
	@param node2 any node
	returns a float of the distance from one node to another node
	*/
	float calcDistance(Node* node1, Node* node2);

	/*
	checks if a node is within a radius of another node
	@param node1 any node
	@param node2 any node
	@param dist the distance between nodes
	returns whether it found a node or not
	*/
	bool CircleCheck(Node* node1, Node* node2, float Dist);

	/*
	A* algorithm 
	@param start start node 
	@param end end node
	returns the best path to another node
	*/
	std::list<Node*>aStar(Node* Start, Node* End);

	/*
	get the best path from the a* path
	@param current the current node that was nearest the end node 
	returns the nodes that lead to the best path
	*/
	std::list<Node*>reconstructPath(Node* current);

};

