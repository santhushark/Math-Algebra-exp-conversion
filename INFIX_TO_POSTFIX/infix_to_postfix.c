INFIX TO POSTFIX

//function headers and macros
#include<stdio.h>
#include<string.h>
#define sz 20
char output[sz];
char stk[sz];
int check_precedence(char);
int re_evaluate(void);
int c=0,tos=-1;
int main()
{
    int i=0,status;
    char exp[sz];
    printf("\nEnter the INFIX expression\n");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
	   // pushing the character to output array if it is an alphabet
        if(exp[i]>='A' && exp[i]<='z')
        {
            output[c]=exp[i];
            c++;
            i++;
        }	
	   //pushing the character to stack if it is an operator  	
        else
        {
		//function call for precedency check in the stack
            status=check_precedence(exp[i]);
            if(status==0)
            {
                output[c]=stk[tos];
                stk[tos]=exp[i];
                c++;
                i++;
            }
            else if(status==1)
            {
                tos++;
                stk[tos]=exp[i];
                i++;
            }
            else if(status==2)
            {
                while(stk[tos]!='(')
                {
                    output[c]=stk[tos];
                    tos--;
                    c++;
                }
                tos--;
                i++;
            }
        }
        if(tos>0)
        {
		//function call for re-checking precedency if tos>0
            while((status=re_evaluate())!=1)
            {
                output[c]=stk[tos];
                c++;
                tos--;
            }
        }
    }
    //popping out remaining operators from stack onto the output array
    while(tos>=0)
    {
        output[c]=stk[tos];
        tos--;
        c++;
    }
    output[c]='\0';
    printf("\nThe POSTFIX expression is: %s\n",output);
    return 0;
}
//function body for precedency check
int check_precedence(char o)
{
    if(tos==-1)
    {
        return 1;
    }
    else if(o=='+' || o=='-')
    {
        if(stk[tos]=='(')
        {
            return 1;
        }
        else if(stk[tos]=='+' || stk[tos]=='-' || stk[tos]=='/' || stk[tos]=='*')
        {
            return 0;
        }
    }
    else if(o=='/' || o=='*')
    {
        if(stk[tos]=='(')
        {
            return 1;
        }
        else if(stk[tos]=='/' || stk[tos]=='*')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(o=='(')
    {
        return 1;
    }
    else if(o==')')
    {
        return 2;
    }
}
//function body to re-check precedency
int re_evaluate(void)
{
    if(tos==0)
    {
        return 1;
    }
    else if(stk[tos]=='+' || stk[tos]=='-')
    {
        if(stk[tos-1]=='+' || stk[tos-1]=='-' || stk[tos-1]=='/' || stk[tos-1]=='*')
        {
            return 0;
        }
        else if(stk[tos-1]=='(')
        {
            return 1;
        }
    }
    else if(stk[tos]=='/' || stk[tos]=='*')
    {
        if(stk[tos-1]=='/' || stk[tos-1]=='*')
        {
            return 0;
        }
        else if(stk[tos-1]=='(')
        {
            return 1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

