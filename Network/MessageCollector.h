#pragma once

#include "../stdafx.h"
// Connector�κ��� �޾ƿ� �޼������� �߾ӿ��� �����Ѵ�.
// �� �޼����� �Ľ��ؼ� �׿� �´� �׼��� ������ �� �ְ��ϴ�... �߰迪���� ����Ѵ�.



class MagnusMessageCollector
{
public:
	MagnusMessageCollector();
	~MagnusMessageCollector();

public:
	std::vector<std::string> messageContainer;


public:
	void PushMessageToContainer(std::string msg);
	void MessageLoopAsync();
	

};