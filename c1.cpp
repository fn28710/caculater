#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include<string.h>
#include<time.h>
#include <ctype.h>

void runbadapple();

int main() {  
	float a;
	float b;
	char ch;
	
	
	while(1){
	
	a=0;
	b=0;
	ch=0;
	
	printf("请输入你想要的计算方式\n");
	scanf("%c",&ch);
	printf("请输入第一个数字\n");
	scanf("%f",&a); 
	printf("请输入第二个数字\n"); 
	scanf("%f",&b); 
	
	switch(ch){
		case'+':
		printf("加法的结果是%f\n",a+b); 
		break;
		case'-':
		printf("加法的结果是%f\n",a-b);
		break;
		case'*': 
		printf("加法的结果是%f\n",a*b);
		break;
		case'/': 
		printf("加法的结果是%f\n",a/b); 
		break;		
		case'ba':
		runbadapple();
		break;
	}
}
	Sleep(1000);
    return 0;  
}

void runbadapple()
{
	void recursur();
	int i = 0, caf = 33;
	FILE *fp ;
	clock_t stime = 0, ftime = 0;
	char buf[1920], seat[]="out\\BA (0000).txt", ai[5];	
	printf("-----Bad Apple ASCII art player-----\nPress Enter to play.\n");
	getchar();
	system("cls");
	stime = clock();
	while(i <= 6570)
	{		
		if(i % 30 == 0)
		{
			caf = 43;
		}
		else
		{
			caf = 33;
		}
		strcpy(seat, "out\\BA (");
		sprintf(ai, "%d", i);
		strcat(seat, ai);
		strcat(seat, ").txt");
		ftime = clock();	
		if((ftime - stime) >= caf)
		{
			i++;
			fp = fopen(seat, "r");
			fread(buf, sizeof(buf), 1, fp);
			buf[1920] = '\0';
			fclose(fp);
			fprintf(stdout, "%s", buf);
			fprintf(stdout, "Frame:%d", i);
			stime += caf;
			recursur();	
		}
	}
	system("cls");
	printf("-----Bad Apple ASCII art player-----\nThanks for watching!\nMade by chuan.\n\n");
	printf("Press Enter to Exit.\n");
}

void recursur()
{
	HANDLE hout;	
	COORD coord;	
	coord.X = 0;	
	coord.Y = 0;	
	hout = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleCursorPosition(hout,coord);
}
