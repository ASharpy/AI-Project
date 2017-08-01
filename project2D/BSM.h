#pragma once
#include <list>
#include <map>

class BehaviourState;

class BSM
{
public:
	/*
	calls the update function for all active state
	@param deltaTime bootstraps delta time
	no returns
	*/
	void updateState(float DT);

	/*
	adds the register command to the command list
	@param ID the key
	@param the state
	no returns
	*/
	void registerState(int ID , BehaviourState * bState);

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


	BehaviourState * getTopState();

private:

	//A map for all states
	std::map<int, BehaviourState*> RegoState;

	//Link list for active states this defines what the programm is currently in
	std::list<BehaviourState*> activeStates;

	enum class commandTypes{REGISTER, PUSH,POP};

	struct commands
	{
		commandTypes command;
		int id;
		BehaviourState * commandState;

	};
	
	//link list of the types of commands to do to the states
	std::list<commands> commandList;

	/*
	executes all the commands that were added to the command list
	no returns
	*/
	void docommands();
	
	/*
	adds all the states that need to be registered to the map
	no returns
	*/
	void doRegoStates(int id , BehaviourState* bStates);

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
	void doPushState(int id);

	BSM();

	~BSM();


};

