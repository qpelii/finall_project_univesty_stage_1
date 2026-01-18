#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<conio.h>
static char user_admin[10]="admin";
static char pass_admin[20]="dgplq456789";// hashed
static long int limit_admin=0;
struct struct_departeman
{
    char name[20];
    char family[30];
    char date_start[15];
    char name_of_group[20];
    char ID_code[15];
    char phone_num[15];
    char email[40];
    char user_Name[20];
    char pass1[50];
    struct struct_departeman *link;
};
struct struct_departeman *start_struct_departemant, *end_struct_departemant, *temp_struct_separtemant;

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
void password_to_star(char pass_pointer[])
{
    char pass[50];
    int i=0;
    do{
        pass[i]=getch();
        switch (pass[i])
        {
        case 8:
            printf("\b \b");
            pass[i-1]='\0';
            pass[i]='\0';
            i=i-1;
            break;
        case 13:
            printf("\n");
            break;
        default:
            printf("*");
            i++;
            break;
        }
    }while(pass[i]!=13);
    pass[i]='\0';
    strcpy(pass_pointer,pass);
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
    char pass[50]={0};
    if (limit_time-time(NULL)>0)
        return 2;
    for(i=0;i<3;i++)
    {
        printf("eneter your password: ");
        password_to_star(pass);
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
        if (strcmp(user,user_corect)!=0 || len_corect_user!=len_get_user || check_str_whitout_space(user))
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
        char temp;
        do
        {
            temp=getch();
        } while (temp!=13);
    }
    if (flag_pass==2)
    {
        //you alraredy have limit
        long int time;
        time=time_left_limt(*limit_time);
        printf("You have been limited!! Try agian after ");
        change_form_time(time);
        printf(" later\n");
        printf("prese Enter to continue");
        char temp;
        do
        {
            temp=getch();
        } while (temp!=13);
        
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
    if (slash_flag!=2)
        return 1;
    // len years =4
    sscanf(date,"%d/%d/%d",&year,&mounth,&day);
    int counter;
    i=year;
    for (counter=0;;counter++)
    {
        if (i==0)
            break;
        i/=10;
    }
    if (counter!=4)
        return 1;
    if (year<0 || mounth<1 || mounth>12 || day<1 || day>31)
        return 1;

    return 0;

}
int check_email(char email[])
{
    // if corect -> 0 else 1;
    int counter,counter_2=0,len=strlen(email),atsing_flag=0;
    char name_email[45]="",domain[30]="";
    for(counter=0;counter<len;counter++)
    {
        if (email[counter]=='@')
            atsing_flag++;
        else if (atsing_flag==0)
            name_email[counter]=email[counter];
        else if (atsing_flag==1)
            domain[counter_2++]=email[counter];
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
    // ---------------------------------------------- checker domain
    len=strlen(domain);
    int flag_dot=0;
    for(counter=0;counter<len;counter++)
    {
        if (isspace(domain[counter]))
            return 1;
        if (domain[counter]=='-' || domain[counter]=='.')
        {
            if (counter==0 || counter==len-1 || domain[counter+1]=='.' || domain[counter+1]=='-')
                return 1;
            else if (domain[counter]=='.')
                flag_dot++;
        }
        else if (ispunct(domain[counter]))
            return 1;
    }
    if (flag_dot==0)
        return 1;

    return 0;
}
int check_strong_password(char pass[])
{
    // note: 1==tow meny few char|2==not digit|3==not alpha upper|4== not !@#$| 5== not char lower| 0==corect
    int len=strlen(pass),i;
    int flag_upper=0,flag_lower=0,flag_punct=0,flag_digit=0;
    if (len<8)
        return 1;
    for(i=0;i<len;i++)
    {
        if (isupper(pass[i]))
            flag_upper++;
        else if (islower(pass[i]))
            flag_lower++;
        else if (ispunct(pass[i]))
            flag_punct++;
        else if (isdigit(pass[i]))
            flag_digit++;
    }
    if (flag_digit==0)
        return 2;
    else if (flag_upper==0)
        return 3;
    else if (flag_punct==0)
        return 4;
    else if (flag_lower==0)
        return 5;

    return 0;

}
void set_new_departemant()
{
    FILE *file_departemant;
    file_departemant=fopen("file_departemant.txt","a");
    if (file_departemant==NULL)
    {
        printf("memory is not allowed!");
        exit(1);
    }
    char name[20],family[30],date_start[15],name_of_group[20],ID_code[15],phone_num[15],email[40],user_Name[20];
    char pass1[50],pass2[50];
    printf("Please enter this information about Departemant\n");

    printf("Enter name: ");
    do{
        gets(name);
        if (check_str_full_alpha_whit_space(name) || strlen(name)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter family: ");
    do{
        gets(family);
        if (check_str_full_alpha_whit_space(family) || strlen(family)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter date start Departemant\n(hint:enter whith this form YYYY/MM/DD): ");
    do{
        gets(date_start);
        if (check_str_date(date_start) || strlen(date_start)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter name of Departiment group: ");
    do{
        gets(name_of_group);
        if (check_str_full_alpha_whit_space(name_of_group) || strlen(name_of_group)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter ID: ");
    do{
        gets(ID_code);
        if (check_str_was_int(ID_code) || strlen(ID_code)!=10)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Phone number(whit this form 09123456789): ");
    do{
        gets(phone_num);
        if (check_str_was_int(phone_num) || phone_num[0]!='0' || phone_num[1]!='9' || strlen(phone_num)!=11)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Email: ");
    do{
        gets(email);
        if (check_email(email))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter User name of Departemant: ");
    do{
        gets(user_Name);    // ----------------------------- need edit for duplicated user_name
        if (check_str_whitout_space(user_Name) || strlen(user_Name)==0)
            printf("Invalid input! Try again: ");
        else
        {
            str_to_lower(user_Name);
            break;
        }
    }while(1);

    printf("Set Password for Departemant: ");
    do
    {
        gets(pass1);
        if (check_str_whitout_space(pass1) || strlen(pass1)==0)
        {
           printf("Invalid input! Try again: ");
            continue;
        }
        // ----- show why eror
        switch (check_strong_password(pass1))
        {
        case 1:
            printf("too few character! Try again: ");
            break;
        case 2:
            printf("Your password for security must have number! Try again: ");
            break;
        case 3:
            printf("Your password must have Capital and Small letters! Try again: ");
            break;
        case 4:
            printf("Your password must have punct(!@#$%^) character! Try again: ");
            break;
        case 5:
            printf("Your password must have Capital and Small letters! Try again: ");
            break;
        default:
            break;
        }
        if (check_strong_password(pass1))
            continue;

        printf("Please repeat password: ");
        gets(pass2);
        if (strcmp(pass1,pass2)!=0 || strlen(pass1)!=strlen(pass2))
        {
            printf("your password is not corect! Try agian: ");
            continue;
        }
        break;
    } while (1);
    // ----------------------------------file apend
    fputs(name,file_departemant);
    fputs(", ",file_departemant);
    fputs(family,file_departemant);
    fputs(", ",file_departemant);
    fputs(date_start,file_departemant);
    fputs(", ",file_departemant);
    fputs(name_of_group,file_departemant);
    fputs(", ",file_departemant);
    fputs(ID_code,file_departemant);
    fputs(", ",file_departemant);
    fputs(phone_num,file_departemant);
    fputs(", ",file_departemant);
    fputs(email,file_departemant);
    fputs(", ",file_departemant);
    fputs(user_Name,file_departemant);
    fputs(", ",file_departemant);
    fputs(pass1,file_departemant);
    fputc('\n',file_departemant);
    printf("Successfully added!\npreas Enter to continue");
    fclose(file_departemant);
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);
    

}
void set_new_academic()
{
    FILE *file_academic;
    file_academic=fopen("file_academic.txt","a");
    if (file_academic==NULL)
    {
        printf("memory is not allowed!");
        exit(1);
    }
    char name[20],family[30],date_start[15],rate[10],phone_num[15],email[40],user_Name[20];
    char pass1[50],pass2[50];
    printf("Please enter this information about Academic\n");

    printf("Enter name: ");
    do{
        gets(name);
        if (check_str_full_alpha_whit_space(name) || strlen(name)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter family: ");
    do{
        gets(family);
        if (check_str_full_alpha_whit_space(family) || strlen(family)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter date start Academic\n(hint:enter whit this form YYYY/MM/DD): ");
    do{
        gets(date_start);
        if (check_str_date(date_start) || strlen(date_start)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Rated of Academic : ");
    do{
        gets(rate);
        if (check_str_full_alpha_whit_space(rate) || strlen(rate)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Phone number(whit this form 09123456789): ");
    do{
        gets(phone_num);
        if (check_str_was_int(phone_num) || phone_num[0]!='0' || phone_num[1]!='9' || strlen(phone_num)!=11)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Email: ");
    do{
        gets(email);
        if (check_email(email))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter User name of Academic: ");
    do{
        gets(user_Name);    // ----------------------------- need edit for duplicated user_name
        if (check_str_whitout_space(user_Name) || strlen(user_Name)==0)
            printf("Invalid input! Try again: ");
        else
        {
            str_to_lower(user_Name);
            break;
        }
    }while(1);

    printf("Set Password for Academic: ");
    do
    {
        gets(pass1);
        if (check_str_whitout_space(pass1) || strlen(pass1)==0)
        {
           printf("Invalid input! Try again: ");
            continue;
        }
        // ----- show why eror
        switch (check_strong_password(pass1))
        {
        case 1:
            printf("too few character! Try again: ");
            break;
        case 2:
            printf("Your password for security must have number! Try again: ");
            break;
        case 3:
            printf("Your password must have Capital and Small letters! Try again: ");
            break;
        case 4:
            printf("Your password must have punct(!@#$%^) character! Try again: ");
            break;
        case 5:
            printf("Your password must have Capital and Small letters! Try again: ");
            break;
        default:
            break;
        }
        if (check_strong_password(pass1))
            continue;

        printf("Please repeat password: ");
        gets(pass2);
        if (strcmp(pass1,pass2)!=0 || strlen(pass1)!=strlen(pass2))
        {
            printf("your password is not corect! Try agian: ");
            continue;
        }
        break;
    } while (1);
    // ----------------------------------file apend
    fputs(name,file_academic);
    fputs(", ",file_academic);
    fputs(family,file_academic);
    fputs(", ",file_academic);
    fputs(date_start,file_academic);
    fputs(", ",file_academic);
    fputs(rate,file_academic);
    fputs(", ",file_academic);
    fputs(phone_num,file_academic);
    fputs(", ",file_academic);
    fputs(email,file_academic);
    fputs(", ",file_academic);
    fputs(user_Name,file_academic);
    fputs(", ",file_academic);
    fputs(pass1,file_academic);
    fputs(", ",file_academic);
    fputc('N',file_academic);// date exit
    fputc('\n',file_academic);
    printf("Successfully added!\npreas Enter to continue");
    fclose(file_academic);
    char temp;
    do
    {
        temp=getch(); 
    } while (temp!=13);
    

}
int set_departemants_as_link_list()
{
    start_struct_departemant=malloc(sizeof(struct struct_departeman));
    if (start_struct_departemant==NULL)
    {
        printf("memory is not allowed!");
        return 1;
    }
    end_struct_departemant=start_struct_departemant;

    FILE *departemant;
    departemant=fopen("file_departemant.txt", "r");
    if (departemant==NULL)
        printf("Error! program need fierst set Departemant!\n");
    char temp[225],info[50]={0};
    int i=0,j=0,flag_info=1;
    for(i=0;;i++)
    {
        fgets(temp,225,departemant);
        if (temp[i]==',' && temp[i+1]==' ')
        {
            switch (flag_info)
            {
            case 1:
                strcpy(start_struct_departemant->name,info);
                break;
            case 2:
                strcpy(start_struct_departemant->family,info);
                break;
            case 3:
                strcpy(start_struct_departemant->date_start,info);
                break;
            case 4:
                strcpy(start_struct_departemant->name_of_group,info);
                break;
            case 5:
                strcpy(start_struct_departemant->ID_code,info);
                break;
            case 6:
                strcpy(start_struct_departemant->phone_num,info);
                break;
            case 7:
                strcpy(start_struct_departemant->email,info);
                break;
            case 8:
                strcpy(start_struct_departemant->user_Name,info);
                break;
            case 9:
                strcpy(start_struct_departemant->pass1,info);
                break;
            default:
                break;
            }
            flag_info++;
            j=0;
            i++;
        }
        else
        {
            info[j]=temp[i];
            j++;
        }
    }   
    start_struct_departemant->link=NULL;
    
    while (feof(departemant)==0)
    {
        temp_struct_separtemant=malloc(sizeof(struct struct_departeman));
        fgets(temp,225,departemant);
        flag_info=0,i=0,j=0;
        while(flag_info!=9)
        {
            if (temp[i]==',' && temp[i+1]==' ')
            {
                switch (flag_info)
                {
                case 1:
                    strcpy(temp_struct_separtemant->name,info);
                    break;
                case 2:
                    strcpy(temp_struct_separtemant->family,info);
                    break;
                case 3:
                    strcpy(temp_struct_separtemant->date_start,info);
                    break;
                case 4:
                    strcpy(temp_struct_separtemant->name_of_group,info);
                    break;
                case 5:
                    strcpy(temp_struct_separtemant->ID_code,info);
                    break;
                case 6:
                    strcpy(temp_struct_separtemant->phone_num,info);
                    break;
                case 7:
                    strcpy(temp_struct_separtemant->email,info);
                    break;
                case 8:
                    strcpy(temp_struct_separtemant->user_Name,info);
                    break;
                case 9:
                    strcpy(temp_struct_separtemant->pass1,info);
                    break;
                default:
                    break;
                }
                flag_info++;
                j=0;
                i++;
            }
            else
            {
                info[j]=temp[i];
                j++;
            }
        }
        temp_struct_separtemant->link=NULL;
        end_struct_departemant->link=temp_struct_separtemant;
        end_struct_departemant=temp_struct_separtemant;
    }
    return 0;
}


void main()
{
    char *pointer_Uadmin;
    pointer_Uadmin=malloc(sizeof(user_admin));
    pointer_Uadmin=user_admin;
    if (pointer_Uadmin==NULL)
    {
        printf("memory is not allow! Try later");
        exit(1);
    }
    char *pointer_Padmin;
    pointer_Padmin=malloc(sizeof(pass_admin));
    pointer_Padmin=pass_admin;
    if (pointer_Padmin==NULL)
    {
        printf("memory is not allow! Try later");
        exit(1);
    }
    long int *pointer_Limit_admin;
    pointer_Limit_admin=malloc(sizeof(limit_admin));
    *pointer_Limit_admin=limit_admin;
    if (pointer_Limit_admin==NULL)
    {
        printf("memory is not allow! Try later");
        exit(1);
    }
    long int *limit;
    
    start_struct_departemant=malloc(sizeof(struct struct_departeman));
    
    
    
    while(1)
    {
    menu_login_print();
    int menu_type=menu_login_filter_selection();
    // -------------------------------------------- rotation part
    switch (menu_type)
    {
        case 1:
            unti_hash_to_password(pointer_Padmin);
            int login_flag=get_check_user_pass(pointer_Uadmin,pointer_Padmin,pointer_Limit_admin);// 0:= succces; 1,2:unsaccses; -1:cancel login;
            password_to_hash(pointer_Padmin);
            if (login_flag==0)
            {
                do{
                    menu_admin_page_print();
                    menu_type=menu_admin_page_filter_selection();
                    switch (menu_type)
                    {
                    case 1:
                        set_new_departemant();
                        break;
                    case 2:
                        set_new_academic();
                        break;
                    case 3:
                        set_departemants_as_link_list();
                        break;
                    case 7:
                        break;

                    default:
                        break;
                    }
                }while(menu_type!=7);
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
