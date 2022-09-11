#include "stdafx.h"
#include "MainGame.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "LineMgr.h"
#include "CollisionMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	
	CObjMgr::Get_Instance()->Add_Obj(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	CLineMgr::Get_Instance()->Initialize();

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();

	if (0 == CObjMgr::Get_Instance()->m_ObjList[OBJ_MONSTER].size())
	{
		for (size_t i = 0; i < 5; i++)
		{
			CObjMgr::Get_Instance()->Add_Obj(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(i * 100.f , CObjMgr::Get_Instance()->m_ObjList[OBJ_PLAYER].front()->Get_Info(),
				CObjMgr::Get_Instance()->m_ObjList[OBJ_PLAYER].front()->Get_Angle()));
		}
	}
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

	// 충돌 처리 추가
	CollisionMgr::Collision_Sphere(CObjMgr::Get_Instance()->m_ObjList[OBJ_BULLET], CObjMgr::Get_Instance()->m_ObjList[OBJ_MONSTER]);
	CollisionMgr::Collision_Sphere(CObjMgr::Get_Instance()->m_ObjList[OBJ_PLAYER], CObjMgr::Get_Instance()->m_ObjList[OBJ_MONSTER]);
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_DC);
	CLineMgr::Get_Instance()->Render(m_DC);

	

}
