#pragma once
#include "GameObj.h"
class BomMan : public GameObj
{
public:
	BomManStatus status;
	BomMan();
	~BomMan();
	void SetStatus(BomManStatus _status);
};

