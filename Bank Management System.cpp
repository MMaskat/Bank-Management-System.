                        /// Bank Management System///

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<string.h>
char name[20];
char password[20];
int diposite_amount, amount = 0, account_no, account, count1 = 0,ID,Taka=0; // Global variables
int transfer_amount;


void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail_$();
void transaction_details();
void exchange_noney();
void LastDetail_Taka();
void withdraw_Taka();
void Activity();
void Menu();

void creativity()
{
    for (int i = 0; i < 25; i++)
    {
        printf("*");
    }
}

//#Driver function
int main()
{
    FILE *File = fopen("File_of_Data.txt", "w");

    printf("Enter your name : ");
    gets(name);
    printf("Enter your ID: ");
    scanf("%d",&ID);
    fprintf(File, "\nName : %s\n", name);
    printf("Enter your account no. : ");
    scanf("%d", &account_no);
    printf("Enter your password: ");
    scanf("%s",password);
    fprintf(File, "Account no. : %d\n", account_no);

    fclose(File);
    Activity();
    return 0;
}

void Activity()
{
    while (1)
    {
        int ch;
        system("cls\n");
        Menu();
        printf("\nEnter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            deposit_money();
            break;
        case 2:

            withdraw_money();
            break;

        case 3:

            transfer_money();
            break;

        case 4:

            checkDetail_$();
            break;

        case 5:
            transaction_details();
            break;

        case 6:
            exchange_noney();
            break;
        case 7:
            withdraw_Taka();

        case 8:
            LastDetail_Taka();
        case 9:
            exit(0);

        default:
            printf("****Invalid choice****");
        }
    }
}
void Menu()
{
    system("cls\n");
    printf("Daffodil International University\n");
    creativity();
    printf("\n\tMENU\n");

    creativity();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Check details $\n");
    printf("5.transaction details\n");
    printf("6.Exchange Money\n");
    printf("7.Withdraw Taka\n");
    printf("8.Details Taka\n");
    printf("9.Exit\n");
    creativity();
}

void deposit_money()
{

    time_t tm;
    time(&tm);
    FILE *File = fopen("File_of_Data.txt", "a");
    printf("****DEPOSITING MONEY****\n");
    creativity();

    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &diposite_amount);
    amount += diposite_amount;
    printf("***Money Deposited***\n");
    printf("Now balance : %d $\n", amount);
    fprintf(File, "\n$ %d had been deposited to your account \n", diposite_amount);
    fprintf(File, "Date/Time of transaction :  %s\n", ctime(&tm));
    count1++;

    fclose(File);// close part of file
    printf("Press any key....\n");
    getch();
}

void withdraw_money()
{
    int withdrow_amount;
    time_t tm;
    time(&tm);
    FILE *File = fopen("File_of_Data.txt", "a");
    printf("****WITHDRAWING MONEY****\n");
    creativity();

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &withdrow_amount);


    if (amount < withdrow_amount)
    {
        printf("***Insufficient balance***\n");
        withdraw_money();
        return;

    }
    else
    {
        char pass[20];
        printf("Enter your password: ");
        scanf("%s",pass);
        if(strcmp(pass,password)==0)
        {
            amount = amount - withdrow_amount;
            printf("Money withdrawn successfuly\n");
            printf("Current balance : %d $\n", amount);
            fprintf(File, "\n$ %d had been withdrawn from your account \n", withdrow_amount);
            fprintf(File, "Date/Time of transaction :  %s\n", ctime(&tm));
            count1++;
        }
        else
        {
            printf("Wrong password.Try again....\n");
            withdraw_money();
            return;
        }
    }
    fclose(File);
    printf("Press any key....\n");
    getch();
}

void transfer_money()
{

    time_t tm;
    time(&tm);
    FILE *File = fopen("File_of_Data.txt", "a");
    printf("****TRANSFERRING MONEY****\n");
    creativity();

    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &account);
    if(account==account_no)
    {
        printf("Invalid Transection\n");
        transfer_money();
        return;
    }
    else
    {
        printf("\nEnter the amount you want to transfer\n");
        scanf("%d", &transfer_amount);

        if (amount < transfer_amount)
        {
            printf("***You do not have sufficient balance***\n");
            transfer_money();
            return;
        }
        else
        {
            char pass[20];
            printf("Enter your password: ");
            scanf("%s",pass);
            if(strcmp(pass,password)==0)
            {
                amount = amount - transfer_amount;
                printf("Money Transferred successfuly\n");
                printf("Current balance : %d $\n", amount);
                fprintf(File, "\n$%d had been transferred from your account to %d\n", transfer_amount, account);
                fprintf(File, "Date/Time of transaction :  %s\n", ctime(&tm));
                count1++;
            }
            else
            {
                printf("Wrong password.Try again....");
                transfer_money();
                return;
            }
        }

        fclose(File);
        printf("Press any key....\n");
        getch();
    }
}
void checkDetail_$()
{
    printf("ACCOUNT DETAILS\n");
    creativity();
    printf("\nName : %s\n", name);
    printf("ID: %d\n",ID);
    printf("Account No. : %d\n", account_no);
    printf("Total balance = %d\n ", amount);
    printf("\n%d transactions have been made from your account \n", count1);
    printf("Press any key.....");
    getch();
}

void transaction_details()
{


    FILE *FILE=fopen("File_of_Data.txt", "r");
    char chh = fgetc(FILE);
    //printf("%c\n",chh);
    if (feof(FILE))
    {
        printf("TRANSACTION DETAILS\n");
        creativity();
        printf("\n******NO RECENT TRANSACTION******\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
        creativity();
        printf("\n%d transactions have been made from your account \n", count1);
        while (!feof(FILE)) // EOF=End of file
        {
            chh = fgetc(FILE);
            printf("%c", chh);

        }
    }
    printf("\n\nPress any key to exit.....");
    getch();
}



void exchange_noney()
{
    time_t tm;
    time(&tm);
    FILE *File = fopen("File_of_Data.txt", "a");
    char pass[20];
    printf("Enter your password: ");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
        system("cls\n");
        int press;
        printf("Today $ rate is 105\n");
        printf("press 1 to continue and 0 to back\n");
        scanf("%d",&press);
        if(press==1)
        {
            int p,a,press;
            printf("Enter amount I want to exchange: ");
            scanf("%d",&p);
            if(p>amount)
            {
                printf("You do not have sufficient balance\n");
                exchange_noney();
            }
            else
            {
                a=p*100;
                printf("After exchange the BDT is:%d\n",a);
                amount = amount - p;
                printf("Current balance : %d $\n", amount);
                Taka+=a;
                printf("Money exchange successfully\n");
                fprintf(File, "\n%d $ had been exchanged from your account and exchanged money %d Taka\n",p,a);
                fprintf(File, "Date/Time of transaction :  %s\n", ctime(&tm));
                count1++;
                fclose(File);
                int x;
                printf("Press 1 to main manue and press any key to exit\n");
                scanf("%d",&press);
                if(press==1)
                {
                    Activity();
                }
                else
                {
                    exit(0);
                }
            }
        }
        else if(press==0)
        {
            Menu();

        }
        else
        {
            printf("Invalid choice\n");
            exit(0);
        }
    }
    else
    {
        printf("Wrong password\n");
        exchange_noney();
    }
}


void LastDetail_Taka()

{
    int press;
    printf("ACCOUNT DETAILS\n");
    creativity();
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", account_no);
    printf("Total Balance  = %d\n ", Taka);
    printf("Press 1 to main manue and press any key to exit\n");
    scanf("%d",&press);
    if(press==1)
    {
        Activity();
    }
    else
    {
        exit(0);
    }
}

void withdraw_Taka()
{
    int withdrow_Taka;
    time_t tm;
    time(&tm);
    FILE *File = fopen("File_of_Data.txt", "a");
    printf("****WITHDRAWING TAKA****\n");
    creativity();

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &withdrow_Taka);


    if (Taka < withdrow_Taka)
    {
        printf("***Insufficient balance***\n");
        withdraw_Taka();
        return;

    }
    else
    {
        char pass[20];
        printf("Enter your password: ");
        scanf("%s",pass);
        if(strcmp(pass,password)==0)
        {
            Taka -= withdrow_Taka;
            printf("Money withdrawn successfuly\n");
            printf("Current balance : %d Taka\n", Taka);
            fprintf(File, "\nTaka %d had been withdrawn from your account \n", withdrow_Taka);
            fprintf(File, "Date/Time of transaction :  %s\n", ctime(&tm));
            count1++;
        }
        else
        {
            printf("Wrong password.Try again....\n");
            withdraw_Taka();
            return;
        }
    }
    fclose(File);
    int press;
    printf("Press 1 to main manue and press any key to exit\n");
    scanf("%d",&press);
    if(press==1)
    {
        Activity();
    }
    else
    {
        exit(0);
    }
}

