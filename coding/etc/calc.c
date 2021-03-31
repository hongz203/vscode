#include <stdio.h>
#include <string.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

char OperatorStack[100];
char OperandStack[100];

int OperatorTop;
int OperandTop;

void InitializeStack(void);
void OperatorPush(char);
void OperandPush(int);
char OperatorPop(void);
int OperandPop(void);
int isEmptyOperatorStack(void);
int isEmptyOperandStack(void);

int GreaterOpr(char, char);
int Calculate(int, int, char);

void main(void)
{
    char buf[80];
    int len, i;
    int opn1, opn2;
    char opr, c;

    InitializeStack();

    //strcpy(buf, "1 + 2 * 3 - 1");
    scanf("%s", buf);

    len = strlen(buf);
    i = 0;
    while(i < len) {
        c = buf[i++];

        if(c == ' ')
            continue;
        else if( c <= '9' && c >= '0') //number
            OperandPush(c - '0');
        else if(c == '+' || c == '-' || c == '*' || c =='/') {
            if(isEmptyOperatorStack())
                OperatorPush(c);
            else {
                opr = OperatorPop();

                if(GreaterOpr(opr, c)) {
                    opn2 = OperandPop();
                    opn1 = OperandPop();
                    opn1 = Calculate(opn1, opn2, opr);
                    OperandPush(opn1);
                    OperatorPush(c);
                }
                else {
                    OperatorPush(opr);
                    OperatorPush(c);
                }
            }
        }
    }

    while(!isEmptyOperatorStack()) {
        opn1 = OperandPop();
        opn2 = OperandPop();
        opr = OperatorPop();
        opn1 = Calculate(opn1, opn2, opr);
        OperandPush(opn1);
    }

    printf("%s = %d\n", buf, OperandPop());
}

void InitializeStack(void)
{
    OperatorTop = 0;
    OperandTop = 0;
}

void OperatorPush(char opr)
{
    OperatorStack[OperatorTop++] = opr;
}

void OperandPush(int opn)
{
    OperandStack[OperandTop++] = opn;
}

char OperatorPop(void)
{
    return OperatorStack[--OperatorTop];
}

int OperandPop(void)
{
    return OperandStack[--OperandTop];
}

int isEmptyOperandStack(void)
{
    if(OperandTop == 0)
        return TRUE;
    else
        return FALSE;
}

int isEmptyOperatorStack(void)
{
    if(OperatorTop == 0)
        return TRUE;
    else
        return FALSE;
}

int GreaterOpr(char opr1, char opr2)
{
    if(opr1 == '*' || opr1 =='/') {
        if(opr2 == '+' || opr2 == '-')
            return TRUE;
        else
            return FALSE;
    }
    else
        return FALSE;
}

int Calculate(int opn1, int opn2, char opr)
{
    switch(opr) {
        case '+' :
            opn1 = opn1 + opn2;
            break;
        case '-' :
            opn1 = opn2 - opn1;
            break;
        case '*' :
            opn1 = opn1 * opn2;
            break;
        case '/':
            opn1 = opn2 / opn1;
            break;
    }

    return opn1;
}