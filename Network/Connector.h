#pragma once

#include "../stdafx.h"

// Magnus���� �н���ų ���Ӱ� ���ʷ� ����ϴ� Ŭ�����̴�.
// ���Ӱ��� ���� ���¸� �����Ѵ�.
// ���ӿ��� �����ϴ� �޼����� ���ʷ� �޾ƿ��� Ŭ�����̴�.

class MagnusConnector
{
public:

	MagnusConnector();
	~MagnusConnector();

public:

	void ConnectorSocketInitialize();
	void CreateConnectorIOCP();
	void ConnectorReady();
	void ConnectorListen();
	void ConnectorClose();
	void PublishData();


public:

};