#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <Lmcons.h>

#pragma warning(disable : 4996)

#if (_MSC_VER >= 1915)
#define no_init_all deprecated
#endif

extern "C" __declspec(dllexport) void rundll(HWND hwnd, HINSTANCE hinst, LPTSTR lpCmdLine, INT nCmdShow) {

	MessageBox(NULL, TEXT("rundll"), TEXT("Rundll32"), MB_OK);
	system("cmd /c calc");
	/*FILE * fp;
	fp = fopen("Joke.txt", "w+");
	fprintf(fp, "                                 Even Judged?\n");
	fprintf(fp, "                                       /           Let me in?\n");
	fprintf(fp, " No license, no problem.            ∩＿＿＿∩        / \n");
	fprintf(fp, " 　\\     ∩＿＿＿∩                ∕︵　ㄟ |   ∩＿＿＿∩\n");
	fprintf(fp, "　 　    |ˊ ︵ ︵ˋ               (⊙)(⊙)  ﹨ ∕︵　ㄟ  | \n");
	fprintf(fp, "　　    ∕  (⊙)(⊙)              ≡(_●_ )   ≡(⊙)(⊙)  ﹨\n");
	fprintf(fp, " 　　   | 　( _●_) ≡         ＿ _\\ |∪|　   /≡(_●_ )   ≡\n");
	fprintf(fp, "     ╴≡     |∪| |          (((@         _／￣\\ |∪|     /╮\n");
	fprintf(fp, "　 　ˋ       ﹨ˊ_ ＼          ╰╮      (((@_            Q)))\n");
	fprintf(fp, "　　   /rundll32／  (  )           ﹨ .cpl    ﹨          |﹨\n");
	fprintf(fp, "　　  /       ╱                    |           |   .dll  ﹨| \n");
	fprintf(fp, " 　 　    ╴／                      \\           |          |/\n");
	fprintf(fp, "Dll/CPL GENERATES TIME: %lu\n", (unsigned long)time(NULL));
	fclose(fp);*/
	return;
}

void reverse_shell()
{
	MessageBox(NULL, TEXT("reverse_shell"), TEXT("Rundll32"), MB_OK);
	char resultStr[UNLEN + 1];
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	wcstombs(resultStr, username, wcslen(username));
	sprintf(resultStr, "%S", username);
	FILE * fp;
	char fpath[2048];
	sprintf(fpath, "C:\\Users\\%s\\Desktop\\WLtester.txt", resultStr);
	fp = fopen(fpath, "a+");
	fprintf(fp, "Rundll32Bypass.\n");
	fclose(fp);
	/*fp = fopen("Joke.txt", "w+");
	fprintf(fp, "                                 Even Judged?\n");
	fprintf(fp, "                                       /           Let me in?\n");
	fprintf(fp, " No license, no problem.            ∩＿＿＿∩        / \n");
	fprintf(fp, " 　\\     ∩＿＿＿∩                ∕︵　ㄟ |   ∩＿＿＿∩\n");
	fprintf(fp, "　 　    |ˊ ︵ ︵ˋ               (⊙)(⊙)  ﹨ ∕︵　ㄟ  | \n");
	fprintf(fp, "　　    ∕  (⊙)(⊙)              ≡(_●_ )   ≡(⊙)(⊙)  ﹨\n");
	fprintf(fp, " 　　   | 　( _●_) ≡         ＿ _\\ |∪|　   /≡(_●_ )   ≡\n");
	fprintf(fp, "     ╴≡     |∪| |          (((@         _／￣\\ |∪|     /╮\n");
	fprintf(fp, "　 　ˋ       ﹨ˊ_ ＼          ╰╮      (((@_            Q)))\n");
	fprintf(fp, "　　   /rundll32／  (  )           ﹨ .cpl    ﹨          |﹨\n");
	fprintf(fp, "　　  /       ╱                    |           |   .dll  ﹨| \n");
	fprintf(fp, " 　 　    ╴／                      \\           |          |/\n");
	fprintf(fp, "Dll/CPL GENERATES TIME: %lu\n", (unsigned long)time(NULL));
	fclose(fp);*/
	return;
}

BOOL WINAPI DllMain(HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{

	
	switch (dwReason)
	{
	printf("\n%d", dwReason);
	case DLL_PROCESS_ATTACH:
		MessageBox(NULL, TEXT("dllmain"), TEXT("Rundll32"), MB_OK);
		reverse_shell();
		printf("\nProcess attach of dll");
		break;

	case DLL_PROCESS_DETACH:
		printf("\nProcess detach of dll");
		break;

	case DLL_THREAD_ATTACH:
		printf("\nThread attach of dll");
		break;

	case DLL_THREAD_DETACH:
		printf("\nThread detach of dll");
		break;
	}
	return TRUE;
}