#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct    //������
{
	int a[MAX];
	int top;
}OPND;

typedef struct    //�����
{
	char a[MAX];
	int top;
}OPTR;

void Init_OPND(OPND *s); //��ʼ��������ջ 
void Push_OPND(OPND *s, int x); //pushһ�������� 
int Pop_OPND(OPND *s); //popһ�������� 
int GetTop_OPND(OPND *s); //ȡջ�������� 
void Init_OPTR(OPTR *s); //��ʼ�������ջ 
void Push_OPTR(OPTR *s, char x); //pushһ������� 
char Pop_OPTR(OPTR *s); //popһ������� 
char GetTop_OPTR(OPTR *s); //ȡջ������� 
int IsOpr(char c); //�ж������ַ��Ƿ�Ϊ����� 
char Precede(char s, char c); //�ж��ַ������ȼ� 
int Operate(int x, char opr, int y); //����

void Init_OPND(OPND *s)    //��ʼ��������ջ

{
	s->top = -1;
}


void Init_OPTR(OPTR *s)   //��ʼ�������ջ

{
	s->top = -1;
}

void Push_OPND(OPND *s, int x)   //pushһ��������

{
	s->top++;
	s->a[s->top] = x;
}


void Push_OPTR(OPTR *s, char x)   //pushһ�������

{
	s->top++;
	s->a[s->top] = x;
}


int Pop_OPND(OPND *s)     //popһ��������
{
	int x;
	x = s->a[s->top];
	s->top--;
	return x;
}


char Pop_OPTR(OPTR *s)    //popһ�������

{
	char x;
	x = s->a[s->top];
	s->top--;
	return x;
}


int GetTop_OPND(OPND *s) //ȡջ��������

{
	return (s->a[s->top]);
}


char GetTop_OPTR(OPTR *s)   //ȡջ�������

{
	return (s->a[s->top]);
}

int IsOpr(char c)   //�ж������ַ��Ƿ�Ϊ����� 
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')
		return 1;
	else
		return 0;
}


char Precede(char s, char c) //�ж��ַ������ȼ� 
{
	switch (s)
	{
	case '+':
	case '-':
	{
		if (c == '+' || c == '-')
			return '>';
		else if (c == '*' || c == '/')
			return '<';
		else if (c == '(')
			return '<';
		else if (c == ')')
			return '>';
		else
			return '>';
	}
	break;

	case '*':
	case '/':
	{
		if (c == '+' || c == '-')
			return '>';
		else if (c == '*' || c == '/')
			return '>';
		else if (c == '(')
			return '<';
		else if (c == ')')
			return '>';
		else
			return '>';
	}
	break;

	case '(':
	{
		if (c == ')')
			return '=';
		else
			return '<';
	}
	break;


	case ')':
	{
		return '>';
	}
	break;


	case '#':
	{
		if (c == '#')
			return '=';
		else
			return '<';

	}
	break;
	}
}


int Operate(int x, char opr, int y)   //����
{
	int result;
	switch (opr)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	}
	return result;
}


void main()
{
	OPND sdata;
	OPTR soper;
	int a, b, result, i;
	char ch, theta;
	Init_OPND(&sdata);
	Init_OPTR(&soper);
	Push_OPTR(&soper, '#');
	ch = getchar();
	while (ch != '#' || GetTop_OPTR(&soper) != '#') //��������ַ���OPTRջ�����ַ���Ϊ��#��ʱ��������
	{
		if (!IsOpr(ch))                           //�������������
		{
			i = atoi(&ch);                           //���ַ���תΪ����
			ch = getchar();                           //ʹ�ÿ������뼸λ��
			while (!IsOpr(ch))
			{
				i = i * 10 + atoi(&ch);
				ch = getchar();
			}
			Push_OPND(&sdata, i);
		}
		else
		{
			switch (Precede(GetTop_OPTR(&soper), ch))    //�Ƚ�ջ��������͸���������������ȼ�
			{

			case '<':
				Push_OPTR(&soper, ch);
				ch = getchar();
				break;

			case '=':
				theta = Pop_OPTR(&soper);
				ch = getchar();
				break;

			case '>':
				theta = Pop_OPTR(&soper);
				b = Pop_OPND(&sdata);
				a = Pop_OPND(&sdata);
				result = Operate(a, theta, b);
				Push_OPND(&sdata, result);
				break;
			}
		}
	}
	printf("%d", GetTop_OPND(&sdata));
}
