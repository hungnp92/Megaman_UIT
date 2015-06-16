#include "Resources.h"

MyResources::MyResources()
{ }

MyResources::~MyResources()
{
	if (sRockMan != NULL)
	{
		delete sRockMan;
	}

	if (sSniperJoe != NULL)
	{
		delete sSniperJoe;
	}

	if (sBanner != NULL)
	{
		delete sBanner;
	}
}

void MyResources::LoadResources()
{
	//Sprite of menu--------------------------------------------------------------------------------------------------
	sBanner = new Sprite();
	sBanner->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/logo.png", NULL));
	sBanner->AddStatus(SpriteStatus(1, 184, 57, 0));

	sboss_cutman = new Sprite();
	sboss_cutman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/boss_cutman.png", NULL));
	sboss_cutman->AddStatus(SpriteStatus(1, 45, 45, 0));

	sboss_elecman = new Sprite();
	sboss_elecman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/boss_elecman.png", NULL));
	sboss_elecman->AddStatus(SpriteStatus(1, 45, 45, 0));

	sboss_bomman = new Sprite();
	sboss_bomman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/boss_bomman.png", NULL));
	sboss_bomman->AddStatus(SpriteStatus(1, 45, 45, 0));

	sboss_fireman = new Sprite();
	sboss_fireman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/boss_fireman.png", NULL));
	sboss_fireman->AddStatus(SpriteStatus(1, 45, 45, 0));

	sboss_gastman = new Sprite();
	sboss_gastman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/boss_gastman.png", NULL));
	sboss_gastman->AddStatus(SpriteStatus(1, 45, 45, 0));

	sboss_iceman = new Sprite();
	sboss_iceman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/boss_iceman.png", NULL));
	sboss_iceman->AddStatus(SpriteStatus(1, 45, 45, 0));

	schoose = new Sprite();
	schoose->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/menu/choose.png", NULL));
	schoose->AddStatus(SpriteStatus(2, 45, 45, 0));

	//Sprite off map--------------------------------------------------------------------------------------------------
	sBgrMap1 = new Sprite();
	sBgrMap1->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/background/map1.png", NULL));
	sBgrMap1->AddStatus(SpriteStatus(36, 16, 16, 0));

	sCharactersNormal = new Sprite();
	sCharactersNormal->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/background/characters_normal.png", NULL));
	sCharactersNormal->AddStatus(SpriteStatus(39, 8, 8, 0));

	sCharactersBold = new Sprite();
	sCharactersBold->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/background/characters_bold.png", NULL));
	sCharactersBold->AddStatus(SpriteStatus(30, 8, 8, 0));
	//Sprite of Rockman-----------------------------------------------------------------------------------------------

	sRockMan = new Sprite();
	sRockMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/megaman/megaman.png", NULL));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManIntro),			5, 32, 32, 0));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManStop),			1, 22, 24, 32));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManRun),			3, 26, 24, 56));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManRunAndShoot),	3, 32, 24, 80));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManClimb),			2, 16, 28, 104));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManClimbOnTop),	2, 16, 22, 132));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManFall),			2, 28, 28, 154));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManShootWhenClimb),1, 30, 28, 182));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManShoot),			1, 32, 24, 210));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManWait),			1, 22, 24, 234));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManAfterJump),		1, 28, 24, 258));
	sRockMan->AddStatus(SpriteStatus(static_cast<int>(RockManStatus::RockManJump),			2, 26, 30, 282));

	//Sprite of boss--------------------------------------------------------------------------------------------------

	//Sprite of BomMan
	sBomMan = new Sprite();
	sBomMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/boss/bomman-full.png", NULL));
	sBomMan->AddStatus(SpriteStatus(static_cast<int>(BomManStatus::BomManJump),			3, 30, 30, 0));
	sBomMan->AddStatus(SpriteStatus(static_cast<int>(BomManStatus::BomManJumpThrow),	3, 30, 43, 30));
	sBomMan->AddStatus(SpriteStatus(static_cast<int>(BomManStatus::BomManThrow),		4, 32, 38, 73));
	sBomMan->AddStatus(SpriteStatus(static_cast<int>(BomManStatus::BomManIntro),		3, 24, 24, 111));

	//Sprite of CutMan
	sCutMan = new Sprite();
	sCutMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/boss/cutman-full.png", NULL));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManJumpNoWepond),		1, 24, 25, 0));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManJumpWithWepond),	1, 24, 32, 25));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManRunNoWepon),		3, 25, 24, 57));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManRunWithWepond),	3, 25, 32, 81));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManStopNoWepond),		2, 24, 24, 113));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManStopWithWepond),	2, 24, 32, 137));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManUnknow),			1, 30, 32, 169));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManWaitNoWepond),		1, 24, 25, 201));
	sCutMan->AddStatus(SpriteStatus(static_cast<int>(CutManStatus::CutManWaitWithWepond),	1, 24, 32, 226));

	//Sprites of ElecMan
	sElecMan = new Sprite();
	sElecMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/boss/elecman-full.png", NULL));
	sElecMan->AddStatus(SpriteStatus(static_cast<int>(ElecManStatus::ElecManJump),	1, 27, 32, 0));
	sElecMan->AddStatus(SpriteStatus(static_cast<int>(ElecManStatus::ElecManRun),	2, 22, 25, 32));
	sElecMan->AddStatus(SpriteStatus(static_cast<int>(ElecManStatus::ElecManThrow), 2, 32, 32, 57));
	sElecMan->AddStatus(SpriteStatus(static_cast<int>(ElecManStatus::ElecManIntro), 2, 26, 25, 89));
	sElecMan->AddStatus(SpriteStatus(static_cast<int>(ElecManStatus::ElecManWait),	1, 24, 24, 114));

	//Sprites of FireMan
	sFireMan = new Sprite();
	sFireMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/boss/fireman-full.png", NULL));
	sFireMan->AddStatus(SpriteStatus(static_cast<int>(FireManStatus::FireManIntro),		2, 24, 32, 32));
	sFireMan->AddStatus(SpriteStatus(static_cast<int>(FireManStatus::FireManDefend),	2, 24, 32, 0));
	sFireMan->AddStatus(SpriteStatus(static_cast<int>(FireManStatus::FireManJump),		1, 24, 38, 64));
	sFireMan->AddStatus(SpriteStatus(static_cast<int>(FireManStatus::FireManRun),		4, 25, 28, 102));
	sFireMan->AddStatus(SpriteStatus(static_cast<int>(FireManStatus::FireManShoot),		2, 30, 32, 130));
	sFireMan->AddStatus(SpriteStatus(static_cast<int>(FireManStatus::FireManWait),		2, 24, 32, 162));

	//Sprites of GastMan
	sGastMan = new Sprite();
	sGastMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/boss/gastman-full.png", NULL));
	sGastMan->AddStatus(SpriteStatus(static_cast<int>(GastManStatus::GastManIntro),		2, 32, 32, 0));
	sGastMan->AddStatus(SpriteStatus(static_cast<int>(GastManStatus::GastManHangUp),	2, 32, 32, 32));
	sGastMan->AddStatus(SpriteStatus(static_cast<int>(GastManStatus::GastManJump),		1, 32, 32, 64));
	sGastMan->AddStatus(SpriteStatus(static_cast<int>(GastManStatus::GastManThrow),		1, 32, 32, 96));
	sGastMan->AddStatus(SpriteStatus(static_cast<int>(GastManStatus::GastManWait),		1, 32, 32, 128));

	//Sprites of IceMan
	sIceMan = new Sprite();
	sIceMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/boss/iceman-full.png", NULL));
	sIceMan->AddStatus(SpriteStatus(static_cast<int>(IceManStatus::IceManIntro),	2, 24, 24, 0));
	sIceMan->AddStatus(SpriteStatus(static_cast<int>(IceManStatus::IceManRun),		2, 24, 22, 24));
	sIceMan->AddStatus(SpriteStatus(static_cast<int>(IceManStatus::IceManBlow),		1, 22, 24, 46));
	sIceMan->AddStatus(SpriteStatus(static_cast<int>(IceManStatus::IceManJump),		2, 24, 28, 70));
	sIceMan->AddStatus(SpriteStatus(static_cast<int>(IceManStatus::IceManStop),		1, 28, 24, 98));
	sIceMan->AddStatus(SpriteStatus(static_cast<int>(IceManStatus::IceManWait),		1, 24, 24, 122));

	//Sprite of static object-----------------------------------------------------------------------------------------
	sBrick = new Sprite();
	sBrick->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/background/brick.png", NULL));
	sBrick->AddStatus(SpriteStatus(1, 32, 32, 0));

	//Sprite of enemy-------------------------------------------------------------------------------------------------

	sBunbyHeliBlue = new Sprite();
	sBunbyHeliBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BunbyHeliBlue.png", NULL));
	sBunbyHeliBlue->AddStatus(SpriteStatus(2, 18, 21, 0));

	sBunbyHeliGreen = new Sprite();
	sBunbyHeliGreen->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BunbyHeliGreen.png", NULL));
	sBunbyHeliGreen->AddStatus(SpriteStatus(2, 18, 19, 0));

	sBlasterRed = new Sprite();
	sBlasterRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BlasterRed.png", NULL));
	sBlasterRed->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterWaitForProtected), 4, 16, 16, 16));
	sBlasterRed->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterProtected), 1, 16, 16, 0));
	sBlasterRed->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterWaitForShoot), 4, 16, 16, 0));
	sBlasterRed->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterShoot), 1, 16, 16, 16));


	sBlasterOrange = new Sprite();
	sBlasterOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BlasterOrange.png", NULL));
	sBlasterOrange->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterWaitForProtected), 4, 16, 16, 16));
	sBlasterOrange->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterProtected), 1, 16, 16, 0));
	sBlasterOrange->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterWaitForShoot), 4, 16, 16, 0));
	sBlasterOrange->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterShoot), 1, 16, 16, 16));

	//////
	sBlasterBlue = new Sprite();
	sBlasterBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BlasterBlue.png", NULL));
	sBlasterBlue->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterWaitForProtected), 4, 16, 16, 16));
	sBlasterBlue->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterProtected), 1, 16, 16, 0));
	sBlasterBlue->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterWaitForShoot), 4, 16, 16, 0));
	sBlasterBlue->AddStatus(SpriteStatus(static_cast<int>(BlasterStatus::BlasterShoot), 1, 16, 16, 16));

	/////
	sBouncingMushroomRed = new Sprite();
	sBouncingMushroomRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BouncingMushroomRed.png", NULL));
	sBouncingMushroomRed->AddStatus(SpriteStatus(static_cast<int>(BouncingMushroomStatus::BouncingMushroomOnAir), 1, 14, 20, 0));
	sBouncingMushroomRed->AddStatus(SpriteStatus(static_cast<int>(BouncingMushroomStatus::BouncingMushroomOnGround), 1, 14, 20, 20));

	sBouncingMushroomBlue = new Sprite();
	sBouncingMushroomBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BouncingMushroomBlue.png", NULL));
	sBouncingMushroomBlue->AddStatus(SpriteStatus(static_cast<int>(BouncingMushroomStatus::BouncingMushroomOnAir), 1, 14, 20, 0));
	sBouncingMushroomBlue->AddStatus(SpriteStatus(static_cast<int>(BouncingMushroomStatus::BouncingMushroomOnGround), 1, 14, 20, 20));

	sMambu = new Sprite();
	sMambu->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/Mambu.png", NULL));
	sMambu->AddStatus(SpriteStatus(2, 17, 21, 0));

	sGabyoallOrange = new Sprite();
	sGabyoallOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/GabyoallOrange.png", NULL));
	sGabyoallOrange->AddStatus(SpriteStatus(2, 16, 8, 0));

	sGabyoallRed = new Sprite();
	sGabyoallRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/GabyoallRed.png", NULL));
	sGabyoallRed->AddStatus(SpriteStatus(2, 16, 8, 0));

	sGabyoallBlue = new Sprite();
	sGabyoallBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/GabyoallBlue.png", NULL));
	sGabyoallBlue->AddStatus(SpriteStatus(2, 16, 8, 0));

	sPicketMan = new Sprite();
	sPicketMan->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/PicketMan.png", NULL));
	sPicketMan->AddStatus(SpriteStatus(5, 32, 24, 0));

	sSniperJoe = new Sprite();
	sSniperJoe->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/SniperJoe.png", NULL));
	sSniperJoe->AddStatus(SpriteStatus(4, 32, 31, 0));

	sWatcher = new Sprite();
	sWatcher->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/Watcher.png", NULL));
	sWatcher->AddStatus(SpriteStatus(3, 16, 42, 0));

	sPepe = new Sprite();
	sPepe->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/Pepe.png", NULL));
	sPepe->AddStatus(SpriteStatus(2, 24, 15, 0));

	sChangkey = new Sprite();
	sChangkey->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/Changkey.png", NULL));
	sChangkey->AddStatus(SpriteStatus(2, 16, 16, 0));

	sFootHolderGreen = new Sprite();
	sFootHolderGreen->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/FootHolderGreen.png", NULL));
	sFootHolderGreen->AddStatus(SpriteStatus(2, 24, 24, 0));

	sFootHolderOrange = new Sprite();
	sFootHolderOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/FootHolderOrange.png", NULL));
	sFootHolderOrange->AddStatus(SpriteStatus(2, 24, 24, 0));

	sCrazyRazy = new Sprite();
	sCrazyRazy->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/CrazyRazy.png", NULL));
	sCrazyRazy->AddStatus(SpriteStatus(2, 32, 31, 0));

	sCrazyRazyBody = new Sprite();
	sCrazyRazyBody->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/CrazyRazyBody.png", NULL));
	sCrazyRazyBody->AddStatus(SpriteStatus(3, 32, 26, 0));

	sCrazyRazyFoot = new Sprite();
	sCrazyRazyFoot->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/CrazyRazyFoot.png", NULL));
	sCrazyRazyFoot->AddStatus(SpriteStatus(2, 16, 16, 392));

	sBigEyeRed = new Sprite();
	sBigEyeRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BigEyeRed.png", NULL));
	sBigEyeRed->AddStatus(SpriteStatus(static_cast<int>(BigEyeStatus::BigEyeOnAir), 1, 40, 48, 0));
	sBigEyeRed->AddStatus(SpriteStatus(static_cast<int>(BigEyeStatus::BigEyeOnGround), 1, 40, 48, 48));

	sBigEyeBlue = new Sprite();
	sBigEyeBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/BigEyeBlue.png", NULL));
	sBigEyeBlue->AddStatus(SpriteStatus(static_cast<int>(BigEyeStatus::BigEyeOnAir), 1, 40, 48, 0));
	sBigEyeBlue->AddStatus(SpriteStatus(static_cast<int>(BigEyeStatus::BigEyeOnGround), 1, 40, 40, 40));

	sSuzyBlue = new Sprite();
	sSuzyBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/SuzyBlue.png", NULL));
	sSuzyBlue->AddStatus(SpriteStatus(3, 16, 16, 0));

	sSuzyRed = new Sprite();
	sSuzyRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/SuzyRed.png", NULL));
	sSuzyRed->AddStatus(SpriteStatus(static_cast<int>(SuzyStatus::SuzyAttack), 3, 16, 16, 0));
	sSuzyRed->AddStatus(SpriteStatus(static_cast<int>(SuzyStatus::SuzyNormal), 3, 16, 16, 16));

	sSuzyOrange = new Sprite();
	sSuzyOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/SuzyOrange.png", NULL));
	sSuzyOrange->AddStatus(SpriteStatus(3, 16, 16, 0));

	sScrewDriverOrange = new Sprite();
	sScrewDriverOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/ScrewDriverOrange.png", NULL));
	sScrewDriverOrange->AddStatus(SpriteStatus(3, 16, 16, 0));

	sScrewDriverBlue = new Sprite();
	sScrewDriverBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/ScrewDriverBlue.png", NULL));
	sScrewDriverBlue->AddStatus(SpriteStatus(3, 16, 16, 0));

	sScrewDriverRed = new Sprite();
	sScrewDriverRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/ScrewDriverRed.png", NULL));
	sScrewDriverRed->AddStatus(SpriteStatus(3, 16, 16, 0));

	sSuperCutter = new Sprite();
	sSuperCutter->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/SuperCutter.png", NULL));
	sSuperCutter->AddStatus(SpriteStatus(2, 23, 20, 0));

	sKillerBombOrange = new Sprite();
	sKillerBombOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/KillerBombOrange.png", NULL));
	sKillerBombOrange->AddStatus(SpriteStatus(1, 16, 16, 0));

	sKillerBombRed = new Sprite();
	sKillerBombRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/KillerBombRed.png", NULL));
	sKillerBombRed->AddStatus(SpriteStatus(1, 16, 16, 0));

	sKillerBombBlue = new Sprite();
	sKillerBombBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/KillerBombBlue.png", NULL));
	sKillerBombBlue->AddStatus(SpriteStatus(1, 16, 16, 0));

	sMetall = new Sprite();
	sMetall->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/enemies/Metall.png", NULL));
	sMetall->AddStatus(SpriteStatus(2, 18, 15, 0));

	//Bullet	
	bRed = new Sprite();
	bRed->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/bullet/Red.png", NULL));
	bRed->AddStatus(SpriteStatus(1, 6, 6, 0));

	bGreen = new Sprite();
	bGreen->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/bullet/Green.png", NULL));
	bGreen->AddStatus(SpriteStatus(1, 6, 6, 0));

	bBlue = new Sprite();
	bBlue->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/bullet/Blue.png", NULL));
	bBlue->AddStatus(SpriteStatus(1, 6, 6, 0));

	bOrange = new Sprite();
	bOrange->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/bullet/Orange.png", NULL));
	bOrange->AddStatus(SpriteStatus(1, 8, 6, 0));

	bRockman = new Sprite();
	bRockman->LoadSprite(DxMngr::GetInstance().GetTextureFromBitmap("Resources/Images/bullet/Rockman.png", NULL));
	bRockman->AddStatus(SpriteStatus(1, 6, 6, 0));
}