#pragma once
#include "Obj.h"
class CollisionMgr
{
public:
	CollisionMgr();
	~CollisionMgr();
public:
	static void Collision_Sphere(list<CObj*> _pDesc, list<CObj*> _pSrc);
	static bool Collision_Check(CObj* _pDesc, CObj* _pSrc);

};

