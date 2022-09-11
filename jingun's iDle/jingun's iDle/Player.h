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
	float		m_fPower;	// ���� ���� ũ��
	float		m_fTime;

	// ����

public:
	// �÷��̾� ��ǥ Ȯ�� ��
	void		Player_Location(HDC hDC);
	// �Ѿ� ����
	void		Create_Bullet();

	
};

