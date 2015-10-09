#pragma once

class CSprite
{
protected:
	SDL_Rect SpriteRect;
	SDL_Rect SpriteMask;
	int x, y;
	SDL_Point center;
	float rotation;
	SDL_RendererFlip flip;

	SDL_Surface * SpriteImage;
	SDL_Texture * SpriteTexture;
	char * SpriteName;
	
public:
	CSprite();
	CSprite(char *, int w, int h, int mx,int my,int mw, int mh);
	virtual ~CSprite();

	void SetSpriteImage(char *);

	void SetSpriteRect(int,int);
	void SetSpriteX(int);
	void SetSpriteY(int);
	void SetSpriteRotation(float); //ȸ���� ����
	void SetSpriteRotate(int);	//ȸ���� ��ȭ
	void SetSpriteCenter(int x, int y);

	SDL_Rect* GetSpriteRect();
	SDL_Rect* GetSpriteMask();
	int GetSpriteX();
	int GetSpriteY();
	float GetSpriteRotation();
	SDL_Texture * GetSpriteTexture();
	char * GetSpriteName();
	SDL_Point * GetSpriteCenter();
	SDL_RendererFlip * GetSpriteFlip();


	virtual void Update() = 0;
	
};

