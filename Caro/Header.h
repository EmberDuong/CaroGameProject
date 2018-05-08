#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Windows.h"
#include "windows.h"
#include <time.h>
#include <stdlib.h>
#include <wchar.h>

#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_MAGENTA 5
#define DARK_YELLOW 6
#define LIGHT_GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define LIGHT_YELLOW 14
#define WHITE 15

struct Option
{
	int mode;
	int turn;
	int time;
};

void gotoxy(int x, int y);
void textColor(int x);

void ve_Menu(Option a);
void chon_Menu(Option opt);
void Setting(Option &opt);

void ve_GiaoDien(Option opt, char** mangGame);
void ve_BanCo(char** mangGame);
void danhso_Doc(int n);
void danhso_Ngang(int n);
void ve_BienDuoi(int n);
void ve_KeDong(int n);
void ve_Dong(int n);
void ve_BienTren(int n);
void ve_Caro();
void ve_GiupDo();
void ve_GioiThieu();

void ve_ThongBao();
void ve_Nguoi2();
void ve_Nguoi1();
void ve_May();

void danh_VoiMay(Option &opt, char* s1, char** mangGame);
void COM(char *s2, int x, int y, char **mangGame, int &max2, int &luot);
int danhThang(char **mangGame, int ch, int &x, int &y);
int danhPhaTran(char **mangGame, char ch, int x, int y, int &kiemtra);
void danhDau(int n, int x, int y, char **mangGame, int &max2);
int tinhGiaTri(char **a, char ch, int x, int y);
void timDeDanh(int &x, int &y, char **mangGame, char ch);
int vitriTot(char **mangGame, char ch, int &x, int &y);

void nhapten_1Nguoi(char *s1);
void nhapten_2Nguoi(char *s1, char *s2);
void danh_HaiNguoi(Option opt, char* s1, char* s2, char** mangGame);
void Player1(Option &opt, char *s1, char *s2, int &x, int &y, char **mangGame, int &max1);
void Player2(Option &opt, char *s1, char *s2, int &x, int &y, char **mangGame, int &max2);
void PhimTuyChon(Option &opt, char *s1, char *s2, char c, char **mangGame);
void Win(int x, int y, char **mangGame, int &max);
void ThongBaoThang(int x1, int y1, int x2, int y2, int color1, int color2);

char* setFileName();
void saveGame(Option opt, char *s1, char *s2, char **mangGame);
void loadGame(Option &opt, char *s1, char *s2, char *str);
void ve_menuTaiGame(Option opt, char *s1, char *s2);
void hoiTruocKhiLuu(Option opt, char *s1, char *s2, char **mangGame);