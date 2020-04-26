#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <Lmcons.h>

#pragma warning(disable : 4996)

int main() {
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
	fprintf(fp, "SystemPathWOW64SyncCenterBypass.\n");
	fclose(fp);
	return 0;
}