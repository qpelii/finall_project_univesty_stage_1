#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
static char user_admin[10]="admin";
static char pass_admin[20]="dgplq456789";// hashed
static long int limit_admin=0;

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
        strcpy(temp,"Exit Program");
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

            // system("cls");
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
int check_str_full_alpha_whit_space(char string[])
{
    int len=strlen(string),i;
    for (i=0;i<len;i++)
        if (!isalpha(string[i]))
            if (isspace(string[i]))
                continue;
            else
                return 1;
    
    return 0;
}
int check_str_full_alpha_whitout_space(char string[])
{
    int len=strlen(string),i;
    for (i=0;i<len;i++)
        if (!isalpha(string[i]))
                return 1;
    
    return 0;
}
int check_corect_pass_and_set_limit(char corect_pass[], int limit_time)
{
    // note: if corect --> return 0;  ||  if invalid --> return 1;  ||  if have limit -->return 2; if want Exit -->return -1;
    int i;
    char pass[50];
    if (limit_time-time(NULL)>0)
        return 2;
    for(i=0;i<3;i++)
    {
        printf("eneter your password: ");
        gets(pass);
        if (strlen(pass)==0)
            return -1;
        int len_get_pass=strlen(pass),len_corect_pass=strlen(corect_pass);
        if (strcmp(pass,corect_pass)==0 && len_corect_pass==len_get_pass)
            return 0;
        else
        {
            if (i==2)
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
    long int time_limited;
    time_limited=time(NULL)+(5*60);
    return time_limited;
}
void change_form_time(int time_left)
{
    int min=time_left%60;
    int houer=time_left/60;
    printf("%.2d:%.2d",houer,min);
}
int get_check_user_pass(char user_corect[], char corect_pass[],long int *limit_time)
{
    // -------------------- just user_name
    char user[30];
        printf("note: if you want Exit from Login page's, Just prsse enter\n");
    do{
        printf("enter your User Name: ");
        gets(user);
        if (strlen(user)==0)
            return -1;
        int len_get_user=strlen(user),len_corect_user=strlen(user_corect);
        str_to_lower(user);
        if (strcmp(user,user_corect)!=0 || len_corect_user!=len_get_user || check_str_whitout_space)
        {
            printf("This user name is Invalid! Try agian\n");
            continue;
        }
        else
            break;
    }while(1);
    // -------------------- just password
    // ------------------------------ note: corect--> return 0 else 1,2 || cancel login -1;
    int flag_pass=check_corect_pass_and_set_limit(corect_pass,*limit_time);

    if (flag_pass==-1)
        // ---------- cancel login
        return -1;
    if (flag_pass==0)
    // ------------- dont have limit and pass is corcet!
        return 0;
    // else
    if (flag_pass==1)
    {
        //now you give limit
        *limit_time=make_limit_time();
        int time=time_left_limt(*limit_time);
        printf("You have been limited for ");
        change_form_time(time);
        printf("\n");
        printf("prese enter to continue");
        getchar();
    }
    if (flag_pass==2)
    {
        //you alraredy have limit
        long int time;
        time=time_left_limt(*limit_time);
        printf("You have been limited!! Try agian after ");
        change_form_time(time);
        printf(" later\n");
        printf("prese enter to continue");
        getchar();
    }
    return 1;
}
void menu_admin_page_print()
{
    char temp[25],line_char='|';
    printf("------------------------------\n");
    for(int i=0; i<7; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Add new Departemant");// modir goorooh:)
        break;
    case 1:
        strcpy(temp,"Add new Academic");
        break;
    case 2:
        strcpy(temp,"Show lsit of user");
        break;
    case 3:
        strcpy(temp,"Keck user from system");
        break;
    case 4:
        strcpy(temp,"Grt Log");
        break;
    case 5:
        strcpy(temp,"Get backup from Files");
        break;
    case 6:
        strcpy(temp,"Exit from Admin User");
        break;
    default:
        break;
    }

    printf("%-25s%c\n",temp,line_char);
    if (i!=6)
        printf("|--+-------------------------|\n");


    }
    printf("------------------------------\n\n");
    printf("select a option from menu: ");
}
int menu_admin_page_filter_selection()
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
            if (num>7 || num<1)
            {
                printf("Your input is out of range! Try agian: ");
                flag++;
                continue;
            }

            // system("cls");
            return num;
        }
    } while (flag);
    
}
void password_to_hash(char password[])
{
    int len=strlen(password);
    int temp_ASCII;
    for (int i=0; i<len; i++)
    {
        temp_ASCII=password[i];
        temp_ASCII= temp_ASCII+3;
        password[i]=temp_ASCII;
    }
}
void unti_hash_to_password(char password[])
{
    int len=strlen(password);
    int temp_ASCII;
    for (int i=0; i<len; i++)
    {
        temp_ASCII=password[i];
        temp_ASCII= (temp_ASCII-3);
        password[i]=temp_ASCII;
    }
}
int check_str_date(char date[])
{
    int len=strlen(date),i,slash_flag=0;
    int year,mounth,day;
    for(i=0;i<len;i++)
        if (date[i]=='/')
            slash_flag++;
    if (slash_flag!=3)
        return 1;
    sscanf(date,"%d/%d/%d",&year,&mounth,&day);
    if (year<0 || mounth<1 || mounth>12 || day<1 || day>31)
        return 1;
        
    return 0;
    
}
void set_new_departemant(FILE file_departemant)
{
    char name[20],family[30],date_start[15],name_of_group[20],ID_code[15],phone_num[15],email[40],user_Name[20];
    printf("Please enter this information about Departemant\n")

    printf("Enter name: ");
    do{
        gets(name);
        if (check_str_full_alpha_whit_space(name))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter family: ");
    do{
        gets(family);
        if (check_str_full_alpha_whit_space(family))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter date start Departemant\n(hint:enter whit this form YYYY/MM/DD): ");
    do{
        gets(date_start);
        if (check_str_date(date_start))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1)

    printf("Enter name of Departiment group: ");
    do{
        gets(name_of_group);
        if (check_str_full_alpha_whit_space(name_of_group))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1)

    printf("Enter ID: ");
    do{
        gets(ID_code);
        if (check_str_was_int(ID_code))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1)

    printf("Enter Phone number(whit this form 09123456789): ");
    do{
        gets(phone_num);
        if (check_str_was_int(phone_num) || phone_num[0]!='0' || phone_num[1]!='9')
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1)

    printf("Enter Email: ");
    gets(email);
    printf("Enter User name of Departemant: ");
    gets(user_Name);
    
}
int check_email(char email[])
{
    // if corect -> 0 else 1;
    int counter,counter_2=0,len=strlen(email),atsing_flag=0;
    char name_email[45]="",domain[30]="";
    for(counter=0;counter<len;counter++)
    {
        if (word_input[counter]=='@')
            atsing_flag++;
        else if (atsing_flag==0)
            name_email[counter]=word_input[counter];
        else if (atsing_flag==1)
            domain[counter_2++]=word_input[counter];
    }
    if (atsing_flag!=1)
        return 1;
    
    // ---------------------------------------------- checker name mail
    len=strlen(name_email);
    for(counter=0;counter<len;counter++)
    {
        if (isspace(name_email[counter]))
            return 1;

        if (name_email[counter]=='-' || name_email[counter]=='_' || name_email[counter]=='+' || name_email[counter]=='.')
        {
            if (counter==0 || counter==len-1)
            return 1;
        }
        else if (ispunct(name_email[counter]))
            return 1;
        
    }
    // ---------------------------------------------- checker name mail
    len=strlen(domain);
    for(counter=0;counter<len;counter++)
    {
        if (isspace(domain[counter]))
            return 1;
        if (domain[counter]=='-' || domain[counter]=='.')
        {
            if (counter==0 || counter==len-1 || domain[counter+1]=='.' || domain[counter+1]=='-')
                return 1;
        }
        else if (ispunct(domain[counter]))
            return 1;
    }
    return 0;
}

void main()
{
    FILE *file_departemant;
    FILE *file_academic;

    char *pointer_Uadmin;
    pointer_Uadmin=malloc(sizeof(user_admin));
    pointer_Uadmin=user_admin;
    if (pointer_Uadmin==NULL)
    {
        printf("memory is not allow!");
        exit(1);
    }
    char *pointer_Padmin;
    pointer_Padmin=malloc(sizeof(pass_admin));
    pointer_Padmin=pass_admin;
    if (pointer_Padmin==NULL)
    {
        printf("memory is not allow!");
        exit(1);
    }
    long int *pointer_Limit_admin;
    pointer_Limit_admin=malloc(sizeof(limit_admin));
    *pointer_Limit_admin=limit_admin;
    if (pointer_Limit_admin==NULL)
    {
        printf("memory is not allow!");
        exit(1);
    }
    char user[30],password[50];
    long int *limit;
    while(1)
    {
    menu_login_print();
    int menu_type=menu_login_filter_selection();
    // -------------------------------------------- rotation part
    switch (menu_type)
    {
        case 1:
            unti_hash_to_password(pointer_Padmin);
            int login_flag=get_check_user_pass(pointer_Uadmin,pointer_Padmin,pointer_Limit_admin);// 1:= succces; 2:unsaccses; -1:cancel login;
            if (login_flag==0)
            {
                menu_admin_page_print();
                menu_type=menu_admin_page_filter_selection();
                switch (menu_type)
                {
                case 1:
                    // set new modir gorooh
                    // ----------------------------------------------- file opening
                    file_departemant=fopen("file_departemant","a");
                    if (file_departemant==NULL)
                    {
                        printf("memory is not allowed!");
                        exit(1);
                    }

                    break;
                
                default:
                    break;
                }
            }
            break;
        case 4:
            exit(1);
            break;

        default:
            break;
    }
    } 

}