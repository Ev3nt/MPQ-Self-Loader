#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		char* lpName = (char*)calloc(MAX_PATH, sizeof(char));
		HANDLE hMpq;

		GetModuleFileNameA(hModule, lpName, MAX_PATH);
		(reinterpret_cast<BOOL(CALLBACK*)(LPCSTR lpArchiveName, DWORD dwPriority, DWORD dwFlags, HANDLE &hArchiveHandle)>(GetProcAddress(GetModuleHandleA("Storm.dll"), (const char*)266)))(lpName, 0x11, 0, hMpq);
	}

	return TRUE;
}