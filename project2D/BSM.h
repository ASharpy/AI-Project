#pragma once
#include <list>
#include <vector>
#include <map>

class BehaviourState;

class BSM
{
public:
	BSM();

	~BSM();
	/*
	calls the update function for all active state
	@param deltaTime bootstraps delta time
	no returns
	*/
	void updateBehaveState(float DT);

	/*
	adds the register command to the command list
	@param ID the key
	@param the state
	no returns
	*/
	void registerBState(int ID , BehaviourState * bState);

	/*
	adds the push command to the command list
	no returns
	*/
	void pushBehaveState(int ID);

	/*
	adds the pop command to the command list
	no returns
	*/
	void popBehaveState();


	BehaviourState * getTopBehaveState();

private:

	//A map for all states
	std::map<int, BehaviourState*> RegoState;

	//Link list for active states this defines what the programm is currently in
	std::list<BehaviourState*> activeBehaveStates;

	enum class BehavecommandTypes{REGISTER, PUSH,POP};

	struct Behaviourcommands
	{
		BehavecommandTypes Behavecommand;
		int id;
		BehaviourState * BehavecommandState;

	};
	
	//link list of the types of commands to do to the states
	std::vector<Behaviourcommands> BehavecommandList;

	/*
	executes all the commands that were added to the command list
	no returns
	*/
	void doBehavecommands();
	
	/*
	adds all the states that need to be registered to the map
	no returns
	*/
	void doRegoBStates(int id , BehaviourState* bStates);

	/*
	pop back all active states
	no returns
	*/
	void doPopBehaveState();

	/*
	pushes the active state to the list
	@param ID the key for the state (the enum)
	no returns
	*/
	void doPushBehaveState(int id);




};

