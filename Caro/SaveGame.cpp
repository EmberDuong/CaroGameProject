#include "Header.h"

char* setFileName()
{
	time_t rawtime;
	char* name = new char[35];
	char* s;

	time(&rawtime);
	s = ctime(&rawtime);
	for (int i = 4; i < strlen(s); ++i)
	if (s[i] != ' ' && s[i] != ':')
		name[i - 4] = s[i];
	else name[i - 4] = '_';
	s = ".cr.txt";
	for (int i = 0; i < 7; ++i)
		name[20 + i] = s[i];
	name[27] = '\0';

	return name;
}

void saveGame(Option opt, char *s1, char *s2, char **mangGame)
{
	char *name;
	name = setFileName();
	FILE*  saveName = fopen("Save.txt", "a+t");
	if (saveName != NULL)
	{
		fprintf(saveName, "%s\n", name);
		fclose(saveName);
	}

	FILE* saveFile = fopen(name, "wt");
	if (saveFile != NULL)
	{
		fprintf(saveFile, "%d %d %d\n", opt.mode, opt.turn, opt.time);
		fprintf(saveFile, "%s\n", s1);
		if (opt.mode == 2)
			fprintf(saveFile, "%s\n", s2);

		for (int i = 1; i < 21; ++i)
		{
			for (int j = 1; j < 21; ++j)
				fprintf(saveFile, "%c", mangGame[i][j]);
			fprintf(saveFile, "\n");
		}
		fclose(saveFile);
	}
}

void hoiTruocKhiLuu(Option opt, char *s1, char *s2, char **mangGame)
{
	textColor(11);

	gotoxy(40, 5);
	printf("%c", 201);
	for (int i = 0; i < 59; ++i)
		printf("%c", 205);
	printf("%c", 187);
	for (int i = 6; i < 19; ++i)
	{
		gotoxy(100, i);
		printf("%c", 186);
	}
	gotoxy(100, 19);
	printf("%c", 188);
	for (int i = 99; i > 40; --i)
	{
		gotoxy(i, 19);
		printf("%c", 205);
	}
	gotoxy(40, 19);
	printf("%c", 200);
	for (int i = 18; i >= 6; --i)
	{
		gotoxy(40, i);
		printf("%c", 186);
	}

	gotoxy(53, 9);
	printf("BAN CO MUON LUU GAME HIEN TAI KHONG?");
	gotoxy(60, 13);
	printf("%c  CO", 254);
	gotoxy(75, 13);
	printf("%c  KHONG", 254);
	char ch = 'x';
	gotoxy(60, 13);
	int x = 60;
	while (ch != 13)
	{
		ch = getch();
		switch (ch)
		{
		case 75: if (x > 60)
			x -= 15;
			break;
		case 77: if (x < 75)
			x += 15;
		}
		if (ch == 27)
			break;
		gotoxy(x, 13);
	}
	if (ch == 13)
	{
		if (x == 60)
		{
			saveGame(opt, s1, s2, mangGame);
			gotoxy(60, 15);
			printf("LUU GAME THANH CONG!");
			Sleep(300);
			gotoxy(60, 15);
			printf("                     ");
			Sleep(300);
			gotoxy(60, 15);
			printf("LUU GAME THANH CONG!");
		}
		if (x == 75)
		{
			gotoxy(60, 13);
			printf("                          ");
			gotoxy(62, 13);
			printf("KHONG LUU GAME!");
			Sleep(300);
			gotoxy(62, 13);
			printf("                ");
			Sleep(300);
			gotoxy(62, 13);
			printf("KHONG LUU GAME!");
		}
		Sleep(500);
	}
}

void loadGame(Option &opt, char *s1, char *s2, char *name)
{
	char cha;
	FILE* openFile = fopen(name, "rt");
	if (openFile != NULL)
	{
		char **mangGame = new char*[21];

		for (int i = 1; i < 21; ++i)
			mangGame[i] = new char[21];

		fscanf(openFile, "%d %d %d", &opt.mode, &opt.turn, &opt.time);
		fgetc(openFile);
		fgets(s1, 50, openFile);
		s1[strlen(s1) - 1] = '\0';
		if (opt.mode == 2)
		{
			fgets(s2, 50, openFile);
			s2[strlen(s2) - 1] = '\0';
		}

		for (int i = 1; i < 21; ++i)
		{
			for (int j = 1; j < 21; ++j)
				fscanf(openFile, "%c", &mangGame[i][j]);
			fscanf(openFile, "%c", &cha);
		}
		system("cls");
		fclose(openFile);
		if (opt.mode == 2)
		{
			ve_GiaoDien(opt, mangGame);
			danh_HaiNguoi(opt, s1, s2, mangGame);
		}
		if (opt.mode == 1)
		{
			ve_GiaoDien(opt, mangGame);
			danh_VoiMay(opt, s1, mangGame);
		}
		getch();
	}
}

void ve_menuTaiGame(Option opt, char *s1, char *s2)
{
	system("cls");
	char name[50], s[30];

	FILE* load = fopen("Save.txt", "r");

	textColor(15);
	gotoxy(50, 10);
	printf("%c", 201);
	for (int i = 0; i < 39; ++i)
		printf("%c", 205);

	printf("%c", 187);
	for (int i = 11; i < 40; ++i)
	{
		gotoxy(90, i);
		printf("%c", 186);
	}
	gotoxy(90, 40);
	printf("%c", 188);
	for (int i = 89; i >= 50; --i)
	{
		gotoxy(i, 40);
		printf("%c", 205);
	}
	gotoxy(50, 40);
	printf("%c", 200);
	for (int i = 39; i > 10; --i)
	{
		gotoxy(50, i);
		printf("%c", 186);
	}
	gotoxy(51, 13);
	for (int i = 0; i < 39; ++i)
		printf("%c", 196);
	gotoxy(65, 11);
	printf("TAI GAME");

	int line = 15;
	fgets(name, 29, load);
	gotoxy(52, line);
	if (feof(load) == 0)
		printf("%c    %s", 254, name);
	line++;
	if (feof(load))
	{
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(54, 15);
			printf("Khong co game nao duoc luu!");
			Sleep(500);
			gotoxy(54, 15);
			printf("                           ");
			Sleep(500);
		}
		system("CLS");
		ve_Menu(opt);
	}
	else
	while (!feof(load))
	{
		strcpy(s, name);
		fgets(name, 99, load);
		if (strcmp(s, name))
		{
			gotoxy(52, line);
			printf("%c    %s", 254, name);
			line++;
		}
	}
	gotoxy(52, 15);
	rewind(load);
	char ch;
	ch = 'x';
	int y = 15;
	while (ch != 13)
	{
		ch = getch();
		if (ch == 27)
		{
			system("cls");
			fclose(load);
			break;
		}
		switch (ch)
		{
		case 72: if (y > 15)
			y -= 1;
			break;
		case 80: if (y < line - 1)
			y += 1;
		}
		gotoxy(52, y);
		if (ch == 13)
		{
			for (int i = 15; i <= y; i++)
			{
				fgets(name, 99, load);
			}
			fclose(load);
			name[strlen(name)-1] = '\0';
			printf("%s", name);
			loadGame(opt, s1, s2, name);
		}
	}
}