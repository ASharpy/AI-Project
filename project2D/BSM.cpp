#include "BSM.h"
#include "BehaviourState.h"

BSM::BSM()
{
}


BSM::~BSM()
{
}

void BSM::updateBehaveState(float DT)
{
	doBehavecommands();

	for (auto &var : activeBehaveStates)
	{
		var->update(DT);
	}

}

void BSM::registerBState(int ID, BehaviourState * bState)
{
	Behaviourcommands tempCommand;
	tempCommand.id = ID;
	tempCommand.Behavecommand = BehavecommandTypes::REGISTER;
	tempCommand.BehavecommandState = bState;
	BehavecommandList.push_back(tempCommand);

}

void BSM::pushBehaveState(int ID)
{
	Behaviourcommands tempCommand;
	tempCommand.id = ID;
	tempCommand.Behavecommand = BehavecommandTypes::PUSH;
	tempCommand.BehavecommandState = nullptr;
	BehavecommandList.push_back(tempCommand);

}
void BSM::popBehaveState()
{
	Behaviourcommands tempCommand;
	tempCommand.id = -1;
	tempCommand.Behavecommand = BehavecommandTypes::POP;
	tempCommand.BehavecommandState = nullptr;
	BehavecommandList.push_back(tempCommand);
}

BehaviourState * BSM::getTopBehaveState()
{
	return activeBehaveStates.back();
}

void BSM::doBehavecommands()
{
	for (auto var : BehavecommandList)
	{
		Behaviourcommands & command = var;

		switch (command.Behavecommand)
		{
		case BehavecommandTypes::REGISTER:
			doRegoBStates(command.id, command.BehavecommandState);
			break;
		case BehavecommandTypes::POP:
			doPopBehaveState();
			break;
		case BehavecommandTypes::PUSH:
			doPushBehaveState(command.id);
			break;

		}
	}
	BehavecommandList.clear();
}

void BSM::doRegoBStates(int id, BehaviourState * bStates)
{
	RegoState.insert(std::pair<int, BehaviourState*>(id, bStates));
}

void BSM::doPopBehaveState()
{
	activeBehaveStates.pop_back();
}

void BSM::doPushBehaveState(int id)
{
	activeBehaveStates.push_back(RegoState[id]);
}



