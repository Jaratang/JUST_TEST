#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#define Max 100

INPUT_RECORD rec;
DWORD dwNOER, CIN, mode;
int play = 0;
int p = 0;
int page = 1;
int check1 = 0;
int check2 = 0;
int check3 = 0;
int price1 = 0;
int price2 = 0;
int price3 = 0;
int price4 = 0;
int price_hap;
int price_all;



struct Sell_Product{
	char product[Max]; //¹°Ç°Á¤º¸ ÀÔ·Â
	char price[Max]; //°¡°ÝÁ¤º¸ ÀÔ·Â 
};

struct Buy_Product{	//¼±ÅÃÇÑ¹°Ç°Á¤º¸1 
	char buy_product[Max];
	char buy_price[Max];
};
struct Buy_Product2{ //¼±ÅÃÇÑ¹°Ç°Á¤º¸2
	char buy_product2[Max];
	char buy_price2[Max];
};
struct Buy_Product3{ //¼±ÅÃÇÑ¹°Ç°Á¤º¸3
	char buy_product3[Max];
	char buy_price3[Max];
};
struct Buy_Product4{ //¼±ÅÃÇÑ¹°Ç°Á¤º¸4
	char buy_product4[Max];
	char buy_price4[Max];
};

void Mouse_Control()
{
	int x, y;
	
	
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // ÄÜ¼ÖÃ¢ ÀÔ·ÂÀ» ¹Þ¾ÆµéÀÓ.
	if (rec.EventType == MOUSE_EVENT) // ¸¶¿ì½º ÀÌº¥Æ®ÀÏ °æ¿ì
	{
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // ÁÂÃø ¹öÆ°ÀÌ Å¬¸¯µÇ¾úÀ» °æ¿ì
	    {
	        x = rec.Event.MouseEvent.dwMousePosition.X; // X°ª ¹Þ¾Æ¿È
	    	y = rec.Event.MouseEvent.dwMousePosition.Y; // Y°ª ¹Þ¾Æ¿È
	    }
   	} 	
   	system("cls");
    CIN = GetStdHandle(STD_INPUT_HANDLE); //¸¶¿ì½º ÀçÈ°¼ºÈ­
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	Mouse_Check(&x, &y);
}

void Mouse_Check(int *cx, int *cy) //ÁÂÇ¥¿¡ µû¸¥ ½ÇÇà°ª 
{
	int x, y;

	x = *cx;
	y = *cy;
	
	do{
		if(x >= 7 && x <= 24 && y >= 11 && y <= 15){
			play++;
			Sell_Product();
		}
				
		if(x >= 30 && x <= 47 && y >= 11 && y <= 15){
			play++;
			Change_Product();		
		}
			
		if(x >= 7 && x <= 24 && y >= 17 && y <= 21){
			play++;
			Reset_A();	
		}
			
		if(x >= 30 && x <= 47 && y >= 17 && y <= 21){
			play++;
			All_money();
		}
			
		if(x >= 7 && x <= 24 && y >= 23 && y <= 27){
			play++;
			Seller_name();		
		}
				
		if(x >= 30 && x <= 47 && y >= 23 && y <= 27){
			play++;
			List_Consol();	
		}
	}while(play != 0 );
	
	
}

void Mouse_Control2()
{
	int x2, y2;
	
	
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // ÄÜ¼ÖÃ¢ ÀÔ·ÂÀ» ¹Þ¾ÆµéÀÓ.
	if (rec.EventType == MOUSE_EVENT) // ¸¶¿ì½º ÀÌº¥Æ®ÀÏ °æ¿ì
	{
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // ÁÂÃø ¹öÆ°ÀÌ Å¬¸¯µÇ¾úÀ» °æ¿ì
	    {
	        x2 = rec.Event.MouseEvent.dwMousePosition.X; // X°ª ¹Þ¾Æ¿È
	    	y2 = rec.Event.MouseEvent.dwMousePosition.Y; // Y°ª ¹Þ¾Æ¿È
	    }
   	} 	
   	system("cls");
    CIN = GetStdHandle(STD_INPUT_HANDLE); //¸¶¿ì½º ÀçÈ°¼ºÈ­
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	Mouse_Check2(&x2, &y2);
}

void Mouse_Check2(int *dx, int *dy) //ÁÂÇ¥¿¡ µû¸¥ ½ÇÇà°ª 
{
	int x2, y2;

	x2 = *dx;
	y2 = *dy;
	
	if(x2 >= 7 && x2 <= 46 && y2 >= 11 && y2 <= 15){
		if(check1 <= 3)
		{
			check1++;
		}	
	}
		
	else if(x2 >= 7 && x2 <= 46 && y2 >= 17 && y2 <= 21){
		if(check2 <= 3)
		{
			check2++;
		}
	}
		
	else if(x2 >= 7 && x2 <= 46 && y2 >= 23 && y2 <= 27){
		if(check3 <= 3)
		{
			check3++;
		}
	}
	else if(x2 >= 7 && x2 <= 17 && y2 >= 29 && y2 <= 31){ //ÀÌÀü¸ñ·Ï 
		if(p == 0){
			p = 0;
			page = 1;
		}		
		else if (p > 0){
			p = p - 3;
			page--;
		}
	}
	
	else if(x2 >= 36 && x2 <= 46 && y2 >= 29 && y2 <= 31){ //´ÙÀ½¸ñ·Ï 
		if(p < 6){
			p = p + 3;
			page++;
		}
		else if(p == 6){
			p = 6;
			page = 3;
		}
	}
	
	else if(x2 >= 82 && x2 <= 93 && y2 >= 29 && y2 <= 31){ //°áÁ¦ 
		purchase_Screen();
	}
	else if(x2 == 0 && y2 == 0){
		play = 0;
	}

}

//¼³Á¤¸Þ´ºÃ¢ Ãâ·Â
void Setting_Consol()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("Seller_name.txt", "r");
	fp1 = fopen("Seller_num.txt", "r");
	
	char name[20];
	char num[20];
	fgets(name, sizeof(name), fp); 
	fgets(num, sizeof(num), fp1);
	
	if (fp == NULL || sizeof(name) < 5)
	{
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à	                               ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à        <µî·ÏµÈ »ç¿ëÀÚ>         ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à      »ç¿ëÀÚ¸¦ µî·ÏÇÏ¼¼¿ä       ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à           <ÀüÈ­¹øÈ£>           ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à       Tel. 000-0000-0000       ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	}
	
	else if(sizeof(name) == 20)
	{
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à	                               ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à        <µî·ÏµÈ »ç¿ëÀÚ>         ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à             %s             ¡à     ¡á \n", name);
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à           <ÀüÈ­¹øÈ£>           ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à       Tel. %s       ¡à     ¡á \n", num);
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	}
		
	fclose(fp);
	fclose(fp1);
}

//¹°Ç°µî·Ï
void Sell_Product()
{
	struct Sell_Product SP;
	
	FILE* fp;
	fp = fopen("Sell_Product.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};


	if (fp == NULL)
	{
		fp = fopen("Sell_Product.txt", "w");
	}

	else if (fp != NULL)
	{
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à   ÆÇ¸ÅÇÒ ¹°Ç°ÀÇ ÀÌ¸§À» ÀÔ·Â    ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.product);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à   ÀÔ·ÂÇÑ ¹°Ç°ÀÇ °¡°ÝÀ» ÀÔ·Â    ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.price);
		fp = fopen("Sell_Product.txt", "a");
		fputs(SP.product, fp);
		fputs(" ", fp); 
		fputs(SP.price, fp);
		fputs(" ", fp); 
		fputs("\n", fp);
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp); 
	play = 0;
}

//¹°Ç°Á¤º¸ÆíÁý
void Change_Product()
{
	struct Sell_Product SP;
	
	FILE* fp; // ÀÐ¾î¿Ã ÆÄÀÏ 
	fp = fopen("Sell_Product.txt", "r+");

	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	char buffer[Max], *token;
	char str2[Max], str2_price[Max];
	int find_pos; 

	if (fp == NULL)
	{
		fp = fopen("Sell_Product.txt", "w");
	}

	else
	{
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à   ¼öÁ¤ÇÏ°íÀÚ ÇÏ´Â ¹°Ç°ÀÔ·Â     ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.product);
		
		
		while(fgets(buffer, Max, fp) != NULL)
		{		
			token = strstr(buffer, SP.product);	
			if(strstr(buffer, SP.product) == NULL)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				
				printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
				printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
				printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à  ÀÔ·ÂÇÑ ¹°Ç°ÀÌ Á¸ÀçÇÏÁö ¾ÊÀ½.. ¡à     ¡á \n");
				printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");	
				sleep(2);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				fclose(fp);
				play = 0;
				break;
			}
			else
			{
				printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
				printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
				printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à       ¼öÁ¤µÇ´Â ¹°Ç°ÀÔ·Â        ¡à     ¡á \n");
				printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
				printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
				gets(str2);			
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
				printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
				printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
				printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à   ¼öÁ¤ÇÑ ¹°Ç°ÀÇ °¡°ÝÀ» ÀÔ·Â    ¡à     ¡á \n");
				printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
				printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
				printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á                                                                                                            ¡á \n");
				printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
				gets(str2_price);
			
				find_pos = strlen(buffer) - (token - buffer) + 1;
				fseek(fp, (-1)*find_pos, SEEK_CUR);
				fputs(str2, fp);
				fputs(" ", fp);
				fputs(str2_price, fp);
				fputs(" ", fp);
				fputs("\n", fp);
				fseek(fp, find_pos - (strlen(str2) + strlen(str2_price) + 2), SEEK_CUR);
			}
		}
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp);
	play = 0;
}

//Á¤º¸ÃÊ±âÈ­
void Reset_A()
{
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	char ask;

	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
	printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
	printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
	printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
	printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
	printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à  ÃÊ±âÈ­ ÇÏ½Ã°Ú½À´Ï±î? >> y/n   ¡à     ¡á \n");
	printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
	printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
	scanf("%c", &ask);

	if (ask == 'y')
	{
		remove("Seller_name.txt");
		remove("Seller_num.txt"); 
		remove("Sell_Product.txt");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à         ÃÊ±âÈ­ ¿Ï·á !!         ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		Sleep(2000);
	}
	else if (ask == 'n')
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à         ÃÊ±âÈ­ Ãë¼Ò...         ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		Sleep(2000);
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	play = 0;
}

//ÃÑ ¼öÀÍ 
void All_money()
{
	FILE* fp;
	fp = fopen("Buy_Product.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	int price;
	
	if(fp == NULL)
	{
		fp = fopen("Buy_Product.txt", "w");
	}	
	
	else
	{
		fscanf(fp, "%d", &price);
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à      Áö±Ý±îÁöÀÇ ÆÇ¸Å¼öÀÍ       ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		if(price == NULL || price == 0)
			printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >> 0 ¿ø                      ¡à     ¡á \n", price);	
		else 
			printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >> %8d ¿ø               ¡à     ¡á \n", price);	
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		sleep(2);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		play = 0;
	}
	fclose(fp); 
}

//»ç¿ëÀÚµî·Ï
void Seller_name()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("Seller_name.txt", "r");
	fp1 = fopen("Seller_num.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	
	char name[20];
	char num[20];

	if ((fp == NULL))
	{
		fp = fopen("Seller_name.txt", "w");
		fp1 = fopen("Seller_num.txt", "w");
	}

	else
	{
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à  ÇØ´ç±â±âÀÇ °ü¸®ÀÚ ÀÌ¸§ ÀÔ·Â   ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(name);
		fprintf(fp = fopen("Seller_name.txt", "w"), "%s", name);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á¡á     ¡á \n");
		printf("¡á     ¡á               ¡á                 ¡á             ¡á           ¡á       ¡á¡á    ¡á     ¡á             ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á           ¡á       ¡á  ¡á  ¡á     ¡á    ¡á¡á     ¡á \n");
		printf("¡á                 ¡á   ¡á                 ¡á             ¡á           ¡á       ¡á    ¡á¡á     ¡á      ¡á     ¡á \n");
		printf("¡á       ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á             ¡á         ¡á¡á¡á     ¡á      ¡á       ¡á¡á¡á       ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à   ¹°Ç°µî·Ï   ¡à     ¡à ¹°Ç°Á¤º¸ÆíÁý ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à  »ç¿ëÀÚ ÀüÈ­¹øÈ£(-Æ÷ÇÔ ÀÔ·Â)   ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à   >>                           ¡à     ¡á \n");
		printf("¡á     ¡à  Á¤º¸ÃÊ±âÈ­  ¡à     ¡à  ÃÑ¼öÀÔÈ®ÀÎ  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à  »ç¿ëÀÚµî·Ï  ¡à     ¡à  ½Ã½ºÅÛ½ÇÇà  ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à              ¡à     ¡à              ¡à                     ¡à                                ¡à     ¡á \n");
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡à¡à¡à¡à¡à¡à¡à¡à¡à                     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á                                                                                                            ¡á \n");
		printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(num);
		fprintf(fp1 = fopen("Seller_num.txt", "w"), "%s", num);
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp); 
	fclose(fp1);
	play = 0;
}

//½ÇÇà¸Þ´ºÃ¢ ½ÇÇà
void List_Consol()
{	
	struct Buy_Product BP[3];
	struct Buy_Product2 BP2[3];
	struct Buy_Product3 BP3[3];
	struct Buy_Product4 BP4[3];

	Mouse_Control2();
	FILE* fp;
	fp = fopen("Sell_Product.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	
	struct Sell_Product SP[Max];
	int i = 0;
	int idx = 0;
	int check = 0;
	check1 == 0;
	check2 == 0;
	check3 == 0;
	price1 = 0;
	price2 = 0;
	price3 = 0;
	price4 = 0;
	char buffer[Max], *token;
	
	if (fp == NULL)
	{
		fp = fopen("Sell_Product.txt", "w");
	}
	while(!feof(fp))
	{
		i = 0;
		fgets(buffer, Max, fp);
		token = strtok(buffer, " ");
		while (token != NULL)
		{
			if (i == 0)
			{
				strcpy(SP[idx].product, token);
			}
			else if (i == 1)
			{
				strcpy(SP[idx].price, token);
			}
			i++;
			token = strtok(NULL, " ");
		}
		idx++;
	}
	
	int show1 = strlen(SP[p].product) + strlen(SP[p].price);
	int show2 = strlen(SP[p+1].product) + strlen(SP[p+1].price);
	int show3 = strlen(SP[p+2].product) + strlen(SP[p+2].price);
	
	
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                              ¡á           ¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á                             ¡á \n");
	printf("¡á                              ¡á             ¡á     ¡á                   ¡á                                 ¡á \n");
	printf("¡á                              ¡á             ¡á       ¡á¡á¡á¡á¡á         ¡á                                 ¡á \n");
	printf("¡á                              ¡á             ¡á                 ¡á       ¡á                                 ¡á \n");
	printf("¡á                              ¡á¡á¡á¡á¡á   ¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á                                 ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à                      ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
	printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n");
	if(show2 < 3)
	{
		printf("¡á     ¡à                                    ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	else if (show1 == 7)
	{
		printf("¡á     ¡à%s %s                            ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);	
	}
	else if(show1 == 8)
	{		
		printf("¡á     ¡à%s %s                           ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);	
	}
	else if(show1 == 9)
	{
		printf("¡á     ¡à%s %s                          ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 10)
	{
		printf("¡á     ¡à%s %s                         ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 11)
	{
		printf("¡á     ¡à%s %s                        ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 12)
	{
		printf("¡á     ¡à%s %s                       ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 13)
	{
		printf("¡á     ¡à%s %s                      ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 14)
	{
		printf("¡á     ¡à%s %s                     ¡à                      ¡à          <¼±ÅÃÇÑ ¹°Ç°>         ¡à     ¡á \n", SP[p].product, SP[p].price);
	}
	//1¹øÂ° Ä­ 
	printf("¡á     ¡à                                    ¡à                      ");
	if(p == 0 || p == 3 || p == 6)
	{
		if(check == 0)
		{
			if(check1 == 1)
			{
				strcpy(BP[0].buy_product, SP[p].product);
				strcpy(BP[0].buy_price, SP[p].price);
				price1 = atoi(BP[0].buy_price);
				
				if (show1 == 7)
				{	
					printf("¡à%s %s                        ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP[0].buy_product, BP[0].buy_price);	
				}
			}
			else if(check2 == 1) 
			{
				strcpy(BP[1].buy_product, SP[p+1].product);
				strcpy(BP[1].buy_price, SP[p+1].price);
				price1 = atoi(BP[1].buy_price);
					
				if (show2 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP[1].buy_product, BP[1].buy_price);	
				}
			}
			else if(check3 == 1) 
			{
				strcpy(BP[2].buy_product, SP[p+2].product);
				strcpy(BP[2].buy_price, SP[p+2].price);
				price1 = atoi(BP[2].buy_price);
				
				if (show3 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				} 
				else if (show3 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP[2].buy_product, BP[2].buy_price);	
				}
			}
			else
			{
				printf("¡à                                ¡à     ¡á \n");
			}
			check ++;
		}
		
		//2¹øÂ° Ä­ 
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à                      ");
		if(check == 1)
		{
			if(check1 == 2)
			{
				strcpy(BP2[0].buy_product2, SP[p].product);
				strcpy(BP2[0].buy_price2, SP[p].price);
				price2 = atoi(BP2[0].buy_price2);
				
				if (show1 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
			}
			else if(check2 == 2)
			{
				strcpy(BP2[1].buy_product2, SP[p+1].product);
				strcpy(BP2[1].buy_price2, SP[p+1].price);
				price2 = atoi(BP2[1].buy_price2);
				
				if (show2 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
			}
			else if(check3 == 2)
			{
				strcpy(BP2[2].buy_product2, SP[p+2].product);
				strcpy(BP2[2].buy_price2, SP[p+2].price);
				price2 = atoi(BP2[2].buy_price2);
				
				if (show3 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
			}
			else
			{
				printf("¡à                                ¡à     ¡á \n");
			}
			check++;
		}
	
		//3¹øÂ° Ä­ 
		printf("¡á                                                                   ");
		if(check == 2)
		{
			if(check1 == 3)
			{
				strcpy(BP3[0].buy_product3, SP[p].product);
				strcpy(BP3[0].buy_price3, SP[p].price);
				price3 = atoi(BP3[0].buy_price3);

				if (show1 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
			}
			else if(check2 == 3)
			{
				strcpy(BP3[1].buy_product3, SP[p+1].product);
				strcpy(BP3[1].buy_price3, SP[p+1].price);
				price3 = atoi(BP3[1].buy_price3);
					
				if (show2 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
			}
			else if(check3 == 3)
			{
				strcpy(BP3[2].buy_product3, SP[p+2].product);
				strcpy(BP3[2].buy_price3, SP[p+2].price);
				price3 = atoi(BP3[2].buy_price3);
				
				if (show3 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
			}
			else
			{
				printf("¡à                                ¡à     ¡á \n"); 
			}
			check++;
		}

		//4¹øÂ° ÁÙ 
		printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à                      ");
		if(check == 3)
		{
			if(check1 == 4)
			{
				strcpy(BP4[0].buy_product4, SP[p].product);
				strcpy(BP4[0].buy_price4, SP[p].price);
				price4 = atoi(BP4[0].buy_price4);

				if (show1 == 7)
				{	
					printf("¡à%s %s                        ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
			}
			else if(check2 == 4)
			{
				strcpy(BP4[1].buy_product4, SP[p+1].product);
				strcpy(BP4[1].buy_price4, SP[p+1].price);
				price4 = atoi(BP4[1].buy_price4);
					
				if (show2 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
			}
			else if(check3 == 4)
			{
				strcpy(BP4[2].buy_product4, SP[p+2].product);
				strcpy(BP4[2].buy_price4, SP[p+2].price);
				price4 = atoi(BP4[2].buy_price4);
					
				if (show3 == 7)
				{
					printf("¡à%s %s                        ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 8)
				{
					printf("¡à%s %s                       ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 9)
				{
					printf("¡à%s %s                      ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 10)
				{
					printf("¡à%s %s                     ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 11)
				{
					printf("¡à%s %s                    ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 12)
				{
					printf("¡à%s %s                   ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 13)
				{
					printf("¡à%s %s                  ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 14)
				{
					printf("¡à%s %s                 ¡à     ¡á \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
			}
			else
			{
				printf("¡à                                ¡à     ¡á \n");
			}
		}
	}
	printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n");
	if(show2 < 3)
	{
		printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 7)
	{
		printf("¡á     ¡à%s %s                            ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 8)
	{
		printf("¡á     ¡à%s %s                           ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 9)
	{
		printf("¡á     ¡à%s %s                          ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 10)
	{
		printf("¡á     ¡à%s %s                         ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 11)
	{
		printf("¡á     ¡à%s %s                        ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 12)
	{
		printf("¡á     ¡à%s %s                       ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 13)
	{
		printf("¡á     ¡à%s %s                      ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 14)
	{
		printf("¡á     ¡à%s %s                     ¡à                      ¡à                                ¡à     ¡á \n", SP[p+1].product, SP[p+1].price);
	}
	
	printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à                      ¡à                                ¡à     ¡á \n");
	printf("¡á                                                                   ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à                      ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n");
	if(show3 < 3)
	{
		printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 7)
	{
		printf("¡á     ¡à%s %s                            ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 8)
	{
		printf("¡á     ¡à%s %s                           ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 9)
	{
		printf("¡á     ¡à%s %s                          ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 10)
	{
		printf("¡á     ¡à%s %s                         ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 11)
	{
		printf("¡á     ¡à%s %s                        ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}	
	else if(show3 == 12)
	{
		printf("¡á     ¡à%s %s                       ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 13)
	{
		printf("¡á     ¡à%s %s                      ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 14)
	{
		printf("¡á     ¡à%s %s                     ¡à                      ¡à                                ¡à     ¡á \n", SP[p+2].product, SP[p+2].price);
	}
	printf("¡á     ¡à                                    ¡à                      ¡à                                ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à                      ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á    ¦£          ¦¤                 ¦£          ¦¤                                  ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                ¡á \n");
	printf("¡á    ¦¢ ÀÌÀü ¸ñ·Ï¦¢        %d        ¦¢ ´ÙÀ½ ¸ñ·Ï¦¢                                  ¦¢    °áÁ¦   ¦¢                ¡á \n", page);
	printf("¡á    ¦¦          ¦¥                 ¦¦          ¦¥                                  ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                ¡á \n");
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");	
	
	fclose(fp);
}
//°áÁ¦È­¸é
void purchase_Screen()
{
	FILE* fp; // ÀÐ¾î¿Ã ÆÄÀÏ 
	fp = fopen("Buy_Product.txt", "r");

	if (fp == NULL)
	{
		fp = fopen("Buy_Product.txt", "w");
	}
	
	price_hap = 0;
	fscanf(fp, "%d", &price_all);
	
	price_hap = price1 + price2 + price3 + price4;	
	price_all = price_all + price_hap;
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                              ¡á           ¡á¡á¡á     ¡á¡á¡á¡á¡á     ¡á¡á¡á¡á¡á                             ¡á \n");
	printf("¡á                              ¡á             ¡á     ¡á                   ¡á                                 ¡á \n");
	printf("¡á                              ¡á             ¡á       ¡á¡á¡á¡á¡á         ¡á                                 ¡á \n");
	printf("¡á                              ¡á             ¡á                 ¡á       ¡á                                 ¡á \n");
	printf("¡á                              ¡á¡á¡á¡á¡á   ¡á¡á¡á     ¡á¡á¡á¡á¡á         ¡á                                 ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á    ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬    ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                    °áÁ¦°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù!                                    ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                    ÃÑ ±Ý¾× : %8d                                        ¡à     ¡á \n", price_hap);
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à                                                                                              ¡à     ¡á \n");
	printf("¡á     ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à     ¡á \n");
	printf("¡á                                                                                                            ¡á \n");
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	check1 = 0;
	check2 = 0;
	check3 = 0;
	fp = fopen("Buy_Product.txt", "w");
	fprintf(fp, "%d", price_all);
	sleep(2);
	fclose(fp);
}

int main()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	system("mode con:cols=113 lines=34");

	do
	{
		Mouse_Control();
		Setting_Consol();
	}while(play == 0);	

	return 0;
}
