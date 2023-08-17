#include "MessageCollector.h"



MagnusMessageCollector::MagnusMessageCollector()
{

}

MagnusMessageCollector::~MagnusMessageCollector()
{

}

void MagnusMessageCollector::PushMessageToContainer(std::string msg)
{
	messageContainer.push_back(msg);
}

void MagnusMessageCollector::MessageLoopAsync()
{
	while (1)
	{
		if (!messageContainer.empty())
		{
			for (int i = 0; i < messageContainer.size(); ++i)
			{
				// 메세지를 꺼낸다

				// 메세지를가지고 무언갈 한다

				// 꺼낸 메세지를 소거한다
			}
		}
	}
}

