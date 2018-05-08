#include "Header.h"

void nhapten_1Nguoi(char *s1)
{
	system("cls");
	textColor(15);
	gotoxy(40, 5);
	printf("%c", 218);
	for (int i = 0; i < 59; i++)
	{
		printf("%c", 196);
	}
	printf("%c", 191);
	for (int i = 6; i < 20; i++)
	{
		gotoxy(100, i);
		printf("%c", 179);
	}
	gotoxy(100, 20);
	printf("%c", 217);
	for (int i = 99; i > 40; i--)
	{
		gotoxy(i, 20);
		printf("%c", 196);
	}
	gotoxy(40, 20);
	printf("%c", 192);
	for (int i = 19; i > 5; i--)
	{
		gotoxy(40, i);
		printf("%c", 179);
	}

	gotoxy(41, 7);
	for (int i = 1; i <= 59; i++)
	{
		printf("%c", 196);
	}
	gotoxy(41, 8);
	for (int i = 1; i <= 59; i++)
	{
		printf("%c", 196);
	}
	gotoxy(59, 6);
	textColor(15);
	printf("NHAP TEN NGUOI CHOI");
	gotoxy(41, 12);
	textColor(12);
	printf("TEN NGUOI CHOI: ");
	fflush(stdin);
	fgets(s1, 16, stdin);
	int l1 = strlen(s1);
	s1[l1 - 1] = '\0';
	gotoxy(61, 15);
	printf("SAN SANG CHOI!");
	Sleep(700);
}

void COM(char *s2, int x, int y, char **mangGame, int &max2, int &luot)
{
	int test;
	int kiemtra = 0;
	int xRoot = (x - 30) / 4 + 2;
	int yRoot = (y - 7) / 2 + 1;
	gotoxy(50, 1);
	printf("                                      ");
	gotoxy(60, 1);
	printf("Den luot %s", s2);

	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	if (danhThang(mangGame, 'O', i, j))
	{
		textColor(9);
		mangGame[j][i] = 'O';
		gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
		Sleep(5);
		printf("O");

		danhDau(20, i, j, mangGame, max2);
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", i, j);
		goto thoat;
	}
	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	if (danhThang(mangGame, 'X', i, j))
	{
		test = 1;
		mangGame[j][i] = 'X';
		for (int i2 = 1; i2 <= 20; i2++)
		for (int j2 = 1; j2 <= 20; j2++)
		if (mangGame[j2][i2] == ' ')
		if (danhThang(mangGame, 'X', i2, j2))
		{
			mangGame[j][i] = ' ';
			break;
			test = 0;
		}
		if (test == 0)
			continue;
		textColor(9);
		mangGame[j][i] = 'O';
		gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
		Sleep(5);
		printf("O");
		danhDau(20, i, j, mangGame, max2);
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", i, j);
		goto thoat;
	}

	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	if (vitriTot(mangGame, 'O', i, j))
	{
		textColor(9);
		mangGame[j][i] = 'O';
		gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
		Sleep(5);
		printf("O");
		danhDau(20, i, j, mangGame, max2);
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", i, j);
		goto thoat;
	}

	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)

	if (mangGame[j][i] == ' ')
	if (vitriTot(mangGame, 'X', i, j))
	{
		textColor(9);
		mangGame[j][i] = 'O';
		gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
		Sleep(5);
		printf("O");
		danhDau(20, i, j, mangGame, max2);
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", i, j);
		goto thoat;
	}

	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	{
		if (danhPhaTran(mangGame, 'O', i, j, kiemtra))
		if (kiemtra)
		{
			textColor(9);
			mangGame[j][i] = 'O';
			gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
			Sleep(5);
			printf("O");

			danhDau(20, i, j, mangGame, max2);
			gotoxy(8, 14);
			printf("       ");
			gotoxy(8, 14);
			printf("(%d,%d)", i, j);
			goto thoat;
		}

	}
	else kiemtra = 0;
	kiemtra = 0;
	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	if (danhPhaTran(mangGame, 'X', i, j, kiemtra))
	{
		if (kiemtra)
		{
			textColor(9);
			mangGame[j][i] = 'O';
			gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
			printf("O");
			danhDau(20, i, j, mangGame, max2);
			gotoxy(8, 14);
			printf("       ");
			gotoxy(8, 14);
			printf("(%d,%d)", i, j);
			goto thoat;
		}
	}
	else
		kiemtra = 0;

	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	if (danhPhaTran(mangGame, 'O', i, j, kiemtra))
	{
		textColor(9);
		mangGame[j][i] = 'O';
		gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
		Sleep(5);
		printf("O");

		danhDau(20, i, j, mangGame, max2);
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", i, j);
		goto thoat;
	}

	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	if (danhPhaTran(mangGame, 'X', i, j, kiemtra))
	{
		textColor(9);
		mangGame[j][i] = 'O';
		gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
		printf("O");

		danhDau(20, i, j, mangGame, max2);
		gotoxy(8, 14);
		printf("       ");
		gotoxy(8, 14);
		printf("(%d,%d)", i, j);
		goto thoat;
	}

	int ktra = 0;
	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[j][i] == ' ')
	{
		mangGame[j][i] = 'O';
		for (int i2 = 1; i2 <= 20; i2++)
		for (int j2 = 1; j2 <= 20; j2++)
		if (mangGame[j2][i2] == ' ')
		if (danhPhaTran(mangGame, 'O', i2, j2, kiemtra))
			ktra = 1;

		if (ktra)
		{
			textColor(9);
			gotoxy((i - 1) * 4 + 31, (j - 1) * 2 + 7);
			printf("O");
			goto thoat;
		}
		mangGame[j][i] = ' ';
	}

	timDeDanh(x, y, mangGame, 'O');
	gotoxy((xRoot - 1) * 4 + 30, (yRoot - 1) * 2 + 7);
	mangGame[y][x] = 'O';

	textColor(9);

	gotoxy((x - 1) * 4 + 31, (y - 1) * 2 + 7);
	Sleep(5);
	printf("O");

	danhDau(20, x, y, mangGame, max2);
	gotoxy(8, 14);
	printf("       ");
	gotoxy(8, 14);
	printf("(%d,%d)", x, y);
thoat:;
}

int danhThang(char **mangGame, int ch, int &x, int &y)
{
	int max = 0;
	int j = x + 1;
	int i = y;
	int kt = 0;
	while (j <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	j = x - 1;
	while (j >= 1)
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}

	if (kt == 2)
		max = 0;
	if (max == 4)
		return 1;
	/*------------------------------------------------------------------*/

	max = 0;
	i = y + 1;
	j = x;
	kt = 0;
	while (i <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	i = y - 1;
	while (i >= 1)
	{
		if (mangGame[i][j] == ch)
		{
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	if (max == 4)
		return 1;
	/*---------------------------------------------------------------*/

	max = 0;
	j = x + 1;
	i = y + 1;
	kt = 0;
	while ((i <= 20) && (j <= 20))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	j = x - 1;
	i = y - 1;
	while ((i >= 1) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	if (max == 4)
		return 1;
	/*----------------------------------------------------------------*/

	max = 0;
	j = x - 1;
	i = y + 1;
	kt = 0;
	while ((i <= 20) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	j = x + 1;
	i = y - 1;
	while ((i >= 1) && (j <= 20))
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	if (max == 4)
		return 1;

	return 0;
}

int danhPhaTran(char **mangGame, char ch, int x, int y, int &kiemtra)
{
	int flagSpace = 0;
	int flag = 0;
	int flagch = 0;
	int j = x + 1;
	int i = y;
	int kt = 0;
	while (j <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (j + 1 <= 20 && mangGame[i][j + 1] == ch && flagSpace == 0)
			{
				j++;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;
	}
	j = x - 1;
	while (j > 0)
	{

		if (mangGame[i][j] == ch)
		{
			j--;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (j - 1 >= 1 && mangGame[i][j - 1] == ch && flagSpace == 0)
			{
				j--;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}

		else
		if (mangGame[i][j] != ' ')
			break;
	}
	if (((kt == 2) && (flagch == 2)) || ((kt == 2) && (flagch == 3)) || (flagch == 4) || ((kt == 1) && (flagch == 3)))
		flag++;
	if ((kt == 1) && (flagch == 3))
		kiemtra = 1;

	flagSpace = 0;
	flagch = 0;
	j = x;
	i = y + 1;
	kt = 0;
	while (i <= 20)
	{

		if (mangGame[i][j] == ch)
		{
			i++;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (i + 1 <= 20 && mangGame[i + 1][j] == ch && flagSpace == 0)
			{
				i++;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;

	}
	i = y - 1;
	while (i >= 1)
	{

		if (mangGame[i][j] == ch)
		{
			i--;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (i - 1 >= 1 && mangGame[i - 1][j] == ch && flagSpace == 0)
			{
				i--;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;

	}
	if (((kt == 2) && (flagch == 2)) || ((kt == 2) && (flagch == 3)) || (flagch == 4) || ((kt == 1) && (flagch == 3)))
		flag++;
	if ((kt == 1) && (flagch == 3))
		kiemtra = 1;
	if (flag == 2)
		return 1;
	/*---------------------------------------------------------------*/

	flagSpace = 0;
	flagch = 0;
	j = x + 1;
	i = y + 1;
	kt = 0;
	while ((i <= 20) && (j <= 20))
	{

		if (mangGame[i][j] == ch)
		{
			i++;
			j++;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (j + 1 <= 20 && i + 1 <= 20 && mangGame[i + 1][j + 1] == ch && flagSpace == 0)
			{
				i++;
				j++;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;

	}
	j = x - 1;
	i = y - 1;
	while ((i >= 1) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			i--;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (j - 1 >= 1 && i - 1 >= 1 && mangGame[i - 1][j - 1] == ch && flagSpace == 0)
			{
				i--;
				j--;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;
	}
	if (((kt == 2) && (flagch == 2)) || ((kt == 2) && (flagch == 3)) || (flagch == 4) || ((kt == 1) && (flagch == 3)))
		flag++;
	if ((kt == 1) && (flagch == 3))
		kiemtra = 1;
	if (flag == 2)
		return 1;
	/*----------------------------------------------------------------*/

	flagSpace = 0;
	flagch = 0;
	j = x - 1;
	i = y + 1;
	kt = 0;
	while ((i <= 20) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j--;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (j - 1 >= 1 && i + 1 <= 20 && mangGame[i + 1][j - 1] == ch && flagSpace == 0)
			{
				i++;
				j--;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;
	}
	j = x + 1;
	i = y - 1;
	while ((i >= 1) && (j <= 20))
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			i--;
			flagch++;
		}
		else
		if (mangGame[i][j] == ' ')
		{
			if (j + 1 <= 20 && i - 1 >= 1 && mangGame[i - 1][j + 1] == ch && flagSpace == 0)
			{
				i--;
				j++;
				flagSpace = 1;
				continue;
			}
			kt++;
			break;
		}
		else
		if (mangGame[i][j] != ' ')
			break;
	}
	if ((kt == 1) && (flagch == 3))
		kiemtra = 1;
	if (((kt == 2) && (flagch == 2)) || ((kt == 2) && (flagch == 3)) || (flagch == 4) || ((kt == 1) && (flagch == 3)))
		flag++;
	if (flag == 2)
		return 1;
	return 0;
}

void danhDau(int n, int x, int y, char **mangGame, int &max2)
{
	max2 = 1;
	int max = 0;
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
		max++;
	}
	j = x;
	max--;
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
		max++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		max = 0;
	if (max > max2)
		max2 = max;
	/*------------------------------------------------------------------*/

	max = 0;
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
		max++;
	}
	max--;
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
		max++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		max = 0;
	if (max > max2)
		max2 = max;

	/*---------------------------------------------------------------*/

	max = 0;
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
		max++;
	}
	i = y;
	j = x;
	max--;
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
		max++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		max = 0;
	if (max > max2)
		max2 = max;
	/*----------------------------------------------------------------*/
	max = 0;
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
		max++;
	}
	max--;
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
		max++;
	}
	if (ch1 != mangGame[y][x] && ch1 == ch2 && ch1 != ' ')
		max = 0;
	if (max > max2)
		max2 = max;
}

int tinhGiaTri(char **mangGame, char ch, int x, int y) // Trả về điểm tốt nhất
{
	int result = 0;
	int max = 0;
	int i = x + 1;
	int j = y;
	int kt = 0;
	while (i <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	i = x - 1;
	while (i > 0)
	{
		if (mangGame[i][j] == ch)
		{
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	result += max;
	/*------------------------------------------------------------------*/

	max = 0;
	i = x;
	j = y + 1;
	kt = 0;
	while (j <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	j = y - 1;
	while (j >= 1)
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	result += max;
	/*---------------------------------------------------------------*/

	max = 0;
	i = x + 1;
	j = y + 1;
	kt = 0;
	while ((i <= 20) && (j <= 20))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	j = x - 1;
	i = y - 1;
	while ((i >= 1) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	result += max;
	/*----------------------------------------------------------------*/

	max = 0;
	i = x - 1;
	j = y + 1;
	kt = 0;
	while ((i >= 20) && (j <= 1))
	{
		if (mangGame[i][j] == ch)
		{
			i--;
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	i = x + 1;
	j = y - 1;
	while ((i <= 1) && (j >= 20))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
				kt++;
			break;
		}
	}
	if (kt == 2)
		max = 0;
	result += max;
	return result;
}

void timDeDanh(int &x, int &y, char **mangGame, char ch)
{
	int max = 0;
	for (int i = 1; i <= 20; i++)
	for (int j = 1; j <= 20; j++)
	if (mangGame[i][j] == ' ')
	{
		int temp = tinhGiaTri(mangGame, 'O', j, i);
		if (temp > max)
		{
			max = temp;
			x = j;
			y = i;
		}
	}
}

int vitriTot(char **mangGame, char ch, int &x, int &y)
{
	int max = 0; // tra ve so lượng con đánh của máy mà có thể ăn được(tức không bị chặn 2 đầu)
	int j = x + 1;
	int i = y;
	int kt = 0;
	while (j <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if (j + 1 <= 20)
			if (mangGame[i][j] == ' ' && mangGame[i][j + 1] != ' ' && mangGame[i][j + 1] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}
	j = x - 1;
	while (j > 0)
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if (j - 1 >= 1)
			if (mangGame[i][j] == ' ' && mangGame[i][j - 1] != ' ' && mangGame[i][j - 1] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}

	if (kt == 2)
		max = 0;
	if (max >= 3)
		return 1;
	/*------------------------------------------------------------------*/

	max = 0;
	i = y + 1;
	j = x;
	kt = 0;
	while (i <= 20)
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if (i + 1 <= 20)
			if (mangGame[i][j] == ' ' && mangGame[i + 1][j] != ' ' && mangGame[i + 1][j] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}
	i = y - 1;
	while (i >= 1)
	{
		if (mangGame[i][j] == ch)
		{
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if (i - 1 >= 1)
			if (mangGame[i][j] == ' ' && mangGame[i - 1][j] != ' ' && mangGame[i - 1][j] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}
	if (kt == 2)
		max = 0;
	if (max >= 3)
		return 1;
	/*---------------------------------------------------------------*/

	max = 0;
	j = x + 1;
	i = y + 1;
	kt = 0;
	while ((i <= 20) && (j <= 20))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j++;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			break;
			if ((j + 1 <= 20) && (i + 1 <= 20))
			if (mangGame[i][j] == ' ' && mangGame[i + 1][j + 1] != ' ' && mangGame[i + 1][j + 1] != ch)
			{
				max--;
				kt++;
			}
		}
	}
	j = x - 1;
	i = y - 1;
	while ((i >= 1) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			j--;
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if ((j - 1 >= 1) && (i - 1 >= 1))
			if (mangGame[i][j] == ' ' && mangGame[i - 1][j - 1] != ' ' && mangGame[i - 1][j - 1] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}
	if (kt == 2)
		max = 0;
	if (max >= 3)
		return 1;
	/*----------------------------------------------------------------*/

	max = 0;
	j = x - 1;
	i = y + 1;
	kt = 0;
	while ((i <= 20) && (j >= 1))
	{
		if (mangGame[i][j] == ch)
		{
			i++;
			j--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if ((j - 1 >= 1) && (i + 1 <= 20))
			if (mangGame[i][j] == ' ' && mangGame[i + 1][j - 1] != ' ' && mangGame[i + 1][j - 1] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}
	j = x + 1;
	i = y - 1;
	while ((i >= 1) && (j <= 20))
	{
		if (mangGame[i][j] == ch)
		{
			j++;
			i--;
			max++;
		}
		else
		{
			if (mangGame[i][j] != ' ')
			{
				max--;
				kt++;
			}
			if ((j + 1 <= 20) && (i - 1 >= 1))
			if (mangGame[i][j] == ' ' && mangGame[i - 1][j + 1] != ' ' && mangGame[i - 1][j + 1] != ch)
			{
				max--;
				kt++;
			}
			break;
		}
	}
	if (kt == 2)
		max = 0;
	if (max >= 3)
		return 1;
	return 0;
}

void danh_VoiMay(Option &opt, char* s1, char** mangGame)
{
	char c;
	char s2[50] = "COMPUTER";
	int check = 1;
	int x = 67;
	int y = 25;
	int max1 = 0;
	int max2 = 0;
	int luot = opt.turn;
	ve_GiaoDien(opt, mangGame);
	if (opt.turn == 2)
	{
		mangGame[11][11] = 'O';
		gotoxy(10 * 4 + 31, 10 * 2 + 7);
		textColor(9);
		printf("O");
	}
	do
	{
		luot = 1;
		textColor(12);
		gotoxy(50, 1);
		printf("                               ");
		gotoxy(60, 1);
		printf("DEN LUOT: %s", s1);
		gotoxy(x, y);
		Player1(opt, s1, s2, x, y, mangGame, max1);
		if (max1 == 5)
			break;
		if ((check))
		{
			int i = 0;
			int j = 0;
			while ((j == 0 && i == 0) || mangGame[11 + j][11 + i] != ' ')
			{
				i = rand() % 5 - 2;
				j = rand() % 5 - 2;
			}
			textColor(9);
			gotoxy((11 + i - 1) * 4 + 31, (11 + j - 1) * 2 + 7);
			printf("O");
			mangGame[11 + j][11 + i] = 'O';
			check = 0;
		}
		else
			COM(s2, x, y, mangGame, max2, opt.turn);
	} while ((max1 != 5) && (max2 != 5));

	if (max2 == 5)
	{
		textColor(9);
		gotoxy(50, 3);
		printf("                                               ");
		gotoxy(52, 3);
		printf("BAN DA THUA, COMPUTER DA CHIEN THANG!!!");
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
		printf("                                              ");
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