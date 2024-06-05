#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <WinBase.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>



#define DIM_X 40
#define DIM_Y 100

#define CHR_PERETE 219
#define CHR_RACHETA_VARF 30
#define CHR_RACHETA_CORP 219
#define CHR_RACHETA_STANGA 17
#define CHR_RACHETA_DREAPTA 16
#define CHR_RACHETA_FUM 176
#define CHR_PASARE 64
#define CHR_GLONT 197
#define CHR_BOSS_CORP 219
#define CHR_BOSS_ARIPA 126
#define CHR_BOSS_PICIOR_STANG 180
#define CHR_BOSS_PICIOR_DREPT 195
#define GRENADE_BODY 'O'

int scena[DIM_X][DIM_Y] = { 0 };
int racheta_x[4][3];
int racheta_y[4][3];
int forma_racheta[4][3];
int boss_x[2][4];
int boss_y[2][4];
int forma_boss[2][4];
int nrgaini = 0;
int nivel = 10;
int dificultate;
int timp=0;
int viata_boss=30;
int grenade_ammo;
int frag_pieces_x[8];
int frag_pieces_y[8];
int frag_stop[8] ;
int score = 1000;
void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoXY(int x, int y)
{
	COORD coord = { y, x };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initializare_nivel1()
{
	for (int j = 20; j< 78; j += 2) 
		scena[13][j] = 7;
	for (int k = 6; k < 78; k += 6)
		scena[13][k] = 0;
}

void initializare_nivel2()
{
	for (int j = 18; j < 79; j += 2)
		scena[13][j] = 7;
	for (int k = 8; k < DIM_Y - 1; k += 8)
		scena[13][k] = 0;
}

void initializare_nivel3()
{
	for (int i = 11; i < 14; i += 2) {
		for (int j = 18; j < 79; j += 2)
			scena[i][j] = 7;
		for (int k = 8; k < DIM_Y - 1; k += 8)
			scena[i][k] = 0;
		
	}
}

void initializare_nivel4()
{
	for (int i = 11; i < 13; i += 2) {
		for (int j = 18; j < 79; j += 2)
			scena[i][j] = 7;
		for (int k = 8; k < DIM_Y - 1; k += 8)
			scena[i][k] = 0;
	}

		for (int i = 13; i < 15; i += 2) {
			for (int j = 18; j < 79; j += 2)
				scena[i][j] = 7;
			for (int k = 6; k < DIM_Y ; k += 6)
				scena[i][k] = 0;
		}
		
	}

void initializare_nivel5()
{
	for (int i = 9; i < 14; i += 2) {
		for (int j = 18; j < 79; j += 2)
			scena[i][j] = 7;
		for (int k = 8; k < DIM_Y - 1; k += 8)
			scena[i][k] = 0;

	}
}

void initializare_nivel6()
{
	for (int i = 9; i < 14; i += 2) {
		for (int j = 16; j < 85; j += 2)
			scena[i][j] = 7;
		for (int k = 10; k < DIM_Y - 1; k += 10)
			scena[i][k] = 0;

	}
}

void initializare_nivel7()
{
	for (int i = 9; i < 11; i += 2) {
		for (int j = 16; j < 85; j += 2)
			scena[i][j] = 7;
		for (int k = 10; k < DIM_Y - 1; k += 10)
			scena[i][k] = 0;
	}
		for (int i = 11; i < 13; i += 2) {
			for (int j = 18; j < 79; j += 2)
				scena[i][j] = 7;
			for (int k = 8; k < DIM_Y - 1; k += 8)
				scena[i][k] = 0;
		}

		for (int i = 13; i < 15; i += 2) {
			for (int j = 18; j < 79; j += 2)
				scena[i][j] = 7;
			for (int k = 6; k < DIM_Y; k += 6)
				scena[i][k] = 0;
		}


	}

void initializare_nivel8()
{
	for (int i = 9; i < 14; i += 2) {
		for (int j = 14; j < 85; j += 2)
			scena[i][j] = 7;
		for (int k = 12; k < DIM_Y - 1; k += 12)
			scena[i][k] = 0;

	}
}

void initializare_nivel9()
{
	for (int i = 7; i < 9; i += 2) {
		for (int j = 14; j < 85; j += 2)
			scena[i][j] = 7;
		for (int k = 12; k < DIM_Y - 1; k += 12)
			scena[i][k] = 0;
	}
		for (int i = 9; i < 11; i += 2) {
			for (int j = 23; j < 82; j += 2)
				scena[i][j] = 7;
			for (int k = 27; k < DIM_Y - 1; k += 12)
				scena[i][k] = 0;
			for (int l = 29; l < DIM_Y - 1; l += 12)
				scena[i][l] = 0;
			for (int m = 31; m < DIM_Y - 1; m += 12)
				scena[i][m] = 0;
			for (int n = 33; n < DIM_Y - 1; n += 12)
				scena[i][n] = 0;
		}
		for (int i = 11; i < 13; i += 2) {
			for (int j = 14; j < 85; j += 2)
				scena[i][j] = 7;
			for (int k = 12; k < DIM_Y - 1; k += 12)
				scena[i][k] = 0;
		}
		for (int i = 13; i < 15; i += 2) {
			for (int j = 23; j < 82; j += 2)
				scena[i][j] = 7;
			for (int k = 27; k < DIM_Y - 1; k += 12)
				scena[i][k] = 0;
			for (int l = 29; l < DIM_Y - 1; l += 12)
				scena[i][l] = 0;
			for (int m = 31; m < DIM_Y - 1; m += 12)
				scena[i][m] = 0;
			for (int n = 33; n < DIM_Y - 1; n += 12)
				scena[i][n] = 0;
		}
		
	}

void initializare_nivel10()
{
	for (int i = 0; i < DIM_X; i++)
		for (int j = 0; j < DIM_Y; j++)
		{
			scena[7][18] = 7;
			scena[7][20] = 7;
			scena[7][22] = 7;
			scena[7][24] = 7;
			scena[9][18] = 7;
			scena[9][25] = 7;
			scena[11][18] = 7;
			scena[11][20] = 7;
			scena[11][22] = 7;
			scena[11][24] = 7;
			scena[13][18] = 7;
			scena[13][25] = 7;
			scena[15][18] = 7;
			scena[15][20] = 7;
			scena[15][22] = 7;
			scena[15][24] = 7;
			scena[7][31] = 7;
			scena[7][33] = 7;
			scena[9][35] = 7;
			scena[9][29] = 7;
			scena[11][29] = 7;
			scena[11][35] = 7;
			scena[13][29] = 7;
			scena[13][35] = 7;
			scena[15][31] = 7;
			scena[15][33] = 7;
			scena[7][40] = 7;
			scena[7][42] = 7;
			scena[7][44] = 7;
			scena[9][39] = 7;
			scena[9][45] = 0;
			scena[11][40] = 7;
			scena[11][42] = 7;
			scena[11][44] = 7;
			scena[13][39] = 0;
			scena[13][45] = 7;
			scena[15][40] = 7;
			scena[15][42] = 7;
			scena[15][44] = 7;
			scena[7][51] = 7;
			scena[7][53] = 7;
			scena[7][55] = 7;
			scena[9][50] = 7;
			scena[9][56] = 0;
			scena[11][51] = 7;
			scena[11][53] = 7;
			scena[11][55] = 7;
			scena[13][50] = 0;
			scena[13][56] = 7;
			scena[15][51] = 7;
			scena[15][53] = 7;
			scena[15][55] = 7;
			scena[7][62] = 7;
			scena[7][64] = 7;
			scena[7][66] = 7;
			scena[9][61] = 7;
			scena[9][67] = 0;
			scena[11][62] = 7;
			scena[11][64] = 7;
			scena[11][66] = 7;
			scena[13][61] = 0;
			scena[13][67] = 7;
			scena[15][62] = 7;
			scena[15][64] = 7;
			scena[15][66] = 7;
			scena[7][73] = 7;
			scena[7][75] = 7;
			scena[7][77] = 7;
			scena[9][72] = 7;
			scena[9][78] = 0;
			scena[11][73] = 7;
			scena[11][75] = 7;
			scena[11][77] = 7;
			scena[13][72] = 0;
			scena[13][78] = 7;
			scena[15][73] = 7;
			scena[15][75] = 7;
			scena[15][77] = 7;
		
		}
}

void initializare_nivel_endless()
{
	for (int j = 4; j < DIM_Y - 5; j += 5)
	{
		scena[2][j] = 7;
		gotoXY(2, j);
		printf("%c", CHR_PASARE);
	}
		
}

void endless_level()
{

	if (timp == 200)
	{
		for (int i = DIM_X - 1; i > 1; i--)
		{
			for (int j = 0; j < DIM_Y; j++)
			{
				if (scena[i][j] == 7)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					scena[i + 3][j] = 7;
					gotoXY(i + 3, j);
					printf("%c", CHR_PASARE);
				}
			}
		}
		for (int j = 4; j < DIM_Y - 5; j += 5)
		{
			scena[2][j] = 7;
			gotoXY(2, j);
			printf("%c", CHR_PASARE);
		}
		timp = 0;
	}
	timp++;

}

void afisare_nivel()
{
	for (int i = 5; i < 17; i += 2) {
		for (int j = 0; j < DIM_Y; j++)
		{
			gotoXY(i, j);
			switch (scena[i][j])
			{
			case 0:
				printf(" ");
				break;
			case 7:
				printf("%c", CHR_PASARE);
				break;

			}
		}
	}
}

void initializeaza_scena()
{
	for (int i = 0; i < DIM_X; i++)
		for (int j = 0; j < DIM_Y; j++)
		{
			if (i == 0 || j == 0 || i == DIM_X - 1 || j == DIM_Y - 1) scena[i][j] = 8; // perete 
			else scena[i][j] = 0;
		}
	
}

void afiseaza_scena()
{for(int i=0;i<DIM_X;i++,printf("\n"))
	for (int j = 0; j < DIM_Y; j++)
	{
		 if (scena[i][j] == 8) printf("%c", CHR_PERETE);
		 if (scena[i][j] == 0) printf(" ");
	}
		 
	
}

void afiseaza_scena_numeral()
{
	for (int i = 0; i < DIM_X; i++, printf("\n"))
		for (int j = 0; j < DIM_Y; j++)
		{
			printf("%d", scena[i][j]);
		}


}

void initializare_racheta() {
	//coordonate racheta pe x

	racheta_x[0][0] = 33;// prima linie din matricea rachetei
	racheta_x[0][1] = 33;
	racheta_x[0][2] = 33;
	racheta_x[1][0] = 34;// a doua linie 
	racheta_x[1][1] = 34;
	racheta_x[1][2] = 34;
	racheta_x[2][0] = 35;// a treia linie 
	racheta_x[2][1] = 35;
	racheta_x[2][2] = 35;
	racheta_x[3][0] = 36;// a patra linie
	racheta_x[3][1] = 36;
	racheta_x[3][2] = 36;

	//coordonate s
	racheta_y[0][0] = DIM_Y/2-2;
	racheta_y[0][1] = DIM_Y/2-1; 
	racheta_y[0][2] = DIM_Y/2; 
	racheta_y[1][0] = DIM_Y / 2 - 2;
	racheta_y[1][1] = DIM_Y / 2-1;
	racheta_y[1][2] = DIM_Y / 2 ;
	racheta_y[2][0] = DIM_Y / 2 - 2;
	racheta_y[2][1] = DIM_Y / 2-1;
	racheta_y[2][2] = DIM_Y / 2 ;
	racheta_y[3][0] = DIM_Y / 2 - 2;
	racheta_y[3][1] = DIM_Y / 2-1;
	racheta_y[3][2] = DIM_Y / 2 ;

	for(int i=0;i<4;i++)
		for (int j = 0; j < 3; j++)
		{
			scena[racheta_x[i][j]][racheta_y[i][j]] = 1;
		}
}

void creeaza_forma()
{

	forma_racheta[0][0] = 0;
	forma_racheta[0][1] = 1;
	forma_racheta[0][2] = 0;
	forma_racheta[1][0] = 0;
	forma_racheta[1][1] = 2;
	forma_racheta[1][2] = 0;
	forma_racheta[2][0] = 3;
	forma_racheta[2][1] = 2;
	forma_racheta[2][2] = 4;
	forma_racheta[3][0] = 0;
	forma_racheta[3][1] = 5;
	forma_racheta[3][2] = 0;
	 
}

void afiseaza_racheta()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++) {
			scena[racheta_x[i][j]][racheta_y[i][j]] = forma_racheta[i][j];
			gotoXY(racheta_x[i][j], racheta_y[i][j]);
			switch (forma_racheta[i][j])
			{
			case 0:
				printf(" ");
				break;
			case 1:
				printf("%c", CHR_RACHETA_VARF);
				break;
			case 2:
				printf("%c", CHR_RACHETA_CORP);
				break;
			case 3:
				printf("%c", CHR_RACHETA_STANGA);
				break;
			case 4:
				printf("%c", CHR_RACHETA_DREAPTA);
				break;
			case 5:
				printf("%c", CHR_RACHETA_FUM);
				break;
			}
		}
}

void initializare_glont()
{
	scena[racheta_x[0][1] - 1][racheta_y[0][1]] = 6;
}

void miscare_glont()
{
	for (int i = 1; i < DIM_X; i++)
		for (int j = 0; j < DIM_Y; j++)
		{
			if (scena[i][j] == 6)
			{
				if (i == 1)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
				}
				if (scena[i - 1][j] == 0)
				{
					scena[i][j] = 0;
					scena[i - 1][j] = 6;
					gotoXY(i, j);
					printf(" ");
					gotoXY(i - 1, j);
					printf("%c", CHR_GLONT);
				}
				else if (scena[i - 1][j] == 9)
				{
					scena[i][j] = 0;
					scena[i - 1][j] = 0;
					gotoXY(i, j);
					printf(" ");
					gotoXY(i - 1, j);
					printf(" ");
				}
				else if (scena[i - 1][j] == 7)
				{
					scena[i][j] = 0;
					scena[i - 1][j] = 0;
					gotoXY(i, j);
					printf(" ");
					gotoXY(i - 1, j);
					printf(" ");
					score += 5;
				}
				else if (scena[i-1][j]==11 || scena[i - 1][j]==12 || scena[i - 1][j]==13 || scena[i - 1][j]==14 )
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					viata_boss--;
					
				}
			}

		}

}

void initializare_glont_dublu()
{
	scena[racheta_x[0][0] - 1][racheta_y[0][0]] = 6;
	scena[racheta_x[0][2] - 1][racheta_y[0][2]] = 6;
}

void miscare_stanga()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			scena[racheta_x[i][j]][racheta_y[i][j]] = 0;
			gotoXY(racheta_x[i][j], racheta_y[i][j]);
			printf(" ");
		}
	for(int i=0;i<4;i++)
		for (int j = 0; j < 3; j++)
		{
		racheta_y[i][j]--;
		}
	afiseaza_racheta();
}

void miscare_dreapta()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			scena[racheta_x[i][j]][racheta_y[i][j]] = 0;
			gotoXY(racheta_x[i][j], racheta_y[i][j]);
			printf(" ");
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			racheta_y[i][j]++;
		}
	afiseaza_racheta();
}

void genereaza_oo()
{
	for (int j = 0; j < DIM_Y; j++)
	{
		int i = rand() % DIM_Y;
		if ( scena[i][j] == 7 || scena[i][j]==13 || scena[i][j]==14 )
		{
			scena[i+1][j]=9;
			gotoXY(i + 1, j);
			printf("o");
		}
	}
}
void get_grenade_ammo()
{
	if (score >= 200 && grenade_ammo < 3)
	{
		score -= 200;
		grenade_ammo++;
	}
}
void seteaza_grenada()
{
	if (grenade_ammo != 0)
	{
		scena[racheta_x[0][1] - 1][racheta_y[0][1]] = 15;
		gotoXY(racheta_x[0][1] - 1, racheta_y[0][1]);
		printf("%c", (char)GRENADE_BODY);
	}
	grenade_ammo--;

}

void misca_grenada()
{
	for (int i = 0; i < DIM_X; i++)
	{
		for (int j = 0; j < DIM_Y; j++)
		{
			if (scena[i][j] == 15)
			{
				if (scena[i - 1][j] == 7 )
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					for (int r = 0; r < 8; r++)
					{
						frag_pieces_x[r] = i;
						frag_pieces_y[r] = j;
						frag_stop[r] = 0;
						scena[i][j] = 16;
					}

				}
				if (scena[i - 1][j] == 0)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					scena[i - 1][j] = 15;
					gotoXY(i - 1, j);
					printf("%c", (char)GRENADE_BODY);
				}
				if (scena[i - 1][j] == 8 || scena[i - 1][j] == 11 || scena[i - 1][j] == 12 || scena[i - 1][j] == 13 || scena[i - 1][j] == 14)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					for (int r = 0; r < 5; r++)
					{
						frag_pieces_x[r] = i;
						frag_pieces_y[r] = j;
						frag_stop[r] = 0;
						scena[i][j] = 16;
					}
				}

			}
		}
	}
}
void imprastie_fragmente() {
	int ok = 0;
	for (int i = 0; i < DIM_X; i++) {
		for (int j = 0; j < DIM_Y; j++) {
			if (scena[i][j] == 16) ok = 1;
		}
	}
	if (ok) {
		for (int i = 0; i < DIM_X; i++) {
			for (int j = 0; j < DIM_Y; j++) {
				if (scena[i][j] == 16 && (scena[i - 1][j] == 11 || scena[i - 1][j] == 12 || scena[i - 1][j] == 13 || scena[i - 1][j] == 14)) {
					for (int r = 0; r < 5; r++) {
						scena[frag_pieces_x[r]][frag_pieces_y[r]] = 0;
						gotoXY(frag_pieces_x[r], frag_pieces_y[r]);
						printf(" ");
						frag_pieces_x[0]++;
						frag_pieces_y[0]--;
						frag_pieces_x[1]++;
						frag_pieces_x[2]++;
						frag_pieces_y[2]++;
						frag_pieces_y[3]--;
						frag_pieces_y[4]++;
						frag_pieces_x[5]--;
						frag_pieces_y[5]--;
					}
				}
				else if (scena[i][j] == 16 && (scena[i - 1][j] == 0 || scena[i - 1][j] == 7)) {
					for (int r = 0; r < 8; r++) {
						scena[frag_pieces_x[r]][frag_pieces_y[r]] = 0;
						gotoXY(frag_pieces_x[r], frag_pieces_y[r]);
						printf(" ");
						frag_pieces_x[0]++;
						frag_pieces_y[0]--;
						frag_pieces_x[1]++;
						frag_pieces_x[2]++;
						frag_pieces_y[2]++;
						frag_pieces_y[3]--;
						frag_pieces_y[4]++;
						frag_pieces_x[5]--;
						frag_pieces_y[5]--;
						frag_pieces_x[6]--;
						frag_pieces_x[7]--;
						frag_pieces_y[7]++;
					}
				}
				for (int k = 0; k < 8; k++) {
					// Verific?m limitele înainte de a accesa array-ul scena
					if (frag_pieces_x[k] >= 0 && frag_pieces_x[k] < DIM_X && frag_pieces_y[k] >= 0 && frag_pieces_y[k] < DIM_Y) {
						if (scena[frag_pieces_x[k]][frag_pieces_y[k]] == 7) {
							scena[frag_pieces_x[k]][frag_pieces_y[k]] = 0;
							gotoXY(frag_pieces_x[k], frag_pieces_y[k]);
							printf(" ");
							score += 5;
						}
						if (scena[frag_pieces_x[k]][frag_pieces_y[k]] == 11 || scena[frag_pieces_x[k]][frag_pieces_y[k]] == 12 || scena[frag_pieces_x[k]][frag_pieces_y[k]] == 13 || scena[frag_pieces_x[k]][frag_pieces_y[k]] == 14) {
							viata_boss -= 5;
							frag_stop[k] = 1;
						}
						if (scena[frag_pieces_x[k]][frag_pieces_y[k]] == 0) {
							scena[frag_pieces_x[k]][frag_pieces_y[k]] = 16;
							gotoXY(frag_pieces_x[k], frag_pieces_y[k]);
							printf("*");
							frag_stop[k] = 1;
						}
						else {
							frag_stop[k] = 1;
						}
					}
				}
			}
		}
	}
}

void misca_oo()
{
	for(int i=DIM_X-2;i>=1;i--)
		for (int j = 0; j < DIM_Y; j++)
		{
			if (scena[i][j] == 9)
			{
				if (i == DIM_X - 2)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
				}
				if (scena[i + 1][j] == 7)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					int k = i;
					while (scena[k + 1][j] == 7)
					{
						k++;
					}
					scena[k+1][j] = 9;
					gotoXY(k+1, j);
					printf("o");
				}
				else if (scena[i + 1][j] == 0)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					scena[i + 1][j] = 9;
					gotoXY(i + 1, j);
					printf("o");

				}
				else if (scena[i + 1][j] == 1 || scena[i + 1][j] == 3 || scena[i + 1][j] == 4)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							scena[racheta_x[i][j]][racheta_y[i][j]] = 0;
							gotoXY(racheta_x[i][j], racheta_y[i][j]);
							printf(" ");
						}
					}
				}
			}
		}
}

void sterge_boss()
{
	if (viata_boss == 0)
	{
		for(int i=0;i<DIM_X;i++)
			for (int j = 0; j < DIM_Y; j++)
			{
				if (scena[i][j] == 11 || scena[i][j] == 12 || scena[i][j] == 13 || scena[i][j] == 14)
				{
					scena[i][j] = 0;
					gotoXY(i, j);
					printf(" ");
				}
			}
	}
}

void verifica_tastele()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 75:
			if(scena[racheta_x[0][0]][racheta_y[0][0]-1]!=8)
			miscare_stanga();
			break;
		case 77:
			if (scena[racheta_x[0][2]][racheta_y[0][2] + 1] != 8) 
			miscare_dreapta();
			break;
		case 'z':
			initializare_glont();
			break;
		case 'x':
			if (nivel >= 3)
				initializare_glont_dublu();
			break;
		case ' ':
			while (_getch() != ' ') {}
			break;
		case 27:
			system("cls");
			exit(0);
			break;
		case 'b':
			get_grenade_ammo();
			break;
		case 'c':
			seteaza_grenada();
			break;
		}
	}
}

void initializare_boss()
{
	boss_x[0][0] = 3;//prima linie din matricea bossului
	boss_x[0][1] = 3;
	boss_x[0][2] = 3;
	boss_x[0][3] = 3;
	boss_x[1][0] = 4;//a doua linie
	boss_x[1][1] = 4;
	boss_x[1][2] = 4;
	boss_x[1][3] = 4;
	

	boss_y[0][0] = DIM_Y / 2 - 1;//pozitiile pe coordonata lui y
	boss_y[0][1] = DIM_Y / 2;
	boss_y[0][2] = DIM_Y / 2 + 1;
	boss_y[0][3] = DIM_Y / 2 + 2;
	boss_y[1][0] = DIM_Y / 2 - 1;
	boss_y[1][1] = DIM_Y / 2;
	boss_y[1][2] = DIM_Y / 2 + 1;
	boss_y[1][3] = DIM_Y / 2 + 2;

}

void creeaza_boss()
{
	forma_boss[0][0] = 12;
	forma_boss[0][1] = 11;
	forma_boss[0][2] = 11;
	forma_boss[0][3] = 12;
	forma_boss[1][0] = 0;
	forma_boss[1][1] = 13;
	forma_boss[1][2] = 14;
	forma_boss[1][3] = 0;

}

void afisare_boss()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			scena[boss_x[i][j]][boss_y[i][j]] = forma_boss[i][j];
			gotoXY(boss_x[i][j], boss_y[i][j]);
			switch (forma_boss[i][j])
			{
			case 0:
				printf(" ");
				break;
			case 11:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c", CHR_BOSS_CORP);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case 12:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c", CHR_BOSS_ARIPA);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case 13:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c", CHR_BOSS_PICIOR_STANG);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case 14:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c", CHR_BOSS_PICIOR_DREPT);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			}
		}
}

void miscare_stanga_boss()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			scena[boss_x[i][j]][boss_y[i][j]] = 0;
			gotoXY(boss_x[i][j], boss_y[i][j]);
			printf(" ");
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			boss_y[i][j]--;
		}
	afisare_boss();
}

void miscare_boss_dreapta()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			scena[boss_x[i][j]][boss_y[i][j]] = 0;
			gotoXY(boss_x[i][j], boss_y[i][j]);
			printf(" ");
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			boss_y[i][j]++;
		}
	afisare_boss();
}

void miscare_boss()
{
	int x = (rand() % 2) + 1;
	switch (x)
	{
	case 1:
		if (scena[boss_x[0][0]][boss_y[0][0] - 1] != 8)
		miscare_stanga_boss();
		break;
	case 2:
		if (scena[boss_x[0][3]][boss_y[0][3] + 1] != 8)
		miscare_boss_dreapta();
		break;
	}
}

void selecteaza_nivel()
{
	switch (nivel)
	{
	case 1:
	{
		initializare_nivel1();
		afisare_nivel();
		break;
	}
	case 2:
	{
		initializare_nivel2();
		afisare_nivel();
		break;
	}
	case 3:
	{
		initializare_nivel3();
		afisare_nivel();
		break;
	}
	case 4:
	{

		initializare_nivel4();
		afisare_nivel();
		break;
	}
	case 5:
	{

		initializare_nivel5();
		afisare_nivel();
		break;
	}
	case 6:
	{

		initializare_nivel6();
		afisare_nivel();
		break;
	}
	case 7:
	{

		initializare_nivel7();
		afisare_nivel();
		break;
	}
	case 8:
	{

		initializare_nivel8();
		afisare_nivel();
		break;
	}
	case 9:
	{

		initializare_nivel9();
		afisare_nivel();
		break;
	}
	case 10:
	
		
		initializare_nivel10();
		afisare_nivel();
		initializare_boss();
		creeaza_boss();
		afisare_boss();
		break;
	
	case 11:
	
		initializare_nivel_endless();
		afisare_nivel();
		endless_level();
		break;
	
	}
}

bool joc_pierdut()
{
	for (int j = 0; j < DIM_Y; j++)
	{
		if (scena[33][j] == 1 || scena[33][j] == 7)
			return false;
	}
	
	return true;
}

bool nivel_complet()
{
	for (int i = 0; i < DIM_X; i++)
	{
		for (int j = 0; j < DIM_Y; j++)
		{
			if (scena[i][j] == 7 || scena[i][j] == 11 || scena[i][j] == 12 || scena[i][j] == 13 || scena[i][j] == 14)
			{
				return false;
			}
		}
	}
	return true;
}


void meniu()
{
	printf("*** CHICKEN INVADERS ***");
	printf("\n\n\nALEGE DIFICULTATEA:\n\n");
	printf("1. USOR\n");
	printf("2. MEDIU\n");
	printf("3. GREU\n");
	printf("4. IMPOSIBIL");

	char op;
	op = _getch();
	switch (op)
	{
	case '1':
	{
		dificultate = 60;
		break;
	}
	case '2':
	{
		dificultate = 250;
		break;
	}
	case '3':
	{
		dificultate = 450;
		break;
	}
	case '4':
	{
		dificultate = 900;
		break;
	}
	}


}


void main()
{ 
	
	fullscreen();
	hidecursor();
	srand(time(NULL));
	meniu();

	while (true)
	{
		system("cls");
		hidecursor();
		initializeaza_scena();
		afiseaza_scena();
		selecteaza_nivel();
		initializare_racheta();
		creeaza_forma();
		afiseaza_racheta();
		//afiseaza_scena_numeral();

		while (joc_pierdut()==false && nivel_complet()==false)
		{

			for (int i = 0; i < 1000-dificultate; i++)
			{
				Sleep(0.5);
				verifica_tastele();
				
			}
			if (rand() % 7== 0)
			{
				genereaza_oo();
			}
			misca_oo();
			miscare_glont();
			misca_grenada();
			
			
				imprastie_fragmente();
			
			
			if (nivel == 10) 
			{
				miscare_boss();
				sterge_boss();
			}
			if (nivel == 11)
			{
				endless_level();
			}
			gotoXY(41, 0);
			printf("Press b to buy grenades - 200 score\n");
			printf("AMMO:           ");
			gotoXY(42, 6);
			for (int i = 0; i < grenade_ammo; i++)
			{
				printf("%c ", 219);
			}
			gotoXY(44, 0);
			printf("SCORE:          ");
			gotoXY(44, 0);
			printf("SCORE: %4d",score);
			
			
		}
		if (joc_pierdut() == true)
		{
			system("cls");
			gotoXY(25, 50);
			printf("GAME OVER");
			exit(0);
		}
		
		nivel++;
	}
	
}