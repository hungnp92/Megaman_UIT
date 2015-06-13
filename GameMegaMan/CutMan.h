#pragma once
#include "GameObj.h"
class CutMan : public GameObj
{
public:
	CutManStatus status;
	CutMan();
	~CutMan();
	void SetStatus(CutManStatus _status);
};

