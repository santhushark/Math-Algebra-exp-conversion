PREFIX TO POSTFIX

//header file inclusion and macros
#include<stdio.h>
#include<string.h>
#define sz 20
int main()
{
    int i=0,j,tos=-1,row=0,len;
    char pre_exp1[sz],pre_exp[sz],stk[sz][sz];
    printf("\nEnter the PREFIX expression\n");
    scanf("%s",pre_exp1);
    //reversing the prefix expression
	len=strlen(pre_exp1);
	while(pre_exp1[i]!=’\0’)
	{
		pre_exp[i]=pre_exp1[len-i];
		i++;
	}
	pre_exp[i]=’\0’;
    while(pre_exp[i]!='\0')
    {
        if(pre_exp[i]>='A' && pre_exp[i]<='z')
        {
		//pushing the alphabet to stack
            tos++;
            stk[tos][row]=pre_exp[i];
            row++;
            stk[tos][row]='\0';
            row=0;
        }
        else
        {
		//popping out two operands from stack and concatenating it with the operator and pushing it back to stack
            if(tos>0)
            {
                strcat(stk[tos],stk[tos-1]);
                strcpy(stk[tos-1],stk[tos]);
                tos--;
                j=strlen(stk[tos]);
                stk[tos][j]=pre_exp[i];
                j++;
                stk[tos][j]='\0';
            }
            else
            {
                j=strlen(stk[tos]);
                stk[tos][j]=pre_exp[i];
                j++;
                stk[tos][j]='\0';
            }
        }
        i++;
    }
    printf("\n");
    for(tos=tos;tos>=0;tos--)
    {
        printf("%s",stk[tos]);
    }
    return 0;
}

