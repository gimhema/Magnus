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
				// �޼����� ������

				// �޼����������� ���� �Ѵ�

				// ���� �޼����� �Ұ��Ѵ�
			}
		}
	}
}

