﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#pragma comment(lib, "Msimg32.lib")

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <math.h>
#include <assert.h>

// STL
#include <vector>
#include <map>
#include <list>

using namespace std;

// Util
#include "SingleTon.h"
#include "struct.h"
#include "Logger.h"


//========================================
//## 게임 그룹						##
//========================================

enum class GROUP_GAMEOBJ
{
	DEFAULT,
	TILE,
	PLAYER,
	MONSTER,
	MISSILE_PLAYER,
	MISSILE_MONSTER,

	UI,		// UI는 모든 게임오브젝트 중 최상단 Layer에 위치
	SIZE,
};

enum class GROUP_SCENE
{
	TOOL,
	TITLE,
	START,
	STAGE_01,
	STAGE_02,

	SIZE,
};

//========================================
//## Core DC의 GDI					##
//========================================

enum class TYPE_BRUSH
{
	HOLLOW,

	SIZE,
};

enum class TYPE_PEN
{
	RED,
	GREEN,
	BLUE,

	SIZE,
};

//========================================
//## 이벤트 타입					##
//========================================

enum class TYPE_EVENT
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,

	SIZE,
};

// Core & Manager
#include "CCore.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CCollisionManager.h"
#include "CEventManager.h"
#include "CResourceManager.h"
#include "CCameraManager.h"
#include "CUIManager.h"
#include "CSoundManager.h"

//========================================
//##			디파인문				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

#define DT				CTimeManager::getInst()->GetDT()
#define fDT				CTimeManager::getInst()->GetfDT()

#define Key(key)		CKeyManager::getInst()->GetButton(key)
#define KeyUp(key)		CKeyManager::getInst()->GetButtonUP(key)
#define KeyDown(key)	CKeyManager::getInst()->GetButtonDOWN(key)

#define MousePos()		CKeyManager::getInst()->GetMousePos()

#define CreateObj(pObj, group)	CEventManager::getInst()->EventCreateObject(pObj, group)
#define DeleteObj(pObj)			CEventManager::getInst()->EventDeleteObject(pObj)
#define ChangeScn(scene)		CEventManager::getInst()->EventChangeScene(scene)

//========================================
//## 전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;
