#pragma once
#include "GameObj.h"
class ElecMan :public GameObj
{
public:
	ElecManStatus status;
	ElecMan();
	~ElecMan();
	void SetStatus(ElecManStatus _status);
};

