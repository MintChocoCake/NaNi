#pragma once
#include "Obj.h"
#include "AbstractFactory.h"
#include "Bullet.h"
#include "ObjMgr.h"

class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void	   	 Create_Bullet();

};

