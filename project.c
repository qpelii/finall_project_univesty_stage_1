#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<direct.h>
static char user_admin[10]="admin";
static char pass_admin[20]="5v8a6079zqn";// hashed
char User_Name_static[20];
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
struct struct_course
{
    char name_course[30];
    char vahed[3];
    char type_course[3];
    char code_course[15];
    char status[3];
    struct struct_course *link;
};
struct struct_course *start_struct_course, *end_struct_course, *temp_struct_course;
struct struct_student
{
    char name[20];
    char family[30];
    char ID_code[15];
    char date_birthday[15];
    char location_born[20];
    char major[20];
    char ID_uni[15];
    char phone_num[15];
    char email[40];
    char avg_score[8];
    struct struct_student *link;
};
struct struct_student *start_struct_student, *end_struct_student, *temp_struct_student;
struct struct_score
{
    char ID_uni[15];
    char code_course[15];
    char score[8];
    char date[20];
    char user[20];
    struct struct_score *link;
};
struct struct_score *start_struct_score, *end_struct_score, *temp_struct_score;



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
int check_str_was_flaot(char num[])
{
    int len=strlen(num),i,flag_float=0,flag_num=0;
    for (i=0;i<len;i++)
        if (!isdigit(num[i]))
            if (num[i]=='.' && flag_float==0)
            {
                if (i==0 || i==len-1)
                    return 1;
                else
                    flag_float++;
            }
            else
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
int check_str_whitout_punct(char string[])
{
    int len=strlen(string),i;
    for (i=0;i<len;i++)
        if (ispunct(string[i]))
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
void im_not_robot(char ImNotRObot[7])
{

    char charater[]="ABCDEFGHJKLMNPQRSTUVWXYZ23456789";
    int i;
    for (i=0;i<6;i++)
        ImNotRObot[i]=charater[rand()%32];
    ImNotRObot[6]='\0';
    
}
void desplay_ImnotRobot(char imnotrobot[])
{
    char im_not_robot[12];
    im_not_robot[10]=imnotrobot[5];
    im_not_robot[8]=imnotrobot[4];
    im_not_robot[6]=imnotrobot[3];
    im_not_robot[4]=imnotrobot[2];
    im_not_robot[2]=imnotrobot[1];
    im_not_robot[0]=imnotrobot[0];
    char charater[]="!@#$%^&*()_+";
    int i;
    for (i=1;i<11;i+=2)
        im_not_robot[i]=charater[rand()%12];
    im_not_robot[11]='\0';
    printf("%s",im_not_robot);
}
int get_im_not_robot()
{
    char ImNotRObot_mian[6];
    char input[10];
    printf("if you want cancel proses just press Enter\n");
    printf("Enter this code whitout junk character (!@#$%) for Confrim Opration:\n");
    do{
        im_not_robot(ImNotRObot_mian);
        desplay_ImnotRobot(ImNotRObot_mian);
        str_to_lower(ImNotRObot_mian);
        printf("\n");
        gets(input);
        str_to_lower(input);
        if (strlen(input)==0)
            return -1;
        else if (strcmp(input,ImNotRObot_mian)==0 && strlen(input)==strlen(ImNotRObot_mian))
            return 0;
        else 
            printf("Invalid!! enter new code\n");
            printf("__________________________________\n");
    }while(1);
}
int check_corect_pass_and_set_limit(char corect_pass[], int limit_time)
{
    // note: if corect --> return 0;  ||  if invalid --> return 1;  ||  if have limit -->return 2; if want Exit -->return -1;
    int i;
    char pass[50]={0};
    int flag_Im_not_Robot=0;
    if (limit_time-time(NULL)>0)
        return 2;
    for(i=0;i<3;i++)
    {
        printf("eneter your password:");
        password_to_star(pass);
        if (strlen(pass)==0)
            return -1;
        flag_Im_not_Robot=get_im_not_robot();
        if (flag_Im_not_Robot==-1)
            return -1;
        
        int len_get_pass=strlen(pass),len_corect_pass=strlen(corect_pass);
        if (strcmp(pass,corect_pass)==0 && len_corect_pass==len_get_pass)
            return 0;
        else
        {
            if (i==2)
                return 1;
            printf("\nInvalid password!! you have %d time's for enter password, carefull!\n",2-i);
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
void free_course()
{
    if (temp_struct_course==NULL)
    {
        free(temp_struct_course);
        return ;
    }
    do
    {
        temp_struct_course=temp_struct_course->link;
        continue;
    } while (temp_struct_course!=NULL);
    free(temp_struct_course);
}
void free_student()
{
    if (temp_struct_student==NULL)
    {
        free(temp_struct_student);
        return ;
    }
    do
    {
        temp_struct_student=temp_struct_student->link;
        continue;
    } while (temp_struct_student!=NULL);
    free(temp_struct_student);
}
void free_score()
{
    if (temp_struct_score==NULL)
    {
        free(temp_struct_score);
        return ;
    }
    do
    {
        temp_struct_score=temp_struct_score->link;
        continue;
    } while (temp_struct_score!=NULL);
    free(temp_struct_score);
}
int get_check_user_pass(char user_corect[], char corect_pass[],long int *limit_time)
{
    // -------------------- just user_name
    char user[30];
    int flag_user=0;
    if (strcmp(user_corect,user_admin)==0)//user is admin
    {
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
    }
    // -------------------- just password
    // ------------------------------ note: corect--> return 0 else 1,2 || cancel login -1;
    int flag_pass=check_corect_pass_and_set_limit(corect_pass,*limit_time);

    if (flag_pass==-1)
        // ---------- cancel login OR cancel Im not robot
        return -1;
    if (flag_pass==0)
    // ------------- dont have limit and pass is corcet! *and Im not robot corect!
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
int menu_selection_1_6()
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
            if (num>6 || num<1)
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
int menu_selection_1_7()
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

            // // system("cls");;
            return num;
        }
    } while (flag);

}
int menu_selection_1_8()
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
    if (len==0)
        return 1;
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
    if (len==0)
        return 1;
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
    temp_struct_departemant=malloc(sizeof(struct struct_departemant));
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
int search_course_code(char code[])
{
    temp_struct_course=malloc(sizeof(struct struct_course));
    temp_struct_course=start_struct_course;
    do
    {
        if (strcmp(temp_struct_course->code_course,code)==0 && strlen(temp_struct_course->code_course)==strlen(code))
            return 0;
        temp_struct_course=temp_struct_course->link;
    }while(temp_struct_course!=NULL);
    free(temp_struct_course);
    return 1;// 0:= fine | 1:=not found
}
int search_user_name_student(char ID_uni[])
{
    temp_struct_student=malloc(sizeof(struct struct_student));
    temp_struct_student=start_struct_student;
    do
    {
        if (strcmp(temp_struct_student->ID_uni,ID_uni)==0 && strlen(temp_struct_student->ID_uni)==strlen(ID_uni))
            return 0;
        temp_struct_student=temp_struct_student->link;
    }while(temp_struct_student!=NULL);
    free(temp_struct_student);
    return 1;// 0:= fine | 1:=not found
}
int search_user_name_student_sync_with_code_sourse(char ID_uni[], char code[])
{
    temp_struct_score=malloc(sizeof(struct struct_score));
    if (temp_struct_score==NULL)
    {
        printf("memory not allowed!");
        return 1;
    }
    temp_struct_score=start_struct_score;
    
    do
    {
        if (strcmp(temp_struct_score->ID_uni,ID_uni)==0 && strlen(temp_struct_score->ID_uni)==strlen(ID_uni) &&
            strcmp(temp_struct_score->code_course,code)==0 && strlen(temp_struct_score->code_course)==strlen(code))
            return 0;// found
        temp_struct_score=temp_struct_score->link;
    }while(temp_struct_score!=NULL);
    free(temp_struct_score);
    return 1;// 0:= fine | 1:=not found
}
int get_user_pass_user_academics()
{
    char user[20];
    int user_found_flag=0;
    char password[50],str_limit_time[10];
    long int limit_time;
    // limit_time=malloc(sizeof(long int));
    printf("note: if you want Exit from Login page's, Just prsse enter\n");
    do{
        printf("enter your User Name: ");
        gets(user);
        if (strlen(user)==0)
            return -1;
        str_to_lower(user);
        user_found_flag=search_user_name_academic(user);
        if (user_found_flag==0)// is academic
        {
            if (temp_struct_academic->ekhraj[0]!='N')
            {
                printf("Sorry! you have been kicked from admin\nyou can take conaction whit admin to fix that\nPress Enter to back menu");
                free_academic();
                do
                {
                    user[0]=getch();
                } while (user[0]!=13);
                
                return 1;
            }
            strcpy(password,temp_struct_academic->pass1);
            limit_time=atol(temp_struct_academic->limit_time);
            strcpy(User_Name_static,temp_struct_academic->user_Name);
            user_found_flag= get_check_user_pass(user,password,&limit_time);
            ltoa(limit_time,temp_struct_academic->limit_time,10);
            free_academic();
            break;
        }
        else // not found
        {
            printf("User name not found!Try Agian\n");
            continue;
        }
    }while(1);    
        return user_found_flag;
    
}
int get_user_pass_user_departemnts()
{
    char user[20];
    int user_found_flag=0;
    char password[50],str_limit_time[10];
    long int limit_time;
    // limit_time=malloc(sizeof(long int));
    printf("note: if you want Exit from Login page's, Just prsse enter\n");
    do{
        printf("enter your User Name: ");
        gets(user);
        if (strlen(user)==0)
            return -1;
        str_to_lower(user);
        user_found_flag=search_user_name_departemant(user);
        if (user_found_flag==0)// is departemant
        {
            strcpy(password,temp_struct_departemant->pass1);
            unti_hash_to_password(password);
            limit_time=atol(temp_struct_departemant->limit_time);
            strcpy(User_Name_static,temp_struct_departemant->user_Name);
            user_found_flag= get_check_user_pass(user,password,&limit_time);
            ltoa(limit_time,temp_struct_departemant->limit_time,10);
            free_departemant();
            break;
        }
        else // not found
        {
            printf("User name not found!Try Agian\n");
            continue;
        }
    }while(1);    
        return user_found_flag;
    
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
    str_to_lower(name);

    printf("Enter family: ");
    do{
        gets(family);
        if (check_str_full_alpha_whit_space(family) || strlen(family)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);
    str_to_lower(family);

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
    str_to_lower(name_of_group);

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
    str_to_lower(email);

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
            printf("too few character!(minimum character is 8) Try again: ");
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
    printf("Successfully added!\npress Enter to continue\n");
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
            printf("too few character!(minimum character is 8)! Try again: ");
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
    printf("Successfully added!\npress Enter to continue\n");
    fclose(file_academic);
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);


}
void set_new_student()
{
    FILE *file_student;
    file_student=fopen("file_student.txt","a");
    if (file_student==NULL)
    {
        printf("memory is not allowed!");
        return ;
    }
    char name[20],family[30],date_birthday[15],location_born[20],ID_code[15],phone_num[15],email[40],major[20],ID_uni[30];
    printf("Please enter this information about Student\n");

    printf("Enter name: ");
    do{
        gets(name);
        if (check_str_full_alpha_whit_space(name) || strlen(name)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);
    str_to_lower(name);

    printf("Enter family: ");
    do{
        gets(family);
        if (check_str_full_alpha_whit_space(family) || strlen(family)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);
    str_to_lower(family);

    printf("Enter ID: ");
    do{
        gets(ID_code);
        if (check_str_was_int(ID_code) || strlen(ID_code)!=10)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter date Birthday Student\n(hint:enter whith this form YYYY/MM/DD): ");
    do{
        gets(date_birthday);
        if (check_str_date(date_birthday) || strlen(date_birthday)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Location that student born: ");
    do{
        gets(location_born);
        if (check_str_full_alpha_whit_space(location_born) || strlen(location_born)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);
    str_to_lower(location_born);

    printf("Enter Major: ");
    do{
        gets(major);
        if (check_str_full_alpha_whit_space(major) || strlen(major)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter ID of university: ");
    do{
        gets(ID_uni);
        if (check_str_was_int(ID_uni) || strlen(ID_uni)!=10)
            printf("Invalid input! Try again: ");
        else if (search_user_name_student(ID_uni)==0)
            printf("this ID of university is duplicated! Tyr agian: ");
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
    str_to_lower(email);

    // ----------------------------------file apend
    fputs(name,file_student);
    fputs(", ",file_student);
    fputs(family,file_student);
    fputs(", ",file_student);
    fputs(ID_code,file_student);
    fputs(", ",file_student);
    fputs(date_birthday,file_student);
    fputs(", ",file_student);
    fputs(location_born,file_student);
    fputs(", ",file_student);
    fputs(major,file_student);
    fputs(", ",file_student);
    fputs(ID_uni,file_student);
    fputs(", ",file_student);
    fputs(phone_num,file_student);
    fputs(", ",file_student);
    fputs(email,file_student);
    fputs(", ",file_student);
    fputc('N',file_student);// avg score
    fputc('\n',file_student);
    printf("Successfully added!\npress Enter to continue\n");
    fclose(file_student);
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);


}
void set_new_score()
{
    char ID_uni[15],code_course[15],score[7],date_set[20],user_name[20];
    char temp;
    printf("Note: if you want exit from this proses just press Enter\n");
    printf("Enter ID univrsity of student: ");
    do
    {
        gets(ID_uni);
        if (strlen(ID_uni)==0)
            return ;
        else if (check_str_was_int(ID_uni)==1)
            printf("Invalid input! Try agian: ");
        else if (search_user_name_student(ID_uni)==1)
            printf("Student not submit yet! enter another ID: ");
        else 
        {
            free_student();
            break;
        }
    } while (1);
    printf("Enter Code of course: ");
    do
    {
        gets(code_course);
        if (strlen(code_course)==0)
            return ;
        else if (check_str_was_int(ID_uni)==1)
            printf("Invalid input! Try agian: ");
        else if (search_course_code(code_course)==1)
            printf("course not submit yet! Enter another code course: ");
        else 
        {
            free_course();
            break;
        }
    } while (1);

    if (search_user_name_student_sync_with_code_sourse(ID_uni,code_course)==0)
    {
        printf("this steudent alrady set Score!!\n");
        free_score();
        printf("press Enter to back Menu\n");
        do
        {
            temp=getch();
        } while (temp!=13);
        return ;
    }
    printf("Enter Score student: ");
    do
    {
        gets(score);
        if (strlen(score)==0)
            return ;
        else if (check_str_was_flaot(score)==1)
            printf("Invalid format! Try agian: ");
        else 
            break;
    } while (1);
    get_now_time(date_set);
    strcpy(user_name,User_Name_static);

    FILE *file_score_student;
    file_score_student=fopen("file_score_student.txt","a");

    fputs(ID_uni,file_score_student);
    fputs(", ",file_score_student);
    fputs(code_course,file_score_student);
    fputs(", ",file_score_student);
    fputs(score,file_score_student);
    fputs(", ",file_score_student);
    fputs(date_set,file_score_student);
    fputs(", ",file_score_student);
    fputs(User_Name_static,file_score_student);
    fputc('\n',file_score_student);
    printf("Successfully added!\npress Enter to continue\n");
    fclose(file_score_student);
    do
    {
        temp=getch();
    } while (temp!=13);
    // system("cls");
    
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
                    strcpy(temp_struct_departemant->limit_time,info);
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
int set_student_as_link_list()
{
    start_struct_student=malloc(sizeof(struct struct_student));
    if (start_struct_student==NULL)
    {
        printf("memory is not allowed!");
        return 1;
    }
    end_struct_student=start_struct_student;

    FILE *student;
    student=fopen("file_student.txt", "r");
    if (student==NULL)
    {
        fclose(student);
        start_struct_student->name[0]='0';// if file was NULL
        start_struct_student->link=NULL;
        return 1;
    } 
    char temp[225],info[50]={0};
    int i=0,j=0,flag_info=1;
    temp[0]='\0';
    fgets(temp,225,student);
    if (strlen(temp)==0)
    {
        fclose(student);
        start_struct_student->name[0]='0';// if file was NULL
        start_struct_student->link=NULL;
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
                strcpy(start_struct_student->name,info);
                break;
            case 2:
                strcpy(start_struct_student->family,info);
                break;
            case 3:
                strcpy(start_struct_student->ID_code,info);
                break;
            case 4:
                strcpy(start_struct_student->date_birthday,info);
                break;
            case 5:
                strcpy(start_struct_student->location_born,info);
                break;
            case 6:
                strcpy(start_struct_student->major,info);
                break;
            case 7:
                strcpy(start_struct_student->ID_uni,info);
                break;
            case 8:
                strcpy(start_struct_student->phone_num,info);
                break;
            case 9:
                strcpy(start_struct_student->email,info);
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
    start_struct_student->link=NULL;
    
    while (1)
    {
        temp_struct_student=malloc(sizeof(struct struct_student));
        temp[0]='\0';
        fgets(temp,225,student);
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
                    strcpy(temp_struct_student->name,info);
                    break;
                case 2:
                    strcpy(temp_struct_student->family,info);
                    break;
                case 3:
                    strcpy(temp_struct_student->ID_code,info);
                    break;
                case 4:
                    strcpy(temp_struct_student->date_birthday,info);
                    break;
                case 5:
                    strcpy(temp_struct_student->location_born,info);
                    break;
                case 6:
                    strcpy(temp_struct_student->major,info);
                    break;
                case 7:
                    strcpy(temp_struct_student->ID_uni,info);
                    break;
                case 8:
                    strcpy(temp_struct_student->phone_num,info);
                    break;
                case 9:
                    strcpy(temp_struct_student->email,info);
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
        temp_struct_student->link=NULL;
        end_struct_student->link=temp_struct_student;
        end_struct_student=temp_struct_student;
    }
    fclose(student);
    free(temp_struct_student);
    return 0;
}
int set_score_student_as_link_list()
{
    start_struct_score=malloc(sizeof(struct struct_score));
    if (start_struct_score==NULL)
    {
        printf("memory is not allowed!");
        return 1;
    }
    end_struct_score=start_struct_score;

    FILE *score;
    score=fopen("file_score_student.txt", "r");
    if (score==NULL)
    {
        fclose(score);
        start_struct_score->ID_uni[0]='N';// if file was NULL
        start_struct_score->link=NULL;
        return 1;
        }
        
    char temp[225],info[50]={0};
    int i=0,j=0,flag_info=1;
    temp[0]='\0';
    fgets(temp,225,score);
    if (strlen(temp)==0)
    {
        fclose(score);
        start_struct_score->ID_uni[0]='N';// if file was NULL
        start_struct_score->link=NULL;
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
                strcpy(start_struct_score->ID_uni,info);
                break;
            case 2:
                strcpy(start_struct_score->code_course,info);
                break;
            case 3:
                strcpy(start_struct_score->score,info);
                break;
            case 4:
                strcpy(start_struct_score->date,info);
                break;
            case 5:
                strcpy(start_struct_score->user,info);
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
    start_struct_score->link=NULL;

    while (1)
    {
        temp_struct_score=malloc(sizeof(struct struct_score));
        temp[0]='\0';
        fgets(temp,225,score);
        if (strlen(temp)==0)
            break;
        flag_info=1,i=0,j=0;
        while(flag_info!=6)
        {
            if ((temp[i]==',' && temp[i+1]==' ') || temp[i]=='\n')
            {
                info[j]='\0';
                switch (flag_info)
                {
                case 1:
                strcpy(temp_struct_score->ID_uni,info);
                break;
            case 2:
                strcpy(temp_struct_score->code_course,info);
                break;
            case 3:
                strcpy(temp_struct_score->score,info);
                break;
            case 4:
                strcpy(temp_struct_score->date,info);
                break;
            case 5:
                strcpy(temp_struct_score->user,info);
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
        temp_struct_score->link=NULL;
        end_struct_score->link=temp_struct_score;
        end_struct_score=temp_struct_score;
    }
    fclose(score);
    free(temp_struct_score);
    return 0;
}
void show_list_users(int status)
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
            strcpy(temp,"Name");
            printf("%-20s%s\n",temp,temp_struct_departemant->name);
            strcpy(temp,"Family name");
            printf("%-20s%s\n",temp,temp_struct_departemant->family);
            strcpy(temp,"Date start");
            printf("%-20s%s\n",temp,temp_struct_departemant->date_start);
            strcpy(temp,"Name Group");
            printf("%-20s%s\n",temp,temp_struct_departemant->name_of_group);
            strcpy(temp,"ID code");
            printf("%-20s%s\n",temp,temp_struct_departemant->ID_code);
            strcpy(temp,"Phone number");
            printf("%-20s%s\n",temp,temp_struct_departemant->phone_num);
            strcpy(temp,"Email");
            printf("%-20s%s\n",temp,temp_struct_departemant->email);
            strcpy(temp,"User Name");
            printf("%-20s%s\n",temp,temp_struct_departemant->user_Name);
            strcpy(temp,"Password");
            unti_hash_to_password(temp_struct_departemant->pass1);
            printf("%-20s%s\n",temp,temp_struct_departemant->pass1);
            printf("-----------------------------------\n");
            temp_struct_departemant=temp_struct_departemant->link;
        }while(temp_struct_departemant!=NULL);
        free_departemant();
        if (status==1)
        {
            printf("Press Enter to back list");
            do
            {
                temp[0]=getch();
            } while (temp[0]!=13);
            return ;
        }
    }
    printf("Press Enter to show list of Academic\n");
    do
    {
        temp[0]=getch();
    }while (temp[0]!=13);
    printf("-----------------------------------\n");
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
            strcpy(temp,"Name");
            printf("%-20s%s\n",temp,temp_struct_academic->name);
            strcpy(temp,"Family name");
            printf("%-20s%s\n",temp,temp_struct_academic->family);
            strcpy(temp,"Date start");
            printf("%-20s%s\n",temp,temp_struct_academic->date_start);
            strcpy(temp,"Rate of Academic");
            printf("%-20s%s\n",temp,temp_struct_academic->rate);
            strcpy(temp,"Phone number");
            printf("%-20s%s\n",temp,temp_struct_academic->phone_num);
            strcpy(temp,"Email");
            printf("%-20s%s\n",temp,temp_struct_academic->email);
            strcpy(temp,"User Name");
            printf("%-20s%s\n",temp,temp_struct_academic->user_Name);
            strcpy(temp,"Password");
            unti_hash_to_password(temp_struct_academic->pass1);
            printf("%-20s%s\n",temp,temp_struct_academic->pass1);
            printf("-----------------------------------\n");
        }
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    

    printf("Press enter to back menu\n");
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
    fclose(Academic);
}
void add_linked_list_departemant_to_notpadd()
{
    FILE *Departemant;
    Departemant=fopen("file_departemant.txt","w");
    temp_struct_departemant=malloc(sizeof(struct struct_departemant));
    if (temp_struct_departemant==NULL)
    {
        printf("memory is not Allow!! Try later.");
        return ;
    }
    temp_struct_departemant=start_struct_departemant;
    char final[225]={0},temp[50];
    do
    {
        strcpy(temp,temp_struct_departemant->name);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->family);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->date_start);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->name_of_group);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->ID_code);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->phone_num);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->email);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->user_Name);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->pass1);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_departemant->limit_time);
        strcat(final,temp);
        strcat(final,"\n");
        fputs(final,Departemant);
        strcpy(final,"\0");
        temp_struct_departemant=temp_struct_departemant->link;

    } while (temp_struct_departemant!=NULL);
    free(temp_struct_departemant);
    fclose(Departemant);
    
}
void add_linked_list_student_to_notpadd()
{
    FILE *Student;
    Student=fopen("file_student.txt","w");
    temp_struct_student=malloc(sizeof(struct struct_student));
    if (temp_struct_student==NULL)
    {
        printf("memory is not Allow!! Try later.");
        return ;
    }
    temp_struct_student=start_struct_student;
    char final[225]={0},temp[50];
    do
    {
        strcpy(temp,temp_struct_student->name);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->family);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->ID_code);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->date_birthday);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->location_born);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->major);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->ID_uni);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->phone_num);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->email);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_student->avg_score);
        strcat(final,temp);
        strcat(final,"\n");
        fputs(final,Student);
        strcpy(final,"\0");
        temp_struct_student=temp_struct_student->link;

    } while (temp_struct_student!=NULL);
    free(temp_struct_student);
    fclose(Student);
}
void add_linked_list_course_to_notpadd()
{
    FILE *course;
    course=fopen("file_course.txt","w");
    temp_struct_course=malloc(sizeof(struct struct_course));
    if (temp_struct_course==NULL)
    {
        printf("memory is not Allow!! Try later.");
        return ;
    }
    temp_struct_course=start_struct_course;
    char final[225]={0},temp[50];
    do
    {
        strcpy(temp,temp_struct_course->name_course);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_course->vahed);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_course->type_course);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_course->code_course);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_course->status);
        strcat(final,temp);
        strcat(final,"\n");
        fputs(final,course);
        strcpy(final,"\0");
        temp_struct_course=temp_struct_course->link;

    } while (temp_struct_course!=NULL);
    free(temp_struct_course);
    fclose(course);
}
void add_linked_list_score_to_notpadd()
{
    FILE *score;
    score=fopen("file_score_student.txt","w");
    temp_struct_score=malloc(sizeof(struct struct_score));
    if (temp_struct_score==NULL)
    {
        printf("memory is not Allow!! Try later.");
        return ;
    }
    temp_struct_score=start_struct_score;
    char final[225]={0},temp[50];
    do
    {
        strcpy(temp,temp_struct_score->ID_uni);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_score->code_course);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_score->score);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_score->date);
        strcat(final,temp);
        strcat(final,", ");
        strcpy(temp,temp_struct_score->user);
        strcat(final,temp);
        strcat(final,"\n");
        fputs(final,score);
        strcpy(final,"\0");
        temp_struct_score=temp_struct_score->link;

    } while (temp_struct_score!=NULL);
    free(temp_struct_score);
    fclose(score);
}
void press_enter_to_continue()
{
    char temp;
        do
        {
            temp=getch();
        } while (temp!=13);
            // system("cls");
}
void kick_user()
{
    char user_name[20];
    int flag;
    printf("Enter user name that you want kick\n");
    printf("if you ceed of opreation press Enter: ");
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
        printf("Press Enter to back menu\n");
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
        printf("Successfully! press Enter to continue\n");
        char temp;
        do
        {
            temp=getch();
        } while (temp!=13);
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
        strcpy(temp,"Name");
        printf("%-20s%s\n",temp,temp_struct_academic->name);
        strcpy(temp,"Family name");
        printf("%-20s%s\n",temp,temp_struct_academic->family);
        strcpy(temp,"Date start");
        printf("%-20s%s\n",temp,temp_struct_academic->date_start);
        strcpy(temp,"Rate of Academic");
        printf("%-20s%s\n",temp,temp_struct_academic->rate);
        strcpy(temp,"Phone number");
        printf("%-20s%s\n",temp,temp_struct_academic->phone_num);
        strcpy(temp,"Email");
        printf("%-20s%s\n",temp,temp_struct_academic->email);
        strcpy(temp,"User Name");
        printf("%-20s%s\n",temp,temp_struct_academic->user_Name);
        strcpy(temp,"Password");
        unti_hash_to_password(temp_struct_academic->pass1);
        printf("%-20s%s\n",temp,temp_struct_academic->pass1);
        strcpy(temp,"Status");
        if (temp_struct_academic->ekhraj[0]=='N')
            printf("%-20sin Work\n",temp);
        else
            printf("%-20sDismissed at %s\n",temp,temp_struct_academic->ekhraj);
        printf("-----------------------------------\n");
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    printf("Press Enter to back list");
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
            strcpy(temp,"Name");
            printf("%-20s%s\n",temp,temp_struct_academic->name);
            strcpy(temp,"Family name");
            printf("%-20s%s\n",temp,temp_struct_academic->family);
            strcpy(temp,"Date start");
            printf("%-20s%s\n",temp,temp_struct_academic->date_start);
            strcpy(temp,"Rate of Academic");
            printf("%-20s%s\n",temp,temp_struct_academic->rate);
            strcpy(temp,"Phone number");
            printf("%-20s%s\n",temp,temp_struct_academic->phone_num);
            strcpy(temp,"Email");
            printf("%-20s%s\n",temp,temp_struct_academic->email);
            strcpy(temp,"User Name");
            printf("%-20s%s\n",temp,temp_struct_academic->user_Name);
            strcpy(temp,"Password");
            unti_hash_to_password(temp_struct_academic->pass1);
            printf("%-20s%s\n",temp,temp_struct_academic->pass1);
            strcpy(temp,"Status");
            printf("%-20sDismissed at %s\n",temp,temp_struct_academic->ekhraj);
            printf("-----------------------------------\n");
        }
        temp_struct_academic=temp_struct_academic->link;
    }while(temp_struct_academic!=NULL);
    if (i==1 && temp_struct_academic->name[0]!='0')
        printf("No one of Academic has't dismissed!\n");
    printf("Press Enter to back list\n");
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
    // ------------------------------------- backup departemant
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
    // ------------------------------------- backup academic

    flag_file=0;
    char location_academic[150];
    strcpy(location_academic,file_location);
    strcat(location_academic,"/file_academic.txt");
    FILE *backup_academic;
    FILE *academic_main;
    academic_main=fopen("file_academic.txt","r");
    if (academic_main==NULL)
        flag_file++;
    backup_academic=fopen(location_academic,"w");
    while(flag_file==0)
    {
        fgets(read_line, 225, academic_main);
        if (feof(academic_main)==1)
            break;
        fputs(read_line,backup_academic);
    }
    fclose(academic_main);
    fclose(backup_academic);
    // ------------------------------------- backup course
    
    flag_file=0;
    char location_course[150];
    strcpy(location_course,file_location);
    strcat(location_course,"/file_course.txt");
    FILE *backup_course;
    FILE *course_main;
    course_main=fopen("file_course.txt","r");
    if (course_main==NULL)
        flag_file++;
    backup_course=fopen(location_course,"w");
    while(flag_file==0)
    {
        fgets(read_line, 225, course_main);
        if (feof(course_main)==1)
            break;
        fputs(read_line,backup_course);
    }
    fclose(course_main);
    fclose(backup_course);

    // ------------------------------------- backup Score student
    
    flag_file=0;
    char location_score_student[150];
    strcpy(location_score_student,file_location);
    strcat(location_score_student,"/file_score_student.txt");
    FILE *backup_score_student;
    FILE *score_student_main;
    score_student_main=fopen("file_score_student.txt","r");
    if (score_student_main==NULL)
        flag_file++;
    backup_score_student=fopen(location_score_student,"w");
    while(flag_file==0)
    {
        fgets(read_line, 225, score_student_main);
        if (feof(score_student_main)==1)
            break;
        fputs(read_line,backup_score_student);
    }
    fclose(score_student_main);
    fclose(backup_score_student);

    // ------------------------------------- backup student
    
    flag_file=0;
    char location_student[150];
    strcpy(location_student,file_location);
    strcat(location_student,"/file_student.txt");
    FILE *backup_student;
    FILE *student_main;
    student_main=fopen("file_student.txt","r");
    if (student_main==NULL)
        flag_file++;
    backup_student=fopen(location_student,"w");
    while(flag_file==0)
    {
        fgets(read_line, 225, student_main);
        if (feof(student_main)==1)
            break;
        fputs(read_line,backup_student);
    }
    fclose(student_main);
    fclose(backup_student);
    printf("Backup complit!\nPress Enter to continue\n");
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
    // -------------------------------------------------- departemant
    
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
    // --------------------------------------- academic
    
    flag_file=0;
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
    // ------------------------------------ course

    char location_course[150];
    strcpy(location_course,file_location);
    strcat(location_course,"/file_course.txt");
    FILE *backup_course;
    FILE *course_main;
    backup_course=fopen(location_course,"r");
    course_main=fopen("file_course.txt","w");
    if (backup_course==NULL)
        flag_file++;
    while(flag_file==0)
    {
        fgets(read_line, 225, backup_course);
        if (feof(backup_course)==1)
            break;
        fputs(read_line,course_main);
    }
    fclose(course_main);
    fclose(backup_course);
    // --------------------------------------------------- score

    char location_score_student[150];
    strcpy(location_score_student,file_location);
    strcat(location_score_student,"/file_score_student.txt");
    FILE *backup_score_student;
    FILE *score_student_main;
    backup_score_student=fopen(location_score_student,"r");
    score_student_main=fopen("file_score_student.txt","w");
    if (backup_score_student==NULL)
        flag_file++;
    while(flag_file==0)
    {
        fgets(read_line, 225, backup_score_student);
        if (feof(backup_score_student)==1)
            break;
        fputs(read_line,score_student_main);
    }
    fclose(score_student_main);
    fclose(backup_score_student);
    // ------------------------------------------------------- student

    char location_student[150];
    strcpy(location_student,file_location);
    strcat(location_student,"/file_student.txt");
    FILE *backup_student;
    FILE *student_main;
    backup_student=fopen(location_student,"r");
    student_main=fopen("file_student.txt","w");
    if (backup_student==NULL)
        flag_file++;
    while(flag_file==0)
    {
        fgets(read_line, 225, backup_student);
        if (feof(backup_student)==1)
            break;
        fputs(read_line,student_main);
    }
    fclose(student_main);
    fclose(backup_student);

    printf("Backup restor compllit!\npress Enter to continue\n");
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);
    // system("cls");
}
void menu_departemant_print()
{
    char temp[35],line_char='|';
    printf("-----------------------------------\n");
    for(int i=0; i<8; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Add new Course");
        break;
    case 1:
        strcpy(temp,"Set Student score");
        break;
    case 2:
        strcpy(temp,"Edit Student score");
        break;
    case 3:
        strcpy(temp,"Edit Information about Course");
        break;
    case 4:
        strcpy(temp,"Delete Course Information's");
        break;
    case 5:
        strcpy(temp,"Get Log");
        break;
    case 6:
        strcpy(temp,"Settings");
        break;
    case 7:
        strcpy(temp,"Exit from Panle");
        break;
    default:
        break;
    }

    printf("%-30s%c\n",temp,line_char);
    if (i!=7)
        printf("|--+------------------------------|\n");


    }
    printf("-----------------------------------\n\n");
    printf("select a option from menu: ");
}
void list_type_of_course()
{
    char temp[15],line_char='|';
    printf("\n--------------------\n");
    for(int i=0; i<4; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"teori");
        break;
    case 1:
        strcpy(temp,"Amali");
        break;
    case 2:
        strcpy(temp,"Azmayeshgahi");
        break;
    case 3:
        strcpy(temp,"kargahi");
        break;
    default:
        break;
    }

    printf("%-15s%c\n",temp,line_char);
    if (i!=3)
        printf("|--+---------------|\n");


    }
    printf("--------------------\n\n");
}
void add_new_course()
{
    FILE *file_course;
    file_course=fopen("file_course.txt","a");
    if (file_course==NULL)
    {
        printf("memory is not allowed!");
        return ;
    }
    char name[20],vahed[3],type[3],code_course[15];
    printf("Please enter this information about Academic\n");

    printf("Enter name course: ");
    do{
        gets(name);
        if (check_str_whitout_punct(name) || strlen(name)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);
    str_to_lower(name);

    printf("Enter number of \"vahed\": ");
    do{
        gets(vahed);
        if (check_str_was_int(vahed) || strlen(vahed)==0)
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);
    list_type_of_course();
    printf("selcet number of type: ");
    do{
        gets(type);
        if (check_str_was_int(type) || strlen(type)==0 || (type[0]<'1' && type[0]>4))
            printf("Invalid input! Try again: ");
        else
            break;
    }while(1);

    printf("Enter Course Code's: ");
    do{
        gets(code_course);
        if (check_str_was_int(code_course) || strlen(code_course)<4)
            printf("Invalid input! Try again: ");
        else if (search_course_code(code_course)==0)
        {
            printf("this code Course is duplicate! Try agian: ");
            free_course();
        }
        else
            break;
    }while(1);

    // ----------------------------------file apend
    fputs(name,file_course);
    fputs(", ",file_course);
    fputs(vahed,file_course);
    fputs(", ",file_course);
    fputs(type,file_course);
    fputs(", ",file_course);
    fputs(code_course,file_course);
    fputs(", ",file_course);
    fputc('E',file_course);//E :=enable D:=desable
    fputc('\n',file_course);
    fclose(file_course);
    printf("Successfully added!\npress Enter to continue\n");
    char temp;
    do
    {
        temp=getch();
    } while (temp!=13);
}
int set_course_as_link_list()
{
    start_struct_course=malloc(sizeof(struct struct_course));
    if (start_struct_course==NULL)
    {
        printf("memory is not allowed!");
        return 1;
    }
    end_struct_course=start_struct_course;

    FILE *course;
    course=fopen("file_course.txt", "r");
    if (course==NULL)
    {
        fclose(course);
        start_struct_course->name_course[0]='!';// if file was NULL
        start_struct_course->link=NULL;
        return 1;
    } 
    char temp[225],info[50]={0};
    int i=0,j=0,flag_info=1;
    temp[0]='\0';
    fgets(temp,225,course);
    if (strlen(temp)==0)
    {
        fclose(course);
        start_struct_course->name_course[0]='!';// if file was NULL
        start_struct_course->link=NULL;
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
                strcpy(start_struct_course->name_course,info);
                break;
            case 2:
                strcpy(start_struct_course->vahed,info);
                break;
            case 3:
                strcpy(start_struct_course->type_course,info);
                break;
            case 4:
                strcpy(start_struct_course->code_course,info);
                break;
            case 5:
                strcpy(start_struct_course->status,info);
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
    start_struct_course->link=NULL;
    
    while (1)
    {
        temp_struct_course=malloc(sizeof(struct struct_course));
        temp[0]='\0';
        fgets(temp,225,course);
        if (strlen(temp)==0)
            break;
        flag_info=1,i=0,j=0;
        while(flag_info!=6)
        {
            if ((temp[i]==',' && temp[i+1]==' ') || temp[i]=='\n')
            {
                info[j]='\0';
                switch (flag_info)
                {
                case 1:
                    strcpy(temp_struct_course->name_course,info);
                    break;
                case 2:
                    strcpy(temp_struct_course->vahed,info);
                    break;
                case 3:
                    strcpy(temp_struct_course->type_course,info);
                    break;
                case 4:
                    strcpy(temp_struct_course->code_course,info);
                    break;
                case 5:
                    strcpy(temp_struct_course->status,info);
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
        temp_struct_course->link=NULL;
        end_struct_course->link=temp_struct_course;
        end_struct_course=temp_struct_course;
    }
    fclose(course);
    free(temp_struct_course);
    return 0;
}
void menu_academic_print()
{
    char temp[35],line_char='|';
    printf("-----------------------------------\n");
    for(int i=0; i<6; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Add new Student");
        break;
    case 1:
        strcpy(temp,"Edit information Student");
        break;
    case 2:
        strcpy(temp,"Set score");
        break;
    case 3:
        strcpy(temp,"Get Log");
        break;
    case 4:
        strcpy(temp,"Settings");
        break;
    case 5:
        strcpy(temp,"Exit from Panel");
        break;
    default:
        break;
    }

    printf("%-30s%c\n",temp,line_char);
    if (i!=5)
        printf("|--+------------------------------|\n");


    }
    printf("-----------------------------------\n\n");
    printf("Select a option from menu: ");
}
void edit_info_student()
{
    char ID_uni[15];
    char name[20],family[30],date_birthday[15],location_born[20],ID_code[15],phone_num[15],email[40],major[20];
    int flag_user_found=0;
    printf("enter ID university of studet\nif you dessuaded fro edit just press Enter\n");
    do{
        gets(ID_uni);
        if (strlen(ID_uni)==0)
            return ;
        flag_user_found=search_user_name_student(ID_uni);
        if (flag_user_found)
            printf("Student whit this ID university not found! Try agian: ");
        
    }while(flag_user_found);
    printf("if you don't want edit, just press Enter\n");

    printf("Enter name: ");
    do{
        gets(name);
        if (strlen(name)==0)
            break;
        else if (check_str_full_alpha_whit_space(name))
            printf("Invalid input! Try again: ");
        else
        {
            strcpy(temp_struct_student->name,name);
            break;
        }
    }while(1);

    printf("Enter family: ");
    do{
        gets(family);
        if (strlen(family)==0)
            break;
        else if (check_str_full_alpha_whit_space(family))
            printf("Invalid input! Try again: ");
        else
        {
            strcpy(temp_struct_student->family,family);
            break;
        }
    }while(1);

    printf("Enter Major: ");
    do{
        gets(major);
        if (strlen(major)==0)
            break;
        else if (check_str_full_alpha_whit_space(major))
            printf("Invalid input! Try again: ");
        else
        {
            strcpy(temp_struct_student->major,major);
            break;
        }
    }while(1);

    printf("Enter Phone number(whit this form 09123456789): ");
    do{
        gets(phone_num);
        if (strlen(phone_num)==0)
            break;
        else if (check_str_was_int(phone_num) || phone_num[0]!='0' || phone_num[1]!='9' || strlen(phone_num)!=11)
            printf("Invalid input! Try again: ");
        else
        {
            strcpy(temp_struct_student->phone_num,phone_num);
            break;
        }
    }while(1);

    printf("Enter Email: ");
    do{
        gets(email);
        if (strlen(email)==0)
            break;
        else if (check_email(email))
            printf("Invalid input! Try again: ");
        else
        {
            strcpy(temp_struct_student->email,email);
            break;
        }
    }while(1);

    free_student();
    printf("Process compelit! Press Enter to continue\n");
    do
    {
        ID_uni[0]=getch();
    } while (ID_uni[0]!=13);
    
    
}
void edit_score_student()
{
    char ID_uni[20],code_course[20];
    printf("if you want Exit from proses just perss enter\n");
    printf("Enter ID university of Student: ");
    do
    {
        gets(ID_uni);
        if (strlen(ID_uni)==0)
            return ;
        else if (check_str_was_int(ID_uni)==1)
            printf("This format is Invalid! Try agian: ");
        else if (search_user_name_student(ID_uni)==1)
            printf("not found student whit tish ID! Try agian: ");
        else
            break;
    } while (1);

    int flag_found=0;
    printf("enter code of course: ");
    do
    {
        gets(code_course);
        if (strlen(code_course)==0)
            return ;
        else if (check_str_was_int(code_course)==1)
            printf("this format is Invalid! Try agian: ");
        else
        {
            flag_found=search_user_name_student_sync_with_code_sourse(ID_uni,code_course);
            break;
        }   

    } while (1);
    
    if (flag_found==1)
        printf("student whit this data not found! first you need set socre from student and then edit score!\n\n");
    
    else if (flag_found==0)
    {
        printf("Old score: %s",temp_struct_score->score);
        printf("\nEnter new Score: ");
        do
        {
            gets(ID_uni);// baraye in ce moteghayere ezafa add nakonam
            if (strlen(ID_uni)==0 || check_str_was_flaot(ID_uni)==1)
                printf("Invlid! Try again: ");
            else
                break;
        } while (1);
        strcpy(ID_uni,temp_struct_score->score);
        free_score();
        printf("edited whit Successfully! Press Enter for back to menu\n");
        do
        {
            ID_uni[0]=getch();
        } while (ID_uni[0]!=13);
            // system("cls");

    }

    
}
void edit_info_course()
{
    char code_course[20];
    char name[20],vahed[3],type[3];
    printf("if you want Exit from proses just perss enter\n");
    printf("Enter Code course: ");
    do
    {
        gets(code_course);
        if (strlen(code_course)==0)
            return ;
        else if (check_str_was_int(code_course)==1)
            printf("Invalid input! Try agian: ");
        else if (search_course_code(code_course)==1)
            printf("Not found course whit this code! Try agian: ");
        else 
            break;
    } while (1);
    // system("cls");
    printf("if you don't want edit, just press Enter\n");
    printf("enter name of course: ");
    do
    {
        gets(name);
        if (strlen(name)==0)
            break;
        else if (check_str_whitout_punct(name)==1)
            printf("Invalid name! Try another name: ");
        else
        {
            strcpy(temp_struct_course->name_course,name);
            break;
        }
    } while (1);

    printf("enter number of \"vahed\": ");
    do
    {
        gets(vahed);
        if (strlen(vahed)==0)
            break;
        else if (check_str_was_int(vahed)==1)
            printf("Invalid Input! Try again: ");
        else
        {
            strcpy(temp_struct_course->vahed,vahed);
            break;
        }
    } while (1);
    list_type_of_course();
    printf("enter type of course: ");
    do
    {
        gets(type);
        if (strlen(type)==0)
            break;
        else if (check_str_was_int(type)==1)
            printf("Invalid name! Try another name: ");
        else if (strlen(type)!=1 || type[0]>'4' || type[0]<'1')
            printf("Out of range! Try again: ");
        else
        {
            strcpy(temp_struct_course->type_course,type);
            break;
        }
    } while (1);
    free_course();
    printf("Process compelit! Press Enter to continue\n");
    do
    {
        name[0]=getch();
    } while (name[0]!=13);
    // system("cls");
    
}
void remove_course()
{
    char code_course[20];
    printf("if you want Exit from proses just perss enter\n");
    printf("Enter Code course: ");
    do
    {
        gets(code_course);
        if (strlen(code_course)==0)
            return ;
        else if (check_str_was_int(code_course)==1)
            printf("Invalid input! Try agian: ");
        else if (search_course_code(code_course)==1)
            printf("Not found course whit this code! Try agian: ");
        else 
            break;
    } while (1);
    if (temp_struct_course->status[0]=='D')
        printf("this course alrady removed of list!\n");
    else 
        strcpy(temp_struct_course->status,"D");
    free_course();
    printf("Process compelit! Press Enter to continue\n");
    do
    {
        code_course[0]=getch();
    } while (code_course[0]!=13);
    // system("cls");

}
void settings_departemant()
{
    char str_temp[50];
    search_user_name_departemant(User_Name_static);
    printf("if you want Exit from proses just perss enter\n");
    
    
        printf("Enter Password: ");
        do
        {
            password_to_star(str_temp);
            if (strlen(str_temp)==0)
                break;
            else if (check_str_whitout_space(str_temp)==1)
                printf("Invlid! Try again: ");
            else if (strlen(str_temp)<8)
                printf("too few character!(minimum character is 8) Try again: ");
            else
            {
                password_to_hash(str_temp);
                if (strcmp(str_temp,temp_struct_departemant->pass1)==0 && strlen(str_temp)==strlen(temp_struct_departemant->pass1))
                {
                    printf("new password should not be same as old password! Try another password: ");
                    continue;
                }
                strcpy(temp_struct_departemant->pass1,str_temp);
                break;
            }
        } while (1);
        
        printf("Enter Email: ");
        do
        {
            gets(str_temp);
            if (strlen(str_temp)==0)
                break;
            else if (check_email(str_temp)==1)
                printf("Invlid! Try again: ");
            else
            {
                if (strcmp(str_temp,temp_struct_departemant->email)==0 && strlen(str_temp)==strlen(temp_struct_departemant->email))
                {
                    printf("new Email should not be same as old Email! Try another Email: ");
                    continue;
                }
                strcpy(temp_struct_departemant->email,str_temp);
                break;
            }
        } while (1);

        printf("Enter Phone number: ");
        do
        {
            gets(str_temp);
            if (strlen(str_temp)==0)
                break;
            else if (check_str_was_int(str_temp)==1 || str_temp[0]!='0' || str_temp[1]!='9')
                printf("Invlid! enter whit this form (09123456789): ");
            else if (strlen(str_temp)!=11)
                printf("too few charater for Phone number!! Try again: ");
            else
            {
                if (strcmp(str_temp,temp_struct_departemant->email)==0 && strlen(str_temp)==strlen(temp_struct_departemant->email))
                {
                    printf("new Phone should not be same as old Phone! Try another Phone: ");
                    continue;
                }
                strcpy(temp_struct_departemant->email,str_temp);
                break;
            }
        } while (1);
        free_departemant();
        printf("edited whit Successfully! Press Enter for back to menu\n");
        do
        {
            str_temp[0]=getch();
        } while (str_temp[0]!=13);
            // system("cls");
}
void settings_academic()
{
    char str_temp[50];
    search_user_name_academic(User_Name_static);
    printf("if you want Exit from proses just perss enter\n");
    
    
        printf("Enter Password: ");
        do
        {
            password_to_star(str_temp);
            if (strlen(str_temp)==0)
                break;
            else if (check_str_whitout_space(str_temp)==1)
                printf("Invlid! Try again: ");
            else if (strlen(str_temp)<8)
                printf("too few character!(minimum character is 8) Try again: ");
            else
            {
                password_to_hash(str_temp);
                if (strcmp(str_temp,temp_struct_academic->pass1)==0 && strlen(str_temp)==strlen(temp_struct_academic->pass1))
                {
                    printf("new password should not be same as old password! Try another password: ");
                    continue;
                }
                strcpy(temp_struct_academic->pass1,str_temp);
                break;
            }
        } while (1);
        
        printf("Enter Email: ");
        do
        {
            gets(str_temp);
            if (strlen(str_temp)==0)
                break;
            else if (check_email(str_temp)==1)
                printf("Invlid! Try again: ");
            else
            {
                if (strcmp(str_temp,temp_struct_academic->email)==0 && strlen(str_temp)==strlen(temp_struct_academic->email))
                {
                    printf("new Email should not be same as old Email! Try another Email: ");
                    continue;
                }
                strcpy(temp_struct_academic->email,str_temp);
                break;
            }
        } while (1);

        printf("Enter Phone number: ");
        do
        {
            gets(str_temp);
            if (strlen(str_temp)==0)
                break;
            else if (strlen(str_temp)!=11)
                printf("too few charater for Phone number!! Try again: ");
            else if (check_str_was_int(str_temp)==1 || str_temp[0]!='0' || str_temp[1]!='9')
                printf("Invlid! enter whit this form (09123456789): ");
            else
            {
                if (strcmp(str_temp,temp_struct_academic->email)==0 && strlen(str_temp)==strlen(temp_struct_academic->email))
                {
                    printf("new Phone should not be same as old Phone! Try another Phone: ");
                    continue;
                }
                strcpy(temp_struct_academic->email,str_temp);
                break;
            }
        } while (1);
        free_academic();
        printf("edited whit Successfully! Press Enter for back to menu\n");
        do
        {
            str_temp[0]=getch();
        } while (str_temp[0]!=13);
            // system("cls");
}
//reports departemant
void info_student_sync_with_id_print()
{
    char num[20];
    printf("Enter ID University of student: ");
    do
    {
        gets(num);
        if (check_str_was_int(num) || strlen(num)!=10)
            printf("Invalid from input!! try again: ");
        else if (search_user_name_student(num)==1)
            printf("Student with this ID not found! try with another ID: ");
        else
            break;
    } while (1);

     printf("Information about Student (ID: %s)\n________________________________________\n\n",temp_struct_student->ID_uni);
    int i=1;
    char temp[25];
        strcpy(temp,"Name");
        printf("%-20s%s\n",temp,temp_struct_student->name);
        strcpy(temp,"Family name");
        printf("%-20s%s\n",temp,temp_struct_student->family);
        strcpy(temp,"Major");
        printf("%-20s%s\n",temp,temp_struct_student->major);
        strcpy(temp,"Date Birthday");
        printf("%-20s%s\n",temp,temp_struct_student->date_birthday);
        strcpy(temp,"Location born");
        printf("%-20s%s\n",temp,temp_struct_student->location_born);
        strcpy(temp,"ID code");// code meli
        printf("%-20s%s\n",temp,temp_struct_student->ID_code);
        strcpy(temp,"Phone number");
        printf("%-20s%s\n",temp,temp_struct_student->phone_num);
        strcpy(temp,"Email");
        printf("%-20s%s\n",temp,temp_struct_student->email);
        printf("--------------------------------------\n");
     
    printf("Press Enter to back list\n");
    free_student();
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
    
}
void list_student_print()
{
    char temp[25];
    int i=1;
        // system("cls");;
        printf("list of Student\n_______________________________________\n\n");
        temp_struct_student=malloc(sizeof(struct struct_student));
        temp_struct_student=start_struct_student;
        do
        {
            if (temp_struct_student->name[0]=='0')//file is NULL
            {
                printf("-----------------------------------\n");
                printf("No result to show!\n");
                printf("-----------------------------------\n");
                break;
            }
            printf("Student's %d\n",i++);
            printf("-----------------------------------\n");
            strcpy(temp,"Name: ");
            printf("%s%s |",temp,temp_struct_student->name);
            strcpy(temp,"Family name: ");
            printf("%s%s |",temp,temp_struct_student->family);
            strcpy(temp,"ID Univesity: ");
            printf("%s%s |",temp,temp_struct_student->ID_uni);
            strcpy(temp,"Date Birthday: ");
            printf("%s%s |",temp,temp_struct_student->date_birthday);
            strcpy(temp,"Location born: ");
            printf("%s%s |",temp,temp_struct_student->location_born);
            strcpy(temp,"ID code: ");// code meli
            printf("%s%s |",temp,temp_struct_student->ID_code);
            strcpy(temp,"Phone number: ");
            printf("%s%s |",temp,temp_struct_student->phone_num);
            strcpy(temp,"Email: ");
            printf("%s%s |",temp,temp_struct_student->email);
            strcpy(temp,"Major: ");
            printf("%s%s |",temp,temp_struct_student->major);
            temp_struct_student=temp_struct_student->link;
        }while(temp_struct_student!=NULL);

    free_student();
    printf("\n-----------------------------------\n");
    printf("Press enter to back menu\n");
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
}
void list_course_print()
{
    char temp[25];
    char type[20];
    int i=1;
        // system("cls");;
        printf("list of Course\n_______________________________________\n\n");
        temp_struct_course=malloc(sizeof(struct struct_course));
        temp_struct_course=start_struct_course;
        do
        {
            if (temp_struct_course->name_course[0]=='!')//file is NULL
            {
                printf("-----------------------------------\n");
                printf("No result to show!\n");
                printf("-----------------------------------\n");
                break;
            }
            printf("Course's %d\n",i++);
            printf("-----------------------------------\n");
            strcpy(temp,"Name Course");
            printf("%s%s |",temp,temp_struct_course->name_course);
            strcpy(temp,"Code fo Course");
            printf("%s%s |",temp,temp_struct_course->code_course);
            strcpy(temp,"Type of Course");
            switch (atoi(temp_struct_course->type_course))
            {
             case 1:
                strcpy(type,"teori");
                break;
            case 2:
                strcpy(type,"Amali");
                break;
            case 3:
                strcpy(type,"Azmayeshgahi");
                break;
            case 4:
                strcpy(type,"kargahi");
                break;
            default:
                break;
            }
            printf("%s%s |",temp,type);
            strcpy(temp,"\"tedede vahed\"");
            printf("%s%s |",temp,temp_struct_course->vahed);
            strcpy(temp,"Status Course");
            if (temp_struct_course->status[0]=='E')
                printf("%s%s |",temp,"Enable");
            else
                printf("%s%s |",temp,"Disable");
            temp_struct_course=temp_struct_course->link;
        }while(temp_struct_course!=NULL);

    free_course();
    printf("-----------------------------------\n");
    printf("Press enter to back menu\n");
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
}
void list_course_spetial_print(int status)// status1 := D and 0:= E
{
    char temp[25];
    char type[20];
    int i=1;
        // system("cls");;
        printf("list of Course\n_______________________________________\n\n");
        temp_struct_course=malloc(sizeof(struct struct_course));
        temp_struct_course=start_struct_course;
        do
        {
            if (temp_struct_course->name_course[0]=='!')//file is NULL
            {
                printf("-----------------------------------\n");
                printf("No result to show!\n");
                printf("-----------------------------------\n");
                break;
            }
            if (status==1 && temp_struct_course->status[0]=='D')
            {
                printf("Course's %d\n",i++);
                printf("-----------------------------------\n");
                strcpy(temp,"Name Course");
                printf("%-20s%s\n",temp,temp_struct_course->name_course);
                strcpy(temp,"Code fo Course");
                printf("%-20s%s\n",temp,temp_struct_course->code_course);
                strcpy(temp,"Type of Course");
                switch (atoi(temp_struct_course->type_course))
                {
                case 1:
                    strcpy(type,"teori");
                    break;
                case 2:
                    strcpy(type,"Amali");
                    break;
                case 3:
                    strcpy(type,"Azmayeshgahi");
                    break;
                case 4:
                    strcpy(type,"kargahi");
                    break;
                default:
                    break;
                }
                printf("%-20s%s\n",temp,type);
                strcpy(temp,"\"tedede vahed\"");
                printf("%-20s%s\n",temp,temp_struct_course->vahed);
                strcpy(temp,"Status Course");
                if (temp_struct_course->status[0]=='E')
                    printf("%-20s%s\n",temp,"Enable");
                else
                    printf("%-20s%s\n",temp,"Disable");
                printf("-----------------------------------\n");
            }
            else if (status==0 && temp_struct_course->status[0]=='D')
            {
                printf("Course's %d\n",i++);
                printf("-----------------------------------\n");
                strcpy(temp,"Name Course");
                printf("%-20s%s\n",temp,temp_struct_course->name_course);
                strcpy(temp,"Code fo Course");
                printf("%-20s%s\n",temp,temp_struct_course->code_course);
                strcpy(temp,"Type of Course");
                switch (atoi(temp_struct_course->type_course))
                {
                case 1:
                    strcpy(type,"teori");
                    break;
                case 2:
                    strcpy(type,"Amali");
                    break;
                case 3:
                    strcpy(type,"Azmayeshgahi");
                    break;
                case 4:
                    strcpy(type,"kargahi");
                    break;
                default:
                    break;
                }
                printf("%-20s%s\n",temp,type);
                strcpy(temp,"\"tedede vahed\"");
                printf("%-20s%s\n",temp,temp_struct_course->vahed);
                strcpy(temp,"Status Course");
                if (temp_struct_course->status[0]=='E')
                    printf("%-20s%s\n",temp,"Enable");
                else
                    printf("%-20s%s\n",temp,"Disable");
                printf("-----------------------------------\n");
            }
            temp_struct_course=temp_struct_course->link;
        }while(temp_struct_course!=NULL);
    if (i==1)
        printf("Course with this status not found!\n");

    free_course();
    printf("Press enter to back menu\n");
    do
    {
        temp[0]=getch();
    } while (temp[0]!=13);
}
void search_scores_of_student_by_ID()
{
    char ID[11];
    printf("if you can cancel prosses, just press Enter\n");
    printf("enter ID University: ");
    do
    {
        gets(ID);
        if (strlen(ID)==0)
            return ;
        if (strlen(ID)!=10 || check_str_was_int(ID))
            printf("Invalid input! Try again: ");
        else if (search_user_name_student(ID)==1)
            printf("Student with this ID not found!! Try again: ");
        else
            break;
    } while (1);
    int counter=0;
    char temp[20];
    temp_struct_score=malloc(sizeof(struct struct_score));
    if (temp_struct_score==NULL)
    {
        printf("Memory not Alow!");
        return ;
    }
    temp_struct_score=start_struct_score;
    printf("   Scores of Student with ID %s\n",temp_struct_score->ID_uni);
    printf("__________________________________________\n");
    do
    {
        if (strcmp(temp_struct_score->ID_uni,ID)==0 && strlen(temp_struct_score->ID_uni)==strlen(ID))
        {
            counter++;
            search_course_code(temp_struct_score->code_course);
            strcpy(temp,"Name course: ");
            printf("%-2s%s\n",temp,temp_struct_course->name_course);
            free_course();
            strcpy(temp,"Code Course: ");
            printf("%-20s%s\n",temp,temp_struct_score->code_course);
            strcpy(temp,"Score: ");
            printf("%-20s%s\n",temp,temp_struct_score->score);
            printf("__________________________________________\n");
        }
        temp_struct_score=temp_struct_score->link;
    }while(temp_struct_score!=NULL);
    free_score();
    if (counter==0)
        printf("     No Score are recorded for this ID\n");
    printf("Press enter to back menu\n");
    press_enter_to_continue();
}
void panle_log_print_page3()
{
    char temp[60],line_char='|';
    printf("\t\t    Log page(Page 3/3)\n");
    printf("------------------------------------------------------------\n");
    for(int i=0; i<7; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Show list of Sudent (Sorted by Avrage)");
        break;
    case 1:
        strcpy(temp,"Show list of Students \"ghabool shode\" in Spicail Course");
        break;
    case 2:
        strcpy(temp,"Show list of Sudent that not pass in Specail Course");
        break;
    case 3:
        strcpy(temp,"Show list of All Sudent submited");
        break;
    case 4:
        strcpy(temp,"Show list of All Sudent submited");
        break;
    case 5:
        strcpy(temp,"Previous Page");
        break;
    case 6:
        strcpy(temp,"Exit");
        break;
    default:
        break;
    }

    printf("%-55s%c\n",temp,line_char);
    if (i!=6)
        printf("|--+-------------------------------------------------------|\n");


    }
    printf("------------------------------------------------------------\n\n");
    printf("select a option from menu: ");
}
void panle_log_print_page2()
{
    char temp[60],line_char='|';
    printf("\t\t    Log page (Page 2/3)\n");
    printf("-------------------------------------------------------------\n");
    for(int i=0; i<8; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Scores student report whit ID Uuiversity");
        break;
    case 1:
        strcpy(temp,"Scores student report whit Code course");
        break;
    case 2:
        strcpy(temp,"Scores student report whit ID Uuiversity(sorted by name)");
        break;
    case 3:
        strcpy(temp,"Avrege score of Student");
        break;
    case 4:
        strcpy(temp,"Avrege score of Course");
        break;
    case 5:
        strcpy(temp,"Next page");
        break;
    case 6:
        strcpy(temp,"Previous Page");
        break;
    case 7:
        strcpy(temp,"Exit");
        break;
    default:
        break;
    }

    printf("%-56s%c\n",temp,line_char);
    if (i!=7)
        printf("|--+--------------------------------------------------------|\n");


    }
    printf("-------------------------------------------------------------\n\n");
    printf("select a option from menu: ");
}
void panle_log_print_page1()
{
    char temp[35],line_char='|';
    printf("\t  Log page (Page 1/3)\n");
    printf("----------------------------------------\n");
    for(int i=0; i<7; i++)
    {
    printf("%c%-2d%c",line_char,i+1,line_char);
    switch (i)
    {
    case 0:
        strcpy(temp,"Found student with ID university");
        break;
    case 1:
        strcpy(temp,"Show list of Student");
        break;
    case 2:
        strcpy(temp,"Show list of Course");
        break;
    case 3:
        strcpy(temp,"Show list of Course Desable");
        break;
    case 4:
        strcpy(temp,"Show list of Course Ensable");
        break;
    case 5:
        strcpy(temp,"Next Page");
        break;
    case 6:
        strcpy(temp,"Exit");
        break;
    default:
        break;
    }

    printf("%-35s%c\n",temp,line_char);
    if (i!=6)
        printf("|--+-----------------------------------|\n");


    }
    printf("----------------------------------------\n\n");
    printf("select a option from menu: ");
}
void contorol_panle_print_log_departemant_panel(int num_page)
{
    switch (num_page)
    {
    case 1:
        panle_log_print_page1();
        break;
    case 2:
        panle_log_print_page2();
        break;
    case 3:
        panle_log_print_page3();
        break;
    default:
        break;
    }
}
int log_departemant()// -----------------------------------------------------------------------------p23193asdi1[2pio3p[oiasd]]
{
    int num_menu;
    int num_page=1;
    while (1)
        switch (num_page)
        {
        // ------------------------------------------------------------------page 1
        case 1:
            do{
                contorol_panle_print_log_departemant_panel(num_page);
                num_menu=menu_selection_1_7();
                switch (num_menu)
                {
                    case 1:
                        info_student_sync_with_id_print();
                        break;
                    case 2:
                        list_student_print();
                        break;
                    case 3:
                        list_course_print();
                        break;
                    case 4:
                        list_course_spetial_print(1);
                        break;
                    case 5:
                        list_course_spetial_print(0);
                        break;
                    case 6:
                        num_page=2;
                        break;
                    case 7:
                        return 1;
                        break;
                    default:
                        break;
                }
                break;
                if (num_menu==6)
                    break;
            }while(1);
                break;
        // ----------------------------------------------------------------- page 2
        
        case 2:
            do{
                contorol_panle_print_log_departemant_panel(num_page);
                num_menu=menu_selection_1_8();
                switch (num_menu)
                {
                    case 1:
                        search_scores_of_student_by_ID();
                        break;
                    case 6:
                        num_page=3;
                        break;
                    case 7:
                        num_page=1;
                        break;
                    case 8:
                        return 1;
                        break;
                    default:
                        break;
                }
                break;
            if (num_menu==6 || num_menu==7 || num_menu==8)
                break;
            }while(1);
                break;
        // ------------------------------------------------------------------ page 3
        
        case 3:
            do{
                contorol_panle_print_log_departemant_panel(num_page);
                num_menu=menu_selection_1_7();
                switch (num_menu)
                {
                    case 1:
                        //def
                        break;
                    case 6:
                        num_page=2;
                        break;
                    case 7:
                        return 1;
                        break;
                    default:
                        break;
                }
                break;
            if (num_menu==6)
                break;
            }while(1);
                break;
        default:
            break;
        }
        
    
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


    char temp_user[20];
    int temp_flag=0,menu_type,type_list_log=0,login_flag;
    set_academic_as_link_list();
    set_departemants_as_link_list();
    srand(time(NULL));
    while(1)
    {
        menu_login_print();
        menu_type=menu_login_filter_selection();
        // -------------------------------------------- rotation part
        switch (menu_type)
        {
            case 1:// ------------------------------------------------------------------------------- Admin
                unti_hash_to_password(pointer_Padmin);
                login_flag=get_check_user_pass(pointer_Uadmin,pointer_Padmin,pointer_Limit_admin);// 0:= succces; 1,2:unsaccses; -1:cancel login;
                password_to_hash(pointer_Padmin);
                // system("cls");;
                if (login_flag==0)
                {
                    do{
                        menu_admin_page_print();
                        set_departemants_as_link_list();
                        set_academic_as_link_list();
                        menu_type=menu_selection_1_8();
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
                            // system("cls");
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
                                    // system("cls");
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
            case 2:// ------------------------------------------------------------------------------- Departemant
                
                login_flag=get_user_pass_user_departemnts();
                
                if (login_flag==0)
                {
                    set_score_student_as_link_list();
                    set_student_as_link_list();
                    set_course_as_link_list();
                    do{
                        menu_departemant_print();
                        menu_type=menu_selection_1_8();
                        switch (menu_type)
                        {
                        case 1:
                            add_new_course();
                            set_course_as_link_list();
                            break;
                        case 2:
                            set_new_score();
                            set_score_student_as_link_list();
                            break;
                        case 3:
                            edit_score_student();
                            add_linked_list_score_to_notpadd();
                            break;
                        case 4:
                            edit_info_course();
                            add_linked_list_course_to_notpadd();
                            break;
                        case 5:
                            remove_course();
                            add_linked_list_course_to_notpadd();
                            break;
                        case 6:
                            log_departemant();
                            break;
                        case 7:
                            settings_departemant();
                            add_linked_list_departemant_to_notpadd();
                            break;
                        case 8:
                            break;
                        default:
                            break;
                        }
                    }while(menu_type!=8);
                }
                else
                    add_linked_list_departemant_to_notpadd();
                break;
            
            case 3:// --------------------------------------------------------------------------------- Academic
                login_flag=get_user_pass_user_academics();
                
                if (login_flag==0)
                {
                    do{
                        set_student_as_link_list();
                        set_course_as_link_list();
                        set_score_student_as_link_list();
                        menu_academic_print();
                        menu_type=menu_selection_1_6();
                        switch (menu_type)
                        {
                        case 1:
                            set_new_student();
                            set_student_as_link_list();
                            break;
                        case 2:
                            edit_info_student();
                            add_linked_list_student_to_notpadd();
                            break;
                        case 3:
                            set_new_score();
                            set_score_student_as_link_list();
                        case 4:
                            //log def 
                            break;
                        case 5:
                            settings_academic();
                            add_linked_list_academi_to_notpadd();
                        case 6:
                            break;
                            
                        default:
                            break;
                        }
                    }while(menu_type!=6);
                }
                else
                    add_linked_list_academi_to_notpadd();
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

//set file back up for score-student
// dota nomre nabase   Done
// dissbale able   Done
// fix from date      1234/4/4 --> 1234/04/04
// list kamele kholase che samiya baraye deoartemant log???