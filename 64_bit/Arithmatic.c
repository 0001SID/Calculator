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
int main()
{
    char res;
    do
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
        printf("\n\n");
        printf("Do you want to calculate again?(y/n)");
        resp:
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
        res = getche();
        printf("\n");
        if (!(res == 'y' || res =='n'))
        {
            printf("\nPlease enter a valid input");
            goto resp;
        }
    }while(res == 'y');
    return 0;
}