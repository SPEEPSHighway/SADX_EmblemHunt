#include "SADXModLoader.h"
#include "UsercallFunctionHandler.h"

struct LifeBoxLocationData
{
	Float x;
	Float y;
	Float z;
	int level;
	__int16 character;
	int id;
};

struct EMBLEMWND
{
	char flag;
	char emblemchar;
	__int16 stage;
	int number;
	float x;
	float y;
	unsigned int material;
};

struct EMBLEMWNDLIST
{
	__int16 pvrindex;
	__int16 pvrindexhead;
	float headofsx;
	EMBLEMWND* pemblemwnd;
	int emblemwndcount;
	float shadowlocx;
	float shadowlocy;
	float shadowsizx;
	float shadowsizy;
};

struct StageMission {
	char character;
	__int16 stage;
	__int16 seqid;
};

StageMission clearlist[] = {
	{Characters_Sonic, LevelIDs_EmeraldCoast, 166},
	{Characters_Sonic, LevelIDs_WindyValley, 167},
	{Characters_Sonic, LevelIDs_Casinopolis, 168},
	{Characters_Sonic, LevelIDs_TwinklePark, 169},
	{Characters_Sonic, LevelIDs_SpeedHighway, 170},
	{Characters_Sonic, LevelIDs_IceCap, 171},
	{Characters_Sonic, LevelIDs_SkyDeck, 172},
	{Characters_Sonic, LevelIDs_LostWorld, 173},
	{Characters_Sonic, LevelIDs_FinalEgg, 174},
	{Characters_Tails, LevelIDs_WindyValley, 225},
	{Characters_Tails, LevelIDs_Casinopolis, 226},
	{Characters_Tails, LevelIDs_SpeedHighway, 227},
	{Characters_Tails, LevelIDs_IceCap, 228},
	{Characters_Tails, LevelIDs_SkyDeck, 229},
	{Characters_Knuckles, LevelIDs_Casinopolis, 287},
	{Characters_Knuckles, LevelIDs_SpeedHighway, 288},
	{Characters_Knuckles, LevelIDs_RedMountain, 289},
	{Characters_Knuckles, LevelIDs_LostWorld, 290},
	{Characters_Knuckles, LevelIDs_SkyDeck, 294},
	{Characters_Amy, LevelIDs_TwinklePark, 342},
	{Characters_Amy, LevelIDs_HotShelter, 343},
	{Characters_Amy, LevelIDs_FinalEgg, 344},
	{Characters_Gamma, LevelIDs_EmeraldCoast, 411},
	{Characters_Gamma, LevelIDs_WindyValley, 412},
	{Characters_Gamma, LevelIDs_RedMountain, 413},
	{Characters_Gamma, LevelIDs_HotShelter, 414},
	{Characters_Gamma, LevelIDs_FinalEgg, 415},
	{Characters_Big, LevelIDs_EmeraldCoast, 469},
	{Characters_Big, LevelIDs_HotShelter, 470},
	{Characters_Big, LevelIDs_TwinklePark, 471},
	{Characters_Big, LevelIDs_IceCap, 472},
};

EMBLEMWND emblemwnd_page1[] = {
	//Emerald Coast S
	{1, 0, 0, 0, 275.0f, 142.0f, 0xFFFFFFFF},
	{0x14, 0, 1, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 2, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 3, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 4, 0, 26.0f, 25.0f, 0xFFFFFFFF},

	//Windy Valley S
	{1, 0, 0, 0, 275.0f, 197.0f, 0xFFFFFFFF},
	{0x14, 0, 5, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 6, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 7, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 8, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 9, 0, 26.0f, 25.0f, 0xFFFFFFFF},

	//Casinopolis S
	{1, 0, 0, 0, 275.0f, 252.0f, 0xFFFFFFFF},
	{0x14, 0, 10, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 2, 0, 26.0f, 25.0f, 0xFFFFFFFF},

	//Icecap S
	{1, 0, 0, 0, 275.0f, 307.0f, 0xFFFFFFFF},
	{0x14, 1, 4, 0, 26.0f, 25.0f, 0xFFFFFFFF},

	//Twinkle Park S
	{1, 0, 0, 0, 275.0f, 362.0f, 0xFFFFFFFF},
	{0x14, 1, 6, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 8, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 9, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 4, 0, 26.0f, 25.0f, 0xFFFFFFFF}
};

EMBLEMWND emblemwnd_page2[] = {
	//Speed Highway S
	{1, 0, 0, 0, 275.0f, 142.0f, 0xFFFFFFFF},
	{0x14, 2, 5, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 6, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 7, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 9, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 3, 3, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 3, 10, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{1, 0, 0, 0, 275.0f, 185.0f, 0xFFFFFFFF},
	{0x14, 3, 12, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 1, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 2, 0, 26.0f, 25.0f, 0xFFFFFFFF},

	//Red Mountain S
	{1, 0, 0, 0, 275.0f, 235.0f, 0xFFFFFFFF},
	{0x14, 5, 5, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 10, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 12, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 1, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 3, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 8, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{1, 0, 0, 0, 275.0f, 278.0f, 0xFFFFFFFF},
	{0x14, 4, 12, 0, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 1, 1, 26.0f, 25.0f, 0xFFFFFFFF},

	//Sky Deck S
	{1, 0, 0, 0, 275.0f, 328.0f, 0xFFFFFFFF},
	{0x14, 0, 2, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 3, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 4, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 5, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 6, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 7, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{1, 0, 0, 0, 275.0f, 371.0f, 0xFFFFFFFF},
	{0x14, 0, 8, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 9, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 10, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 2, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 4, 1, 26.0f, 25.0f, 0xFFFFFFFF}
};

EMBLEMWND emblemwnd_page3[] = {
	//Lost World S
	{1, 0, 0, 0, 275.0f, 142.0f, 0xFFFFFFFF},
	{0x14, 1, 6, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 8, 1, 26.0f, 25.0f, 0xFFFFFFFF},

	//Final Egg S
	{1, 0, 0, 0, 275.0f, 197.0f, 0xFFFFFFFF},
	{0x14, 1, 9, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 4, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 5, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 6, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 7, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 9, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{1, 0, 0, 0, 275.0f, 240.0f, 0xFFFFFFFF},
	{0x14, 3, 3, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 3, 10, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 3, 12, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 1, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 2, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 5, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{1, 0, 0, 0, 275.0f, 283.0f, 0xFFFFFFFF},
	{0x14, 5, 10, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 12, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 1, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 3, 1, 26.0f, 25.0f, 0xFFFFFFFF}
};

EMBLEMWND emblemwnd_page4[] = {
	//Windy Valley T
	{1, 0, 0, 0, 275.0f, 142.0f, 0xFFFFFFFF},
	{0x14, 4, 8, 1, 26.0f, 25.0f, 0xFFFFFFFF},

	//Casinoolis T
	{1, 0, 0, 0, 275.0f, 197.0f, 0xFFFFFFFF},
	{0x14, 4, 12, 1, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 1, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Sky Deck T
	{1, 0, 0, 0, 275.0f, 252.0f, 0xFFFFFFFF},
	{0x14, 0, 2, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 3, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 4, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Speed Highway T
	{1, 0, 0, 0, 275.0f, 307.0f, 0xFFFFFFFF},
	{0x14, 0, 5, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 6, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 7, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 8, 2, 26.0f, 25.0f, 0xFFFFFFFF}
};

EMBLEMWND emblemwnd_page5[] = {
	//Speed Highway K
	{1, 0, 0, 0, 275.0f, 142.0f, 0xFFFFFFFF},
	{0x14, 0, 9, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 0, 10, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Casinopolis K
	{1, 0, 0, 0, 275.0f, 197.0f, 0xFFFFFFFF},
	{0x14, 1, 2, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 4, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Red Mountain K
	{1, 0, 0, 0, 275.0f, 252.0f, 0xFFFFFFFF},
	{0x14, 1, 6, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 8, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 1, 9, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 4, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Sky Deck K
	{1, 0, 0, 0, 275.0f, 307.0f, 0xFFFFFFFF},
	{0x14, 2, 5, 2, 26.0f, 25.0f, 0xFFFFFFFF}
};

EMBLEMWND emblemwnd_page6[] = {
	//Twinkle Park A
	{1, 0, 0, 0, 275.0f, 142.0f, 0xFFFFFFFF},
	{0x14, 2, 6, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Hot Shelter A
	{0x11, 0, 0, 0, 41.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 7, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 2, 9, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 3, 3, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Final Egg A
	{1, 0, 0, 0, 275.0f, 197.0f, 0xFFFFFFFF},
	{0x14, 3, 10, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 3, 12, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Icecap B
	{1, 0, 0, 0, 275.0f, 252.0f, 0xFFFFFFFF},
	{0x14, 5, 1, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Hot Shelter B
	{0x11, 0, 0, 0, 41.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 2, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Emerald Coast E
	{1, 0, 0, 0, 275.0f, 307.0f, 0xFFFFFFFF},
	{0x14, 5, 5, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Windy Valley E
	{0x11, 0, 0, 0, 41.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 10, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 5, 12, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Red Mountain E
	{0x11, 0, 0, 0, 41.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 1, 2, 26.0f, 25.0f, 0xFFFFFFFF},

	//Hot Shelter E
	{1, 0, 0, 0, 275.0f, 362.0f, 0xFFFFFFFF},
	{0x14, 4, 3, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 8, 2, 26.0f, 25.0f, 0xFFFFFFFF},
	{0x11, 0, 0, 0, 26.0f, -25.0f, 0xFFFFFFFF},
	{0x14, 4, 12, 2, 26.0f, 25.0f, 0xFFFFFFFF}
};

EMBLEMWNDLIST emblemwnd1ist[] = {
	{0x16, 0x0C, 64.0f, emblemwnd_page1, 32, 256.0f, 122.0f, 352.0f, 306.0f},
	{0x12, 0x0C, 64.0f, emblemwnd_page2, 56, 256.0f, 122.0f, 352.0f, 306.0f},
	{0x10, 0x0C, 64.0f, emblemwnd_page3, 36, 256.0f, 122.0f, 352.0f, 226.0f},
	{0x17, 0x0D, 64.0f, emblemwnd_page4, 20, 256.0f, 122.0f, 352.0f, 256.0f},
	{0x14, 0x0A, 0.0f, emblemwnd_page5, 18, 256.0f, 122.0f, 352.0f, 256.0f},
	{0x0F, 5, 64.0f, emblemwnd_page6, 30, 256.0f, 122.0f, 352.0f, 306.0f}
};


//Some of these are different in DC conversion, so keep a list of the DC positions too.
//If there aren't that many differences I'll just merge with the first list.
LifeBoxLocationData locations[] = {
	{1053.08f, -6.77f, 745.21f, LevelAndActIDs_EmeraldCoast1, Characters_Sonic, 0},
	{6297.18f, 312.70f, 1271.14f, LevelAndActIDs_EmeraldCoast1, Characters_Sonic, 1},
	{6297.18f, 316.95f, 1271.14f, LevelAndActIDs_EmeraldCoast1, Characters_Sonic, 1}, //DC
	{1078.81f, 656.17f, -748.29f, LevelAndActIDs_EmeraldCoast2, Characters_Sonic, 2},
	{1078.81f, 650.54f, -748.29f, LevelAndActIDs_EmeraldCoast2, Characters_Sonic, 2},
	{1086.19f, 650.54f, -753.55f, LevelAndActIDs_EmeraldCoast2, Characters_Sonic, 2}, //DC
	{3161.46f, -0.28f, -2630.8f, LevelAndActIDs_EmeraldCoast2, Characters_Sonic, 3},
	{3161.46f, 0.44f, -2630.8f, LevelAndActIDs_EmeraldCoast2, Characters_Sonic, 3}, //DC
	{2212.05f, -567.0f, -16.74f, LevelAndActIDs_WindyValley1, Characters_Sonic, 4},
	{2996.38f, -434.8972f, -1504.0f, LevelAndActIDs_WindyValley1, Characters_Sonic, 5},
	{1147.72f, -2209.17f, 1260.16f, LevelAndActIDs_WindyValley3, Characters_Sonic, 6},
	{1677.8f, -2577.0f, 1117.49f, LevelAndActIDs_WindyValley3, Characters_Sonic, 7},
	{4159.61f, -4484.5f, -1826.59f, LevelAndActIDs_WindyValley3, Characters_Sonic, 8},
	{-2.18f, -8.14f, 104.95f, LevelAndActIDs_Casinopolis2, Characters_Sonic, 9}, //evil tower bypass lol
	{-2.18f, -3.0f, 104.95f, LevelAndActIDs_Casinopolis2, Characters_Sonic, 9}, //evil tower bypass but DX
	{-1.93f, -3.0f, 39.95f, LevelAndActIDs_Casinopolis2, Characters_Sonic, 10}, //bumper tower bypass
	{-161.4f, 55.0f, 2.32f, LevelAndActIDs_Casinopolis3, Characters_Sonic, 9},
	{-161.4f, 50.0f, 12.32f, LevelAndActIDs_Casinopolis3, Characters_Sonic, 9}, //m
	{166.62f, 50.0f, 14.55f, LevelAndActIDs_Casinopolis3, Characters_Sonic, 10},
	{487.79f, 250.67f, 1149.06f, LevelAndActIDs_IceCap1, Characters_Sonic, 11},
	{487.79f, 249.67f, 1149.06f, LevelAndActIDs_IceCap1, Characters_Sonic, 11}, //DX
	{-2537.78f, -208.31f, 7597.23f, LevelAndActIDs_TwinklePark1, Characters_Sonic, 12},
	{119.35f, -1519.96f, 7602.92f, LevelAndActIDs_TwinklePark1, Characters_Sonic, 13},
	{372.47f, 317.02f, -363.36f, LevelAndActIDs_TwinklePark2, Characters_Sonic, 14},
	{-24.25f, 425.3f, 125.35f, LevelAndActIDs_TwinklePark2, Characters_Sonic, 15},
	{1904.17f, -93.17f, 21.84f, LevelAndActIDs_SpeedHighway1, Characters_Sonic, 16},
	{1912.92f, -93.17f, 594.75f, LevelAndActIDs_SpeedHighway1, Characters_Sonic, 17},
	{1772.14f, -683.0f, 304.35f, LevelAndActIDs_SpeedHighway1, Characters_Sonic, 18},
	{3798.5f, -1370.0f, 159.9f, LevelAndActIDs_SpeedHighway1, Characters_Sonic, 19},
	{4626.2f, -1675.0f, 1667.93f, LevelAndActIDs_SpeedHighway1, Characters_Sonic, 20},
	{4271.06f, -1525.98f, 4152.68f, LevelAndActIDs_SpeedHighway1, Characters_Sonic, 21},
	{1.0f, -5565.0f, -55.4f, LevelAndActIDs_SpeedHighway2, Characters_Sonic, 22},
	{8.0f, -5565.0f, -55.4f, LevelAndActIDs_SpeedHighway2, Characters_Sonic, 22},  //m
	{-138.84f, 185.0f, -1014.24f, LevelAndActIDs_SpeedHighway3, Characters_Sonic, 23},
	{14.83f, 0.0f, -1688.95f, LevelAndActIDs_SpeedHighway3, Characters_Sonic, 24},
	{-534.08f, 1255.3f, -170.27f, LevelAndActIDs_RedMountain1, Characters_Sonic, 25},
	{-534.08f, 1254.21f, -170.27f, LevelAndActIDs_RedMountain1, Characters_Sonic, 25}, //No Fixed Edition
	{-855.52f, 1096.57f, -347.76f, LevelAndActIDs_RedMountain1, Characters_Sonic, 26},
	{-3035.25f, 173.02f, -1385.02f, LevelAndActIDs_RedMountain1, Characters_Sonic, 27},
	{-3452.31f, 134.38f, -1580.31f, LevelAndActIDs_RedMountain1, Characters_Sonic, 28},
	{-2954.26f, 884.3f, -1751.26f, LevelAndActIDs_RedMountain1, Characters_Sonic, 29},
	{-2969.36f, 884.3f, -1738.15f, LevelAndActIDs_RedMountain1, Characters_Sonic, 30},
	{-3767.93f, 1221.38f, -1908.67f, LevelAndActIDs_RedMountain1, Characters_Sonic, 31},
	{-3767.93f, 1226.38f, -1929.57f, LevelAndActIDs_RedMountain1, Characters_Sonic, 31}, //DX
	{-907.53f, 137.85f, 871.08f, LevelAndActIDs_RedMountain2, Characters_Sonic, 32},
	{400.11f, -260.01f, 1125.68f, LevelAndActIDs_SkyDeck1, Characters_Sonic, 33},
	{401.52f, -210.01f, 1320.11f, LevelAndActIDs_SkyDeck1, Characters_Sonic, 34},
	{487.7f, -450.0f, 3727.33f, LevelAndActIDs_SkyDeck1, Characters_Sonic, 35},
	{401.04f, -601.0f, 4220.15f, LevelAndActIDs_SkyDeck1, Characters_Sonic, 36},
	{401.04f, -599.5f, 4220.15f, LevelAndActIDs_SkyDeck1, Characters_Sonic, 36}, //DX
	{-277.49f, -38.98f, 2545.97f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 37},  //No fixed edition
	{-277.3672f, -37.6f, 2546.101f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 37},
	{-408.93f, -7.59f, 1069.63f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 38},
	{-473.49f, -2.309165f, 44.75f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 39},
	{-473.49f, 1.5f, 44.75f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 39}, //DX
	{181.6f, 0.0f, -4277.61f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 40},
	{99.44f, 0.0f, -4278.86f, LevelAndActIDs_SkyDeck2, Characters_Sonic, 41},
	{-696.41f, -2.0f, -209.24f, LevelAndActIDs_SkyDeck3, Characters_Sonic, 42},
	{-696.41f, 2.0f, -209.24f, LevelAndActIDs_SkyDeck3, Characters_Sonic, 42},  //m
	{245.39f, -20.4f, 2.38f, LevelAndActIDs_SkyDeck3, Characters_Sonic, 43},
	{251.39f, -20.4f, 2.38f, LevelAndActIDs_SkyDeck3, Characters_Sonic, 43}, //m
	{5629.72f, -2545.0f, 1672.61f, LevelAndActIDs_LostWorld1, Characters_Sonic, 44},
	{7539.95f, -2545.0f, 1097.54f, LevelAndActIDs_LostWorld2, Characters_Sonic, 45},
	{177.63f, -102.98f, -144.15f, LevelAndActIDs_FinalEgg1, Characters_Sonic, 46},
	{1486.61f, 203.0f, -1314.31f, LevelAndActIDs_FinalEgg1, Characters_Sonic, 47},
	{1898.99f, 203.99f, -1066.92f, LevelAndActIDs_FinalEgg1, Characters_Sonic, 48},
	{942.18f, 86.56f, -744.57f, LevelAndActIDs_FinalEgg2, Characters_Sonic, 49},
	{942.18f, 88.93f, -744.57f, LevelAndActIDs_FinalEgg2, Characters_Sonic, 49}, //DX
	{799.51f, 90.78f, -1108.67f, LevelAndActIDs_FinalEgg2, Characters_Sonic, 50},
	{1093.7f, -10.62f, -826.47f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 51},
	{1209.16f, 111.17f, -980.11f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 52},
	{1317.62f, -297.22f, -1461.64f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 53},
	{1468.63f, -357.65f, -1444.59f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 54},
	{2615.22f, -278.9f, -1764.73f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 55},
	{2260.76f, -2739.37f, -1175.08f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 56},
	{856.85f, -3171.438f, -489.48f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 57},
	{-3.58f, -3003.81f, -278.32f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 58},
	{16.42f, -3003.81f, -298.32f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 59},
	{16.42f, -3003.81f, -278.32f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 60},
	{-3.58f, -3003.81f, -298.32f, LevelAndActIDs_FinalEgg3, Characters_Sonic, 61},
	{5327.94f, -4014.36f, -2284.31f, LevelAndActIDs_WindyValley3, Characters_Tails, 62},
	{-1173.27f, -1239.73f, 2849.5f, LevelAndActIDs_Casinopolis2, Characters_Tails, 63},
	{-1945.4f, -1475.73f, 3009.3f, LevelAndActIDs_Casinopolis2, Characters_Tails, 64},
	{-1945.4f, -1485.73f, 3019.3f, LevelAndActIDs_Casinopolis2, Characters_Tails, 64}, //m
	{400.11f, -260.01f, 1125.68f, LevelAndActIDs_SkyDeck1, Characters_Tails, 65},
	{401.52f, -210.01f, 1320.11f, LevelAndActIDs_SkyDeck1, Characters_Tails, 66},
	{487.7f, -450.0f, 3727.33f, LevelAndActIDs_SkyDeck1, Characters_Tails, 67},
	{4956.11f, -1714.0f, 1364.51f, LevelAndActIDs_SpeedHighway1, Characters_Tails, 68},
	{4626.2f, -1675.0f, 1667.93f, LevelAndActIDs_SpeedHighway1, Characters_Tails, 69},
	{4259.64f, -1704.04f, 4095.85f, LevelAndActIDs_SpeedHighway1, Characters_Tails, 70},
	{4259.64f, -1705.34f, 4095.85f, LevelAndActIDs_SpeedHighway1, Characters_Tails, 70}, //DX
	{5246.12f, -2332.0f, 7842.45f, LevelAndActIDs_SpeedHighway1, Characters_Tails, 71},
	{14.83f, 0.0f, -1688.95f, LevelAndActIDs_SpeedHighway3, Characters_Knuckles, 72},
	{70.51f, 24.5f, 223.17f, LevelAndActIDs_SpeedHighway3, Characters_Knuckles, 73},
	{510.5f, 165.89f, -304.94f, LevelAndActIDs_Casinopolis1, Characters_Knuckles, 74},
	{5.1f, 448.0f, 0.25f, LevelAndActIDs_Casinopolis1, Characters_Knuckles, 75},
	{-3666.69f, 63.45f, -2346.65f, LevelAndActIDs_RedMountain3, Characters_Knuckles, 76},
	{-3666.69f, 62.2f, -2346.65f, LevelAndActIDs_RedMountain3, Characters_Knuckles, 76}, //DX
	{-3349.6f, 206.0f, -1142.93f, LevelAndActIDs_RedMountain3, Characters_Knuckles, 77},
	{-1895.37f, 58.92f, -1854.58f, LevelAndActIDs_RedMountain3, Characters_Knuckles, 78},
	{-3804.06f, 1122.98f, -2094.58f, LevelAndActIDs_RedMountain3, Characters_Knuckles, 79},
	{342.68f, 178.18f, 434.17f, LevelAndActIDs_SkyDeck3, Characters_Knuckles, 80},
	{267.4f, 306.02f, -297.65f, LevelAndActIDs_TwinklePark2, Characters_Amy, 81},
	{-320.14f, 250.0f, -248.29f, LevelAndActIDs_HotShelter2, Characters_Amy, 82},
	{-320.14f, 253.95f, -248.29f, LevelAndActIDs_HotShelter2, Characters_Amy, 82}, //No fixed edition
	{-29.18f, 50.78f, -437.51f, LevelAndActIDs_HotShelter2, Characters_Amy, 83},
	{538.82f, 1040.0f, -2092.6f, LevelAndActIDs_HotShelter2, Characters_Amy, 84},
	{ 548.45f, -232.0f, -1552.75f, LevelAndActIDs_FinalEgg1, Characters_Amy, 85},
	{ 1629.58f, 240.0f, -1319.99f, LevelAndActIDs_FinalEgg1, Characters_Amy, 86},
	{ 1174.01f, 332.79f, -256.39f, LevelAndActIDs_IceCap4, Characters_Big, 87},
	{ 931.23f, 0.99f, -659.31f, LevelAndActIDs_HotShelter1, Characters_Big, 88},
	{ 1048.05f, -5.07f, 747.43f, LevelAndActIDs_EmeraldCoast1, Characters_Gamma, 89},
	{ 635.3f, -61.0f, 247.38f, LevelAndActIDs_WindyValley1, Characters_Gamma, 90},
	{ 2028.11f, -467.0f, 6.6f, LevelAndActIDs_WindyValley1, Characters_Gamma, 91},
	{ -253.36f, 239.01f, 549.6f, LevelAndActIDs_RedMountain2, Characters_Gamma, 92},
	{ -28.29f, 50.78f, -433.41f, LevelAndActIDs_HotShelter3, Characters_Gamma, 93},
	{ -848.5f, 825.0f, -3620.1f, LevelAndActIDs_HotShelter3, Characters_Gamma, 94},
	{ -848.5f, 820.0f, -3620.1f, LevelAndActIDs_HotShelter3, Characters_Gamma, 94}, //DX
	{ -664.08f, 474.0215f, -3583.48f, LevelAndActIDs_HotShelter3, Characters_Gamma, 95}
};

struct CLEAR_TIME
{
	char m;
	char s;
	char f;
};

extern "C"
{
	float movelength = 32.0f;
	bool emblemCheckPosition(task* tp, BYTE axis, Float list, int id);
	int LastStage = 0;
	bool forcedSonicLayout = false;
	DataPointer(BYTE, functest, 0x4B4AFA);
	DataPointer(ADVERTISE_WORK, Advertise_Work, 0x3B2A2F0);
	int boxToEmblem(task* tp);
	void removeRankText(int texid, float x, float y, float z);
	void removeRankWin(float x, float y, float z, int sswin_type);
	void moveText(int val, int keta, unsigned __int8 zflg, float x, float y, float z, float magx, float magy);
	void moveWeightg(int texnum, float x, float y, float z, float scaleX, float scaleY);
	void moveTimer(CLEAR_TIME* clp, float x, float y, float z);
	bool checkEmblemOverride(SaveFileData* savefile, int character, int stage, int mission);
	void setEmblemOverride(SaveFileData* savefile, int character, int stage, int mission);
	void fixCasino(char no);
	void killCasinoCube(task* tp);
	void gameGear();
	void fixGameOver(int sel);
	void getEmblemOverride();
	int checkSETFile(const char* name, LPVOID* data);
	int testUnlockText(char* a1, unsigned __int8 id);
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Hijack the item box's clip level check.
		WriteCall((int*)0x4D6F1A, boxToEmblem);
		WriteCall((int*)0x4C07DA, boxToEmblem);

		//Stop collecting emblems from stages.
		WriteCall((void*)0x4287EF, getEmblemOverride);
		WriteCall((void*)0x428681, setEmblemOverride);
		WriteCall((void*)0x4D4802, killCasinoCube);

		//Stop collecting an emblem disabling your controls.
		WriteCall((void*)0x4B4891, EnableControl);
		WriteCall((void*)0x4B46C5, EnableControl);

		//Game gear
		WriteCall((void*)0x4B47D5, gameGear);
		GenerateUsercallHook(testUnlockText, rEAX, 0x4B53C0, rEAX, rCL);

		WriteData((EMBLEMWNDLIST*)0x10D9DD8, emblemwnd1ist);

		//Prevent the game drawing the ranks in the trial menu.
		WriteCall((void*)0x50ACB7, removeRankWin);
		WriteCall((void*)0x50AD38, removeRankText);
		WriteCall((void*)0x50AE75, moveTimer);
		WriteCall((void*)0x50AE26, moveText); //Score
		WriteCall((void*)0x50AEBD, moveText); //Weight
		WriteCall((void*)0x50AF79, moveText); //Rings
		WriteCall((void*)0x50AF20, moveWeightg); //g
		WriteCall((void*)0x5C07B1, fixCasino); //g

		//Override the game checking for level missions to be based on event clear flags instead of emblems, forcing either the first or last mission.
		WriteCall((void*)0x42845C, checkEmblemOverride);
		WriteCall((void*)0x428471, checkEmblemOverride);
		WriteCall((void*)0x428486, checkEmblemOverride);
		WriteCall((void*)0x42A7BB, checkEmblemOverride);
		WriteCall((void*)0x4575E5, checkEmblemOverride);
		WriteCall((void*)0x45762E, checkEmblemOverride);
		WriteCall((void*)0x4576A1, checkEmblemOverride);
		WriteCall((void*)0x457746, checkEmblemOverride);
		WriteCall((void*)0x457784, checkEmblemOverride);
		WriteCall((void*)0x45780E, checkEmblemOverride);
		WriteCall((void*)0x457849, checkEmblemOverride);
		WriteCall((void*)0x457879, checkEmblemOverride);
		WriteCall((void*)0x4578C3, checkEmblemOverride);
		WriteCall((void*)0x4578F3, checkEmblemOverride);
		WriteCall((void*)0x457964, checkEmblemOverride);
		WriteCall((void*)0x457A25, checkEmblemOverride);
		WriteCall((void*)0x457A49, checkEmblemOverride);
		WriteCall((void*)0x47C226, checkEmblemOverride);
		WriteCall((void*)0x47C23C, checkEmblemOverride);

		WriteCall((void*)0x422A08, checkSETFile);

		WriteCall((void*)0x42C3AC, fixGameOver);

		//Skip drawing emblems in the trial menu if not Metal Sonic.
		WriteData((BYTE*)0x50ADC3, (BYTE)0xEB);
		WriteData((BYTE*)0x50ADC4, (BYTE)0x03);
		WriteData<3>((BYTE*)0x50ADC5, (BYTE)0x90);

	}
	__declspec(dllexport) void __cdecl OnFrame()
	{
		//Stop it assigning adventure field IDs if you're in an action stage.
		if (CurrentLevel <= 12) {
			if (functest == 0x0F) {
				WriteJump((int*)0x4B4AFA, (int*)0x4B4B7F);
			}
		}
		else {
			if (functest == 0xE9) {
				WriteData((BYTE*)0x4B4AFA, (BYTE)0x0F);
				WriteData((BYTE*)0x4B4AFB, (BYTE)0xBF);
				WriteData((BYTE*)0x4B4AFC, (BYTE)0x05);
				WriteData((BYTE*)0x4B4AFD, (BYTE)0xCC);
				WriteData((BYTE*)0x4B4AFE, (BYTE)0x2D);
			}
		}

		if (GameMode != GameModes_Adventure_ActionStg && GameMode != GameModes_Trial && GameMode != GameModes_Mission && LastStage != 0) {
			LastStage = 0;
		}
	}

	int checkSETFile(const char* name, LPVOID* data) {
		if (LoadFileWithMalloc(name, data) == -1) {
			forcedSonicLayout = true;
		}
		else {
			forcedSonicLayout = false;
		}
		return LoadFileWithMalloc(name, data);
	}

	void getEmblemOverride() {
		VoidFunc(InitGetEmblem, 0x4B4540);
		if (CurrentLevel > 12) {
			InitGetEmblem();
		}
	}

	void fixGameOver(int sel) {
		FunctionPointer(void, DisplayGameOver, (int sel), 0x42BFD0);
		LastStage = 0;
		DisplayGameOver(sel);
	}

	void gameGear() {
		FunctionPointer(void, GameGearThing, (), 0x4B5800);
		if (SubtitleThing_Count == 0) {
			GameGearThing();
		}
	}

	int testUnlockText(char* a1, unsigned __int8 id) {
	//	return UnlockGamegearGameOrMetalsonic(a1, id);
		return 0;
	}


	void killCasinoCube(task* tp) {
		if (GetLevelAndAct() == LevelAndActIDs_Casinopolis2 &&
			tp->twp->pos.x < 1.0f && tp->twp->pos.x > -1.0f &&
			tp->twp->pos.y > -1716.0f && tp->twp->pos.y < -1713.0f &&
			tp->twp->pos.z > 2766.0f && tp->twp->pos.z < 2769.0f) {
			tp->twp->pos.y = -20000.0f;
		}
		else {
			ClipSetObject((ObjectMaster*)tp);
		}
	}

	void fixCasino(char no) {
		NonStaticFunctionPointer(void, LandChangeStage, (char no), 0x43A460);
		LandChangeStage(-2);
	}

	void removeRankDisplay() {

	}

	void removeRankText(int texid, float x, float y, float z) {
		if (Advertise_Work.PlayerChar == 6) {
			DisplayScreenTexture(texid, x, y, z);
		}
		else {
			if (texid != 67108876) {
				DisplayScreenTexture(texid, x, y - movelength, z);
			}
		}
	}

	void moveTimer(CLEAR_TIME* clp, float x, float y, float z) {
		NonStaticFunctionPointer(void, DrawTrialTime, (CLEAR_TIME * clp, float x, float y, float z), 0x507880);
		if (Advertise_Work.PlayerChar == 6) {
			DrawTrialTime(clp, x, y, z);
		}
		else {
			DrawTrialTime(clp, x, y - movelength, z);
		}
	}

	void removeRankWin(float x, float y, float z, int sswin_type) {
		NonStaticFunctionPointer(void, DrawRankWin, (float x, float y, float z, int sswin_type), 0x506E90);
		if (Advertise_Work.PlayerChar == 6) {
			DrawRankWin(x, y, z, sswin_type);
		}
		else {
			if (sswin_type != 2) {
				DrawRankWin(x, y - movelength, z, sswin_type);
			}
		}
	}

	void moveText(int val, int keta, unsigned __int8 zflg, float x, float y, float z, float magx, float magy) {
		NonStaticFunctionPointer(void, DrawValTrialS, (int val, int keta, unsigned __int8 zflg, float x, float y, float z, float magx, float magy), 0x507570);
		if (Advertise_Work.PlayerChar == 6) {
			DrawValTrialS(val, keta, zflg, x, y, z, magx, magy);
		}
		else {
			DrawValTrialS(val, keta, zflg, x, y - movelength, z, magx, magy);
		}
	}

	void moveWeightg(int texnum, float x, float y, float z, float scaleX, float scaleY) {
		if (Advertise_Work.PlayerChar == 6) {
			DrawBG(texnum, x, y, z, scaleX, scaleY);
		}
		else {
			DrawBG(texnum, x, y - movelength, z, scaleX, scaleY);
		}
	}

	void setEmblemOverride(SaveFileData* savefile, int character, int stage, int mission) {
		if (MetalSonicFlag || CurrentLevel > 12) {
			SetLevelEmblemCollected(savefile, character, stage, mission);
		}
	}

	bool checkEmblemOverride(SaveFileData* savefile, int character, int stage, int mission) {
		DataArray(char, seqVars, 0x3B18808, 512);

		//Don't interfere with non-action stages or Metal Emblems.
		if (stage > LevelIDs_HotShelter || MetalSonicFlag) {
			return GetLevelEmblemCollected(savefile, character, stage, mission);
		}

		//Find the stage and see if its event flag is ticked. If not, mission C.
		for (unsigned int i = 0; i < LengthOfArray(clearlist); i++) {
			if (clearlist[i].character == character && clearlist[i].stage == stage && seqVars[clearlist[i].seqid] == 0) {
				return false;
			}
		}

		return true;
	}

	//Float == Float is bad so check a radius around the item
	bool emblemCheckPosition(task* tp, BYTE axis, Float list, int id) {
		switch (axis) {
		case 0:
			if (list > (tp->twp->pos.x - 1.0f) && list < (tp->twp->pos.x + 1.0f)) {
				return true;
			}
			break;
		case 1:
			if (tp->twp->ang.x != 0x200 || id == 13) {
				if (list > (tp->twp->pos.y - 1.0f) && list < (tp->twp->pos.y + 1.0f)) {
					return true;
				}
			}
			else {
				if ((list + 7.0f) > (tp->twp->pos.y - 1.0f) && (list + 7.0f) < (tp->twp->pos.y + 1.0f)) {
					return true;
				}
			}
			break;
		case 2:
			if (list > (tp->twp->pos.z - 1.0f) && list < (tp->twp->pos.z + 1.0f)) {
				return true;
			}
			break;
		}
		return false;
	}

	//Check if the item box being loaded is a 1up. If it is, spawn an emblem and cull the original item box.
	int boxToEmblem(task* tp) {
		if (CurrentLevel <= 12) {
			if ((tp->twp->scl.x >= 6.0f && tp->twp->scl.x < 7.0f) || (tp->twp->scl.x < 1.0f && CurrentStageAndAct == LevelAndActIDs_Casinopolis2)) {
				//Scan for a match in the location list.
				for (unsigned int i = 0; i < LengthOfArray(locations); i++) {
					if (emblemCheckPosition(tp, 0, locations[i].x, locations[i].id) &&
						emblemCheckPosition(tp, 1, locations[i].y, locations[i].id) &&
						emblemCheckPosition(tp, 2, locations[i].z, locations[i].id) &&
						CurrentStageAndAct == locations[i].level &&
						(CurrentCharacter == locations[i].character || forcedSonicLayout == true)) {


						//Make the emblem spin and give it an ID.
						if (tp->twp->ang.x != 0x200) {

							//Tweaks for specific emblems to fix minor issues.
							switch (locations[i].id) {
							case 2:
								tp->twp->pos.y = 650.54f;
								break;
							case 9:
								//Account for rotation.
								if (CurrentAct == 2) {
									tp->twp->pos.y = 50.0f;
									tp->twp->pos.z = 12.32f;
								}
								break;
							case 22:
								//Gets partially swallowed by building.
								tp->twp->pos.x = 8.0f;
								break;
							case 64:
								//Account for rotation.
								tp->twp->pos.y = -1485.73f;
								tp->twp->pos.z = 3019.3f;
								break;
							case 42:
								//Too low.
								tp->twp->pos.y = 2.0f;
								break;
							case 43:
								//Clipping into a wall.
								tp->twp->pos.x = 251.39f;
							default:
								break;
							}

							//Need to be raised so they're not in the floor or too low. Except 13 because Sonic's kart won't reach it.
							if (locations[i].id != 13) {
								tp->twp->pos.y = tp->twp->pos.y + 7.0f;
							}

							tp->twp->value.l = locations[i].id;
							tp->twp->ang.x = 0x200;
						}

						//If the textures aren't loaded, load them.
						if (CurrentLevel != LastStage) {
							LoadPVM("EMBLEM", &EMBLEM_TEXLIST);
							LastStage = CurrentLevel;
						}

						//Create the Emblem and exit.
						//For some reason it crashes if the Emblems are still loaded when returning to Casinopolis 1 from SLOT Pinball, so quickly delete them beforehand.
						if (GetLevelAndAct() != LevelAndActIDs_Casinopolis3 ||(GetLevelAndAct() == LevelAndActIDs_Casinopolis3 && (PlayerPtrs[0]->Data1->Position.y > -10.00f || Casino_BallCount > 1))) {
							if (GetLevelAndAct() == LevelAndActIDs_TwinklePark2 && CurrentCharacter == Characters_Amy && PlayerPtrs[0]->Data1->Position.y < 170.0f) {
								DestroyTask(tp);
							}
							else {
								Emblem_Main((ObjectMaster*)tp);
							}
						}
						else {
							DestroyTask(tp);
						}
						return 1;
					}
				}
			}
		}
		//Spawn item box
		return ClipSetObject((ObjectMaster*)tp);
	}



}