#include "HUD.h"

HUD::HUD(){};
HUD::~HUD(){};

void HUD::update()
{

}
void HUD::draw()
{

}
void HUD::setTextures(UTexture2D* texClock, UTexture2D* texBuildMenu,
	UTexture2D* texIncome, UTexture2D* texSpeed, UTexture2D* texHealth, texEscMenu)
{
	UTexture2D* clockTexture = texClock;
	UTexture2D* buildMenuTexture = texBuildMenu;
	UTexture2D* towerTimerAndCurrencyTexture = texIncome;
	UTexture2D playerHealthTexture = texHealth;
	UTexture2D speedMeterTexture = texSpeed;
	UTexture2D escMenuTexture = texEscMenu;
}
void HUD::setPointers(float* time, float* incomeTimer, int* currency, float* speed, int* health)
{
	clock = time;
	timer = incomeTimer;
	towerPlayerCurrency = currency;
	playerSpeed = speed;
	playerHealth = health;
}