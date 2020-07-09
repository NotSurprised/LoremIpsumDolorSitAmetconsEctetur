// dllmain.cpp : 定義 DLL 應用程式的進入點。
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Lmcons.h>

#pragma warning(disable : 4996)

#if (_MSC_VER >= 1915)
#define no_init_all deprecated
#endif

void WLprinter() {
	/*printf("                                 Even Judged?\n");
	printf("                                       /           Let me in?\n");
	printf(" No license, no problem.            ∩＿＿＿∩        / \n");
	printf(" 　\\     ∩＿＿＿∩                ∕︵　ㄟ |   ∩＿＿＿∩\n");
	printf("　 　    |ˊ ︵ ︵ˋ               (⊙)(⊙)  ﹨ ∕︵　ㄟ  | \n");
	printf("　　    ∕  (⊙)(⊙)              ≡(_●_ )   ≡(⊙)(⊙)  ﹨\n");
	printf(" 　　   | 　( _●_) ≡         ＿ _\\ |∪|　   /≡(_●_ )   ≡\n");
	printf("     ╴≡     |∪| |          (((@         _／￣\\ |∪|     /╮\n");
	printf("　 　ˋ       ﹨ˊ_ ＼          ╰╮      (((@_            Q)))\n");
	printf("　　   /rundll32／  (  )           ﹨ .cpl    ﹨          |﹨\n");
	printf("　　  /       ╱                    |           |   .dll  ﹨| \n");
	printf(" 　 　    ╴／                      \\           |          |/\n");
	printf("Dll/CPL GENERATES TIME: %lu\n", (unsigned long)time(NULL));

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
	fprintf(fp, "CplBypass.\n");
	fclose(fp); */
	return;
}

extern "C" __declspec(dllexport) void rundll(HWND hwnd, HINSTANCE hinst, LPTSTR lpCmdLine, INT nCmdShow) {
	/*printf("                                 Even Judged?\n");
	printf("                                       /           Let me in?\n");
	printf(" No license, no problem.            ∩＿＿＿∩        / \n");
	printf(" 　\\     ∩＿＿＿∩                ∕︵　ㄟ |   ∩＿＿＿∩\n");
	printf("　 　    |ˊ ︵ ︵ˋ               (⊙)(⊙)  ﹨ ∕︵　ㄟ  | \n");
	printf("　　    ∕  (⊙)(⊙)              ≡(_●_ )   ≡(⊙)(⊙)  ﹨\n");
	printf(" 　　   | 　( _●_) ≡         ＿ _\\ |∪|　   /≡(_●_ )   ≡\n");
	printf("     ╴≡     |∪| |          (((@         _／￣\\ |∪|     /╮\n");
	printf("　 　ˋ       ﹨ˊ_ ＼          ╰╮      (((@_            Q)))\n");
	printf("　　   /rundll32／  (  )           ﹨ .cpl    ﹨          |﹨\n");
	printf("　　  /       ╱                    |           |   .dll  ﹨| \n");
	printf(" 　 　    ╴／                      \\           |          |/\n");
	printf("Dll/CPL GENERATES TIME: %lu\n", (unsigned long)time(NULL));*/

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
	fprintf(fp, "DllOfflinePayloadBypass.\n");
	fclose(fp);
	return;
}

void rundll2()
{
	/*MessageBox(NULL, TEXT("rundll"), TEXT("Rundll32"), MB_OK);
	system("cmd /c calc");

	MessageBox(NULL, TEXT("reverse_shell"), TEXT("Rundll32"), MB_OK);
	FILE * fp;
	fp = fopen("JokeDll.txt", "w+");
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
	fprintf(fp, "DllOnlinePayloadBypass.\n");
	fclose(fp);
	return;
}

BOOL WINAPI DllMain(HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{


	switch (dwReason)
	{
		printf("\n%d", dwReason);
	case DLL_PROCESS_ATTACH:
		//MessageBox(NULL, TEXT("dllmain"), TEXT("Rundll32"), MB_OK);
		//WLprinter();
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