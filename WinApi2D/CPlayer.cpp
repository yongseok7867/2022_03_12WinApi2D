#include "framework.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	SetScale(fPoint(100.f, 100.f));
}

CPlayer::~CPlayer()
{

}

CGameObject* CPlayer::Clone()
{
	return nullptr;
}

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (key('W'))
	{
		pos.y -= 1000 * fDT;
	}

	if (key('A'))
	{
		pos.x -= 1000 * fDT;
	}

	if (key('W'))
	{
		pos.y += 1000 * fDT;
	}

	if (key('W'))
	{
		pos.x += 1000 * fDT;
	}
	
	SetPos(pos);
}

void CPlayer::render(HDC hDc)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	Rectangle(hDC,
		(int)(pos.x - scale.x / 2),
		(int)(pos.y - scale.y / 2),
		(int)(pos.x - scale.x / 2),
		(int)(pos.y - scale.y / 2)
		);
}