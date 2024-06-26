// Very thin executable that just launches zplayer.exe located in a folder called "data"
// next to this exe. Used by the basic standalone packaging feature.

#include <windows.h>

int APIENTRY WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	TCHAR cmdArgs[] = "zplayer.exe -package";

	bool success = CreateProcessA(
		"data/zplayer.exe",
		cmdArgs,
		NULL,
		NULL,
		FALSE,
		NULL,
		NULL,
		"data",
		&si,
		&pi
	);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return !success;
}
