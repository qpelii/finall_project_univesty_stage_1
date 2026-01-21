#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<direct.h>
static char user_admin[10]="admin";
static char pass_admin[20]="5v8a6079zqn";// hashed
static long int limit_admin=0;
struct struct_departemant
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
    char limit_time[10];
    struct struct_departemant *link;
};
struct struct_departemant *start_struct_departemant, *end_struct_departemant, *temp_struct_departemant;
struct struct_academic
{
    char name[20];
    char family[30];
    char date_start[15];
    char rate[15];
    char phone_num[15];
    char email[40];
    char user_Name[20];
    char pass1[50];
    char limit_time[10];
    char ekhraj[20];
    struct struct_academic *link;
};
struct struct_academic *start_struct_academic, *end_struct_academic, *temp_struct_academic;

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
            if (i==0)
                continue;
            
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

            // // system("cls");;
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
        printf("eneter your password:");
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
void free_academic()
{
    if (temp_struct_academic==NULL)
    {
        free(temp_struct_academic);
        return ;
    }
    do
    {
        temp_struct_academic=temp_struct_academic->link;
        continue;
    } while (temp_struct_academic!=NULL);
    free(temp_struct_academic);
}
void free_departemant()
{
    if (temp_struct_departemant==NULL)
    {
        free(temp_struct_departemant);
        return ;
    }
    do
    {
        temp_struct_departemant=temp_struct_departemant->link;
        continue;
    } while (temp_struct_departemant!=NULL);
    free(temp_struct_departemant);
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
    for(int i=0; i<8; i++)
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
        strcpy(temp,"Get Log");
        break;
    case 5:
        strcpy(temp,"Get backup from Files");
        break;
    case 6:
        strcpy(temp,"Load Backup");
        break;
    case 7:
        strcpy(temp,"Exit from Admin User");
        break;
    default:
        break;
    }

    printf("%-25s%c\n",temp,line_char);
    if (i!=7)
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
            if (num>8 || num<1)
            {
                printf("Your input is out of range! Try agian: ");
                flag++;
                continue;
            }

            // // system("cls");;
            return num;
        }
    } while (flag);

}
void password_to_hash(char password[])
{
    char temp;
    int len,i=0;
    len=strlen(password);
    //swap (ayne)
    for (i=0; i<len/2; i++)
    {
        temp=password[i];
        password[i]=password[len-i-1];
        password[len-i-1]=temp;
    }
    //swap random note:min pass==8
    {
        temp=password[3];
        password[3]=password[6];
        password[6]=temp;

        temp=password[1];
        password[1]=password[7];
        password[7]=temp;
        
        temp=password[5];
        password[5]=password[0];
        password[0]=temp;
    }
    //swap in self domain
    for (int i=0; i<len; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            password[i] = 'a' + (password[i] - 'a' + 13) % 26;

        else if (password[i] >= 'A' && password[i] <= 'Z')
            password[i] = 'A' + (password[i] - 'A' + 52) % 26;

        else if (password[i] >= '0' && password[i] <= '9')
            password[i] = '0' + (password[i] - '0' + 14) % 10;

        else if (password[i] >= '!' && password[i] <= '/')
            password[i] = '!' + (password[i] - '!' + 17) % 15;

        else if (password[i] >= ':' && password[i] <= '@')
            password[i] = ':' + (password[i] - ':' + 21) % 7;
    }
}
void unti_hash_to_password(char password[])
{
    char temp;
    int len,i=0;
    len=strlen(password);
    //swap to delf domain
    for (i = 0; i < len; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            password[i] = 'a' + (password[i] -'a'-13+26) %26;

        else if (password[i] >= 'A' && password[i] <= 'Z')
            password[i] = 'A' + (password[i]-'A'-52+78) %26;

        else if (password[i] >= '0' && password[i] <= '9')
            password[i] = '0' + (password[i]-'0'-14+20) %10;

        else if (password[i] >= '!' && password[i] <= '/')
            password[i] = '!' + (password[i] -'!'-17+30) %15;

        else if (password[i] >= ':' && password[i] <= '@')
            password[i] = ':' + (password[i] -':'-21+28)%7;
    }
    //swap random note:min pass==8
    {
        temp=password[3];
        password[3]=password[6];
        password[6]=temp;

        temp=password[1];
        password[1]=password[7];
        password[7]=temp;
        
        temp=password[5];
        password[5]=password[0];
        password[0]=temp;
    }
    //swap (ayne)
    for (i=0; i<len/2; i++)
    {
        temp=password[i];
        password[i]=password[len-i-1];
        password[len-i-1]=temp;
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
int search_user_name_academic(char user_name[])
{
    temp_struct_academic=malloc(sizeof(struct struct_academic));
    temp_struct_academic=start_struct_academic;
    do
    {
        if (strcmp(temp_struct_academic->user_Name,user_name)==0 && strlen(temp_struct_academic->user_Name)==strlen(user_name))
            return 0;
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    free(temp_struct_academic);
    return 1;// 0:= fine | 1:=not found
}
int search_user_name_departemant(char user_name[])
{
    temp_struct_departemant=start_struct_departemant;
    do
    {
        if (strcmp(temp_struct_departemant->user_Name,user_name)==0 && strlen(temp_struct_departemant->user_Name)==strlen(user_name))
            return 0;
        temp_struct_departemant=temp_struct_departemant->link;
    }while(temp_struct_departemant!=NULL);
    free(temp_struct_departemant);
    return 1;// 0:= fine | 1:=not found
}
void get_now_time(char result[])
{
    time_t now = time(NULL);
    struct tm *time = localtime(&now);
    strftime(result, 20, "%Y/%m/%d|%H:%M:%S", time);
}
void set_new_departemant()
{
    FILE *file_departemant;
    file_departemant=fopen("file_departemant.txt","a");
    if (file_departemant==NULL)
    {
        printf("memory is not allowed!");
        return ;
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
        str_to_lower(user_Name);
        if (check_str_whitout_space(user_Name) || strlen(user_Name)==0)
            printf("Invalid input! Try again: ");
        else if (search_user_name_academic(user_Name)==0 || search_user_name_departemant(user_Name)==0 || strcmp(user_Name,user_admin)==0)
            printf("this user name is duplicated!! Try again: ");
        else if (strlen(user_Name)<6)
            printf("too few charachter! Try again: ");
        else
            break;
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
    password_to_hash(pass1);
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
    fputs(", ",file_departemant);
    fputs("0",file_departemant);
    fputc('\n',file_departemant);
    printf("Successfully added!\npreas Enter to continue\n");
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
        return ;
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
        if (check_str_whitout_space(rate) || strlen(rate)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Phone number(whit this form 09123456789): ");
    do{
        gets(phone_num);
        if (check_str_was_int(phone_num) || phone_num[0]!='0' || phone_num[1]!='9' || strlen(phone_num)!=11)
            printf("Invalid input! Try again: ");
        else if (search_user_name_academic(user_Name)==0 || search_user_name_departemant(user_Name)==0 || strcmp(user_Name,user_admin)==0)
            printf("this user name is duplicated!! Try again: ");
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
    password_to_hash(pass1);
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
    fputs("0",file_academic);
    fputs(", ",file_academic);
    fputc('N',file_academic);// date exit
    fputc('\n',file_academic);
    printf("Successfully added!\npreas Enter to continue\n");
    fclose(file_academic);
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);


}
int set_departemants_as_link_list()
{
    start_struct_departemant=malloc(sizeof(struct struct_departemant));
    if (start_struct_departemant==NULL)
    {
        printf("memory is not allowed!");
        return 1;
    }
    end_struct_departemant=start_struct_departemant;

    FILE *departemant;
    departemant=fopen("file_departemant.txt", "r");
    if (departemant==NULL)
    {
        fclose(departemant);
        start_struct_departemant->name[0]='0';// if file was NULL
        start_struct_departemant->link=NULL;
        return 1;
        }
        
    char temp[225],info[50]={0};
    int i=0,j=0,flag_info=1;
    temp[0]='\0';
    fgets(temp,225,departemant);
    if (strlen(temp)==0)
    {
        fclose(departemant);
        start_struct_departemant->name[0]='0';// if file was NULL
        start_struct_departemant->link=NULL;
        return 1;
    } 
    int len=strlen(temp);
    for(i=0;i<len;i++)
    {
        if ((temp[i]==',' && temp[i+1]==' ') || temp[i]=='\n')
        {
            info[j]='\0';
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
            case 10:
                strcpy(start_struct_departemant->limit_time,info);
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

    while (1)
    {
        temp_struct_departemant=malloc(sizeof(struct struct_departemant));
        temp[0]='\0';
        fgets(temp,225,departemant);
        if (strlen(temp)==0)
            break;
        flag_info=1,i=0,j=0;
        while(flag_info!=11)
        {
            if ((temp[i]==',' && temp[i+1]==' ') || temp[i]=='\n')
            {
                info[j]='\0';
                switch (flag_info)
                {
                case 1:
                    strcpy(temp_struct_departemant->name,info);
                    break;
                case 2:
                    strcpy(temp_struct_departemant->family,info);
                    break;
                case 3:
                    strcpy(temp_struct_departemant->date_start,info);
                    break;
                case 4:
                    strcpy(temp_struct_departemant->name_of_group,info);
                    break;
                case 5:
                    strcpy(temp_struct_departemant->ID_code,info);
                    break;
                case 6:
                    strcpy(temp_struct_departemant->phone_num,info);
                    break;
                case 7:
                    strcpy(temp_struct_departemant->email,info);
                    break;
                case 8:
                    strcpy(temp_struct_departemant->user_Name,info);
                    break;
                case 9:
                    strcpy(temp_struct_departemant->pass1,info);
                    break;
                case 10:
                    strcpy(start_struct_departemant->limit_time,info);
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
            i++;
        }
        temp_struct_departemant->link=NULL;
        end_struct_departemant->link=temp_struct_departemant;
        end_struct_departemant=temp_struct_departemant;
    }
    fclose(departemant);
    free(temp_struct_departemant);
    return 0;
}
int set_academic_as_link_list()
{
    start_struct_academic=malloc(sizeof(struct struct_academic));
    if (start_struct_academic==NULL)
    {
        printf("memory is not allowed!");
        return 1;
    }
    end_struct_academic=start_struct_academic;

    FILE *academic;
    academic=fopen("file_academic.txt", "r");
    if (academic==NULL)
    {
        fclose(academic);
        start_struct_academic->name[0]='0';// if file was NULL
        start_struct_academic->link=NULL;
        return 1;
    } 
    char temp[225],info[50]={0};
    int i=0,j=0,flag_info=1;
    temp[0]='\0';
    fgets(temp,225,academic);
    if (strlen(temp)==0)
    {
        fclose(academic);
        start_struct_academic->name[0]='0';// if file was NULL
        start_struct_academic->link=NULL;
        return 1;
    }        
    int len=strlen(temp);
    for(i=0;i<len;i++)
    {
        if ((temp[i]==',' && temp[i+1]==' ') || temp[i]=='\n')
        {
            info[j]='\0';
            switch (flag_info)
            {
            case 1:
                strcpy(start_struct_academic->name,info);
                break;
            case 2:
                strcpy(start_struct_academic->family,info);
                break;
            case 3:
                strcpy(start_struct_academic->date_start,info);
                break;
            case 4:
                strcpy(start_struct_academic->rate,info);
                break;
            case 5:
                strcpy(start_struct_academic->phone_num,info);
                break;
            case 6:
                strcpy(start_struct_academic->email,info);
                break;
            case 7:
                strcpy(start_struct_academic->user_Name,info);
                break;
            case 8:
                strcpy(start_struct_academic->pass1,info);
                break;
            case 9:
                strcpy(start_struct_academic->limit_time,info);
                break;
            case 10:
                strcpy(start_struct_academic->ekhraj,info);
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
    start_struct_academic->link=NULL;
    
    while (1)
    {
        temp_struct_academic=malloc(sizeof(struct struct_academic));
        temp[0]='\0';
        fgets(temp,225,academic);
        if (strlen(temp)==0)
            break;
        flag_info=1,i=0,j=0;
        while(flag_info!=11)
        {
            if ((temp[i]==',' && temp[i+1]==' ') || temp[i]=='\n')
            {
                info[j]='\0';
                switch (flag_info)
                {
                case 1:
                    strcpy(temp_struct_academic->name,info);
                    break;
                case 2:
                    strcpy(temp_struct_academic->family,info);
                    break;
                case 3:
                    strcpy(temp_struct_academic->date_start,info);
                    break;
                case 4:
                    strcpy(temp_struct_academic->rate,info);
                    break;
                case 5:
                    strcpy(temp_struct_academic->phone_num,info);
                    break;
                case 6:
                    strcpy(temp_struct_academic->email,info);
                    break;
                case 7:
                    strcpy(temp_struct_academic->user_Name,info);
                    break;
                case 8:
                    strcpy(temp_struct_academic->pass1,info);
                    break;
                case 9:
                    strcpy(temp_struct_academic->limit_time,info);
                    break;
                case 10:
                    strcpy(temp_struct_academic->ekhraj,info);
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
            i++;
        }
        temp_struct_academic->link=NULL;
        end_struct_academic->link=temp_struct_academic;
        end_struct_academic=temp_struct_academic;
    }
    fclose(academic);
    free(temp_struct_academic);
    return 0;
}
void show_list_users(int status)//eit bayad bokhore bara vaghti ke karbari voojood nadare
{
    char temp[25];
    int i=1;
    if (status==0 || status==1)
    {
        // system("cls");;
        printf("list of Departemant\n_______________________________________\n\n");
        temp_struct_departemant=malloc(sizeof(struct struct_departemant));
        temp_struct_departemant=start_struct_departemant;
        do
        {
            if (temp_struct_departemant->name[0]=='0')//file is NULL
            {
                printf("-----------------------------------\n");
                printf("No result to show!\n");
                printf("-----------------------------------\n");
                break;
            }
            printf("Departemant's %d\n",i++);
            printf("-----------------------------------\n");
            strcpy(temp,"Name: ");
            printf("%s%s\n",temp,temp_struct_departemant->name);
            strcpy(temp,"Family name: ");
            printf("%s%s\n",temp,temp_struct_departemant->family);
            strcpy(temp,"Date start: ");
            printf("%s%s\n",temp,temp_struct_departemant->date_start);
            strcpy(temp,"Name Group: ");
            printf("%s%s\n",temp,temp_struct_departemant->name_of_group);
            strcpy(temp,"ID code: ");
            printf("%s%s\n",temp,temp_struct_departemant->ID_code);
            strcpy(temp,"Phone number: ");
            printf("%s%s\n",temp,temp_struct_departemant->phone_num);
            strcpy(temp,"Email: ");
            printf("%s%s\n",temp,temp_struct_departemant->email);
            strcpy(temp,"User Name: ");
            printf("%s%s\n",temp,temp_struct_departemant->user_Name);
            strcpy(temp,"Password: ");
            unti_hash_to_password(temp_struct_departemant->pass1);
            printf("%s%s\n",temp,temp_struct_departemant->pass1);
            printf("-----------------------------------\n");
            temp_struct_departemant=temp_struct_departemant->link;
        }while(temp_struct_departemant!=NULL);
        free_departemant();
        if (status==1)
        {
            printf("Preas Enter to back list");
            do
            {
                temp[0]=getch();
            } while (temp[0]!=13);
            return ;
        }
    }
    printf("Preas Enter to show list of Academic\n");
    do
    {
        temp[0]=getch();
    }while (temp[0]!=13);
    temp_struct_academic=malloc(sizeof(struct struct_academic));
    temp_struct_academic=start_struct_academic;
    i=1;
    do
    {
        if (temp_struct_academic->name[0]=='0')//file is NULL
            {
                printf("No result to show!\n");
                break;
            }
        if (temp_struct_academic->ekhraj[0]=='N')
        {
            printf("Academic's %d\n",i++);
            printf("-----------------------------------\n");
            strcpy(temp,"Name: ");
            printf("%s%s\n",temp,temp_struct_academic->name);
            strcpy(temp,"Family name: ");
            printf("%s%s\n",temp,temp_struct_academic->family);
            strcpy(temp,"Date start: ");
            printf("%s%s\n",temp,temp_struct_academic->date_start);
            strcpy(temp,"Rate of Academic: ");
            printf("%s%s\n",temp,temp_struct_academic->rate);
            strcpy(temp,"Phone number: ");
            printf("%s%s\n",temp,temp_struct_academic->phone_num);
            strcpy(temp,"Email: ");
            printf("%s%s\n",temp,temp_struct_academic->email);
            strcpy(temp,"User Name: ");
            printf("%s%s\n",temp,temp_struct_academic->user_Name);
            strcpy(temp,"Password: ");
            unti_hash_to_password(temp_struct_academic->pass1);
            printf("%s%s\n",temp,temp_struct_academic->pass1);
            printf("-----------------------------------\n");
        }
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    

    printf("Preas enter to back menu\n");
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
    free_academic();
    // system("cls");;
}

void add_linked_list_academi_to_notpadd()
{
    FILE *Academic;
    Academic=fopen("file_academic.txt","w");
    temp_struct_academic=malloc(sizeof(struct struct_academic));
    if (temp_struct_academic==NULL)
    {
        printf("memory is not Allow!! Try later.");
        return ;
    }
    temp_struct_academic=start_struct_academic;
    char final[225]={0},temp[50];
    do
    {
        strcpy(temp,temp_struct_academic->name);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->family);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->date_start);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->rate);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->phone_num);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->email);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->user_Name);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->pass1);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->limit_time);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_academic->ekhraj);
        strcat(final,temp);
        strcat(final,"\n");
        fputs(final,Academic);
        strcpy(final,"\0");
        temp_struct_academic=temp_struct_academic->link;

    } while (temp_struct_academic!=NULL);
    free(temp_struct_academic);
    printf("Successfully! preas Enter to Back menu\n");
    fclose(Academic);
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
}
void kick_user()
{
    char user_name[20];
    int flag;
    printf("Enter user name that you want kick\n");
    printf("if you ceed of opreation preas Enter: ");
    do
    {
        gets(user_name);
        str_to_lower(user_name);
        if (strlen(user_name)==0)
        {
            // system("cls");
            return ;
        }
        flag=search_user_name_academic(user_name);
        if (flag==1)
            printf("user not found!! Try agian: ");
    } while (flag);
    if (temp_struct_academic->ekhraj[0]!='N')
    {
        printf("This user already kicked from program!\n");
        printf("Preas Enter to back menu\n");
        do
        {
            user_name[0]=getch();
        } while (user_name[0]!=13);
        // system("cls");;
        return ;
    }    
    if (flag==0)
    {
        char date[20];
        get_now_time(date);
        strcpy(temp_struct_academic->ekhraj,date);
        free_academic();
        add_linked_list_academi_to_notpadd();
    }
}
void list_of_log_print()
{
    char temp[25],line_char='|';
    printf("\n---------------------------\n");
    for(int i=0; i<4; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"List info Academic");
        break;
    case 1:
        strcpy(temp,"List Departemant");
        break;
    case 2:
        strcpy(temp,"List User Dismissed");
        break;
    case 3:
        strcpy(temp,"Back to Menu");
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
void list_of_log_academic()
{
    // system("cls");;
    printf("list of Academic\n_______________________________________\n\n");
    temp_struct_academic=malloc(sizeof(struct struct_academic));
    temp_struct_academic=start_struct_academic;
    int i=1;
    char temp[25];
    do
    {
    if (temp_struct_academic->name[0]=='0')//file is NULL
        {
            printf("-----------------------------------\n");
            printf("No result to show!\n");
            printf("-----------------------------------\n");
            break;
        }
        printf("Academic's %d\n",i++);
        printf("-----------------------------------\n");
        strcpy(temp,"Name: ");
        printf("%s%s\n",temp,temp_struct_academic->name);
        strcpy(temp,"Family name: ");
        printf("%s%s\n",temp,temp_struct_academic->family);
        strcpy(temp,"Date start: ");
        printf("%s%s\n",temp,temp_struct_academic->date_start);
        strcpy(temp,"Rate of Academic: ");
        printf("%s%s\n",temp,temp_struct_academic->rate);
        strcpy(temp,"Phone number: ");
        printf("%s%s\n",temp,temp_struct_academic->phone_num);
        strcpy(temp,"Email: ");
        printf("%s%s\n",temp,temp_struct_academic->email);
        strcpy(temp,"User Name: ");
        printf("%s%s\n",temp,temp_struct_academic->user_Name);
        strcpy(temp,"Password: ");
        unti_hash_to_password(temp_struct_academic->pass1);
        printf("%s%s\n",temp,temp_struct_academic->pass1);
        strcpy(temp,"Status: ");
        if (temp_struct_academic->ekhraj[0]=='N')
            printf("%sin Work\n",temp);
        else
            printf("%sDismissed at %s\n",temp,temp_struct_academic->ekhraj);
        printf("-----------------------------------\n");
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    printf("Preas Enter to back list");
    free_academic();
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
}
void list_of_log_dismissed()
{
// system("cls");;
    printf("list of Academic\n_______________________________________\n\n");
    temp_struct_academic=malloc(sizeof(struct struct_academic));
    temp_struct_academic=start_struct_academic;
    int i=1;
    char temp[25];
    do
    {
        if (temp_struct_academic->name[0]=='0')//file is NULL
            {
                printf("-----------------------------------\n");
                printf("No result to show!\n");
                printf("-----------------------------------\n");
                break;
            }
        if (temp_struct_academic->ekhraj[0]!='N')
        {
            printf("Academic's %d\n",i++);
            printf("-----------------------------------\n");
            strcpy(temp,"Name: ");
            printf("%s%s\n",temp,temp_struct_academic->name);
            strcpy(temp,"Family name: ");
            printf("%s%s\n",temp,temp_struct_academic->family);
            strcpy(temp,"Date start: ");
            printf("%s%s\n",temp,temp_struct_academic->date_start);
            strcpy(temp,"Rate of Academic: ");
            printf("%s%s\n",temp,temp_struct_academic->rate);
            strcpy(temp,"Phone number: ");
            printf("%s%s\n",temp,temp_struct_academic->phone_num);
            strcpy(temp,"Email: ");
            printf("%s%s\n",temp,temp_struct_academic->email);
            strcpy(temp,"User Name: ");
            printf("%s%s\n",temp,temp_struct_academic->user_Name);
            strcpy(temp,"Password: ");
            unti_hash_to_password(temp_struct_academic->pass1);
            printf("%s%s\n",temp,temp_struct_academic->pass1);
            strcpy(temp,"Status: ");
            printf("%sDismissed at %s\n",temp,temp_struct_academic->ekhraj);
            printf("-----------------------------------\n");
        }
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    if (i==1 && temp_struct_academic->name[0]!='0')
        printf("No one of Academic has't dismissed!\n");
    printf("Preas Enter to back list\n");
    free_academic();
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
}
void get_backup()
{
    char file_location[100];
    int len,i,flag_whlie;
    printf("Please Enter location file that you want save backup\n");
    printf("note:you must enter name file whit this form: c:/blau blau/name file\n");
    do{
        flag_whlie=0;
        gets(file_location);
        //---------- checkt addres
        len=strlen(file_location);
        for (i=0; i<len; i++)
            if (file_location[i]=='\\' || (file_location[i]==':' && i!=1)|| file_location[i]=='*' || file_location[i]=='?' || file_location[i]=='\"' 
            || file_location[i]=='>' || file_location[i]=='<' || file_location[i]=='|' || (file_location[i]=='/' && file_location[i+1]=='/'))
            {
                printf("Invalid file locatin!! Try agian\n");
                flag_whlie++;
                break;
            }
            if (!isalpha(file_location[0]) || file_location[1]!=':' || file_location[2]!='/')
            {
                printf("Invalid file locatin!! Try agian\n");
                flag_whlie++;
            }   
    }while(flag_whlie);
    if (file_location[len-1]=='/')
        file_location[len-1]='\0';

    char time[20];
    get_now_time(time);
    
    //------------------ change format time
    len=strlen(time);
    
    for (i=0;i<len;i++)
        if (time[i]=='/')
            time[i]='_';
        else if (time[i]=='|')
        {
            time[i]='\0';
            break;
        }
    strcat(file_location,"/Backup_Manage_university_");
    strcat(file_location,time);
    mkdir(file_location);
    char location_departemant[150];
    char read_line[225];
    flag_whlie=0;
    strcpy(location_departemant,file_location);
    strcat(location_departemant,"/file_departemant.txt");
    int flag_file=0;
    FILE *backup_departemant;
    FILE *departemant_main;
    departemant_main=fopen("file_departemant.txt","r");
    if (departemant_main==NULL)
        flag_file++;
    backup_departemant=fopen(location_departemant,"w");
    while(flag_file==0)
    {
        fgets(read_line, 225, departemant_main);
        if (feof(departemant_main)==1)
            break;
        fputs(read_line,backup_departemant);
    }
    fclose(departemant_main);
    fclose(backup_departemant);

    char location_academic[150];
    strcpy(location_academic,file_location);
    strcat(location_academic,"/file_academic.txt");
    FILE *backup_academic;
    FILE *academic_main;
    academic_main=fopen("file_academic.txt","r");
    if (academic_main==NULL)
        flag_file++;
    backup_academic=fopen(location_academic,"w");
    while(1)
    {
        fgets(read_line, 225, academic_main);
        if (feof(academic_main)==1)
            break;
        fputs(read_line,backup_academic);
    }
    fclose(academic_main);
    fclose(backup_academic);

    printf("backup_complit!\nprease Enter to continue\n");
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);
    // system("cls");
}
void load_backup()
{
    char file_location[100];
    int len,i,flag_whlie;
    printf("Please Enter location file that you want save backup\n");
    printf("note:you must enter name file whit this form: C:/New folder/Backup_Manage_university_2026_01_21\n");
    do{
        flag_whlie=0;
        gets(file_location);
        //---------- checkt addres
        len=strlen(file_location);
        for (i=0; i<len; i++)
            if (file_location[i]=='\\' || (file_location[i]==':' && i!=1)|| file_location[i]=='*' || file_location[i]=='?' || file_location[i]=='\"' 
            || file_location[i]=='>' || file_location[i]=='<' || file_location[i]=='|' || (file_location[i]=='/' && file_location[i+1]=='/'))
            {
                printf("Invalid file locatin!! Try agian\n");
                flag_whlie++;
                break;
            }
            if (!isalpha(file_location[0]) || file_location[1]!=':' || file_location[2]!='/')
            {
                printf("Invalid file locatin!! Try agian\n");
                flag_whlie++;
            }   
    }while(flag_whlie);
    if (file_location[len-1]=='/')
        file_location[len-1]='\0';
    
    char location_departemant[150];
    char read_line[225];
    flag_whlie=0;
    strcpy(location_departemant,file_location);
    strcat(location_departemant,"/file_departemant.txt");
    int flag_file=0;
    FILE *backup_departemant;
    FILE *departemant_main;
    backup_departemant=fopen(location_departemant,"r");
    departemant_main=fopen("file_departemant.txt","w");
    if (backup_departemant==NULL)
        flag_file++;
    while(flag_file==0)
    {
        fgets(read_line, 225, backup_departemant);
        if (feof(backup_departemant)==1)
            break;
        fputs(read_line,departemant_main);
    }
    fclose(departemant_main);
    fclose(backup_departemant);

    char location_academic[150];
    strcpy(location_academic,file_location);
    strcat(location_academic,"/file_academic.txt");
    FILE *backup_academic;
    FILE *academic_main;
    backup_academic=fopen(location_academic,"r");
    academic_main=fopen("file_academic.txt","w");
    if (backup_academic==NULL)
        flag_file++;
    while(flag_file==0)
    {
        fgets(read_line, 225, backup_academic);
        if (feof(backup_academic)==1)
            break;
        fputs(read_line,academic_main);
    }
    fclose(academic_main);
    fclose(backup_academic);

    printf("Backup restor compllit!\nprease Enter to continue\n");
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);
    // system("cls");
}

void main()
{
    char *pointer_Uadmin;
    pointer_Uadmin=malloc(sizeof(user_admin));
    pointer_Uadmin=user_admin;
    if (pointer_Uadmin==NULL)
    {
        printf("memory is not allow! Try later");
        return ;
    }
    char *pointer_Padmin;
    pointer_Padmin=malloc(sizeof(pass_admin));
    pointer_Padmin=pass_admin;
    if (pointer_Padmin==NULL)
    {
        printf("memory is not allow! Try later");
        return ;
    }
    long int *pointer_Limit_admin;
    pointer_Limit_admin=malloc(sizeof(limit_admin));
    *pointer_Limit_admin=limit_admin;
    if (pointer_Limit_admin==NULL)
    {
        printf("memory is not allow! Try later");
        return ;
    }
    long int *limit;



    int temp_flag=0,menu_type,type_list_log=0;
    while(1)
    {
    menu_login_print();
    menu_type=menu_login_filter_selection();
    // -------------------------------------------- rotation part
    switch (menu_type)
    {
        case 1:
            unti_hash_to_password(pointer_Padmin);
            int login_flag=get_check_user_pass(pointer_Uadmin,pointer_Padmin,pointer_Limit_admin);// 0:= succces; 1,2:unsaccses; -1:cancel login;
            password_to_hash(pointer_Padmin);
            // system("cls");;
            if (login_flag==0)
            {
                do{
                    menu_admin_page_print();
                    set_departemants_as_link_list();
                    set_academic_as_link_list();
                    menu_type=menu_admin_page_filter_selection();
                    // system("cls");;
                    switch (menu_type)
                    {
                    case 1:
                        set_new_departemant();
                        break;
                    case 2:
                        set_new_academic();
                        break;
                    case 3:
                        show_list_users(0);
                        break;
                    case 4:
                        kick_user();
                        break;
                    case 5:
                        //lsit of Log
                        do{
                            list_of_log_print();
                            type_list_log=menu_login_filter_selection();
                            // system("cls");;
                            switch (type_list_log)
                            {
                            case 1:
                                // system("cls");;
                                list_of_log_academic();
                                // system("cls");;
                                break;
                            case 2:
                                show_list_users(1);
                                // system("cls");;
                                break;
                            case 3:
                                list_of_log_dismissed();
                                // system("cls");;
                                break;
                            default:
                                break;
                            }
                        }while(type_list_log!=4);
                        break;
                    case 6:
                        get_backup();
                        break;
                    case 7:
                        load_backup();
                        break;
                    case 8:
                        break;
                    default:
                        break;
                    }
                }while(menu_type!=8);
            }
            break;
        case 4:
            free(start_struct_academic);
            free(start_struct_departemant);
            return ;
            break;

        default:
            break;
    }
    }

}
