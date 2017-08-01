#include "BSM.h"
#include "BehaviourState.h"

BSM::BSM()
{
}


BSM::~BSM()
{
}

void BSM::updateState(float DT)
{
	docommands();

	for (auto &var : activeStates)
	{
		var->update(DT);
	}

}

void BSM::registerBState(int ID, BehaviourState * bState)
{
	commands command;
	command.id = ID;
	command.command = commandTypes::REGISTER;
	command.commandState = bState;
	commandList.push_back(command);

}

void BSM::pushState(int ID)
{
	commands command;
	command.id = ID;
	command.command = commandTypes::PUSH;
	command.commandState = nullptr;
	commandList.push_back(command);

}
void BSM::popState()
{
	commands command;
	command.id = -1;
	command.command = commandTypes::POP;
	command.commandState = nullptr;
	commandList.push_back(command);
}

BehaviourState * BSM::getTopState()
{
	return activeStates.back();
}

void BSM::docommands()
{
	for (auto var : commandList)
	{
		commands & command = var;

		switch (command.command)
		{
		case commandTypes::REGISTER:
			doRegoBStates(command.id, command.commandState);
			break;
		case commandTypes::POP:
			doPopState();
			break;
		case commandTypes::PUSH:
			doPushState(command.id);
			break;

		}
	}
	commandList.clear();
}

void BSM::doRegoBStates(int id, BehaviourState * bStates)
{
	RegoState.insert(std::pair<int, BehaviourState*>(id, bStates));
}

void BSM::doPopState()
{
	activeStates.pop_back();
}

void BSM::doPushState(int id)
{
	activeStates.push_back(RegoState[id]);
}



