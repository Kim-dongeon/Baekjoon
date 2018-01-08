#include <stdio.h>
#include <stdlib.h>

int main()
{

	//------------���� ���� ���� ������ �����ͷ� ����Ŵ-------------
	int a = 10;
	int *p = &a;

	printf("p : %d\n", p);		//p�� ����Ű�� ������ �ּ� == &a
	printf("&p : %d\n", &p);	//p�� �ּ�
	printf("%%p(&p) : %p\n", &p);	//p�� �ּҸ� 16������ ǥ�� 
	printf("%%p(p) : %p\n", p);	//p�� ����Ű�� ������ �ּҸ� 16������ ǥ�� 
	printf("*p : %d\n", *p);	//p�� ����Ű�� ��
	printf("a : %d\n", a);
	printf("&a : %d\n", &a);
	printf("%%p(&a) : %p\n", &a);	//a�� �ּҸ� ��簪���� ǥ�� 


	*p = 39;					//p�� ����Ű�� ���� ������ �� �ִ�.
	printf("*p : %d\n", *p);
	printf("a : %d\n", a);

	printf("--------------------\n");

	//������ �ʱ�ȭ �� �� ���ڿ� ���� 
	char * str = "aaaaa";		//�б� ���� �޸�  -> scanf�� str �� ���� �Ұ� 

	printf("str(%%s) : %s\n",str);
	printf("str(%%d) : %d\n", str);		//str�� ����Ű�� �ִ� ���ڿ��� �ּҸ� ǥ�� 
	printf("str(%%p) : %p\n", str);
	printf("&str(%d) : %d\n", &str);
	//printf("%s\n", *str);			ERROR!!
	printf("*str : %c\n", *str);
	printf("*(str+1) : %c\n", *(str + 1));


	str = "bbbbb";				//�����Ͱ� ����Ű�� �ּ� ���� ���� 
	
	printf("str(%%s) : %s\n", str);
	printf("str(%%p) : %p\n", str);
	printf("&str(%%d) : %d\n", &str);
	printf("strlen(str) :%d \n", strlen(str));

	printf("--------------------\n");

	//������ �ʱ�ȭ�� NULL��
	char *str2 = NULL;
	str2 = "cccc";			//NULL �ʱ�ȭ�� ���ڿ� ���� ����  -> �迭�� strcpy ����ؾ��� 
	printf("str2(%%s) : %s\n", str2);
	str2 = "dddd";
	printf("%s\n", str2);

	printf("-----------------------\n");
	
	//�����Ϳ� scanf�� ���ڿ� �Է� �ޱ� 
	char *str3 = NULL;						//����ؼ� �� ������ scanf�� �Է¹��� �� �ִ�.
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
	printf("%s �� �ּ� %d,  %d\n", str4, str4,&str4);
	str4 = "eeeee";
	printf("%s �� �ּ� %d   %d\n", str4, str4,&str4);

	str4 = "ggggg";
	printf("%s �� �ּ� %d   %d\n", str4, str4, &str4);
}