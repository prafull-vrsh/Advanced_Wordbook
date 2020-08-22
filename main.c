#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
int pass(void);
int passwordchange(void);
int wordsearch(void);
int meaningsearch(void);
void loading(void);
int pattern(int,int);
void tiktok(void);
void helptiktok(void);
void fullformsearch(void);
struct word
{
    int length,occur[27];
    char spelling[30];
};
int main()
{
    int temp;
    char tempc='y',response;
    system("color 0c");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t  KIET GROUP OF INSTITUTIONS,GHAZIABAD");
    printf("\n\n\n\t\t\t\t\t\t\tDEPARTMENT OF COMPUTER SCIENCE AND INFORMATION TECHNOLOGY");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tSESSION : 2019-2020");
    printf("\n\n\n\t\t\t\t\t\t\t\t       \"ADVANCE WORDBOOK\"");
    printf("\n\n\n\t\t\t\t\t\t\t\t  SUBMITTED BY : PRAFULL VARSHNEY");
     printf("\n\n\n\t\t\t\t\t\t\t\t\t\t 1802911032");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO CONTINUE...");
    getch();
    temp=pass();
    if(temp==0)
        return 0;
    while(tempc=='y'||tempc=='Y')
    {
         Sleep(1000);
        system("cls");
        system("color cf");
        printf("\n\n\n\t\t\t\t\t\tPRESS 1 FOR WORD SEARCH");
        printf("\n\n\n\t\t\t\t\t\tPRESS 2 FOR MEANING SEARCH");
        printf("\n\n\n\t\t\t\t\t\tPRESS 3 FOR PASSWORD CHANGE");
        printf("\n\n\n\t\t\t\t\t\tPRESS 4 TO PLAY GAME");
        printf("\n\n\n\t\t\t\t\t\tPRESS 5 FOR FULLFORM SEARCH");
        printf("\n\n\n\t\t\t\t\t\tANY OTHER KEY TO EXIT : ");
        scanf("%c",&response);
        switch(response)
        {
            case '1':wordsearch();
                break;
            case '2':meaningsearch();
                break;
            case '3':passwordchange();
                break;
            case '4':{fflush(stdin);
                    Sleep(1000);
                    system("cls");
                    system("color b1");
                    printf("\n\n\n\t\t\t\tIF YOU DON'T KNOW HOW TO PLAY TITOK GAME THEN PRESS 'Y' : ");
                    scanf("%c",&tempc);
                    if(tempc=='y'||tempc=='Y')
                        helptiktok();
                    tiktok();
                break;
                    }
            case '5':fullformsearch();
                break;
            default:Sleep(1000);
                system("cls");
                system("color b1");
                printf("\n\n\n\t\t\t\t\t\tHAVE A NICE DAY!");
                return 0;
        }
        printf("\n\n\n\t\t\t\t\t\tDO YOU WANT TO DO MORE : ");
        scanf("%c",&tempc);
        fflush(stdin);
        Sleep(1000);
        system("cls");
    }
     printf("\n\n\n\t\t\t\t\t\tHAVE A NICE DAY!");
    return 0;
}
int pass()
{
    system("color 1b");
    system("cls");
    int temp=0,k=0;
    char password[30],ch;
    FILE *p;
    p=fopen("password.txt","r");
    while(k<3)
    {
        temp=0;
        printf("\n\n\n\t\t\t\t\t\tENTER CURRENT PASSWORD : ");
        ch=getch();
        while(ch != 13)
        {
            if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||ch=='!'||ch=='@'||ch=='#'||ch=='$'||ch=='%'||ch=='^'||ch=='&'||ch=='*')
            {
                password[temp]=ch;
                printf("*");
                temp++;
            }
            else if(ch=='\b'&&temp>0)
                {
                    printf("\b \b");
                    temp--;
                }
                ch=getch();
        }
        password[temp]='\0';
        if(!p)
        {
            if(strcmp(password,"\0")==0)
            {
                printf("\n\n\n\t\t\t\t\t\tPASSWORD IS CORRECT");
                return 1;
            }
            else
                printf("\n\n\n\t\t\t\t\t\tPASSWORD IS INCORRECT");
        }
        else
        {   temp=0;
            fseek(p,0,SEEK_SET);
            ch=getc(p);
            while(ch!=EOF)
            {
                if(ch!=password[temp])
                {
                    temp=-1;
                    printf("\n\n\n\t\t\t\t\t\tPASSWORD IS INCORRECT");
                    break;
                }
                temp++;
                ch=getc(p);
            }
            if(temp!=-1)
            {
                if(temp==strlen(password))
                {
                    fclose(p);
                    printf("\n\n\n\t\t\t\t\t\tPASSWORD IS CORRECT");
                    return 1;
                }
                else
                {
                    printf("\n\n\n\t\t\t\t\t\tPASSWORD IS INCORRECT");
                }
            }
        }
        Sleep(1000);
        system("cls");
        k++;
    }
    printf("\n\n\n\t\t\t\t\t\tYOU ENTER 3 TIMES WRONG PASSWORD PLEASE RESTART DICTIONARY");
    fclose(p);
    return 0;
}
int passwordchange()
{
    system("color b1");
    int temp;
    char password[30],confirm[30],ch;
    temp=pass();
    if(temp==0)
    {
        printf("\n\n\n\t\t\t\t\t\tYOU CAN NOT CHANGE PASSWORD TRY AGAIN! ");
        return 0;
    }
    do
    {
        temp=0;
        printf("\n\n\n\t\t\t\t\t\tENTER NEW PASSWORD : ");
        ch=getch();
        while(ch != 13)
        {
            if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||ch=='!'||ch=='@'||ch=='#'||ch=='$'||ch=='%'||ch=='^'||ch=='&'||ch=='*')
            {
                password[temp]=ch;
                printf("*");
                temp++;
            }
            else if(ch=='\b'&&temp>0)
            {
                printf("\b \b");
                temp--;
            }
            ch=getch();
        }
        password[temp]='\0';
        temp=0;
        printf("\n\n\n\t\t\t\t\t\tCONFIRM PASSWORD : ");
        ch=getch();
        while(ch != 13)
        {
            if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||ch=='!'||ch=='@'||ch=='#'||ch=='$'||ch=='%'||ch=='^'||ch=='&'||ch=='*')
            {
                confirm[temp]=ch;
                printf("*");
                temp++;
            }
            else if(ch=='\b'&&temp>0)
            {
                printf("\b \b");
                temp--;
            }
            ch=getch();
        }
        confirm[temp]='\0';
        if(strcmp(password,confirm)!=0)
        {
            printf("\n\n\n\t\t\t\t\t\tMISMATCHED PASSWORD  ");
            Sleep(1000);
            system("cls");
        }
    }while(strcmp(password,confirm)!=0);
    FILE *p;
    p=fopen("password.txt","w");
    for(int i=0;password[i]!='\0';i++)
        putc(password[i],p);
    printf("\n\n\n\t\t\t\t\t\tPASSWORD IS SUCCESSFULLY CHANGED");
    fflush(stdin);
    fclose(p);
    system("color cf");
    return 1;
}
int wordsearch()
{
        struct word w;
        FILE *f;
        int length,temp,alpha[27],noofwords=0;
        char *check,sample[10];
        char filename[10],start[15],end[15],response1,response2,response3,response4,tempc='y';
        noofwords=0;
        system("cls");
        system("color b1");
        fflush(stdin);
        printf("\n\n\n\t\t\t\t\t\tDO YOU KNOW LENGTH OF WORD? (Y/N) : ");
        scanf("%c",&response1);
        if(response1=='y'||response1=='Y')
        {
            system("color a1");
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t\tENTER LENGTH OF WORD : ");
             while(fgets(sample,sizeof(sample),stdin))
            {

                length=strtol(sample,&check,10);
                if(check==sample||*check!='\n')
                {
                    printf("\n\n\n\t\t\t\t\t\tPLEASE ENTER NATURAL NUMBER : ");
                }else break;
            }
            response1='y';
        }
        Sleep(1000);
        system("cls");
        system("color b1");
        fflush(stdin);
        printf("\n\n\n\t\t\t\t\t\tDO YOU KNOW STARTING ALPHABETS OF WORD? (Y/N) : ");
        scanf("%c",&response2);
        fflush(stdin);
        if(response2=='y'||response2=='Y')
        {
            system("color a1");
            printf("\n\n\n\t\t\t\t\t\tENTER STARTING ALPHABETS OF WORD : ");
            gets(start);
            fflush(stdin);
            response2='y';
        }
        Sleep(1000);
        system("cls");
        system("color b1");
        printf("\n\n\n\t\t\t\t\t\tDO YOU KNOW ENDING ALPHABETS OF WORD? (Y/N) : ");
        scanf("%c",&response3);
        fflush(stdin);
        if(response3=='y'||response3=='Y')
        {
            system("color a1");
            printf("\n\n\n\t\t\t\t\t\tENTER ENDING ALPHABETS OF WORD : ");
            gets(end);
            fflush(stdin);
            response3='y';
        }
        Sleep(1000);
        system("cls");
        system("color b1");
        printf("\n\n\n\t\t\t\t\t\tDO YOU KNOW OCCURENCE OF INDIVIDUAL LETTER OF WORD? (Y/N) : ");
        scanf("%c",&response4);
        fflush(stdin);
        if(response4=='y'||response4=='Y')
        {
            response4='y';
            system("color a1");
            for(int i=0;i<27;i++)
                alpha[i]=0;
                while(tempc=='y'||tempc=='Y')
                {
                    printf("\n\n\n\t\t\t\t\t\tENTER LETTER : ");
                    scanf("%c",&tempc);
                    if(tempc>='a'&&tempc<='z')
                        temp=tempc-65-32;
                    else if(tempc>='A'&&tempc<='Z')
                        temp=tempc-65;
                    else
                        temp=26;
                        fflush(stdin);
                    printf("\n\n\n\t\t\t\t\t\tENTER ITS OCCURENCE : ");
                     while(fgets(sample,sizeof(sample),stdin))
                        {
                            alpha[temp]=strtol(sample,&check,10);
                            if(check==sample||*check!='\n')
                            {
                                printf("\n\n\n\t\t\t\t\t\tPLEASE ENTER NATURAL NUMBER : ");
                            }else break;
                        }
                    fflush(stdin);
                    printf("\n\n\n\t\t\t\t\t\tDO YOU WANT TO ENTER MORE? (y/n)");
                    scanf("%c",&tempc);
                    fflush(stdin);
                }
        }
        Sleep(1000);
        system("cls");
        loading();
        system("color df");
        printf("\n\n\n\t\t\t\t\t\tEXPECTED WORDS : \n\n");
        if(response2=='y')
        {
            if(start[0]>='A' && start[0]<='M')
                f=fopen("1.txt","r");
            else if(start[0]>='N' && start[0]<='Z')
                f=fopen("2.txt","r");
            else if(start[0]>='a'&&start[0]<='f')
                f=fopen("3.txt","r");
            else if(start[0]>='g'&&start[0]<='l')
                f=fopen("4.txt","r");
            else if(start[0]>='m'&&start[0]<='s')
                f=fopen("5.txt","r");
            else if(start[0]>='t'&&start[0]<='z')
                f=fopen("6.txt","r");
                while(!feof(f))
                {
                    fread(&w,sizeof(w),1,f);
                    if(strncmp(start,w.spelling,strlen(start))==0)
                    {
                        if(response1=='y')
                        {
                            if(length==w.length)
                            {
                                if(response3=='y')
                                {   temp=0;
                                    for(int i=0;i<strlen(end);i++)
                                        {
                                            if(w.spelling[strlen(w.spelling)-strlen(end)+i]!=end[i])
                                            {
                                                temp=1;
                                                break;
                                            }
                                        }
                                    if(temp==0)
                                    {
                                        if(response4=='y')
                                        {
                                            temp=0;
                                            for(int i=0;i<27;i++)
                                            {
                                                if(w.occur[i]!=alpha[i] && alpha[i]!=0)
                                                {
                                                    temp=1;
                                                    break;
                                                }
                                            }
                                            if(temp==0)
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                        }
                                        else
                                        {
                                            printf("\t\t\t\t\t\t%s\n",w.spelling);
                                            noofwords++;
                                        }
                                    }
                                }
                                else
                                {
                                    if(response4=='y')
                                        {
                                            temp=0;
                                            for(int i=0;i<27;i++)
                                            {
                                                if(w.occur[i]!=alpha[i] && alpha[i]!=0)
                                                {
                                                    temp=1;
                                                    break;
                                                }
                                            }
                                            if(temp==0)
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                        }
                                        else
                                        {
                                            printf("\t\t\t\t\t\t%s\n",w.spelling);
                                            noofwords++;
                                        }
                                }
                            }
                        }
                        else
                        {
                            if(response3=='y')
                                {   temp=0;
                                    for(int i=0;i<strlen(end);i++)
                                        {
                                            if(w.spelling[strlen(w.spelling)-strlen(end)+i]!=end[i])
                                            {
                                                temp=1;
                                                break;
                                            }
                                        }
                                    if(temp==0)
                                    {
                                        if(response4=='y')
                                        {
                                            temp=0;
                                            for(int i=0;i<27;i++)
                                            {
                                                if(w.occur[i]!=alpha[i])
                                                {
                                                    temp=1;
                                                    break;
                                                }
                                            }
                                            if(temp==0)
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                        }
                                        else
                                        {
                                            printf("\t\t\t\t\t\t%s\n",w.spelling);
                                            noofwords++;
                                        }
                                    }
                                }
                                else
                                {
                                    if(response4=='y')
                                        {
                                            temp=0;
                                            for(int i=0;i<27;i++)
                                            {
                                                if(w.occur[i]!=alpha[i])
                                                {
                                                    temp=1;
                                                    break;
                                                }
                                            }
                                            if(temp==0)
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                        }
                                        else
                                        {
                                            printf("\t\t\t\t\t\t%s\n",w.spelling);
                                            noofwords++;
                                        }
                                }
                        }
                    }
                }
        fclose(f);
        }
        else
        {
            for(int i=0;i<6;i++)
            {
                switch(i)
                {
                    case 0:f=fopen("1.txt","r");
                        break;
                    case 1:f=fopen("2.txt","r");
                        break;
                    case 2:f=fopen("3.txt","r");
                        break;
                    case 3:f=fopen("4.txt","r");
                        break;
                    case 4:f=fopen("5.txt","r");
                        break;
                    case 5:f=fopen("6.txt","r");
                }
                while(!feof(f))
                {
                    fread(&w,sizeof(w),1,f);
                    if(response1=='y')
                            {
                                if(length==w.length)
                                {
                                    if(response3=='y')
                                    {   temp=0;
                                        for(int i=0;i<strlen(end);i++)
                                            {
                                                if(w.spelling[strlen(w.spelling)-strlen(end)+i]!=end[i])
                                                {
                                                    temp=1;
                                                    break;
                                                }
                                            }
                                        if(temp==0)
                                        {
                                            if(response4=='y')
                                            {
                                                temp=0;
                                                for(int i=0;i<27;i++)
                                                {
                                                    if(w.occur[i]!=alpha[i] && alpha[i]!=0)
                                                    {
                                                        temp=1;
                                                        break;
                                                    }
                                                }
                                                if(temp==0)
                                                {
                                                    printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                    noofwords++;
                                                }
                                            }
                                            else
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(response4=='y')
                                            {
                                                temp=0;
                                                for(int i=0;i<27;i++)
                                                {
                                                    if(w.occur[i]!=alpha[i] && alpha[i]!=0)
                                                    {
                                                        temp=1;
                                                        break;
                                                    }
                                                }
                                                if(temp==0)
                                                {
                                                    printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                    noofwords++;
                                                }
                                            }
                                            else
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                    }
                                }
                            }
                            else
                            {
                                if(response3=='y')
                                    {   temp=0;
                                        for(int i=0;i<strlen(end);i++)
                                            {
                                                if(w.spelling[strlen(w.spelling)-strlen(end)+i]!=end[i])
                                                {
                                                    temp=1;
                                                    break;
                                                }
                                            }
                                        if(temp==0)
                                        {
                                            if(response4=='y')
                                            {
                                                temp=0;
                                                for(int i=0;i<27;i++)
                                                {
                                                    if(w.occur[i]!=alpha[i])
                                                    {
                                                        temp=1;
                                                        break;
                                                    }
                                                }
                                                if(temp==0)
                                                {
                                                    printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                    noofwords++;
                                                }
                                            }
                                            else
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(response4=='y')
                                            {
                                                temp=0;
                                                for(int i=0;i<27;i++)
                                                {
                                                    if(w.occur[i]!=alpha[i])
                                                    {
                                                        temp=1;
                                                        break;
                                                    }
                                                }
                                                if(temp==0)
                                                {
                                                    printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                    noofwords++;
                                                }
                                            }
                                            else
                                            {
                                                printf("\t\t\t\t\t\t%s\n",w.spelling);
                                                noofwords++;
                                            }
                                    }
                            }
                    }
                fclose(f);
            }
        }
        if(noofwords==0)
            printf("\n\n\n\t\t\t\t\t\t SORRY NO WORD IS FOUND TO SATISFY GIVEN CONSTRAINT ");
        else
            printf("\n\n\n\t\t\t\t\t\tNUMBER OF WORDS : %d",noofwords);
            return 1;
}
int meaningsearch()
{
    system("cls");
    system("color b1");
    char enterword[50],fileword[500],temp;
    int flag=0;
    FILE *p;
    p=fopen("wordwithmeaning.txt","r");
    fflush(stdin);
    printf("\n\n\n\t\t\t\t\t\tENTER WORD : ");
    gets(enterword);
    loading();
    if(enterword[0]>='a'&&enterword[0]<='z')
        enterword[0]-=32;
    while(!feof(p))
    {
        fgets(fileword,500,p);
        if(strncmp(enterword,fileword,strlen(enterword))==0)
        {
            system("color a1");
            printf("\n\t\t\t\t\t\t");
            puts(fileword);
            flag=1;
        }
    }
    if(flag==0)
    {   system("color a1");
        printf("\n\n\n\t\t\t\t\t\tNO MEANING IN OFFLINE DICTIONARY");
        printf("\n\n\n\t\t\t\t\t\tDO YOU WANT TO SEARCH ONLINE : ");
        scanf("%c",&temp);
        if(temp=='y'||temp=='Y')
        {
            strcpy(fileword,"start https://www.dictionary.com/browse/");
            strcat(fileword,enterword);
            system(fileword);
        }
    }
    fclose(p);
    printf("\n\n\n\t\t\t\t\t\tPRESS ENTER TO CONTINUE..");
    getch();
    fflush(stdin);
    system("cls");
    return 0;
}
void loading()
{
   /* system("color 0c");
   system("cls");
    for(int i=0;i<101;i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPLEASE WAIT");
        if(i%4==1)
            printf(".");
        else if(i%4==2)
            printf("..");
        else if(i%4==3)
            printf("...");
        printf("\n\n\t\t\t\t\t\t\t%d",i);
        printf(" %%");
        if(i>0&&i<5 || i>48&&i<54 || i>92&&i<96)
            Sleep(500);
        else if(i==100)
            Sleep(1000);
        else if(i>25&&i<30 || i>75&&i<80)
            Sleep(200);
        else
            Sleep(50);
        system("cls");
    }*/
    return;
}
void tiktok()
{
    system("color 70");
    int position;
    char name1[20],name2[20],*check,sample[10];
    fflush(stdin);
    Sleep(1000);
    system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t\tENTER PLAYER 1 NAME : ");
    gets(name1);
    printf("\n\n\n\t\t\t\t\t\t\t\tENTER PLAYER 2 NAME : ");
    gets(name2);
    Sleep(1000);
    system("cls");
    pattern(0,2);
    for(int i=0;i<9;i++)
    {
        if(i%2==0)
        {
            printf("%s CHANCE : ",name1);
            system("color 0a");
        }
        else
        {
            printf("%s CHANCE : ",name2);
            system("color 0c");
        }
             while(fgets(sample,sizeof(sample),stdin))
            {
                position=strtol(sample,&check,10);
                if(check==sample||*check!='\n')
                {
                    printf("\n\n\n\t\t\t\t\t\tPLEASE ENTER NATURAL NUMBER : ");
                }else break;
            }
            while(position<1 || position>9)
            {
                printf("\n\t\t\t\t\t\t\t\tINVALID POSITION\n\t\t\t\t\t\t\t\t ENTER AGAIN : ");
                 while(fgets(sample,sizeof(sample),stdin))
                {
                    position=strtol(sample,&check,10);
                    if(check==sample||*check!='\n')
                    {
                        printf("\n\n\n\t\t\t\t\t\tPLEASE ENTER NATURAL NUMBER : ");
                    }else break;
                }
            }
            Sleep(1000);
            system("cls");
            position=pattern(position-1,i%2);
            if(position==1)
            {
                Sleep(1000);
                system("cls");
                printf("\n\n\n\t\t\t\t\t\t\t\t%s WINS THE GAME",name1);
                break;
            }
            else if(position==2)
            {
                Sleep(1000);
                system("cls");
                printf("\n\n\n\t\t\t\t\t\t\t\t%s WINS THE GAME",name2);
                break;
            }
            else if(position==3)
            {
                Sleep(1000);
                system("cls");
                printf("DRAW");
            }
            else if(position==4)
            {
                printf("PLEASE ENTER AT VACANT POSITION\n\t\t\t\t\t\t\t\t");
                i-=1;
            }
    }
    printf("\n\n\n\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE..");
    getch();
    system("cls");
    system("color cf");
    fflush(stdin);
    return;
}
int pattern(int para,int para2)
{
    static int postion[9]={2,2,2,2,2,2,2,2,2};
    int flag=0;
    if(postion[para]==0 || postion[para]==1)
        flag=1;
    else
        postion[para]=para2;
    printf("\n\t\t\t\t\t\t\t");
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<68;j++)
        {
            if(i==10||i==21)
                printf("-");
            else if(j==22||j==45)
                printf("|");
            else
            {
                if(i<9 && i>1)
                {
                    if((j<18 && j>3 && postion[0]==0) || (j>26&&j<41&&postion[1]==0) || (j>49&&j<64&&postion[2]==0))
                    {
                            if((j==4||j==17||j==27||j==40||j==50||j==63)&&(i!=2&&i!=8))
                            printf("*");
                            else if((i==2 || i==8)&&(!(j==4||j==17||j==27||j==40||j==50||j==63)))
                                    printf("*");
                             else
                                        printf(" ");
                    }
                    else if((j<18 && j>3 && postion[0]==1) || (j>26&&j<41&&postion[1]==1) || (j>49&&j<64&&postion[2]==1))
                    {
                            if(2*i==j || 2*i==(j-23) || 2*i==(j-46) || 2*i==20-j || 2*i==20-j+23 || 2*i==20+46-j)
                                printf("*");
                            else
                                printf(" ");
                    }
                    else
                        printf(" ");
                }
                else if(i>12 && i<20)
                {
                    if((j<18 && j>3 && postion[3]==0) || (j>26&&j<41&&postion[4]==0) || (j>49&&j<64&&postion[5]==0))
                    {
                            if((j==4||j==17||j==27||j==40||j==50||j==63)&&(i!=13&&i!=19))
                            printf("*");
                            else if((i==13 || i==19)&&(!(j==4||j==17||j==27||j==40||j==50||j==63)))
                                    printf("*");
                             else
                                        printf(" ");
                    }
                    else if((j<18 && j>3 && postion[3]==1) || (j>26&&j<41&&postion[4]==1) || (j>49&&j<64&&postion[5]==1))
                    {
                            if(2*(i-11)==j || 2*(i-11)==(j-23) || 2*(i-11)==(j-46) || 2*(i-11)==20-j || 2*(i-11)==20-j+23 || 2*(i-11)==20+46-j)
                                printf("*");
                            else
                                printf(" ");
                    }
                    else
                        printf(" ");
                }
                else if(i>23 && i<31)
                {
                     if((j<18 && j>3 && postion[6]==0) || (j>26&&j<41&&postion[7]==0) || (j>49&&j<64&&postion[8]==0))
                    {
                            if((j==4||j==17||j==27||j==40||j==50||j==63)&&(i!=24&&i!=30))
                            printf("*");
                            else if((i==24 || i==30)&&(!(j==4||j==17||j==27||j==40||j==50||j==63)))
                                    printf("*");
                             else
                                        printf(" ");
                    }
                    else if((j<18 && j>3 && postion[6]==1) || (j>26&&j<41&&postion[7]==1) || (j>49&&j<64&&postion[8]==1))
                    {
                            if(2*(i-22)==j || 2*(i-22)==(j-23) || 2*(i-22)==(j-46) || 2*(i-22)==20-j || 2*(i-22)==20-j+23 || 2*(i-22)==20+46-j)
                                printf("*");
                            else
                                printf(" ");
                    }
                    else
                        printf(" ");
                }
                else
                    printf(" ");
            }
        }
        printf("\n\t\t\t\t\t\t\t");
    }
    if(postion[0]==postion[1]&&postion[1]==postion[2]&&postion[0]==0 || postion[3]==postion[5]&&postion[3]==postion[4]&&postion[3]==0 || postion[6]==postion[7]&&postion[7]==postion[8]&&postion[6]==0 || postion[0]==postion[3]&&postion[3]==postion[6]&&postion[0]==0 || postion[7]==postion[1]&&postion[4]==postion[1]&&postion[1]==0 || postion[2]==postion[5]&&postion[2]==postion[8]&&postion[2]==0 || postion[0]==postion[4]&&postion[0]==postion[8]&&postion[0]==0 || postion[2]==postion[4]&&postion[2]==postion[6]&&postion[2]==0)
        return 1;
    else if(postion[0]==postion[1]&&postion[1]==postion[2]&&postion[0]==1 || postion[3]==postion[5]&&postion[3]==postion[4]&&postion[3]==1 || postion[6]==postion[7]&&postion[7]==postion[8]&&postion[6]==1 || postion[0]==postion[3]&&postion[3]==postion[6]&&postion[0]==1 || postion[7]==postion[1]&&postion[4]==postion[1]&&postion[1]==1 || postion[2]==postion[5]&&postion[2]==postion[8]&&postion[2]==1 || postion[0]==postion[4]&&postion[0]==postion[8]&&postion[0]==1 || postion[2]==postion[4]&&postion[2]==postion[6]&&postion[2]==1)
        return 2;
    else if(flag==1)
        return 4;
    else
    {
     for(int i=0;i<9;i++)
     {
         if(postion[i]==2)
            return  0;
     }
    }
    return 3;
}
void helptiktok()
{
    system("cls");
    system("color a1");
    printf("\n\n\n\n\t\t\t\t TIKTOK IS A FUN GAME.IN THIS GAME,USER HAS TO ENTER A NUMBER FROM ONE TO NINE.");
    printf("\n\t\t\t\tONE DENOTES TOP LEFTMOST POSITION.");
    printf("\n\t\t\t\tTWO DENOTES TOP MIDDLE POSITION.");
    printf("\n\t\t\t\tTHREE DENOTES TOP RIGHTMOST POSITION.");
    printf("\n\t\t\t\tFOUR DENOTES MID LEFTMOST POSITION.");
    printf("\n\t\t\t\tFIVE DENOTES MIDDLE POSITION.");
    printf("\n\t\t\t\tSIX DENOTES MID RIGHTMOST POSITION.");
    printf("\n\t\t\t\tSEVEN DENOTES BOTTOM LEFTMOST POSITION.");
    printf("\n\t\t\t\tEIGHT DENOTES BOTTOM MID POSITION.");
    printf("\n\t\t\t\tNINE DENOTES BOTTOM RIGHTMOST POSITION.");
    printf("\n\t\t\t\tWHEN THREE SAME FIGURE COME IN STRAIGHT LINE OR AT THE DIALONAL POSITION THAN THAT USER WIN THE GAME.");
    printf("\n\n\n\t\t\t\tPRESS ENTER TO CONTINUE...");
    getch();
    system("cls");
    return;
}
void fullformsearch()
{
    Sleep(1000);
    system("cls");
    system("color b1");
    fflush(stdin);
    FILE *p;
    char full[10],choice,file[80];
    int f;
    printf("\n\n\t\t\t\tPLEASE SELECT CATEGORY : ");
    printf("\n\n\t\t\t\tA. AUTOMOBILE");
    printf("\n\t\t\t\tB. BANKING");
    printf("\n\t\t\t\tC. EDUCATIONAL");
    printf("\n\t\t\t\tD. EXAM");
    printf("\n\t\t\t\tE. FINANCE");
    printf("\n\t\t\t\tF. GADGETS");
    printf("\n\t\t\t\tG. GENERAL");
    printf("\n\t\t\t\tH. INTERNET SLANGS");
    printf("\n\t\t\t\tI. IT");
    printf("\n\t\t\t\tJ. MEDICAL");
    printf("\n\t\t\t\tK. ORGANISATIONAL");
    printf("\n\t\t\t\tL. POLITICAL");
    printf("\n\t\t\t\tM. TELECOM");
    printf("\n\t\t\t\tN. TECHNOLOGY");
    printf("\n\t\t\t\t0. MISCELLANEOUS");
    printf("\n\n\t\t\t\tENTER ALPHABET CORRESPONDING TO CATEGORY : ");
    scanf("%c",&choice);
    if(choice>='a' && choice<='z')
        choice-=32;
    Sleep(1000);
    system("cls");
    system("color a1");
    switch(choice)
    {
        case 'A':p=fopen("automobilefullform.txt","r");
            break;
        case 'B':p=fopen("bankingfullform.txt","r");
            break;
        case 'C':p=fopen("educationfullform.txt","r");
            break;
        case 'D':p=fopen("examfullform.txt","r");
            break;
        case 'E':p=fopen("financefullform.txt","r");
            break;
        case 'F':p=fopen("gadgetsfullform.txt","r");
            break;
        case 'G':p=fopen("generalfullform.txt","r");
            break;
        case 'H':p=fopen("internetslangfullform.txt","r");
            break;
        case 'I':p=fopen("itfullform.txt","r");
            break;
        case 'J':p=fopen("medicalfullform.txt","r");
            break;
        case 'K':p=fopen("organisationalfullform.txt","r");
            break;
        case 'L':p=fopen("politicalfullform.txt","r");
            break;
        case 'M':p=fopen("telecomfullform.txt","r");
            break;
        case 'N':p=fopen("technologyfullform.txt","r");
            break;
        case 'O':p=fopen("miscellaneousfullform.txt","r");
            break;
        default:
            printf("\n\t\t\t\tYOU ENTER WRONG VALUE.");
            return;
    }
    if(!p)
    {
        printf("\n\t\t\t\tERROR IN OPENING FULLFORM FILE.");
        return;
    }
    fflush(stdin);
    printf("\n\t\t\t\tENTER SHORT FORM : ");
    gets(full);
    f=0;
    Sleep(1000);
    system("cls");
    system("color df");
    for(int i=0;full[i]!='\0';i++)
    {
        if(full[i]>='a' && full[i]<='z')
            full[i]-=32;
    }
    loading();
    system("color df");
    while(!feof(p))
    {
        fgets(file,80,p);
        if(strncmp(file,full,strlen(full))==0)
        {   f=1;
            printf("\n\n\n\n\n\n\n\t\t\t\t");
            puts(file);
            break;
        }
    }
    if(f==0)
    {
        printf("\n\t\t\t\tNOT AVALIABLE IN OFFLINE DATA.");
        printf("\n\n\n\t\t\t\tDO YOU WANT TO SEARCH ONLINE? : ");
        scanf("%c",&choice);
        if(choice=='y'||choice=='Y')
        {
            strcpy(file,"start https://fullforms.com/");
            strcat(file,full);
            system(file);
        }
    }
    fclose(p);
    return;
}
