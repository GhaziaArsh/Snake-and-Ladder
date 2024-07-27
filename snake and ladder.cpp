#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void p2game(int &p1, int &p2);
void clearScreen();
void infomation();

void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void sleep(int m)
{
        for(int j=0;j<m*21000;j++)
        {

        }
}

int rollDice()
{
    int z;
    z=(rand()%6)+1;
   return z;
   }

void box(int ri, int ci, int num, int p1, int p2)
{
    gotoRowCol(ri + 3, ci + 2);
    cout << num;
    if(p1 != p2)
        {
        if(num == p1){
            gotoRowCol(ri + 1, ci);
            cout << "#";
        }
        if(num == p2){
            gotoRowCol(ri + 1, ci);
            cout << "@";
        }
    }
    else if(p1 == p2)
    {
        if(num == p1)
{
            gotoRowCol(ri + 1, ci);
            cout << "#";
        }
        if(num == p2)
{
            gotoRowCol(ri + 1, ci + 2);
            cout << "@";
        }
    }
    for(int i = 1; i<=6; i++)
    {
        gotoRowCol(ri, ci);
        cout << char(219);
        ci++;
    }

    for (int i = 1; i <= 5; i++)
    {
        gotoRowCol(ri, ci);
        cout << char(219);
        ri++;
    }
}

void board(int &p1, int &p2)
{
    for(int x=0;x<=69;x++)
    {gotoRowCol(0,x);
    cout<<char(219);}
    for(int y=0;y<=49;y++)
    {gotoRowCol(y,0);
    cout<<char(219);}
    for(int z=0;z<=69;z++)
    {gotoRowCol(49,z);
    cout<<char(219);}


    int num = 100;
    for(int i = 0; i <= 45; i+=5)
    {
        for(int j = 0; j <= 63; j+=7)
        {
            box(i,j, num, p1, p2);
            num--;
        }
    }
}

void clearScreen()
{
    for(int i = 0; i <= 70; i++){
        for(int j = 0; j <= 70; j++){
            gotoRowCol(i, j);
            cout << " ";
        }
    }
}

void p1game(int &p1, int &p2){
    int random_number=0;
    gotoRowCol(23, 85);
    cout << "P1 Turn: ";
    _getch();
    while (true)
        {
        if (_kbhit())
         {
            random_number = rollDice();
             gotoRowCol(27, 85);
            cout << "The dice rolled: " << random_number <<endl;
            if(p1 == 0 && random_number != 6){
                p2game(p1, p2);
            }
            else if(p1== 0 && random_number == 6){
                p1 = 1;
                clearScreen();
                board(p1, p2);
                p1game(p1, p2);
            }
            else if(p1> 0 && random_number == 6){
                if(p1 + random_number <= 100)
                    p1+= 6;
                else{
                    p2game(p1, p2);
                }
                if(p1== 2)

                    p1 = 23;
                else if(p1== 37)
                    p1 = 56;
                else if(p1 == 64)
                    p1 = 82;
                else if(p1 == 98)
                    p1 = 17;
                else if(p1 == 36)
                    p1 = 14;
                else if(p1 == 69)
                    p1= 46;
                clearScreen();
                board(p1, p2);
                p1game(p1, p2);
            }
            if(p1+ random_number <= 100)
                p1 += random_number;
            if(p1 == 2)
                p1 = 23;
            else if(p1 == 37)
                p1 = 56;
            else if(p1 == 64)
                p1 = 82;
            else if(p1 == 98)
                p1 = 17;
            else if(p1 == 36)
                p1 = 14;
            else if(p1 == 69)
                p1= 46;
            clearScreen();
            if(p1 <= 100)
                board(p1, p2);
            break;
        }
    }
    if(p1 == 100){
        gotoRowCol(30, 75);
        cout << "P1 in WINNER!";
        return;
    }
    if(p1 > 100){
        clearScreen();
        board(p1, p2);
        p2game(p1, p2);
    }
    if(true){
        p2game(p1, p2);
    }
}
void p2game(int &p1, int &p2){
    int random_number, a = 0;
    gotoRowCol(24, 85);
    cout << "P2 Turn: ";
    _getch();
    while (true)
        {
        if (kbhit())
         {
            random_number = rollDice();
             gotoRowCol(27, 85);
            cout << "The dice rolled: " << random_number <<endl;
            if(p2 == 0 && random_number != 6){
                p2game(p1, p2);
            }
            else if(p2== 0 && random_number == 6){
                p2 = 1;
                clearScreen();
                board(p1, p2);
                p2game(p1, p2);
            }
            else if(p2> 0 && random_number == 6)
                {
                if(p2 + random_number <= 100)
                    p2+= 6;
                else{
                    p1game(p1, p2);
                }
//snakes and ladders
                if(p2== 2)
                    p2 = 23;
                else if(p2== 37)
                    p2 = 56;
                else if(p2 == 64)
                    p2 = 82;
                else if(p2 == 98)
                    p2 = 17;
                else if(p2 == 36)
                    p2 = 14;
                else if(p2 == 69)
                    p2= 46;
                clearScreen();
                board(p1, p2);
                p2game(p1, p2);
            }
            if(p2+ random_number <= 100)

                p2 += random_number;
            if(p2 == 2)
                p2 = 23;
            else if(p2 == 37)
                p2 = 56;
            else if(p2 == 64)
                p2 = 82;
            else if(p2 == 98)
                p2 = 17;
            else if(p2 == 36)
                p2 = 14;
            else if(p2 == 69)
                p2= 46;
            clearScreen();
            if(p2 <= 100)
                board(p1, p2);
            break;
        }
    }
    if(p2 == 100)
    {
        gotoRowCol(30, 75);
        cout << "P2 in WINNER!";
        return;
    }
    if(p2 > 100){
        clearScreen();
        board(p1, p2);
        p1game(p1, p2);
    }
    if(true){
        p1game(p1, p2);
    }
}
void infomation(){
    gotoRowCol(40, 90);
    cout << "P1------> #";
    gotoRowCol(42, 90);
    cout << "P2------> @";

    gotoRowCol(12, 90);
    cout << "Snakes:" << endl;
    gotoRowCol(13, 90);
    cout << "98------->17" << endl;
    gotoRowCol(14, 90);
    cout << "69------->46" << endl;
    gotoRowCol(15, 90);
    cout << "36----->14" << endl;
    gotoRowCol(16, 90);
    cout << "Ladders:" << endl;
    gotoRowCol(17, 90);
    cout << "2------->23" << endl;
    gotoRowCol(18, 90);
    cout << "37------->56" << endl;
    gotoRowCol(19, 90);
    cout << "64----->82" << endl;
}

int main()
{
    getch();
    infomation();
    int p1= 0, p2 = 0;
    board(p1, p2);
    p1game(p1, p2);
    getch();
    return 0;
}

