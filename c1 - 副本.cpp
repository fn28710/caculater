#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include<string.h>
#include<time.h>
#include <ctype.h>

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
	}
}
	Sleep(1000);
    return 0;  
}
