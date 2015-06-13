#pragma once
#include "GameObj.h"
class ItemObj :
	public GameObj
{
public:
	ItemObj(Sprite* _sprite);
	~ItemObj();
	void Update(float _delta) override;
	
	int i_aliveTime;
	int i_pointBonus;
	int i_healthBonus;
	int i_energyBonus;
};