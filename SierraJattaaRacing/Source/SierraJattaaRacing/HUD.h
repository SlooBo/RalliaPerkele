#ifndef HUD_H
#define HUD_H

class HUD
{
public:
	HUD();
	~HUD();

	void update();
	void draw();

	void setTextures(UTexture2D* texClock, UTexture2D* texBuildMenu,
		UTexture2D* texIncome, UTexture2D* texSpeed, UTexture2D* texHealth, texEscMenu);
	void setPointers(float* time, float* incomeTimer, int* currency, float* speed, int* health);

	void setBuildMenuPosition(float x, float y);
	void setClockPosition(float x, float y);
	void setIncomePosition(float x, float y);
	void setSpeedMeterPosition(float x, float y);
	void setPlayerHealthPosition(float x, float y);
	void setEscMenuPosition(float x, float y);

private:

	//Clock
	float* clock;
	FVector2D clockPosition;
	UTexture2D* clockTexture;

	//Tower build menu
	FVector2D buildMenuPosition;
	UTexture2D* buildMenuTexture;
	//Add hitbox for Build-Menu buttons

	//Tower-player currency and income timer
	float* timer;
	int* towerPlayerCurrency;
	FVector2D towerTimerAndCurrencyPosition;
	UTexture2D* towerTimerAndCurrencyTexture;

	//Driver-player variables
	float* playerSpeed;
	FVector2D speedMeterPosition;
	UTexture2D speedMeterTexture;

	int* playerHealth;
	FVector2D playerHealthPosition;
	UTexture2D playerHealthTexture;

	//Esc menu
	FVector2D escMenuPosition;
	UTexture2D escMenuTexture;

	//Add hitboxes for Esc-Menu buttons

};

#endif