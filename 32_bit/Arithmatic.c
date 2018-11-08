						//A program to calculate any arithmatic expression


#include<stdio.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#define operator(i) (eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*')
void clear()
{
    fflush(stdin);
}
int grange(char a[20],int range)
{
    int b;
	#if turbo == 1
    textcolor(RED+BLINK);
	#endif
    b = strlen(a);
    if(b<=range)
    {
	    return (a);
    }
    else
    {
        #if turbo == 1
        cprintf("Sorry Out of range...\a");
        printf("\n");
        cprintf("Please enter in range");
        printf("\n");
        #else
        printf("Sorry Out of range...\a");
        printf("\n");
        printf("Please enter in range");
        printf("\n");
        #endif
        gets(a);
        grange(a,range);
    }
}
int gfloat(float *result,int range)
{

    char b[20],*c,d[20],e;
    int value = 1,i,j = 0,k;
	#if turbo == 1
    textcolor(RED+BLINK);
	#endif
    while (value == 1) //Loop for checking numeric or alphabetic input
    {
	clear();
	gets(b);
	c = grange(b,range);
	for (i = 0;i <= 20;i++)
	{
		d[i] = *(c+i);
	}
	i = strlen(d);
	for(k = 0;k<i;k++)
	{
		e = isdigit(d[k]);
		clear();
		if(d[k] == '.')
		{
			j = 0;

		}
		else if(e>0)
		{
			j = 0;
		}
		else
		{
			j = 1;
			break;
		}
	}

	if (j == 0)
	{
	    *result = atof(d);
	    break;
	}
	else
	{
        #if turbo == 1
	    cprintf("Please enter an appropiate value");
		printf("\n");
        #else
	    printf("Please enter an appropiate value");
		printf("\n");
        #endif
	}
    }
}
int equation()
{
    FILE *p,*state;
    static char eq[50],dir[100],fdir[100],fcmd[100];
    static char frcmd[100];
    static char err[30];
    int eq_len,ck_eq = 0,ck_err = 0,arr_err = 0;
    int i = 0,j = 0;
    int l;
    char process,statec;
    printf("\nEnter any arithmatic expression\n>> ");
    errorrep:
    _getcwd(dir,100);
    strcpy(fdir,dir);
    strcat(fdir,"\\temp.c");
    p = fopen(fdir,"w");
    fputs("#include<stdio.h>\nint main()\n{\nfloat a;\na = ",p);
    while(1)
    {
        clear();
        memset(err,0,sizeof(err));
        j = 0,ck_err = 0,arr_err =0;
        gets(eq);
        eq_len = strlen(eq);
        for(i = 0; i<eq_len;i++)
        {
            if(eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*'||eq[i] == '.')
            {
                ck_eq = 0;
            }
            else if(eq[i] == '('||eq[i] == ')')
            {
                ck_eq = 0;
            }
            else if(isdigit(eq[i])>0)
            {
                ck_eq = 0;

            }
            else
            {
                j++;
                err[j] = eq[i];
                ck_err++;
            }
            if((operator(i)&&eq[i+1] == ')')||(operator(i)&&operator(i+1))||(eq[i]==')'&&eq[i+1] == '(')||(eq[i]=='('&&eq[i+1] == ')'))
            {
                arr_err++;
            }
        }
        if(ck_err  != 0)
        {
            printf("Error in equation\n");
            printf("You can't use ");
            for(j = 1; j<= ck_err;j++)
            {
                printf("'%c' ",err[j]);
            }
            printf("\nPleasse enter again\n>>");
        }
        else if(arr_err != 0)
        {
            printf("There is a arrengment error in the equation\n\nPlease re-enter the equation\n>> ");
        }
        else
        {
            break;
        }
    }
    fclose(p);
    p = fopen(fdir,"a");
    fputs(eq,p);
    fputs(";\nprintf(\"%.3f\",a);\nreturn 0;\n}",p);
    fclose(p);
    strcpy(fcmd,dir);
    strcat(fcmd,"\\data\\tcc ");
    strcat(fcmd,dir);
    strcat(fcmd,"\\temp.c");
    strcat(fcmd," -o ");
    strcat(fcmd,dir);
    strcat(fcmd,"\\temp.exe");
    if(system(fcmd) == 0)
    {
        for(i = 1;i<= 10;i++)
        {
            if (i%2 == 0)
            {
                process = '\\';
            }
            else
            {
                process = '/';
            }
        Sleep(100);
        printf("\r%c %s",process,"processing...");
        }
        printf("\n\n= ");
    }
    else
    {
        for(i = 1;i<= 10;i++)
        {
            if (i%2 == 0)
            {
                process = '\\';
            }
            else
            {
                process = '/';
            }
        Sleep(100);
        printf("\r%c %s",process,"processing...");
        }
        printf("\nprocessing error (Wrong equqtion format)\n");
        printf("\nPlease re-enter the equation carefully...\n>> ");
        memset(fdir,0,sizeof(fdir));
        memset(eq,0,sizeof(eq));
        memset(dir,0,sizeof(dir));
        memset(fcmd,0,sizeof(fcmd));
        memset(frcmd,0,sizeof(frcmd));
        goto errorrep;
        
    }
    strcpy(frcmd,dir);
    strcat(frcmd,"\\temp.exe");
    system(frcmd);
    remove(fdir);
    memset(fdir,0,sizeof(fdir));
    strcpy(fdir,dir);
    strcat(fdir,"\\temp.exe");
    remove(fdir);
    memset(fdir,0,sizeof(fdir));
    memset(eq,0,sizeof(eq));
    memset(dir,0,sizeof(dir));
    memset(fcmd,0,sizeof(fcmd));
    memset(frcmd,0,sizeof(frcmd));
    return 0;
}
int main()
{
    char r,res;
    float a,b;
    while (1)
    {
        printf("\nWhat you want to do?\n");
        printf("sum(s),mult(m),division(d),subtraction(u),equation(e),Exit(E)\n");
        while(1)
        {
            clear();
            r = getche();
            if ( r == 's' || r == 'm' || r == 'd' || r == 'e' ||r == 'u' || r == 'E')
            {
                break;
            }
            else
            {
                #if turbo == 1
                textcolor(RED+BLINK);
                printf("\n");
                cprintf("You have entered a wrong keyword please re-enter");
                printf("\n");
                #else
                printf("\nYou have entered a wrong keyword please re-enter\n");
                #endif
            }
        }
        clear();
        if(r=='e')
        {
            printf("\n");
            equation();
        }
        else if(r == 'E')
        {
            printf("\nGood Bye");
            break;
        }
        else
        {
            printf("\nEnter the first number\n");
            gfloat(&a,12);
            printf("Enter the second number\n");
            gfloat(&b,12);

            switch(r)
            {
                case 's':
                    printf("The sum of %.3f and %.3f is %.3f",a,b,a+b);
                    break;
                case 'm':
                    printf("The multiply of %.3f and %.3f is %.3f",a,b,a*b);
                    break;
                case 'u':
                    printf("The subtraction of %.3f and %.3f is %.3f",a,b,a-b);
                    break;
                case 'd':
                    printf("The division of %.3f and %.3f is %.3f",a,b,a/b);
                    break;
            }
        }
        printf("\n\nDo you want to calculate again(y/n)\n");
        rep:
        res = getche();
        if(res == 'y')
        {
            continue;
        }
        else if (res == 'n')
        {
            break;
        }
        else
        #if turbo == 1
        printf("\n");
        cprintf("You have entered a wrong keyword");
        printf("\n");
        cprintf("Please try again");
        printf("\n");
        #else
        printf("\nYou have entered a wrong keyword\nPlease try again\n");
        #endif
        goto rep;
    }

}