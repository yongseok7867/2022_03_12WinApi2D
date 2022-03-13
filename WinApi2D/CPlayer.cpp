#include "framework.h"
#include "CPlayer.h"
#include "CTexture.h"

CPlayer::CPlayer()
{
	SetScale(fPoint(100.f, 100.f));

	m_pTex = CResourceManager::getInst()->LoadTextrue(L"Player", L"texture\\Player.bmp");
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

	if (Key('W'))
	{
		pos.y -= 1000 * fDT;
	}

	if (Key('A'))
	{
		pos.x -= 1000 * fDT;
	}

	if (Key('S'))
	{
		pos.y += 1000 * fDT;
	}

	if (Key('D'))
	{
		pos.x += 1000 * fDT;
	}
	
	SetPos(pos);
}

void CPlayer::render(HDC hDC)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	TransparentBlt(hDC
		, (int)(pos.x - m_pTex->GetBmpWidth() / 2.f)
		, (int)(pos.y - m_pTex->GetBmpHeight() / 2.f)
		, m_pTex->GetBmpWidth()
		, m_pTex->GetBmpHeight()
		, m_pTex->GetDC()
		, 0
		, 0
		, m_pTex->GetBmpWidth()
		, m_pTex->GetBmpHeight()
		, RGB(255, 0, 255)	// RGB(255, 0, 255) 마젠타색(보라색) 을 제외한 사진을 그리는 TransparentBlt
	);
}