#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#pragma warning(disable : 4996)

#if (_MSC_VER >= 1915)
#define no_init_all deprecated
#endif

void reverse_shell()
{
	FILE * fp;
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
	fclose(fp);
	return;
}

BOOL WINAPI DllMain(HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{


	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		reverse_shell();
		break;

	case DLL_PROCESS_DETACH:

		break;

	case DLL_THREAD_ATTACH:

		break;

	case DLL_THREAD_DETACH:

		break;
	}
	return TRUE;
}