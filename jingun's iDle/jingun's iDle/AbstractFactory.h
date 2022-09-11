#pragma once

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj*  Create()
	{
		CObj* m_pObj = new T;

		m_pObj->Initialize();

		return m_pObj;
	}
	static CObj*	Create(float _fX, float _fY, float _fAngle)
	{
		CObj* m_pObj = new T;

		m_pObj->Initialize();

		m_pObj->Set_Pos(_fX, _fY);

		m_pObj->Set_Angle(_fAngle);

		return m_pObj;
	}
	static CObj*	Create(float _fY, INFO _tInfo, float _fAngle)
	{
		CObj* m_pObj = new T;

		m_pObj->Initialize();

		m_pObj->Set_Pos(550.f, _fY);

		m_pObj->Set_Angle(_fAngle);

		m_pObj->Set_Target(_tInfo.m_fX, _tInfo.m_fY);
	
		return m_pObj;
	}
};