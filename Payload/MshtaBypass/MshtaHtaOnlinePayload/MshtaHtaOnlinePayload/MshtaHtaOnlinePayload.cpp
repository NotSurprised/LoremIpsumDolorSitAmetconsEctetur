#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <Lmcons.h>

#pragma warning(disable : 4996)

int main() {
	printf("  ___         _   _            _     __        __     _____               _   \n");
	printf(" |_ _|_ __   | | | | __ _  ___| | __ \\ \\      / /__  |_   _| __ _   _ ___| |_ \n");
	printf("  | || '_ \\  | |_| |/ _` |/ __| |/ /  \\ \\ /\\ / / _ \\   | || '__| | | / __| __|\n");
	printf("  | || | | | |  _  | (_| | (__|   <    \\ V  V /  __/   | || |  | |_| \\__ \\ |_ \n");
	printf(" |___|_| |_| |_| |_|\\__,_|\\___|_|\\_\\    \\_/\\_/ \\___|   |_||_|   \\__,_|___/\\__|\n");
	printf("%lu\n", (unsigned long)time(NULL));

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
	fprintf(fp, "MshtaHtaOnlinePayloadBypass.\n");
	fclose(fp);
}