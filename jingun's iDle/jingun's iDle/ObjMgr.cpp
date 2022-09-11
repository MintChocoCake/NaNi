#include "stdafx.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"
#include"LineMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;
CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
}

void CObjMgr::Add_Obj(OBJID _typeId, CObj * _pObj)
{
	m_ObjList[_typeId].push_back(_pObj);
}

void CObjMgr::Update()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_ObjList[i].begin();iter!=m_ObjList[i].end();)
		{
			(*iter)->Update();

			if ((*iter)->Get_Dead())
			{
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
	
}

void CObjMgr::Late_Update()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();
		}
	}

	CollisionMgr::Collision_Sphere(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_MONSTER]);
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hDC);
		}
	}
	CLineMgr::Get_Instance()->Render(hDC);
}

void CObjMgr::Release()
{
}
