#include "Header.h"


void ve_Menu(Option opt)
{

	ve_Caro();

	textColor(15);
	gotoxy(60, 25);
	printf("%c\tGIUP DO", 254);
	gotoxy(60, 27);
	printf("%c\tTUY CHON", 254);
	gotoxy(60, 29);
	printf("%c\tGAME MOI", 254);
	gotoxy(60, 31);
	printf("%c\tTAI GAME", 254);
	gotoxy(60, 33);
	printf("%c\tTHONG TIN", 254);
	gotoxy(60, 35);
	printf("%c\tTHOAT", 254);
	gotoxy(60, 25);

	chon_Menu(opt);
}

void chon_Menu(Option opt)
{
	char ch;
	char s1[50];
	char s2[50];
	ch = getch();
	int y = 25;
	while (ch != 13)
	{
		ch = getch();
		switch (ch)
		{
		case 72: if (y > 25)
			y -= 2;
			break;
		case 80: if (y < 35)
			y += 2;
			break;
		}
		gotoxy(60, y);
	}
	if (ch == 13)
	{
		if (y == 25)
		{
			system("cls");
			ve_GiupDo();
			system("cls");
			ve_Menu(opt);
		}

		if (y == 27)
		{
			system("cls");
			Setting(opt);
			system("cls");
			ve_Menu(opt);
		}

		if (y == 29)
		{
			system("CLS");
			char **mangGame = new char*[21];
			for (int i = 1; i < 21; i++)
			{
				mangGame[i] = new char[21];
				for (int j = 1; j < 21; j++)
					mangGame[i][j] = ' ';
			}

			if (opt.mode == 1)
			{
				nhapten_1Nguoi(s1);
				danh_VoiMay(opt, s1, mangGame);
			}

			if (opt.mode == 2)
			{
				nhapten_2Nguoi(s1, s2);
				danh_HaiNguoi(opt, s1, s2, mangGame);
			}
		}

		if (y == 31)
		{
			system("cls");
			ve_menuTaiGame(opt, s1, s2);
			ve_Menu(opt);
		}

		if (y == 33)
		{
			system("cls");
			ve_GioiThieu();
			system("cls");
			ve_Menu(opt);
		}
		if (y == 35)
		{

			exit(0);
		}
	}
}

void Setting(Option &opt)
{
	ve_Caro();

	textColor(11);

	gotoxy(55, 30);
	printf("%c    DI TRUOC",254);
	
	gotoxy(55, 34);
	printf("%c    THOI GIAN",254);

	gotoxy(55, 26);
	printf("%c    CHE DO CHOI",254);

	if (opt.mode == 2)
	{
		gotoxy(60, 28);
		printf("2 Nguoi");
		if (opt.turn == 1)
		{
			gotoxy(60, 32);
			printf("Nguoi choi 1");
		}
		else
		{
			gotoxy(60, 32);
			printf("Nguoi choi 2");
		}
	}
	else
	{
		gotoxy(60, 28);
		printf("1 Nguoi");
		if (opt.turn == 1)
		{
			gotoxy(60, 32);
			printf("Nguoi choi 1");
		}
		else
		{
			gotoxy(60, 32);
			printf("Computer    ");
		}
	}
	gotoxy(60, 36);
	printf("%d", opt.time);
	gotoxy(55, 26);

	int x = 55;
	int y = 26;
	char ch;
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 72:
		{
				   if (y > 26)
				   {
					   y -= 4;
				   }
				   break;
		}
			
		case 77:
		{
				   if (y == 26)
				   {
					   if (opt.mode == 1)
						   opt.mode = 2;
					   else
						   opt.mode = 1;
				   }
				   if (y == 30)
				   {
					   if (opt.turn == 1)
						   opt.turn = 2;
					   else
						   opt.turn = 1;
				   }
				   if (y == 34 && opt.time < 60)
					   opt.time++;
				   break;
		}
			
		case 80:
		{
				   if (y < 34)
				   {
					   y += 4;
				   }
				   break;
		}
			
		case 75:
		{
				   if (y == 26)
				   {
					   if (opt.mode == 1)
						   opt.mode = 2;
					   else
						   opt.mode = 1;
				   }
				   if (y == 30)
				   {
					   if (opt.turn == 1)
						   opt.turn = 2;
					   else
						   opt.turn = 1;
				   }
				   if (y == 34 && opt.time > 10)
					   opt.time--;
				   break;
		}
			

		case 27:
		{
				   system("cls");
				   ve_Menu(opt);
				   break;
		}
		default: break;

		}
		

		if (opt.mode == 2)
		{
			gotoxy(60, 28);
			printf("2 Nguoi");
			if (opt.turn == 1)
			{
				gotoxy(60, 32);
				printf("Nguoi choi 1");
			}
			else
			{
				gotoxy(60, 32);
				printf("Nguoi choi 2");
			}
		}
		else
		{
			gotoxy(60, 28);
			printf("1 Nguoi");
			if (opt.turn == 1)
			{
				gotoxy(60, 32);
				printf("Nguoi choi 1");
			}
			else
			{
				gotoxy(60, 32);
				printf("Computer    ");
			}
		}
		gotoxy(60, 36);
		printf("%d", opt.time);

		gotoxy(x, y);
	}
}

void PhimTuyChon(Option &opt, char *s1, char *s2, char c, char **mangGame)
{
	if (c == 27) // Quay lại Menu
	{
		system("cls");
		hoiTruocKhiLuu(opt, s1, s2, mangGame);
		system("cls");
		ve_Menu(opt);
	}
	if (c == 59) //F1: Giúp đỡ
	{
		system("cls");
		ve_GiupDo();
		system("cls");
		ve_GiaoDien(opt, mangGame);
	}
	if (c == 60) //F2: Chơi lại
	{
		system("cls");
		for (int i = 1; i < 21; i++)
		{
			for (int j = 1; j < 21; j++)
				mangGame[i][j] = ' ';
		}
		ve_GiaoDien(opt, mangGame);
		if (opt.mode == 2)
			danh_HaiNguoi(opt, s1, s2, mangGame);
		if (opt.mode == 1)
			danh_VoiMay(opt, s1, mangGame);
	}

	if (c == 61) //F3: Lưu game
	{
		system("cls");
		hoiTruocKhiLuu(opt, s1, s2, mangGame);
		system("cls");
		ve_GiaoDien(opt, mangGame);
	}
	if (c == 62) //F4: Tải game
	{
		system("cls");
		ve_menuTaiGame(opt, s1, s2);
		system("cls");
		ve_GiaoDien(opt, mangGame);
	}
	if (c == 63) //F5: Thông tin
	{
		system("cls");
		ve_GioiThieu();
		system("cls");
		ve_GiaoDien(opt, mangGame);
	}
}

void ThongBaoThang(int x1, int y1, int x2, int y2, int color1, int color2)
{
	Sleep(400);

	gotoxy(x1, y1); printf("       ");
	gotoxy(x2, y2); printf("       ");
	textColor(color1);

	Sleep(400);
	gotoxy(x1, y1); printf("WINNER!");
	textColor(color2);
	gotoxy(x2, y2); printf("LOSER!");
}