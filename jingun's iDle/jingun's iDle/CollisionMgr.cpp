#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

void CollisionMgr::Collision_Sphere(list<CObj*> _pDesc, list<CObj*> _pSrc)
{
	for (auto& pDesc : _pDesc)
	{
		for (auto& pSrc : _pSrc)
		{
			if (Collision_Check(pDesc, pSrc))
			{

				pSrc->Set_Dead();

			}
		}
	}
}

bool CollisionMgr::Collision_Check(CObj * _pDesc, CObj * _pSrc)
{
	float fWidth = (_pDesc->Get_Info().m_fX - _pSrc->Get_Info().m_fX);
	float fHeight = _pDesc->Get_Info().m_fY - _pSrc->Get_Info().m_fY;

	float fDiagonal = sqrt(fWidth*fWidth + fHeight * fHeight);
	float fRadius = (_pDesc->Get_Info().m_fCX + _pSrc->Get_Info().m_fCX) / 2;

	if (fDiagonal <= fRadius)
	{
		return true;
	}
	return false;
}
