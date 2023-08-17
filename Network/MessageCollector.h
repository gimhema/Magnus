#pragma once

#include "../stdafx.h"
// Connector로부터 받아온 메세지들을 중앙에서 수집한다.
// 이 메세지를 파싱해서 그에 맞는 액션을 수행할 수 있게하는... 중계역할을 담당한다.



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