#pragma once

class CSprite_Player : public CSprite
{
public:
	CSprite_Player();
	~CSprite_Player();

	virtual void Update() override;
	
	void SetPlayerbIsMove(bool);
	bool *GetPlayerbIsMove();

private:
	bool bIsMove;
};

