#include "Header.h"

void nhapten_2Nguoi(char *s1, char *s2)
{
	system("cls");
	textColor(15);
	gotoxy(25, 5);
	printf("%c", 218);
	for (int i = 0; i < 89; i++)
	{
		printf("%c", 196);
	}
	printf("%c", 191);
	for (int i = 6; i < 20; i++)
	{
		gotoxy(115, i);
		printf("%c", 179);
		gotoxy(25, i);
		printf("%c", 179);
	}
	gotoxy(115, 20);
	printf("%c", 217);
	for (int i = 114; i >= 26; i--)
	{
		gotoxy(i, 20);
		printf("%c", 196);
	}
	gotoxy(25, 20);
	printf("%c", 192);

	for (int i = 1; i <= 89; i++)
	{
		gotoxy(25 + i, 7);
		printf("%c", 196);
		gotoxy(115 - i, 8);
		printf("%c", 196);
	}

	for (int i = 0; i < 11; i++)
	{
		gotoxy(70, 9 + i);
		printf("%c", 186);
	}
	gotoxy(61, 6);
	textColor(15);
	printf("NHAP TEN NGUOI CHOI");
	gotoxy(26, 11);
	textColor(12);
	printf("NGUOI CHOI 1: ");
	fflush(stdin);
	fgets(s1, 16, stdin);
	int l1 = strlen(s1);
	s1[l1 - 1] = '\0';
	gotoxy(42, 15);
	printf("SAN SANG CHOI");
	gotoxy(75, 11);
	textColor(9);
	printf("NGUOI CHOI 2: ");
	fflush(stdin);
	fgets(s2, 16, stdin);
	int l2 = strlen(s2);
	s2[l2 - 1] = '\0';
	gotoxy(85, 15);
	printf("SAN SANG CHOI");
	Sleep(700);
}

void danh_HaiNguoi(Option opt, char* s1, char* s2, char** mangGame)
{
	char c;
	int max1 = 0;
	int max2 = 0;
	system("cls");
	ve_GiaoDien(opt, mangGame);

	int x = 67;
	int y = 25;

	do
	{

		if (opt.turn == 1)
		{
			textColor(12);
			gotoxy(60, 1);
			printf("                             ");
			gotoxy(60, 1);
			printf("DEN LUOT: %s ", s1);
			gotoxy(x, y);
			Player1(opt, s1, s2, x, y, mangGame, max1);
			opt.turn = 2;
			if (max1 == 5)
				break;
		}
		if (opt.turn == 2)
		{
			textColor(9);
			gotoxy(60, 1);
			printf("                             ");
			gotoxy(60, 1);
			printf("DEN LUOT: %s", s2);
			gotoxy(x, y);
			Player2(opt, s1, s2, x, y, mangGame, max2);
			opt.turn = 1;
		}

	} while ((max1 != 5) && (max2 != 5));


	gotoxy(56, 1);
	printf("                             ");
	gotoxy(60, 1);
	printf("TRO CHOI KET THUC!");
	gotoxy(56, 2);
	printf("                             ");

	if (max2 == 5)
	{
		textColor(9);
		gotoxy(50, 3);
		printf("                                         ");
		gotoxy(52, 3);
		printf("XIN CHUC MUNG %s DA CHIEN THANG!!!", s2);
		while (1)
		{
			while (!kbhit())
				ThongBaoThang(3, 16, 130, 16, 9, 12);
			c = getch();
			PhimTuyChon(opt, s1, s2, c, mangGame);
		}
	}

	if (max1 == 5)
	{
		textColor(12);
		gotoxy(50, 3);
		printf("                                         ");
		gotoxy(52, 3);
		printf("XIN CHUC MUNG %s DA CHIEN THANG!!!", s1);
		while (1)
		{
			while (!kbhit())
				ThongBaoThang(130, 16, 3, 16, 12, 9);
			c = getch();
			PhimTuyChon(opt, s1, s2, c, mangGame);
		}
	}
	gotoxy(25, 50);
	getch();
	exit(0);

}

void Player1(Option &opt, char *s1, char *s2, int &x, int &y, char **mangGame, int &max1)
{
	char c, ch;
	int dem = 0;
	int kt = 0;
	while (1)
	{
		while (!kbhit())
		{
			Sleep(10);
			dem++;
			if ((dem / 90 <= opt.time) && (dem % 90 == 0))
			{
				gotoxy(68, 2);
				if (dem / 90 > opt.time - 10)
					printf("0");
				printf("%d", opt.time - dem / 90);
				gotoxy(x, y);
			}
			if ((dem / 90) > opt.time)
			{
				gotoxy(58, 2);
				printf("                                    ");
				gotoxy(58, 2);
				printf("BAN DA THUA DO HET GIO");
				ThongBaoThang(3, 16, 130, 16, 9, 12);
				kt = 1;
			}
		}
		c = getch();
		PhimTuyChon(opt, s1, s2, c, mangGame);
		textColor(12);
		if (kt)
			continue;
		if (c == 13)
		{
			if (mangGame[(y - 7) / 2 + 1][(x - 30) / 4 + 1] == 'X' || mangGame[(y - 7) / 2 + 1][(x - 30) / 4 + 1] == 'O')
			{
				gotoxy(53, 3);
				printf("                                   ");
				gotoxy(53, 3);
				printf("O NAY DA DUOC DANH, HAY DANH LAI!");
				Beep(700, 300);
				gotoxy(x, y);
				continue;
			}
			textColor(12);
			printf("X");
			gotoxy(53, 3);
			printf("                                   ");
			mangGame[(y - 7) / 2 + 1][(x - 30) / 4 + 1] = 'X';
			Win((x - 30) / 4 + 1, (y - 7) / 2 + 1, mangGame, max1);
			break;
		}
		switch (c)
		{
		case 72: if (y > 7)
			y -= 2;
			break;
		case 77: if (x < 27 + 4 * 20)
			x += 4;
			break;
		case 80: if (y < 5 + 2 * 20)
			y += 2;
			break;
		case 75: if (x > 33)
			x -= 4;
		}
		gotoxy(133, 14);
		printf("       ");
		gotoxy(133, 14);
		printf("(%d,%d)", (y - 7) / 2 + 1, (x - 30) / 4 + 1);
		gotoxy(x, y);
	}
}

void Player2(Option &opt, char *s1, char *s2, int &x, int &y, char **mangGame, int &max2)
{
	char c, ch;
	int dem = 0;
	int kt = 0;
	while (1)
	{
		while (!kbhit())
		{
			Sleep(10);
			dem++;
			if ((dem / 90 <= opt.time) && (dem % 90 == 0))
			{
				gotoxy(68, 2);
				if (dem / 90 > opt.time - 10)
					printf("0");
				printf("%d", opt.time - dem / 90);
				gotoxy(x, y);
			}
			if (dem / 90 > opt.time)
			{
				gotoxy(58, 2);
				printf("                                    ");
				gotoxy(58, 2);
				printf("BAN DA THUA DO HET GIO");
				ThongBaoThang(130, 16, 3, 16, 12, 9);
				kt = 1;
			}
		}
		c = getch();
		PhimTuyChon(opt, s1, s2, c, mangGame);
		textColor(9);
		if (kt)
			continue;
		if (c == ' ')
		{
			if (mangGame[(y - 7) / 2 + 1][(x - 30) / 4 + 1] == 'X' || mangGame[(y - 7) / 2 + 1][(x - 30) / 4 + 1] == 'O')
			{
				gotoxy(53, 3);
				printf("                                   ");
				gotoxy(53, 3);
				printf("O NAY DA DUOC DANH, HAY DANH LAI");
				Beep(700, 300);
				gotoxy(x, y);
				continue;
			}

			textColor(9);
			printf("O");
			gotoxy(53, 3);
			printf("                                   ");
			mangGame[(y - 7) / 2 + 1][(x - 30) / 4 + 1] = 'O';
			Win((x - 30) / 4 + 1, (y - 7) / 2 + 1, mangGame, max2);
			break;
		}
		switch (c)
		{
		case 'w': case 'W': if (y > 7)
			y -= 2;
			break;
		case 'd': case 'D': if (x < 27 + 4 * 20)
			x += 4;
			break;
		case 's': case 'S': if (y < 5 + 2 * 20)
			y += 2;
			break;
		case 'a': case 'A': if (x > 33)
			x -= 4;
		}
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", (y - 7) / 2 + 1, (x - 30) / 4 + 1);
		gotoxy(x, y);
	}
}

void Win(int x, int y, char **mangGame, int &max)
{
	//Xét theo hàng ngang
	max = 1;
	int temp = 0;
	int j = x;
	int i = y;
	char ch1 = 'D', ch2 = 'M';

	if (j == 20)
		ch1 = ' ';
	while (j <= 20)
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch1 = mangGame[i][j];
			break;
		}
		j++;
		temp++;
	}
	j = x;
	temp--;
	if (j == 1)
		ch2 = ' ';
	while (j > 0)
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch2 = mangGame[i][j];
			break;
		}
		j--;
		temp++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')//Bị chặn 2 đầu
		temp = 0;
	if (temp > max)
		max = temp;

	//Xét theo hàng dọc
	temp = 0;
	j = x;
	if (i == 20)
		ch1 = ' ';
	while (i <= 20)
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch1 = mangGame[i][j];
			break;
		}
		i++;
		temp++;
	}
	temp--;
	i = y;
	if (i == 1)
		ch2 = ' ';
	while (i > 0)
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch2 = mangGame[i][j];
			break;
		}
		i--;
		temp++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		temp = 0;
	if (temp > max)
		max = temp;

	//Xét theo đường chéo xuôi
	temp = 0;
	i = y;
	if ((i == 20) || (j == 20))
		ch1 = ' ';
	while ((i <= 20) && (j <= 20))
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch1 = mangGame[i][j];
			break;
		}
		i++;
		j++;
		temp++;
	}
	i = y;
	j = x;
	temp--;
	if ((i == 1) || (j == 1))
		ch2 = ' ';
	while ((i > 0) && (j > 0))
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch2 = mangGame[i][j];
			break;
		}
		i--;
		j--;
		temp++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		temp = 0;
	if (temp > max)
		max = temp;

	//Xét theo đường chéo ngược
	temp = 0;
	i = y;
	j = x;
	if ((i == 20) || (j == 1))
		ch1 = ' ';
	while ((i <= 20) && (j > 0))
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch1 = mangGame[i][j];
			break;
		}
		i++;
		j--;
		temp++;
	}
	temp--;
	i = y;
	j = x;
	if ((i == 1) || (j == 20))
		ch2 = ' ';
	while ((i > 0) && (j <= 20))
	{
		if (mangGame[i][j] != mangGame[y][x])
		{
			ch2 = mangGame[i][j];
			break;
		}
		i--;
		j++;
		temp++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		temp = 0;
	if (temp > max)
		max = temp;
}