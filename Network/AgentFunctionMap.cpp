#include "Connector.h"


AgentFunction::AgentFunction()
{

}

AgentFunction::~AgentFunction()
{

}

void AgentFunction::SetParam(char _param[MESSAGE_SIZE])
{

}

void AgentFunction::SetFunction(std::function<void(char*)> _func)
{
	Function = _func;
}

void AgentFunction::Execute()
{
	// std function member execute
	Function(param);
}


