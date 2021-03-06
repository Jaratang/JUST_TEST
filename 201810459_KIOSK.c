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
	char product[Max]; //물품정보 입력
	char price[Max]; //가격정보 입력 
};

struct Buy_Product{	//선택한물품정보1 
	char buy_product[Max];
	char buy_price[Max];
};
struct Buy_Product2{ //선택한물품정보2
	char buy_product2[Max];
	char buy_price2[Max];
};
struct Buy_Product3{ //선택한물품정보3
	char buy_product3[Max];
	char buy_price3[Max];
};
struct Buy_Product4{ //선택한물품정보4
	char buy_product4[Max];
	char buy_price4[Max];
};

void Mouse_Control()
{
	int x, y;
	
	
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
	if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
	{
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
	    {
	        x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
	    	y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
	    }
   	} 	
   	system("cls");
    CIN = GetStdHandle(STD_INPUT_HANDLE); //마우스 재활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	Mouse_Check(&x, &y);
}

void Mouse_Check(int *cx, int *cy) //좌표에 따른 실행값 
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
	
	
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
	if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
	{
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
	    {
	        x2 = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
	    	y2 = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
	    }
   	} 	
   	system("cls");
    CIN = GetStdHandle(STD_INPUT_HANDLE); //마우스 재활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	Mouse_Check2(&x2, &y2);
}

void Mouse_Check2(int *dx, int *dy) //좌표에 따른 실행값 
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
	else if(x2 >= 7 && x2 <= 17 && y2 >= 29 && y2 <= 31){ //이전목록 
		if(p == 0){
			p = 0;
			page = 1;
		}		
		else if (p > 0){
			p = p - 3;
			page--;
		}
	}
	
	else if(x2 >= 36 && x2 <= 46 && y2 >= 29 && y2 <= 31){ //다음목록 
		if(p < 6){
			p = p + 3;
			page++;
		}
		else if(p == 6){
			p = 6;
			page = 3;
		}
	}
	
	else if(x2 >= 82 && x2 <= 93 && y2 >= 29 && y2 <= 31){ //결제 
		purchase_Screen();
	}
	else if(x2 == 0 && y2 == 0){
		play = 0;
	}

}

//설정메뉴창 출력
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
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □	                               □     ■ \n");
		printf("■     □              □     □              □                     □        <등록된 사용자>         □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □      사용자를 등록하세요       □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □           <전화번호>           □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □       Tel. 000-0000-0000       □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
	}
	
	else if(sizeof(name) == 20)
	{
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □	                               □     ■ \n");
		printf("■     □              □     □              □                     □        <등록된 사용자>         □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □             %s             □     ■ \n", name);
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □           <전화번호>           □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □       Tel. %s       □     ■ \n", num);
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
	}
		
	fclose(fp);
	fclose(fp1);
}

//물품등록
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
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □   판매할 물품의 이름을 입력    □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □   >>                           □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.product);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □   입력한 물품의 가격을 입력    □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □   >>                           □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
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

//물품정보편집
void Change_Product()
{
	struct Sell_Product SP;
	
	FILE* fp; // 읽어올 파일 
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
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □   수정하고자 하는 물품입력     □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □   >>                           □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.product);
		
		
		while(fgets(buffer, Max, fp) != NULL)
		{		
			token = strstr(buffer, SP.product);	
			if(strstr(buffer, SP.product) == NULL)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
				printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
				printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
				printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
				printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■                                                                   □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □  입력한 물품이 존재하지 않음.. □     ■ \n");
				printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■                                                                   □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");	
				sleep(2);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				fclose(fp);
				play = 0;
				break;
			}
			else
			{
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
				printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
				printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
				printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
				printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □       수정되는 물품입력        □     ■ \n");
				printf("■                                                                   □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □   >>                           □     ■ \n");
				printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■                                                                   □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
				gets(str2);			
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
				printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
				printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
				printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
				printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □   수정한 물품의 가격을 입력    □     ■ \n");
				printf("■                                                                   □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □   >>                           □     ■ \n");
				printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■                                                                   □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
				printf("■     □              □     □              □                     □                                □     ■ \n");
				printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■                                                                                                            ■ \n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
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

//정보초기화
void Reset_A()
{
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	char ask;

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
	printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
	printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
	printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
	printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
	printf("■     □              □     □              □                     □                                □     ■ \n");
	printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
	printf("■     □              □     □              □                     □                                □     ■ \n");
	printf("■     □□□□□□□□□     □□□□□□□□□                     □  초기화 하시겠습니까? >> y/n   □     ■ \n");
	printf("■                                                                   □                                □     ■ \n");
	printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
	printf("■     □              □     □              □                     □   >>                           □     ■ \n");
	printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
	printf("■     □              □     □              □                     □                                □     ■ \n");
	printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
	printf("■                                                                   □                                □     ■ \n");
	printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
	printf("■     □              □     □              □                     □                                □     ■ \n");
	printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
	printf("■     □              □     □              □                     □                                □     ■ \n");
	printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
	scanf("%c", &ask);

	if (ask == 'y')
	{
		remove("Seller_name.txt");
		remove("Seller_num.txt"); 
		remove("Sell_Product.txt");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □         초기화 완료 !!         □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		Sleep(2000);
	}
	else if (ask == 'n')
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □         초기화 취소...         □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		Sleep(2000);
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	play = 0;
}

//총 수익 
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
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □      지금까지의 판매수익       □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		if(price == NULL || price == 0)
			printf("■     □              □     □              □                     □   >> 0 원                      □     ■ \n", price);	
		else 
			printf("■     □              □     □              □                     □   >> %8d 원               □     ■ \n", price);	
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		sleep(2);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		play = 0;
	}
	fclose(fp); 
}

//사용자등록
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
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □  해당기기의 관리자 이름 입력   □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □   >>                           □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(name);
		fprintf(fp = fopen("Seller_name.txt", "w"), "%s", name);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■       ■■■■■     ■■■■■     ■■■■■     ■■■■■     ■■■     ■      ■       ■■■■     ■ \n");
		printf("■     ■               ■                 ■             ■           ■       ■■    ■     ■             ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■           ■       ■  ■  ■     ■    ■■     ■ \n");
		printf("■                 ■   ■                 ■             ■           ■       ■    ■■     ■      ■     ■ \n");
		printf("■       ■■■■■     ■■■■■         ■             ■         ■■■     ■      ■       ■■■       ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □   물품등록   □     □ 물품정보편집 □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □  사용자 전화번호(-포함 입력)   □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □   >>                           □     ■ \n");
		printf("■     □  정보초기화  □     □  총수입확인  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■                                                                   □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □  사용자등록  □     □  시스템실행  □                     □                                □     ■ \n");
		printf("■     □              □     □              □                     □                                □     ■ \n");
		printf("■     □□□□□□□□□     □□□□□□□□□                     □□□□□□□□□□□□□□□□□□     ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■                                                                                                            ■ \n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(num);
		fprintf(fp1 = fopen("Seller_num.txt", "w"), "%s", num);
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp); 
	fclose(fp1);
	play = 0;
}

//실행메뉴창 실행
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
	
	
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                              ■           ■■■     ■■■■■     ■■■■■                             ■ \n");
	printf("■                              ■             ■     ■                   ■                                 ■ \n");
	printf("■                              ■             ■       ■■■■■         ■                                 ■ \n");
	printf("■                              ■             ■                 ■       ■                                 ■ \n");
	printf("■                              ■■■■■   ■■■     ■■■■■         ■                                 ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■     □□□□□□□□□□□□□□□□□□□□                      □□□□□□□□□□□□□□□□□□     ■ \n");
	printf("■     □                                    □                      □                                □     ■ \n");
	if(show2 < 3)
	{
		printf("■     □                                    □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	else if (show1 == 7)
	{
		printf("■     □%s %s                            □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);	
	}
	else if(show1 == 8)
	{		
		printf("■     □%s %s                           □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);	
	}
	else if(show1 == 9)
	{
		printf("■     □%s %s                          □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 10)
	{
		printf("■     □%s %s                         □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 11)
	{
		printf("■     □%s %s                        □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 12)
	{
		printf("■     □%s %s                       □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 13)
	{
		printf("■     □%s %s                      □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 14)
	{
		printf("■     □%s %s                     □                      □          <선택한 물품>         □     ■ \n", SP[p].product, SP[p].price);
	}
	//1번째 칸 
	printf("■     □                                    □                      ");
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
					printf("□%s %s                        □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP[0].buy_product, BP[0].buy_price);	
				}
			}
			else if(check2 == 1) 
			{
				strcpy(BP[1].buy_product, SP[p+1].product);
				strcpy(BP[1].buy_price, SP[p+1].price);
				price1 = atoi(BP[1].buy_price);
					
				if (show2 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP[1].buy_product, BP[1].buy_price);	
				}
			}
			else if(check3 == 1) 
			{
				strcpy(BP[2].buy_product, SP[p+2].product);
				strcpy(BP[2].buy_price, SP[p+2].price);
				price1 = atoi(BP[2].buy_price);
				
				if (show3 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				} 
				else if (show3 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP[2].buy_product, BP[2].buy_price);	
				}
			}
			else
			{
				printf("□                                □     ■ \n");
			}
			check ++;
		}
		
		//2번째 칸 
		printf("■     □□□□□□□□□□□□□□□□□□□□                      ");
		if(check == 1)
		{
			if(check1 == 2)
			{
				strcpy(BP2[0].buy_product2, SP[p].product);
				strcpy(BP2[0].buy_price2, SP[p].price);
				price2 = atoi(BP2[0].buy_price2);
				
				if (show1 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
			}
			else if(check2 == 2)
			{
				strcpy(BP2[1].buy_product2, SP[p+1].product);
				strcpy(BP2[1].buy_price2, SP[p+1].price);
				price2 = atoi(BP2[1].buy_price2);
				
				if (show2 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
			}
			else if(check3 == 2)
			{
				strcpy(BP2[2].buy_product2, SP[p+2].product);
				strcpy(BP2[2].buy_price2, SP[p+2].price);
				price2 = atoi(BP2[2].buy_price2);
				
				if (show3 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
			}
			else
			{
				printf("□                                □     ■ \n");
			}
			check++;
		}
	
		//3번째 칸 
		printf("■                                                                   ");
		if(check == 2)
		{
			if(check1 == 3)
			{
				strcpy(BP3[0].buy_product3, SP[p].product);
				strcpy(BP3[0].buy_price3, SP[p].price);
				price3 = atoi(BP3[0].buy_price3);

				if (show1 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
			}
			else if(check2 == 3)
			{
				strcpy(BP3[1].buy_product3, SP[p+1].product);
				strcpy(BP3[1].buy_price3, SP[p+1].price);
				price3 = atoi(BP3[1].buy_price3);
					
				if (show2 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
			}
			else if(check3 == 3)
			{
				strcpy(BP3[2].buy_product3, SP[p+2].product);
				strcpy(BP3[2].buy_price3, SP[p+2].price);
				price3 = atoi(BP3[2].buy_price3);
				
				if (show3 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
			}
			else
			{
				printf("□                                □     ■ \n"); 
			}
			check++;
		}

		//4번째 줄 
		printf("■     □□□□□□□□□□□□□□□□□□□□                      ");
		if(check == 3)
		{
			if(check1 == 4)
			{
				strcpy(BP4[0].buy_product4, SP[p].product);
				strcpy(BP4[0].buy_price4, SP[p].price);
				price4 = atoi(BP4[0].buy_price4);

				if (show1 == 7)
				{	
					printf("□%s %s                        □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
			}
			else if(check2 == 4)
			{
				strcpy(BP4[1].buy_product4, SP[p+1].product);
				strcpy(BP4[1].buy_price4, SP[p+1].price);
				price4 = atoi(BP4[1].buy_price4);
					
				if (show2 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
			}
			else if(check3 == 4)
			{
				strcpy(BP4[2].buy_product4, SP[p+2].product);
				strcpy(BP4[2].buy_price4, SP[p+2].price);
				price4 = atoi(BP4[2].buy_price4);
					
				if (show3 == 7)
				{
					printf("□%s %s                        □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 8)
				{
					printf("□%s %s                       □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 9)
				{
					printf("□%s %s                      □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 10)
				{
					printf("□%s %s                     □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 11)
				{
					printf("□%s %s                    □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 12)
				{
					printf("□%s %s                   □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 13)
				{
					printf("□%s %s                  □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 14)
				{
					printf("□%s %s                 □     ■ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
			}
			else
			{
				printf("□                                □     ■ \n");
			}
		}
	}
	printf("■     □                                    □                      □                                □     ■ \n");
	if(show2 < 3)
	{
		printf("■     □                                    □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 7)
	{
		printf("■     □%s %s                            □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 8)
	{
		printf("■     □%s %s                           □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 9)
	{
		printf("■     □%s %s                          □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 10)
	{
		printf("■     □%s %s                         □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 11)
	{
		printf("■     □%s %s                        □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 12)
	{
		printf("■     □%s %s                       □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 13)
	{
		printf("■     □%s %s                      □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 14)
	{
		printf("■     □%s %s                     □                      □                                □     ■ \n", SP[p+1].product, SP[p+1].price);
	}
	
	printf("■     □                                    □                      □                                □     ■ \n");
	printf("■     □□□□□□□□□□□□□□□□□□□□                      □                                □     ■ \n");
	printf("■                                                                   □                                □     ■ \n");
	printf("■     □□□□□□□□□□□□□□□□□□□□                      □                                □     ■ \n");
	printf("■     □                                    □                      □                                □     ■ \n");
	if(show3 < 3)
	{
		printf("■     □                                    □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 7)
	{
		printf("■     □%s %s                            □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 8)
	{
		printf("■     □%s %s                           □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 9)
	{
		printf("■     □%s %s                          □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 10)
	{
		printf("■     □%s %s                         □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 11)
	{
		printf("■     □%s %s                        □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}	
	else if(show3 == 12)
	{
		printf("■     □%s %s                       □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 13)
	{
		printf("■     □%s %s                      □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 14)
	{
		printf("■     □%s %s                     □                      □                                □     ■ \n", SP[p+2].product, SP[p+2].price);
	}
	printf("■     □                                    □                      □                                □     ■ \n");
	printf("■     □□□□□□□□□□□□□□□□□□□□                      □□□□□□□□□□□□□□□□□□     ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■    ┌          ┐                 ┌          ┐                                  ┌───────────┐                ■ \n");
	printf("■    │ 이전 목록│        %d        │ 다음 목록│                                  │    결제   │                ■ \n", page);
	printf("■    └          ┘                 └          ┘                                  └───────────┘                ■ \n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");	
	
	fclose(fp);
}
//결제화면
void purchase_Screen()
{
	FILE* fp; // 읽어올 파일 
	fp = fopen("Buy_Product.txt", "r");

	if (fp == NULL)
	{
		fp = fopen("Buy_Product.txt", "w");
	}
	
	price_hap = 0;
	fscanf(fp, "%d", &price_all);
	
	price_hap = price1 + price2 + price3 + price4;	
	price_all = price_all + price_hap;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                              ■           ■■■     ■■■■■     ■■■■■                             ■ \n");
	printf("■                              ■             ■     ■                   ■                                 ■ \n");
	printf("■                              ■             ■       ■■■■■         ■                                 ■ \n");
	printf("■                              ■             ■                 ■       ■                                 ■ \n");
	printf("■                              ■■■■■   ■■■     ■■■■■         ■                                 ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■     □□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                    결제가 완료되었습니다!                                    □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                    총 금액 : %8d                                        □     ■ \n", price_hap);
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □                                                                                              □     ■ \n");
	printf("■     □□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□     ■ \n");
	printf("■                                                                                                            ■ \n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n");
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
