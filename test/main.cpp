#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>
using namespace std;

#define Button_1 1
#define Button_2 2
#define Button_3 4
#define Button_4 8

int GetKey();

int main()
{
    int _key = 0;
//    int flag = 0;

//    while(1)
//    {
//        flag = getch();
//        if(flag != 0)
//            break;
//    }

    while(1)
    {
//        if (GetAsyncKeyState('A') & 0x8000)
//            cout<<hex<<Button_1;
//        if (GetAsyncKeyState('S') & 0x8000)
//            cout<<hex<<Button_2;
        _key = GetKey();
        cout<<_key;
        cout<<"Ò»´ÎÉ¨Ãè";
        //system("pause");
    }
    return 0;
}
int GetKey()
{
    int _key = 0;

    if (GetAsyncKeyState('A') & 0x8000)
        _key |= Button_1;

    if (GetAsyncKeyState('S') & 0x8000)
        _key |= Button_2;

    if (GetAsyncKeyState('D') & 0x8000)
        _key |= Button_3;

    if (GetAsyncKeyState('F') & 0x8000)
        _key |= Button_4;


    if (_key&Button_1 && _key&Button_2)
        _key |= Button_1|Button_2;

    if (_key&Button_1 && _key&Button_3)
        _key |= Button_1|Button_3;

    if (_key&Button_1 && _key&Button_4)
        _key |= Button_1|Button_4;

    if (_key&Button_2 && _key&Button_3)
        _key |= Button_2|Button_3;

    if (_key&Button_2 && _key&Button_4)
        _key |= Button_2|Button_4;

    if (_key&Button_3 && _key&Button_4)
        _key |= Button_3|Button_4;


    if (_key&Button_1 && _key&Button_2 && _key&Button_3)
        _key |= Button_1|Button_2|Button_3;

    if (_key&Button_1 && _key&Button_2 && _key&Button_4)
        _key |= Button_1|Button_2|Button_4;

    if (_key&Button_1 && _key&Button_3 && _key&Button_4)
        _key |= Button_1|Button_3|Button_4;

    if (_key&Button_2 && _key&Button_3 && _key&Button_4)
        _key |= Button_2|Button_3|Button_4;

    if (_key&Button_1 && _key&Button_2 && _key&Button_3 && _key&Button_4)
        _key |= Button_1|Button_2|Button_3|Button_4;

    Sleep(100);

    return _key;
}
