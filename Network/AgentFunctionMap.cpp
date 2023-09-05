#include "Connector.h"


AgentFunction::AgentFunction()
{

}

AgentFunction::~AgentFunction()
{

}

void AgentFunction::SetParam(std::string _param)
{
	param = _param;
}

void AgentFunction::SetFunction(std::function<void(std::string)> _func)
{
	Function = _func;
}

void AgentFunction::Execute()
{
	// std function member execute
	Function(param);
}


