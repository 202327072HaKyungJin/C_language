#define _YUHAN_C_WINDOW_USER


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _YUHAN_C_WINDOW_USER
#include <windows.h>
#endif

#ifdef _YUHAN_C_MAC_USER
#include <unistd.h>
#endif

int main(void)
{
	clock_t sjtstart;
	sjtstart=clock();

	int i = 0;

	while (i < 3)
	{
		/*system("cls");*/
		
		COORD pos = { 0,0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		printf("��������\n", i+1, (int)sjtstart);
		
		printf("������ �����ϴ�:");

		int j = 0;
		while (j < i)
		{
			printf("#");
			j = j + 1;
		}
		Sleep(100);
		i = i + 1;
	}

	clock_t sjtend;
	sjtend = clock();

	printf("������ %d��ŭ �����ϴ�\n", (int)(sjtend - sjtstart));
	return 0;
}