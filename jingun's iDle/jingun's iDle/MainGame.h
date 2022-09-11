#pragma once
#include "Player.h"
#include "Monster.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();

private:
	HDC m_DC;

public:
	
	
};

