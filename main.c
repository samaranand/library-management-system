#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
// #include<dos.h>
#include<time.h>

char password[10] = {"samar"};
void Password(void);
void mainmenu(void);
void issuebook(void);
void addbook(void);
void searchbook(void);
void booklist(void);
void deletebook(void);
void frame(void);       //body of main
void blink(void);       //dot blinking system
void Mmenu(void);       //unction for calling main-menu
void Ddefault(void);       //function for making false default
void closeApplication(void);        //function to terminate application
char categories[][15] = {"Computer", "Mathematics", "Science", "Engineering", "English", "Literature"};
char language[][10] = {"English", "Hindi"};
FILE *fp, *ft, *fs;

struct book
{
    int bookId;
    char bookName[20];
    char bookAuthor[20];
    char *catg;
    int year;
    char publication[20];
    char *lang;
} a;
int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n", ctime(&t));
    return 0 ;
}
COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    gotoxy(15, 5);
    printf("Welcome To Our Project");
    gotoxy(15, 6);
    t();
    getch();
    system("cls");
    Password();
    return 0;
}
void Password(void) //for password option
{
    system("cls");
    static int k = 0;
    char d[25] = " Password Protected ";
    char ch, pass[10];
    int i = 0, j;
    gotoxy(10, 13);
    for (j = 0; j < (40 + strlen(d)); j++)
    {
        printf("*");
    }
    gotoxy(10, 4);
    for (j = 0; j < 20; j++)
    {
        Sleep(50);
        printf("*");
    }
    for (j = 0; j < strlen(d); j++)
    {
        Sleep(50);
        printf("%c", d[j]);
    }
    for (j = 0; j < 20; j++)
    {
        Sleep(50);
        printf("*");
    }
    gotoxy(10, 6);
    t();
    gotoxy(15, 8);
    printf("Enter Password: ");
    while (ch != 13)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password) == 0)
    {
        for (j = 0; j < 5; j++)
        {
            system("cls");
            gotoxy(15, 2);
            Sleep(250);
            printf("Password match");
            Sleep(250);
        }
        gotoxy(15, 3);
        printf("Processing");
        blink();
        mainmenu();
    }
    else
    {
        gotoxy(15, 16);
        printf("\aWarning!! Incorrect Password");
        getch();
        k++;
        if (k == 2)
            closeApplication();
        Password();
    }
}
void mainmenu(void)
{
    char ch;
    system("cls");
    frame();
    gotoxy(38, 6);
    printf("Welcome To Mainmenu");
    gotoxy(25, 9);
    printf("\xDB\xDB\xDB\xB2 1. Issue Book");
    gotoxy(25, 11);
    printf("\xDB\xDB\xDB\xB2 2. Add Book");
    gotoxy(25, 13);
    printf("\xDB\xDB\xDB\xB2 3. Search Book");
    gotoxy(25, 15);
    printf("\xDB\xDB\xDB\xB2 4. Book List");
    gotoxy(25, 17);
    printf("\xDB\xDB\xDB\xB2 5. Delete Book");
    gotoxy(25, 19);
    printf("\xDB\xDB\xDB\xB2 6. Close Application");
    gotoxy(30, 21);
    t();        //printing time
    gotoxy(30, 23);
    printf("Enter your choice: ");
    fflush(stdin);
    ch = getch();
    switch (ch)
    {
    case '1':
        issuebook();
        break;
    case '2':
        addbook();
        break;
    case '3':
        searchbook();
        break;
    case '4':
        booklist();
        break;
    case '5':
        deletebook();
        break;
    case '6':
    {
        closeApplication();
        break;
    }
    default:
    {
        Ddefault();
        mainmenu();
    }
    }
}
void frame(void)
{
    int i;
    gotoxy(20, 4);
    for (i = 0; i < 30; i++)
        printf("\xB2\xB2");
    gotoxy(20, 24);
    for (i = 0; i < 30; i++)
        printf("\xB2\xB2");
    for (i = 0; i < 20; i++)
    {
        gotoxy(20, 5 + i);
        printf("\xB2");
        gotoxy(79, 4 + i);
        printf("\xB2");
    }
}
void addbook(void)
{
    char another = 'y';
    int ch, tx;
    system("cls");
    frame();
    gotoxy(34, 6);
    printf("Welcome To Add-Book menu");
    gotoxy(25, 9);
    printf("\xDB\xDB\xDB\xB2 1. Computer");
    gotoxy(50, 9);
    printf("\xDB\xDB\xDB\xB2 2. Mathematics");
    gotoxy(25, 11);
    printf("\xDB\xDB\xDB\xB2 3. Science");
    gotoxy(50, 11);
    printf("\xDB\xDB\xDB\xB2 4. Engineering");
    gotoxy(25, 13);
    printf("\xDB\xDB\xDB\xB2 5. English");
    gotoxy(50, 13);
    printf("\xDB\xDB\xDB\xB2 6. Literature");
    gotoxy(25, 17);
    printf("\xDB\xDB\xDB\xB2 9. Go to main-menu.");
    gotoxy(25, 19);
    printf("\xDB\xDB\xDB\xB2 0. Close Application.");
    gotoxy(30, 21);
    t();        //printing time
    gotoxy(30, 23);
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        fp = fopen("library.dat", "ab+");
        while (another == 'y' || another == 'Y')
        {
            system("cls");
            frame();
            gotoxy(34, 6);
            printf("Welcome to adding book");
            gotoxy(25, 8);
            printf("Enter Book id: ");
            scanf("%d", &a.bookId);
            gotoxy(25, 10);
            printf("Enter Book name: ");
            fflush(stdin);
            gets(a.bookName);
            //scanf("%s",a.bookName);
            gotoxy(25, 12);
            printf("Enter Book author: ");
            fflush(stdin);
            gets(a.bookAuthor);
            //scanf("%s",a.bookAuthor);
            gotoxy(25, 14);
            printf("Enter Book publication year: ");
            scanf("%d", &a.year);
            gotoxy(25, 16);
            printf("Enter Book publication: ");
            fflush(stdin);
            gets(a.publication);
            //scanf("%s",a.publication);
to:
            gotoxy(25, 18);
            printf("Enter Language: 1. English 2. Hindi : ");
            scanf("%d", &tx);
            if (tx == 2 || tx == 1)
                a.lang = language[tx - 1];
            else
            {
                gotoxy(25, 18);
                printf("\aEnter The Correct choice:                       ");  //space key is alloted
                getch();
                goto to;
            }
            a.catg = categories[ch - 1];
            fseek(fp, 0, SEEK_END);
            fwrite(&a, sizeof(a), 1, fp);
            gotoxy(25, 20);
            printf("The book is added is successfully.");
            gotoxy(25, 22);
            printf("want to add more book ? Y/N ? ");
            fflush(stdin);
            another = getche();
        }
        fclose(fp);
        //getch();
        Mmenu();
        break;
    case 9:
    {
        Mmenu();
        break;
    }
    case 0:
    {
        closeApplication();
        break;
    }
    default:
    {
        Ddefault();
        addbook();
    }
    }
}
void searchbook(void)
{
    char ch , another = 'y';
    int id;
    char name[20];
    int flag = 0;
    system("cls");
    frame();
    gotoxy(34, 6);
    printf("Welcome To Search-Book menu");
    gotoxy(25, 9);
    printf("\xDB\xDB\xDB\xB2 1. Search Book by id");
    gotoxy(25, 11);
    printf("\xDB\xDB\xDB\xB2 2. Search Book by name");
    gotoxy(25, 13);
    printf("\xDB\xDB\xDB\xB2 3. Go to main-menu.");
    gotoxy(25, 15);
    printf("\xDB\xDB\xDB\xB2 4. Close Application.");
    gotoxy(30, 21);
    t();        //printing time
    gotoxy(30, 23);
    printf("Enter your choice: ");

    fflush(stdin);
    ch = getch();
    switch (ch)
    {
    case '1':
    {
        fp = fopen("library.dat", "rb");
        while (another == 'y' || another == 'Y')
        {
            system("cls");
            flag = 0;
            gotoxy(25, 8);
            printf("Enter book ID: ");
            scanf("%d", &id);
            gotoxy(25, 10);
            blink();
            //fp=fopen("library.dat","rb");
            rewind(fp);
            while ( fread(&a, sizeof(a), 1, fp) == 1)
            {
                if (a.bookId == id)
                {
                    flag = 1;
                    system("cls");
                    frame();
                    gotoxy(25, 9);
                    printf("The book of id: %d is available", a.bookId);
                    gotoxy(25, 11);
                    printf("Book Name: %s", a.bookName);
                    gotoxy(25, 13);
                    printf("Book Author: %s", a.bookAuthor);
                    gotoxy(25, 15);
                    printf("Categories: %s", a.catg);
                    gotoxy(25, 17);
                    printf("Language: %s", a.lang);
                    gotoxy(25, 19);
                    printf("Publication Year: %d", a.publication);
                    gotoxy(25, 21);
                    printf("Published By: %s", a.publication);
                }
            }
            if (flag == 0)
                printf(" Book is not found");
            gotoxy(25, 22);
            printf("want to find more book ? Y/N ? ");
            fflush(stdin);
            another = getche();
        }
        fclose(fp);
        getch();
        Mmenu();
        break;
    }
    case '2':
    {
        fp = fopen("library.dat", "rb");
        while (another == 'y' || another == 'Y')
        {
            system("cls");
            flag = 0;
            gotoxy(25, 8);
            printf("Enter name of book: ");
            scanf("%s", name);
            gotoxy(25, 10);
            blink();
            rewind(fp);
            while ( fread(&a, sizeof(a), 1, fp) == 1)
            {
                if (strcmpi(a.bookName , name) == 0)
                {
                    flag = 1;
                    system("cls");
                    frame();
                    gotoxy(25, 9);
                    printf("The book of name: %s is available", a.bookName);
                    gotoxy(25, 11);
                    printf("Book ID: %d", a.bookId);
                    gotoxy(25, 13);
                    printf("Book Author: %s", a.bookAuthor);
                    gotoxy(25, 15);
                    printf("Categories: %s", a.catg);
                    gotoxy(25, 17);
                    printf("Language: %s", a.lang);
                    gotoxy(25, 19);
                    printf("Publication Year: %d", a.publication);
                    gotoxy(25, 21);
                    printf("Published By: %s", a.publication);
                }
            }
            if ( flag == 0)
                printf(" Book is not found.");
            gotoxy(25, 22);
            printf("want to find more book ? Y/N ? ");
            fflush(stdin);
            another = getche();
        }
        fclose(fp);
        getch();
        Mmenu();
        break;
    }
    case '3':
    {
        Mmenu();
        break;
    }
    case '4':
    {
        closeApplication();
        break;
    }
    default:
    {
        Ddefault();
        searchbook();
    }
    }
}
void booklist(void)
{
    system("cls");
    int j = 4;
    fp = fopen("library.dat", "rb");
    rewind(fp);
    printf("\t************************************* Book List ************************************\n\n");
    printf("      BookId      BookName       BookAuthor       BookCategories        Year         Publication      Language");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        gotoxy(7, j);
        printf("%d", a.bookId);
        gotoxy(19, j);
        printf("%s", a.bookName);
        gotoxy(34, j);
        printf("%s", a.bookAuthor);
        gotoxy(54, j);
        printf("%s", a.catg);
        gotoxy(72, j);
        printf("%d", a.year);
        gotoxy(88, j);
        printf("%s", a.publication);
        gotoxy(103, j);
        printf("%s", a.lang);
        j++;
    }
    fclose(fp);
    gotoxy(8, j + 1);
    printf("Enter any key to go Main-menu...");
    getch();
    Mmenu();
}
void deletebook(void)
{
    char ch , another = 'y';
    int id , flag;
    char name[20];
    system("cls");
    frame();
    gotoxy(34, 6);
    printf("Welcome To Delete-Book menu");
    gotoxy(25, 9);
    printf("\xDB\xDB\xDB\xB2 1. Delete Book by id");
    gotoxy(25, 11);
    printf("\xDB\xDB\xDB\xB2 2. Delete Book by name");
    gotoxy(25, 13);
    printf("\xDB\xDB\xDB\xB2 3. Go to main-menu.");
    gotoxy(25, 15);
    printf("\xDB\xDB\xDB\xB2 4. Close Application.");
    gotoxy(30, 21);
    t();        //printing time
    gotoxy(30, 23);
    printf("Enter your choice: ");
    fflush(stdin);
    ch = getche();
    switch (ch)
    {
    case '1':
    {
        while (another == 'y' || another == 'Y')
        {
            fp = fopen("library.dat", "ab+");
            system("cls");
            frame();
            flag = 0;
            gotoxy(25, 8);
            printf("Enter book ID: ");
            scanf("%d", &id);
            gotoxy(25, 10);
            rewind(fp);
            while ( fread(&a, sizeof(a), 1, fp) == 1)
            {
                if (a.bookId == id)
                {
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                fclose(fp);
                printf(" Book is not found");
            }
            else if (flag != 0)
            {
                rewind(fp);
                fs = fopen("new.dat", "ab+");
                printf(" Book is found. Deleting Book");
                while ( fread(&a, sizeof(a), 1, fp) == 1)
                {
                    if (a.bookId != id)
                    {
                        flag = 1;
                        fseek(fs, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, fs); //write all in tempory file except that
                    }
                }
                fclose(fp);
                fclose(fs);
                remove("library.dat");
                rename("new.dat", "library.dat");
            }
            gotoxy(25, 12);
            printf("want to delete more book ? Y/N ? ");
            fflush(stdin);
            another = getche();
        }
        gotoxy(25, 14);
        printf("Press any key to continue...");
        getch();
        Mmenu();
        break;
    }
    case '2':
    {
        while (another == 'y' || another == 'Y')
        {
            fp = fopen("library.dat", "ab+");
            system("cls");
            frame();
            flag = 0;
            gotoxy(25, 8);
            printf("Enter book name: ");
            fflush(stdin);
            gets(name);
            gotoxy(25, 10);
            rewind(fp);
            while ( fread(&a, sizeof(a), 1, fp) == 1)
            {
                if (strcmpi(a.bookName , name) == 0)
                {
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                fclose(fp);
                printf(" Book is not found");
            }
            else if (flag != 0)
            {
                rewind(fp);
                fs = fopen("new.dat", "ab+");
                printf(" Book is found. Deleting Book");
                while ( fread(&a, sizeof(a), 1, fp) == 1)
                {
                    if (strcmpi(a.bookName , name) != 0)
                    {
                        flag = 1;
                        fseek(fs, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, fs); //write all in tempory file except that
                    }
                }
                fclose(fp);
                fclose(fs);
                remove("library.dat");
                rename("new.dat", "library.dat");
            }
            gotoxy(25, 12);
            printf("want to delete more book ? Y/N ? ");
            fflush(stdin);
            another = getche();
        }
        gotoxy(25, 14);
        printf("Press any key to continue...");
        getch();
        Mmenu();
        break;
    }
    case '3':
    {
        Mmenu();
        break;
    }
    case '4':
    {
        closeApplication();
        break;
    }
    default:
    {
        Ddefault();
        deletebook();
    }
    }
}
void blink(void)
{
    for (int j = 0; j < 10; j++)
    {
        Sleep(350);
        printf(".");
    }
}
void issuebook(void)
{
    char ch, another = 'y';
    system("cls");
    fp = fopen("library.dat", "ab+");
    frame();
    gotoxy(34, 6);
    printf("Welcome To Issue book menu");
    gotoxy(25, 9);
    printf("\xDB\xDB\xDB\xB2 1. Issue Book");
    gotoxy(25, 11);
    printf("\xDB\xDB\xDB\xB2 2. Issued Book List");
    gotoxy(25, 13);
    printf("\xDB\xDB\xDB\xB2 3. Deposit a Book");
    gotoxy(25, 15);
    printf("\xDB\xDB\xDB\xB2 4. Go to main-menu.");
    gotoxy(25, 17);
    printf("\xDB\xDB\xDB\xB2 5. Close Application.");
    gotoxy(30, 21);
    t();        //printing time
    gotoxy(30, 23);
    printf("Enter your choice: ");
    fflush(stdin);
    ch = getche();
    switch (ch)
    {
    case '1':
        system("cls");
        frame();
        printf("ENter issue book list.....");
        getch();
        break;
    case '2':
        addbook();
        break;
    case '3':
        printf("Deposit Book");
        break;
    case '4':
    {
        Mmenu();
        break;
    }
    case '5':
    {
        closeApplication();
        break;
    }
    default:
    {
        Ddefault();
        issuebook();
    }
    }
    fclose(fp);
}
void Mmenu()
{
    system("cls");
    frame();
    gotoxy(25, 6);
    printf("Processing for Main-menu");
    blink();
    mainmenu();
}
void Ddefault(void)
{
    system("cls");
    frame();
    gotoxy(25, 6);
    printf("Enter a valid choice...");
    gotoxy(25, 8);
    printf("Press any key to continue...");
    getch();
}
void closeApplication(void)
{
    system("cls");
    frame();
    gotoxy(25, 6);
    printf("thanks");
    gotoxy(25, 9);
    printf("Brought to u by team 3....");
    gotoxy(25, 11);
    printf("Exiting in three second.");
    blink();
    Sleep(3000);
    gotoxy(10, 25);
    exit(0);
}