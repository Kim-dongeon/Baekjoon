#include <stdio.h>
#include <stdlib.h>

int main()
{

	//------------정수 값을 가진 변수를 포인터로 가리킴-------------
	int a = 10;
	int *p = &a;

	printf("p : %d\n", p);		//p가 가리키는 변수의 주소 == &a
	printf("&p : %d\n", &p);	//p의 주소
	printf("%%p(&p) : %p\n", &p);	//p의 주소를 16진수로 표현 
	printf("%%p(p) : %p\n", p);	//p가 가리키는 변수의 주소를 16진수로 표현 
	printf("*p : %d\n", *p);	//p가 가리키는 값
	printf("a : %d\n", a);
	printf("&a : %d\n", &a);
	printf("%%p(&a) : %p\n", &a);	//a의 주소를 헥사값으로 표현 


	*p = 39;					//p가 가리키는 값을 변경할 수 있다.
	printf("*p : %d\n", *p);
	printf("a : %d\n", a);

	printf("--------------------\n");

	//포인터 초기화 할 때 문자열 저장 
	char * str = "aaaaa";		//읽기 전용 메모리  -> scanf로 str 값 변경 불가 

	printf("str(%%s) : %s\n",str);
	printf("str(%%d) : %d\n", str);		//str이 가리키고 있는 문자열의 주소를 표현 
	printf("str(%%p) : %p\n", str);
	printf("&str(%d) : %d\n", &str);
	//printf("%s\n", *str);			ERROR!!
	printf("*str : %c\n", *str);
	printf("*(str+1) : %c\n", *(str + 1));


	str = "bbbbb";				//포인터가 가리키는 주소 변경 가능 
	
	printf("str(%%s) : %s\n", str);
	printf("str(%%p) : %p\n", str);
	printf("&str(%%d) : %d\n", &str);
	printf("strlen(str) :%d \n", strlen(str));

	printf("--------------------\n");

	//포인터 초기화를 NULL로
	char *str2 = NULL;
	str2 = "cccc";			//NULL 초기화후 문자열 저장 가능  -> 배열은 strcpy 사용해야함 
	printf("str2(%%s) : %s\n", str2);
	str2 = "dddd";
	printf("%s\n", str2);

	printf("-----------------------\n");
	
	//포인터에 scanf로 문자열 입력 받기 
	char *str3 = NULL;						//계속해서 이 공간에 scanf로 입력받을 수 있다.
	str3 = malloc(sizeof(char) * 10);

	scanf("%s", str3);
	printf("str3 : %s\n", str3);
	printf("strlen(str3) :%d\n", strlen(str3));
	printf("sizeof(str3) : %d\n", sizeof(str3));

	printf("============\n");
	scanf("%s", str3);
	printf("str3 : %s\n", str3);

	printf("-----------------------\n");
	
	//
	char *str4 = malloc(sizeof(char) * 10);
	
	strcpy(str4, "fffff");
	printf("%s 의 주소 %d,  %d\n", str4, str4,&str4);
	str4 = "eeeee";
	printf("%s 의 주소 %d   %d\n", str4, str4,&str4);

	str4 = "ggggg";
	printf("%s 의 주소 %d   %d\n", str4, str4, &str4);
}