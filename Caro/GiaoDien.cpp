#include "Header.h"

void gotoxy(int x, int y)
{
	COORD cor;
	cor.X = x;
	cor.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
void textColor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void ve_Caro()
{
	srand(time(NULL));
	textColor(9 + rand() % 7);
	gotoxy(30, 8);  printf("      OXOXOXO      ");
	gotoxy(30, 9);  printf("   OXOXOXOXOXOXO   ");
	gotoxy(30, 10); printf(" XOXOXO     OXOXOX ");
	gotoxy(30, 11); printf("XOXOX         XOXOX");
	gotoxy(30, 12); printf("OXOX               ");
	gotoxy(30, 13); printf("XOXO               ");
	gotoxy(30, 14); printf("OXOX               ");
	gotoxy(30, 15); printf("XOXO               ");
	gotoxy(30, 16); printf("OXOXO         XOXOX");
	gotoxy(30, 17); printf(" OXOXOX     XOXOXO ");
	gotoxy(30, 18); printf("   XOXOXOXOXOXOX   ");
	gotoxy(30, 19); printf("      XOXOXOX      ");

	textColor(9 + rand() % 7);
	gotoxy(49, 8);  printf("         XOX         ");
	gotoxy(49, 9);  printf("        OXOXO        ");
	gotoxy(49, 10); printf("       OXOXOXO       ");
	gotoxy(49, 11); printf("      OXOXOXOXO      ");
	gotoxy(49, 12); printf("      OXOX OXOX      ");
	gotoxy(49, 13); printf("     OXOX   OXOX     ");
	gotoxy(49, 14); printf("    XOXOXOXOXOXOX    ");
	gotoxy(49, 15); printf("   XOXOXOXOXOXOXOX   ");
	gotoxy(49, 16); printf("  XOXOX       XOXOX  ");
	gotoxy(49, 17); printf(" OOXOX         XOXOX ");
	gotoxy(49, 18); printf("XOXOX           XOXOX");
	gotoxy(49, 19); printf("OXOX             OXOX");

	textColor(9 + rand() % 7);
	gotoxy(70, 8);  printf("OXOXOXOXOXOXO     ");
	gotoxy(70, 9);  printf("XOXOXOXOXOXOXOX   ");
	gotoxy(70, 10); printf("OXOX       XOXOXO ");
	gotoxy(70, 11); printf("XOXO         OXOX ");
	gotoxy(70, 12); printf("OXOX         XOXO ");
	gotoxy(70, 13); printf("XOXO       OXOXOX ");
	gotoxy(70, 14); printf("OXOXOXOXOXOXOXO   ");
	gotoxy(70, 15); printf("XOXOXOXOXOXOX     ");
	gotoxy(70, 16); printf("OXOX      XOXOX   ");
	gotoxy(70, 17); printf("XOXO       XOXOX  ");
	gotoxy(70, 18); printf("OXOX        OXOXO ");
	gotoxy(70, 19); printf("XOXO         OXOXO");

	textColor(9 + rand() % 7);
	gotoxy(88, 8);  printf("      OXOXOXO      ");
	gotoxy(88, 9);  printf("   OXOXOXOXOXOXO   ");
	gotoxy(88, 10); printf(" XOXOXO     XOXOXO ");
	gotoxy(88, 11); printf("XOXOX         OXOXO");
	gotoxy(88, 12); printf("OXOX           XOXO");
	gotoxy(88, 13); printf("XOXO           OXOX");
	gotoxy(88, 14); printf("OXOX           XOXO");
	gotoxy(88, 15); printf("XOXO           OXOX");
	gotoxy(88, 16); printf("OXOXO         XOXOX");
	gotoxy(88, 17); printf(" OXOXOX     OXOXOX");
	gotoxy(88, 18); printf("   XOXOXOXOXOXOX   ");
	gotoxy(88, 19); printf("      XOXOXOX      ");

}
void ve_GiupDo()
{
	ve_Caro();
	gotoxy(30, 24);
	textColor(15);
	printf("LUAT CHOI:");
	gotoxy(41, 25);
	printf("Hai ben thay phien nhau di nhung nuoc di bang cac dau X, O tren ban co.");
	gotoxy(41, 26);
	printf("Ben nao co duong 5 quan lien nhau tren mot hang, mot cot hoac duong cheo");
	gotoxy(41, 27);
	printf("ma khong bi chan hai dau la thang");
	gotoxy(30, 29);
	printf("CACH CHOI:");
	gotoxy(30, 30);
	textColor(12);
	printf("Nguoi choi 1: Danh xau X, su dung cac phim dieu huong de di chuyen");
	gotoxy(44, 31);
	printf("va phim ENTER de danh");
	gotoxy(30, 32);
	textColor(9);
	printf("Nguoi choi 2: Danh dau O, su dung cac phim W, A, S, D de di chuyen");
	gotoxy(44, 33);
	printf("va phim SPACEBAR de danh");
	gotoxy(30, 35);
	textColor(15);
	printf("Khi danh voi may, ban duoc mac dinh la nguoi choi 1");
	getch();
}

void ve_GioiThieu()
{
	ve_Caro();
	gotoxy(40, 30);
	textColor(11);
	printf("Tac gia: Hoang Anh Quoc - 1512444");
	gotoxy(49, 32);
	Sleep(100);
	textColor(11);
	printf("Duong Tran Thai Son - 1512457");
	Sleep(100);
	textColor(11);
	gotoxy(40, 34);
	printf("Phien ban: 1.0");
	getch();
}

void ve_BienTren(int n)
{
	printf("%c%c%c", 218, 196, 196);
	for (int i = 0; i < n - 1; ++i)
		printf("%c%c%c%c", 196, 194, 196, 196);
	printf("%c%c\n", 196, 191);
}
void ve_Dong(int n)
{
	for (int i = 0; i < n; ++i)
		printf("%c   ", 179);

	printf("%c", 179);
}
void ve_KeDong(int n)
{
	printf("%c%c%c", 195, 196, 196);
	for (int i = 0; i < n -1; ++i)
		printf("%c%c%c%c", 196, 197, 196, 196);
	printf("%c%c\n", 196, 180);
}
void ve_BienDuoi(int n)
{
	printf("%c%c%c", 192, 196, 196);
	for (int i = 0; i < n -1; ++i)
		printf("%c%c%c%c", 196, 193, 196, 196);
	printf("%c%c", 196, 217);
}
void danhso_Ngang(int n)
{
	gotoxy(29, 6 + 2 * n + 1);
	for (int i = 1; i <= n; ++i)
	if (i <= 9)
		printf(" 0%d ", i);
	else
		printf(" %d ", i);
}
void danhso_Doc(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		gotoxy(30 + n * 4, 5 + 2 * i);
		if (i <= 9)
			printf("0%d", i);
		else
			printf("%d", i);
	}
}
void ve_BanCo(char** mangGame)
{
	int n = 20;
	textColor(3);
	gotoxy(29, 6);
	ve_BienTren(n);

	for (int i = 1; i <= n -1; ++i)
	{
		gotoxy(29, 5 + 2 * i);
		ve_Dong(n);
		gotoxy(29, 5 + 2 * i + 1);
		ve_KeDong(n);
	}

	gotoxy(29, 5 + 2 * n);
	ve_Dong(n);
	gotoxy(29, 5 + 2 * n + 1);
	ve_BienDuoi(n);

	danhso_Ngang(n);
	danhso_Doc(n);

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			if (mangGame[i][j] == 'X')
			{
				textColor(12);
				gotoxy((j - 1) * 4 + 31, (i - 1) * 2 + 7);
				printf("%c", mangGame[i][j]);
			}
			if (mangGame[i][j] == 'O')
			{
				textColor(9);
				gotoxy((j - 1) * 4 + 31, (i - 1) * 2 + 7);
				printf("%c", mangGame[i][j]);
			}
		}
	}

}
void ve_ThongBao()
{
	textColor(3);
	gotoxy(41, 0);
	printf("%c", 201);
	for (int i = 0; i < 55; ++i)
		printf("%c", 205);
	printf("%c", 187);
	for (int i = 1; i < 4; ++i)
	{
		gotoxy(41, i);
		printf("%c", 186);
	}
	for (int i = 1; i < 4; ++i)
	{
		gotoxy(97, i);
		printf("%c", 186);
	}
	gotoxy(41, 4);
	printf("%c", 200);
	for (int i = 0; i < 55; ++i)
		printf("%c", 205);
	printf("%c", 188);
}
void ve_Nguoi2()
{
	textColor(9);
	gotoxy(0, 10);
	for (int i = 0; i < 16; ++i)
		printf("%c", 220);
	for (int i = 11; i <= 28; ++i)
	{
		gotoxy(15, i);
		printf("%c", 222);
	}
	gotoxy(0, 29);
	for (int i = 0; i < 16; ++i)
		printf("%c", 223);
	gotoxy(3, 12);
	printf("NGUOI 2");
	gotoxy(1, 14);
	printf("Toa Do: ");
	gotoxy(2, 19);
	printf("DIEU KHIEN:");
	gotoxy(2, 21); printf("A: TRAI");
	gotoxy(2, 22); printf("D: PHAI");
	gotoxy(2, 23); printf("W: LEN");
	gotoxy(2, 24); printf("S: XUONG");
	gotoxy(2, 26); printf("SPACE: DANH");
}
void ve_Nguoi1()
{
	textColor(12);
	gotoxy(124, 10);
	for (int i = 87; i < 103; ++i)
		printf("%c", 220);
	for (int i = 11; i <= 28; ++i)
	{
		gotoxy(124, i);
		printf("%c", 221);
	}
	gotoxy(124, 29);
	for (int i = 87; i < 103; ++i)
		printf("%c", 223);
	gotoxy(128, 12);
	printf("NGUOI 1");
	gotoxy(126, 14);
	printf("Toa Do: ");
	gotoxy(126, 19);
	printf("DIEU KHIEN:");
	gotoxy(126, 21); 
	printf("SU DUNG");
	gotoxy(126, 22);
	printf("CAC PHIM");
	gotoxy(126, 23);
	printf("DIEU HUONG");
	gotoxy(126, 26); printf("ENTER: DANH ");
}
void ve_May()
{
	textColor(9);
	gotoxy(0, 10);
	for (int i = 0; i < 16; ++i)
		printf("%c", 220);
	for (int i = 11; i <= 28; ++i)
	{
		gotoxy(15, i);
		printf("%c", 222);
	}
	gotoxy(0, 29);
	for (int i = 0; i < 16; ++i)
		printf("%c", 223);
	gotoxy(3, 12);
	printf("COMPUTER");
	gotoxy(1, 14);
	printf("Toa Do: ");
	gotoxy(2, 19);
}
void ve_PhimTuyChon()
{
	textColor(11);
	gotoxy(30, 50);
	printf("F1 : GIUP DO");

	gotoxy(60, 50);
	printf("F2 : CHOI LAI");

	gotoxy(90, 50);
	printf("F3 :LUU GAME");

	gotoxy(30, 52);
	printf("F4 : TAI GAME");

	gotoxy(60, 52);
	printf("F5 : THONG TIN");

	gotoxy(90, 52);
	printf("ESC : THOAT");


}
void ve_GiaoDien(Option opt, char** mangGame)
{
	system("cls");
	ve_BanCo(mangGame);
	ve_ThongBao();
	ve_Nguoi1();
	if (opt.mode == 1)
		ve_May();
	else
		ve_Nguoi2();
	ve_PhimTuyChon();
}