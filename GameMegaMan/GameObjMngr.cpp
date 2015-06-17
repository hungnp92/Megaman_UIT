#include "GameObjMngr.h"

GameObjMngr::GameObjMngr()
{ }

GameObjMngr::~GameObjMngr()
{
}

GameObj* GameObjMngr::CreateGameObject(GameObjectType type, float posX, float posY, int width, int height, int state)
{
	GameObj* obj = NULL;
	switch (type)
	{
	case o_BACKGROUND:
		obj = new BackgroundTitle();
		obj->currentFrame = state;
		break;
	case o_ROCKMAN:
		obj = new RockMan();
		break;
	case o_BOMMAN:
		obj = new BomMan();
		break;
	case o_CUTMAN:
		obj = new CutMan();
		break;
	case o_ELECMAN:
		obj = new ElecMan();
		break;
	case o_FIREMAN:
		//obj = new FireMan();
		break;
	case o_GASTMAN:
		//obj = new GastMan();
		break;
	case o_ICEMAN:
		//obj = new IceMan();
		break;
	case o_BUNBYHELIBLUE:
		obj = new BunbyHeliBlue();
		break;
	case o_BUNBYHELIGREEN:
		obj = new BunbyHeliGreen();
		break;
	case o_BLASTERRED:
		obj = new BlasterRed();
		dynamic_cast<BlasterRed*>(obj)->SetDirection(state != 0);
		break;
	case o_BLASTERORANGE:
		obj = new BlasterOrange();
		break;
	case o_BLASTERBLUE:
		obj = new BlasterBlue();
		dynamic_cast<BlasterBlue*>(obj)->SetDirection(state != 0);
		break;
	case o_MAMBU:
		obj = new Mambu();
		break;
	case o_GABYOALLORANGE:
		obj = new GabyoallOrange();
		break;
	case o_GABYOALLRED:
		obj = new GabyoallRed();
		break;
	case o_GABYOALLBLUE:
		obj = new GabyoallBlue();
		break;
	case o_PICKETMAN:
		obj = new PicketMan();
		break;
	case o_SNIPERJOE:
		obj = new SniperJoe();
		break;
	case o_WATCHER:
		obj = new Watcher();
		break;
	case o_PEPE:
		obj = new Pepe();
		break;
	case o_CHANGKEY:
		obj = new Changkey();
		break;
	case o_FOOTHOLDERGREEN:
		obj = new FootHolderGreen();
		break;
	case o_FOOTHOLDERORANGE:
		obj = new FootHolderOrange();
		break;
	case o_CRAZYRAZY:
		obj = new CrazyRazy();
		break;
	case o_CRAZYRAZYBODY:
		obj = new CrazyRazyBody();
		break;
	case o_CRAZYRAZYFOOT:
		obj = new CrazyRazyFoot();
		break;
	case o_BIGEYERED:
		obj = new BigEyeRed();
		break;
	case o_BIGEYEBLUE:
		obj = new BigEyeBlue();
		break;
	case o_SUZYBLUE:
		obj = new SuzyBlue();
		dynamic_cast<SuzyBlue*>(obj)->SetDirection(state != 0);
		break;
	case o_SUZYRED:
		obj = new SuzyRed();
		dynamic_cast<SuzyRed*>(obj)->SetDirection(state != 0);
		break;
	case o_SUZYORANGE:
		obj = new SuzyOrange();
		dynamic_cast<SuzyOrange*>(obj)->SetDirection(state != 0);
		break;
	case o_SCREWDRIVERORANGE:
		obj = new ScrewDriverOrange();
		break;
	case o_SCREWDRIVERBLUE:
		obj = new ScrewDriverBlue();
		break;
	case o_SCREWDRIVERRED:
		obj = new ScrewDriverRed();
		break;
	case o_SUPERCUTTER:
		obj = new SuperCutter();
		break;
	case o_KILLERBOMBORANGE:
		obj = new KillerBombOrange();
		break;
	case o_KILLERBOMBRED:
		obj = new KillerBombRed();
		break;
	case o_KILLERBOMBBLUE:
		obj = new KillerBombBlue();
		break;
	case o_METALL:
		obj = new Metall();
		break;
	case o_BRICK:
		obj = new Brick();
		break;
	case o_DOOR:
		//obj = new Door();
		break;
	case o_BOUNCINGMUSHROOM:
		obj = new BouncingMushroomBlue();
		break;
	case o_BOUNCINGMUSHROOMRED:
		obj = new BouncingMushroomRed();
		break;
	case o_SUPERCUTTERPARENT:
		obj = new SuperCutterParent();
		break;
	default:
		obj = new GameObj();
		obj->objectType = type;
		break;
	}

	if (obj != NULL)
	{
		obj->SetDefaultValue(posX, posY, width, height);
		obj->SetDefault();
		obj->RefreshBoundary();
	}
return obj;
}