#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef enum {
    lparn = 1, rparn, plus, minus, times, divide, mod, eos, operand
} precedence;

int stack[MAX];
char exprn[MAX], postfix[MAX];
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

precedence getToken(char *symbol, int *n) {
    *symbol = exprn[(*n)++];
    switch(*symbol) {
        case '(': return lparn;
        case ')': return rparn;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '#': return eos;
        default: return operand;
    }
}

precedence getStackToken(char symbol) {
    switch(symbol) {
        case '(': return lparn;
        case ')': return rparn;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '#': return eos;
        default: return operand;
    }
}

void push(int ele, int *top) {
    stack[++(*top)] = ele;
}

int pop(int *top) {
    int ele;
    ele = stack[(*top)--];
    return(ele);
}

void convert(char *exprn, char *postfix) {
    int n = 0, i = 0;
    precedence token;
    char symbol;
    int opr1, opr2;
    int top = -1;
    token = getToken(&symbol, &n);
    while(token != eos) {
        switch(token) {
            case operand:
                postfix[i++] = symbol;
                break;
            case lparn:
                push(symbol, &top);
                break;
            case rparn:
                while(stack[top] != '(')
                    postfix[i++] = pop(&top);
                pop(&top);
                break;
            case plus:
            case minus:
            case times:
            case divide:
            case mod:
                if(top == -1)
                    push(symbol, &top);
                else {
                    while(isp[getStackToken(stack[top])] >= icp[token] && top != -1)
                        postfix[i++] = pop(&top);
                    push(symbol, &top);
                }
                break;
            case eos:
                break;
        }
        token = getToken(&symbol, &n);
    }
    while(top != -1)
        postfix[i++] = pop(&top);
    postfix[i] = '\0';
}

int eval() {
    int n = 0, i, j;
    precedence token;
    char symbol;
    int opr1, opr2;
    int top = -1;
    token = getToken(&symbol, &n);
    while(token != eos) {
        if(token == operand)
            push(symbol - '0', &top);
        else {
            opr2 = pop(&top);
            opr1 = pop(&top);
            switch(token) {
                case plus: push(opr1 + opr2, &top); break;
                case minus: push(opr1 - opr2, &top); break;
                case times: push(opr1 * opr2, &top); break;
                case mod: push(opr1 % opr2, &top); break;
                case divide:
                    if(opr2 != 0)
                        push(opr1 / opr2, &top);
                    else {
                        printf("\nDivide by Zero Error");
                        exit(0);
                    }
                    break;
                case lparn:
                case rparn:
                case eos:
                case operand:
                    break;
            }
        }
        for(j = top; j >= 0; j--)
            printf("\nStack[%d] = %d", j, stack[j]);
        token = getToken(&symbol, &n);
    }
    return pop(&top);
}

int main() {
    char Texprn[MAX];
    printf("\n Enter the Sufix expn\t");
    scanf("%s", exprn);
    strcat(exprn, "#");
    strcpy(Texprn, exprn);
    convert(exprn, postfix);
    strcpy(exprn, postfix);
    strcat(exprn, "#");
    printf("\n Prefix exprn %s", exprn);
    printf("\n After Evaluation of Expression %s is %d", Texprn, eval());
    return 0;
}
