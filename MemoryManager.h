#pragma once
class MemoryManager
{
public:
	MemoryManager();
	~MemoryManager();

	HANDLE m_hDriver = nullptr;
	int processId = 0;
	HANDLE processHandle = nullptr;
	bool allIsWell = false;
	PSIZE_T NumberOfBytes = nullptr;

	DWORD _d = 0;
	float _f = 0.f;
	int _i = 0;
	uint64 _u = 0;
	bool _b = false;
	char _char = 0;
	Vector3f _v3;
	char _playerNameBuffer[32] = "";
	FTTransform2_t _struct;

	bool init();
	int getAowProcId();
	bool getProcHandle();
	void readMemory(PVOID BaseAddress, PVOID Buffer, SIZE_T BufferSize);
	bool search(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, vector<DWORD_PTR>& vRet);
	int find(BYTE* buffer, int dwBufferSize, BYTE* bstr, DWORD dwStrLen);

	DWORD dRead(DWORD base);
	float fRead(DWORD base);
	int iRead(DWORD base);
	uint64 uiRead(DWORD base);
	bool bRead(DWORD base);
	string charRead(DWORD base);
	Vector3f v3Read(DWORD base);
	string charp32Read(DWORD base);
	FTTransform2_t structRead(DWORD base);
};

extern MemoryManager* g_pMemoryManager;