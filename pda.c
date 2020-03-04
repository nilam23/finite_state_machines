/* ROLL NO: CSB17041 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;

void create_emptyStack()
{
	top++;
	stack[top]='z';
}

int isFull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(char symbol)
{
	if(isFull())
	{
		printf("Stack is Full.\n");
		return;
	}
	top++;
	stack[top]=symbol;
}

char pop()
{
	char temp;
	if(isEmpty())
	{
		printf("Stack is Empty.\n");
		exit(1);
	}
	temp=stack[top];
	top--;
	return temp;
}

typedef enum
{
	false,
	true
}BOOLEAN;

typedef enum
{
	//STATES OF THE PDA ARE:
	Q0,
	Q1
	//WHERE Q0 IS THE INITIAL STATE AND Q1 IS THE FINAL STATE.
}STATE;

BOOLEAN check(char *str)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!='0'&&str[i]!='1')
			return false;
	}
	return true;
}

BOOLEAN PDA(char *str)
{
	create_emptyStack();
	STATE st=Q0;
	int i;
	for(i=0;i<strlen(str);i++)
	{
		switch(str[i])
		{
			case '0':
				if(stack[top]=='z')
				{
					st=Q0;
					push('0');
					continue;
				}
				else if(stack[top]=='0')
				{
					st=Q0;
					push('0');
					continue;
				}
				else if(stack[top]=='1')
				{
					st=Q0;
					pop();
					continue;
				}
			case '1':
				if(stack[top]=='z')
				{
					st=Q0;
					push('1');
					continue;
				}
				else if(stack[top]=='1')
				{
					st=Q0;
					push('1');
					continue;
				}
				else if(stack[top]=='0')
				{
					st=Q0;
					pop();
					continue;
				}
		}
	}
	if(stack[top]=='z')
		st=Q1;
	if(st==Q1)
		return true;
	else
		return false;
}

int main()
{
	char *input_str;
	input_str=(char *)malloc(100);
	BOOLEAN res;
	while(1)
	{
		//ENTERING STRING FROM THE USER
		printf("Enter a string of the symbols 0 and 1 only:");
		//gets(input_str);
		scanf("%s", input_str);
		//CHECKING THE STRING FOR EACH SYMBOL
		res=check(input_str);
		if(res==true)
		{
			printf("Input string is correct as it contains 0s and 1s only.\n");
			break;
		}
		else
		{
			printf("Input string is incorrect as it contains symbols other than 0s and 1s.\n");
			printf("Re-");
			continue;
		}
	}
	if(PDA(input_str))
		printf("The input string is accepted by the Push Down Automata.\n");
	else
		printf("The input string is not accepted by the Push Down Automata.\n");

	return 0;
}

/*
LANGUAGE IS:
L2={w|w has equal no of 0s and 1s.}
TRANSITIONS ARE IMPLEMENTED USING SWITCH CASE IN C.
OUT START STATE IS Q0.
1. WHEN INPUT SYMBOL IS 0 AND TOP OF THE STACK IS Z, WE PUSH 0 ONTO THE STACK, AND WE REMAIN IN THE STATE Q0.
2. WHEN INPUT SYMBOL IS 1 AND TOP OF THE STACK IS Z, WE PUSH 1 ONTO THE STACK, AND WE REMAIN IN THE STATE Q0.
3. WHEN INPUT SYMBOL IS 0 AND TOP OF THE STACK IS 0, WE PUSH 0 ONTO THE STACK, AND WE REMAIN IN THE STATE Q0.
4. WHEN INPUT SYMBOL IS 1 AND TOP OF THE STACK IS 1, WE PUSH 1 ONTO THE STACK, AND WE REMAIN IN THE STATE Q0.
5. WHEN INPUT SYMBOL IS 0 AND TOP OF THE STACK IS 1, WE POP 1 FROM THE STACK, AND WE REMAIN IN THE STATE Q0.
6. WHEN INPUT SYMBOL IS 1 AND TOP OF THE STACK IS 0, WE POP 1 FROM THE STACK, AND WE REMAIN IN THE STATE Q0.
7. AFTER READING ALL THE CHARACTERS FROM THE STRING, WITHOUT SEEING ANY SYMBOL WE GO TO THE STATE Q1, WHICH IS THE FINAL STATE OF THE PDA, AND THE STACK REMAINS WITH ONLY Z.
*/