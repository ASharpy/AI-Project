#pragma once
#include "BinaryTree.h"
#include "List.h"
#include "Renderer2D.h"


class Apllication2D;
class State;
class StateManager
{
public:

	/*
	calls the update function for all active state
	@param deltaTime bootstraps delta time
	no returns
	*/
	void updateState(float deltaTime);

	/*
	calls the render function for all active states
	no returns
	*/
	void RenderState();

	/*
	adds the register command to the command list
	@param ID the key 
	@param the state
	no returns
	*/
	void registerState(int ID, State * state);
	
	/*
	adds the push command to the command list
	no returns
	*/
	void pushState(int ID);
	
	/*
	adds the pop command to the command list
	no returns
	*/
	void popState();
	

	StateManager();
	~StateManager();
	State * getTopState();

private:
	//Binary tree for all states
	BinaryTree<int, State*> Registeredstates;
	
	//Link list for active states this defines what the programm is currently in
	List<State*>activeStates;

	enum class commandTypes { REGISTER, PUSH, POP };

	struct commands
	{
		commandTypes command;
		int id;
		State* commandState;
	};

	//link list of the types of commands to do to the states
	List<commands> commandList;

	/*
	executes all the commands that were added to the command list 
	no returns
	*/
	void doCommands();
	
	/*
	adds all the states that need to be registered to the binary tree
	no returns
	*/
	void doRegisterStates(int ID, State* state);
	
	/*
	pop back all active states
	no returns
	*/
	void doPopState();
	
	/*
	pushes the active state to the list
	@param ID the key for the state (the enum)
	no returns
	*/
	void doPushState(int ID);
};

