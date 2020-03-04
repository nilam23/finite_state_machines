/* ROLL NO: CSB17041 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum
{
	false,
	true
}BOOLEAN;

typedef enum
{
	//STATES OF THE DFA:
	Q0,
	Q1,
	Q2
}STATE;

BOOLEAN check_string(char *str)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!='0'&&str[i]!='1'&&str[i]!='2')
			return false;
	}
	return true;
}

void DFA(STATE *st,char symbol)
{
	if(*st==Q0 && symbol=='1')
	{
		*st=Q1;
		return;
	}
	else if(*st==Q0 && (symbol=='0'||symbol=='2'))
	{
		return;
	}
	if(*st==Q1 && symbol=='1')
	{
		*st=Q2;
		return;
	}
	else if(*st==Q1 && (symbol=='0'||symbol=='2'))
	{
		return;
	}
	if(*st==Q2 && (symbol=='0'||symbol=='1'||symbol=='2'))
	{
		return;
	}
}

int main()
{
	char *input_string;
	input_string=(char *)malloc(100);
	int i;
	BOOLEAN res, final_result;
	STATE st=Q0;
	while(1)
	{
		//ENTERING A STRING FROM USER.
		printf("Enter a string of the symboles 0,1 and 2 only:");
		//gets(input_string);
		scanf("%s", input_string);
		//CHECKING THE STRING FOR EACH SYMBOL.
		res=check_string(input_string);
		if(res==true)
		{
			printf("Input string is correct as it contains the symbols 0,1 and 2 only.\n");
			break;
		}
		else
		{
			printf("Input string is incorrect as it contains symbols other than 0,1 and 2.\n");
			printf("Re-");
			continue;
		}
	}

	//TRANSITION TABLE IS AS SHOWN BELOW:
	/*		'0'	'1'	'2'
		Q0	Q0	Q1	Q0
		Q1	Q1	Q2	Q1
		Q2	Q2	Q2	Q2
	*/
	
	//checking if the input string accepted by the DFA or not.
	for(i=0;i<strlen(input_string);i++)
	{
		if(input_string[i]=='0'||input_string[i]=='1'||input_string[i]=='2')
		{
			DFA(&st,input_string[i]);
			continue;
		}
	}
	if(st==Q2)
		printf("String is accepted by the DFA.\n");
	else
		printf("String is not accepted by the DFA.\n");
	return 0;
}
/*
LANGUAGE IS:
L1={w|w has at least two 1s}
IN THE DFA Q0 IS THE START STATE AND Q2 IS THE FINAL STATE.
TRNSITIONS ARE IMPLEMENTED AS IT IS DESCRIBED IN THE TRANSITION TABLE.
*/