#include "framework.h"
#include "CScene_Start.h"
#include "CPlayer.h"

void CScene_Start::Enter()
{
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(fPoint(100.f, 100.f));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);
}

void CScene_Start::Exit()
{
	DeleteAll();
}