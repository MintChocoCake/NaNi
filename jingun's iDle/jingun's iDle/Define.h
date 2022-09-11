#pragma once

#define WINCX 800
#define WINCY 600


typedef struct tagInfo {
	float m_fX;
	float m_fY;
	float m_fCX;
	float m_fCY;
}INFO;


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagLinePoint
{
	float fX;
	float fY;

	tagLinePoint(void) { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

}MYPOINT;

typedef struct tagLine
{
	MYPOINT tLPoint;
	MYPOINT tRPoint;
	tagLine(void) { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(MYPOINT& tLeft, MYPOINT& tRight) : tLPoint(tLeft), tRPoint(tRight) {}

}LINE;

enum OBJID{OBJ_PLAYER,OBJ_MONSTER,OBJ_BULLET,OBJ_END};
extern HWND g_hWnd;