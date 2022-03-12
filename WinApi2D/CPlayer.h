#pragma once
#include "CGameObject.h"

class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	virtual CGameObject* Clone();

	virtual void update();
	virtual void render(HDC hDc);
};

