#pragma once
#include "Sprite.h"

enum GameObjectType
{
	o_TRANSPARENT,
	o_LADDER,
	o_FLAG,
	o_BACKGROUND,
	o_ROCKMAN,
	o_BOMMAN,
	o_CUTMAN,
	o_ELECMAN,
	o_FIREMAN,
	o_GASTMAN,
	o_ICEMAN,
	o_BUNBYHELIBLUE,
	o_BUNBYHELIGREEN,
	o_BLASTERRED,
	o_BLASTERORANGE,
	o_BLASTERBLUE,
	o_MAMBU,
	o_GABYOALLORANGE,
	o_GABYOALLRED,
	o_GABYOALLBLUE,
	o_PICKETMAN,
	o_SNIPERJOE,
	o_WATCHER,
	o_PEPE,
	o_CHANGKEY,
	o_FOOTHOLDERGREEN,
	o_FOOTHOLDERORANGE,
	o_CRAZYRAZY,
	o_CRAZYRAZYBODY,
	o_CRAZYRAZYFOOT,
	o_BIGEYERED,
	o_BIGEYEBLUE,
	o_SUZYBLUE,
	o_SUZYRED,
	o_SUZYORANGE,
	o_SCREWDRIVERORANGE,
	o_SCREWDRIVERBLUE,
	o_SCREWDRIVERRED,
	o_SUPERCUTTER,
	o_KILLERBOMBORANGE,
	o_KILLERBOMBRED,
	o_KILLERBOMBBLUE,
	o_METALL,
	o_FENCE,
	o_SUPERCUTTERPARENT,
	o_BRICK,
	o_DOOR,
	o_BOUNCINGMUSHROOM,

	o_BULLET,
	o_BOUNCINGMUSHROOMRED,
};

enum RockManStatus
{
	RockManIntro,
	RockManStop,
	RockManRun,
	RockManRunAndShoot,
	RockManClimb,
	RockManClimbOnTop,
	RockManFall,
	RockManShootWhenClimb,
	RockManShoot,
	RockManWait,
	RockManAfterJump,
	RockManJump,
};

enum BomManStatus
{
	BomManJump,
	BomManJumpThrow,
	BomManThrow,
	BomManIntro,
};

enum CutManStatus{
	CutManJumpNoWepond,
	CutManJumpWithWepond,
	CutManRunNoWepon,
	CutManRunWithWepond,
	CutManStopNoWepond,
	CutManStopWithWepond,
	CutManUnknow,
	CutManWaitNoWepond,
	CutManWaitWithWepond,
};

enum ElecManStatus{
	ElecManJump,
	ElecManRun,
	ElecManThrow,
	ElecManIntro,
	ElecManWait,
};

enum FireManStatus{
	FireManIntro,
	FireManDefend,
	FireManJump,
	FireManRun,
	FireManShoot,
	FireManWait,
};

enum GastManStatus{
	GastManIntro,
	GastManHangUp,
	GastManJump,
	GastManThrow,
	GastManWait,
};

enum IceManStatus{
	IceManIntro,
	IceManRun,
	IceManBlow,
	IceManJump,
	IceManStop,
	IceManWait,
};

//////////////////////////////////////////////////////////////////////////
//Enermies
enum BlasterStatus
{
	BlasterWaitForShoot,
	BlasterShoot,
	BlasterProtected,
	BlasterWaitForProtected
};

enum BigEyeStatus
{
	BigEyeOnGround,
	BigEyeOnAir,
};

enum BunbyHeliStatus
{
	BunbyHeliNormal,			//Moving only not attack target
	BunbyHeliAttack,			//Attack target
};

enum SuzyStatus
{
	SuzyNormal,			//Suzy stick with the wall
	SuzyAttack,			//Suzy move
};

enum BouncingMushroomStatus
{
	BouncingMushroomOnGround,
	BouncingMushroomOnAir,
};

enum GameStage
{
	STAGE_NONE,
	STAGE_WELCOME,
	STAGE_INTRODUCE,
	STAGE_MAINMENU,
	STAGE_GAMEPLAY
};

class MyResources
{
public:

	//Sprite of menu
	Sprite* sBanner;

	//Sprite of stage
	Sprite* sboss_cutman;
	Sprite* sboss_elecman;
	Sprite* sboss_bomman;
	Sprite* sboss_fireman;
	Sprite* sboss_gastman;
	Sprite* sboss_iceman;
	Sprite* schoose;

	//Sprite off map
	Sprite* sBgrMap1;
	Sprite* sCharactersNormal;
	Sprite* sCharactersBold;

	//Sprite of Rockman
	Sprite* sRockMan;

	//Sprite of boss	
	Sprite* sBomMan;	
	Sprite* sCutMan;
	Sprite* sElecMan;
	Sprite* sFireMan;
	Sprite* sGastMan;
	Sprite* sIceMan;

	//Sprite of static object
	Sprite* sBrick;

	//Sprite of enemy
	Sprite* sBunbyHeliBlue;
	Sprite* sBunbyHeliGreen;
	Sprite* sBlasterRed;
	Sprite* sBlasterOrange;
	Sprite* sBlasterBlue;
	Sprite* sMambu;
	Sprite* sGabyoallOrange;
	Sprite* sGabyoallRed;
	Sprite* sGabyoallBlue;
	Sprite* sPicketMan;
	Sprite* sSniperJoe;
	Sprite* sWatcher;
	Sprite* sPepe;
	Sprite* sChangkey;
	Sprite* sFootHolderGreen;
	Sprite* sFootHolderOrange;
	Sprite* sCrazyRazy;
	Sprite* sCrazyRazyBody;
	Sprite* sCrazyRazyFoot;
	Sprite* sBigEyeRed;
	Sprite* sBigEyeBlue;
	Sprite* sSuzyBlue;
	Sprite* sSuzyRed;
	Sprite* sSuzyOrange;
	Sprite* sScrewDriverOrange;
	Sprite* sScrewDriverBlue;
	Sprite* sScrewDriverRed;
	Sprite* sSuperCutter;
	Sprite* sKillerBombOrange;
	Sprite* sKillerBombRed;
	Sprite* sKillerBombBlue;
	Sprite* sMetall;
	Sprite* sBouncingMushroomBlue;
	Sprite* sBouncingMushroomRed;

	//Sprite of bullet
	Sprite* bBlue;
	Sprite* bRed;
	Sprite* bOrange;
	Sprite* bGreen;
	Sprite* bRockman;


	MyResources();
	~MyResources();
	void LoadResources();
	static MyResources &GetInstance()
	{
		static MyResources resources;
		return resources;
	}
};