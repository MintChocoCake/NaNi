#pragma once
#include "Obj.h"
#include "ObjMgr.h"
#include "Bullet.h"
#include "AbstractFactory.h"

class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void Key_Input();
	void Jump();


private:
	bool		m_bJump;
	float		m_fPower;	// 점프 힘의 크기
	float		m_fTime;

	// 포신

public:
	// 플레이어 좌표 확인 용
	void		Player_Location(HDC hDC);
	// 총알 생성
	void		Create_Bullet();

	
};

