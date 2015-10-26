#pragma once
#include "DrawManager.h"
#include "Sprite.h"

class CScene
{
protected:
	//==== ��������Ʈ ====
	vector<CSprite *> vSprite;
	int nSprite;
	//===================

	//==== Scene�� ��� ====
	SDL_Surface *SceneBGImage;
	SDL_Texture *SceneBGTexture;
	SDL_Rect SceneBGRect;
	//======================

public:
	CScene(int n);
	virtual ~CScene(void);

	void SetSceneBGImage(char *);
	CSprite* FindSpriteByName(char *);

	void addSprite(CSprite *);

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

