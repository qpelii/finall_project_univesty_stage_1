#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define user_admin "admin"
#define pass_admin "admin123456"
static int limit_time_admin=0;

void menu_login_print()
{
    char temp[25],line_char='|';
    printf("Welcome to login page\n\n");
    printf("---------------------------\n");
    for(int i=0; i<4; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Admin Login page");
        break;
    case 1:
        strcpy(temp,"Department Login page");
        break;
    case 2:
        strcpy(temp,"Academic Login page");
        break;
    case 3:
        strcpy(temp,"Exit program");
        break;
    default:
        break;
    }

    printf("%-22s%c\n",temp,line_char);
    if (i!=3)
        printf("|--+----------------------|\n");


    }
    printf("---------------------------\n\n");
    printf("select a option from menu: ");
}
int check_str_was_int(char num[])
{
    int len=strlen(num),i;
    for (i=0;i<len;i++)
        if (!isdigit(num[i]))
            return 1;
    
    return 0;
}
void str_to_lower(char text[])
{
    int len=strlen(text),i;
    char result[len+2];
    for (i=0; i<len; i++)
        text[i]=tolower(text[i]);
}
int menu_login_filter_selection()
{
    char number[3];
    int num,flag;
    do
    {
        flag=num=0;
        gets(number);
        flag=check_str_was_int(number);
        if (flag)
        {
            printf("Invalid input Try agian: ");
            continue;
        }
        else
        {
            num=atoi(number) ;
            if (num>4 || num<1)
            {
                printf("Your input is out of range! Try agian: ");
                flag++;
                continue;
            }

            system("cls");
            return num;
        }
    } while (flag);
    
}
int check_str_whitout_space(char string[])
{
    int len=strlen(string),i;
    for (i=0;i<len;i++)
        if (isspace(string[i]))
            return 1;
    
    return 0;
}
int check_corect_pass_and_set_limit(char corect_pass[])
{
    // note: if corect --> return 0;  ||  if invalid --> return 1;  ||  if have limit -->return 2;
    int i;
    char pass[50];
    if (limit_time_admin>0)
        return 2;
    for(i=0;i<3;i++)
    {
        printf("eneter your password: ");
        gets(pass);
        if (pass==corect_pass)
            return 0;
        else
        {
            if (i=2)
                return 1;
            printf("Invalid password!! you have %d time's for enter password, carefull!\n",2-i);
        }
    }
}
int time_left_limt(long int limited)
{
    // ---------- note: if result is possetiv:= have limit; else limit done!
    long int result=limited-time(NULL);
    return result;
}
long int make_limit_time()
{
    long int time,time_limited;
    time=time(NULL);
    time_limited=time+(5*60);
    return time_limited;
}
void change_form_time(int time_left)
{
    int min=time_left%60;
    int houer=time_left/60;
    printf("%.2d:%.2d",houer,min);
}


void main()
{

}