#include<iostream>
#include<windows.h>
using namespace std;

void printmaze();
void gotoxy(int x, int y);
void erase(int x, int y);
void printpacman(int x, int y);
char getCharAtxy(short int x, short int y);

main()
{
    int pacmanX=1;
    int pacmanY=1;
    bool gamerunning = true;

    system("cls");
    printmaze();
    printpacman(pacmanX, pacmanY);

    while(gamerunning)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            char nextLocation = getCharAtxy(pacmanX-1, pacmanY);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanX=pacmanX-1;
                printpacman(pacmanX, pacmanY);
            }
        }
         if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextLocation = getCharAtxy(pacmanX+1, pacmanY);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanX=pacmanX+1;
                printpacman(pacmanX, pacmanY);
            }
        }
         if (GetAsyncKeyState(VK_UP))
        {
            char nextLocation = getCharAtxy(pacmanX, pacmanY-1);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanY=pacmanY-1;
                printpacman(pacmanX, pacmanY);
            }
        }
         if (GetAsyncKeyState(VK_DOWN))
        {
            char nextLocation = getCharAtxy(pacmanX, pacmanY+1);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanY=pacmanY+1;
                printpacman(pacmanX, pacmanY);
            }
        }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                gamerunning = false;
            }
            Sleep(250);
    }
}
void printmaze()
{
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
    cout<<"%   ........          %"<<endl;
    cout<<"%          .          %"<<endl;
    cout<<"%   ........          %"<<endl;
    cout<<"%          ........   %"<<endl;
    cout<<"%   .                 %"<<endl;
    cout<<"%    .      .         %"<<endl;
    cout<<"%     .     .         %"<<endl;
    cout<<"%      .    .         %"<<endl;
    cout<<"%       .   .......   %"<<endl;
    cout<<"%        .  .         %"<<endl;
    cout<<"%         . .         %"<<endl;
    cout<<"%          ..         %"<<endl;
    cout<<"%.................... %"<<endl;
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void erase(int x, int y)
{
    gotoxy(x, y);
    cout<<" ";
}
void printpacman(int x, int y)
{
    gotoxy(x, y);
    cout<<"P";
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0,0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}