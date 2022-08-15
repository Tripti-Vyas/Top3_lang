#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    char *arr;
    int top;

};

isFull(struct stack *sp)
{
    if(sp->top==sp->size-1)
    return 1;
    else return 0;
}
int isEmpty(struct stack *sp)
{
    if ( sp->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *sp,char c)
{
    if(isFull)
    {
        printf("STACK OVERFLOW!!");
        
    }
    else
    {sp->top++;
    sp->arr[sp->top]=c;}

}

char pop(struct stack *sp)
{
    if(isEmpty(sp))
    {
        printf("STACK UNDERFLOW!!");
        return 0;
    }
    char ch=sp->arr[sp->top];
    sp->top--;
    return ch;
}

int isOperator(char ch)
{
    if(ch == '+ '|| ch ==' - '|| ch ==' * '|| ch ==' /')
    {
        return 1;
    }
    else{
        return 0;
    }
}

char top(struct stack * sp)
{
    return sp->arr[sp->top];
}

int precedence(char ch)
{
    if(ch =='+' || ch =='-')
   return 2;

    else 
    if( ch =='*' || ch =='/')
    return 3;

    else
     return 0;
    
}

char * infixToPostfix (char *infix)
{
    struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
     sp->size=10;
    sp->top=-1;
    sp->arr= (char *)malloc(sizeof((sp->size)*sizeof(char)));
    char * postfix=(char *)malloc(sizeof(strlen((infix)+1) * sizeof(char)));
    int i = 0;
    int j = 0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))   //infix[i] is an operand
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else                         //infix[i] is an operator
        {
            if(precedence(infix[i]>precedence(top(sp))))
            {
                push(sp,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }

      while (!isEmpty(sp))
      {
        postfix[j]=pop(sp);
        j++;
      }
      postfix[j]='\0';          //to make postfix a string 
      
    }
    return postfix;
}


int main()
{
    int size_of_exp;
     scanf("%d",&size_of_exp);
     printf("size of your expression: %d",size_of_exp);
    char * infix = (char*)malloc(sizeof((size_of_exp)*sizeof(char)));
    scanf("%s",&infix);
    printf("INFIX EXPRESSION: %s ",infix);
    infixToPostfix(infix);
    printf("POSTFIX EXPRESSION  : %s",infixToPostfix(infix));
    // char * postfix=(struct stack *)malloc(sizeof((sp->size)*sizeof(char)));
    return 0;
}