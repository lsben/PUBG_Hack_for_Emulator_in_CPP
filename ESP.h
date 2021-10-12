#pragma once
class ESP
{
public:
	ESP();
	~ESP();

	// Offsets
	int ofSearchFrom{ 0X50000000 };
	int ofSearchTo{ 0X60000000 };
	int ofUWorldMinus{ 4786820 };
	int ofGNamesMinus{ 1924332 };
	DWORD ofULevel{ 32 };
	DWORD ofGameInstance{ 36 };
	DWORD ofPlayerController{ 96 };
	DWORD ofPlayerCarry{ 32 };
	DWORD ofUMyObject{ 816 };
	DWORD ofEntityEntry{ 112 };
	DWORD ofEntityCount{ 120 };
	DWORD ofEntityAddv{ 4 };
	DWORD ofTmpEntityAddvId{ 16 };
	int ofEntityWorld = 332;
	int ofPosition = 352;
	int ofStatus = 924;
	int ofTeamId = 1648;
	int ofRobot = 1768;
	int ofPlayerNameAdd = 1608;
	int ofStateInt = 2336;
	int ofHealth = 2344;
	int ofMeshSkeleton = 800;
	int ofActor = 336;
	int ofBoneAddv = 1456;

	DWORD viewWorldBase = 0;
	DWORD uWorld = 0;
	DWORD gNames = 0;
	DWORD tmpGName = 0;
	DWORD uWorlds = 0;
	DWORD uLevel = 0;
	DWORD gameInstance = 0;
	DWORD playerController = 0;
	DWORD playerCarry = 0;
	DWORD uMyObject = 0;
	DWORD entityEntry = 0;
	DWORD entityCount = 0;
	DWORD entityAddv = 0;
	DWORD tmpEntityAddvId = 0;
	string entityName = "";
	long long page = 0;
	long long index = 0;
	long long secPartAddv = 0;
	long long nameAddv = 0;
	DWORD entityWorld = 0;
	Vector3f position;
	Vector3f positionOnScreen;
	float distanceFl = 0.f;
	int distanceValue = 0;
	int status = 0;
	int teamId = 0;
	int myTeamId = 0;
	int enemies = 0;
	bool isRobot = true;
	DWORD playerNameAdd = 0;
	string thePlayerName = "";
	int stateInt = 0;
	int health = 0;
	float fixPosY = 0.f;
	DWORD meshSkeleton = 0;
	FTTransform2_t actor;
	D3DMatrix componentToWorldMatrix;
	DWORD boneAddv = 0;
	Vector3f bonePosition;
	FTTransform2_t bone;
	D3DMatrix boneMatrix;
	D3DMatrix newMatrix;
	float headBoneSize = 0.f;


	bool playAlert{ true };
	void setDrawings();
	bool loadFont();
	void init();
	DWORD getViewWorld();
	void getViewMatrix();
	void scanEntityList();
	string replace(string& str, const string& from);
	string getState(int state);
	D3DMatrix ToMatrixWithScale(Vector3f translation, Vector3f scale, Vector4f rot);
	Vector3f getBonePos(int boneNum);
};

extern ESP* g_pESP;