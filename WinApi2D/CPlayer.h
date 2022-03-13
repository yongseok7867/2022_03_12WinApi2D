#pragma once
#include "CGameObject.h"

class CTexture;

class CPlayer : public CGameObject
{
private:
	CTexture* m_pTex;

public:
	CPlayer();
	~CPlayer();

	virtual CGameObject* Clone();

	virtual void update();
	virtual void render(HDC hDc);
};

