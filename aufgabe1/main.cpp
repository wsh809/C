#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

#define Button_1 1
#define Button_2 2
#define Button_3 4
#define Button_4 8

int GetKey();

int Get_neu_state(int key);

void LedSet(int num);

int main()
{
    int flag = 0;
    int _num = 0;
    int _current_state = 0;
    int _neu_state = 0;
    int _key = 0;

    //等待键盘输入
        while(1)
    {
        flag = getch();
        if(flag != 0)
            break;
    }

    //有键盘输入后进入循环
    while(1)
    {
        //判断按几个键
        _key = GetKey();

        //根据按键得新状态
        _neu_state = Get_neu_state(_key);


        //对比新状态和当前状态得到次数
        switch(_neu_state - _current_state)
        {
            case 1: _num += 1;
                cout<<"_current_state is "<<_current_state<<endl;
                cout<<"_neu_state is "<<_neu_state<<endl;
                cout<<"num is "<<_num<<endl;
                LedSet(_num);
                break;
            case 2: _num += 2;
                cout<<"_current_state is "<<_current_state<<endl;
                cout<<"_neu_state is "<<_neu_state<<endl;
                cout<<"num is "<<_num<<endl;
                LedSet(_num);
                break;
            case 3: _num += 3;
                cout<<"_current_state is "<<_current_state<<endl;
                cout<<"_neu_state is "<<_neu_state<<endl;
                cout<<"num is "<<_num<<endl;
                LedSet(_num);
                break;
            case 4: _num += 4;
                cout<<"_current_state is "<<_current_state<<endl;
                cout<<"_neu_state is "<<_neu_state<<endl;
                cout<<"num is "<<_num<<endl;
                LedSet(_num);
                break;
            default: break;
        }

        //更新当前状态
        _current_state = _neu_state;
    }
    return 0;
}

int Get_neu_state(int key)
{
    int neu_state = 0;
    switch(key)
    {
        case 1: neu_state = 1; break;
        case 2: neu_state = 1; break;
        case 4: neu_state = 1; break;
        case 8: neu_state = 1; break;

       case 3: neu_state = 2; break;
       case 5: neu_state = 2; break;
       case 9: neu_state = 2; break;
       case 6: neu_state = 2; break;
       case 10: neu_state = 2; break;
       case 12: neu_state = 2; break;

       case 7: neu_state = 3; break;
       case 11: neu_state = 3; break;
       case 13: neu_state = 3; break;
       case 14: neu_state = 3; break;

       case 15: neu_state = 4; break;
       default: neu_state = 0;break;
    }
    //cout<<"neu_state is "<<neu_state<<endl;
    return neu_state;
}

int GetKey()
{
    int key = 0;

    if (GetAsyncKeyState('A') & 0x8000)
        key |= Button_1;

    if (GetAsyncKeyState('S') & 0x8000)
        key |= Button_2;

    if (GetAsyncKeyState('D') & 0x8000)
        key |= Button_3;

    if (GetAsyncKeyState('F') & 0x8000)
        key |= Button_4;


    if (key&Button_1 && key&Button_2)
        key |= Button_1|Button_2;

    if (key&Button_1 && key&Button_3)
        key |= Button_1|Button_3;

    if (key&Button_1 && key&Button_4)
        key |= Button_1|Button_4;

    if (key&Button_2 && key&Button_3)
        key |= Button_2|Button_3;

    if (key&Button_2 && key&Button_4)
        key |= Button_2|Button_4;

    if (key&Button_3 && key&Button_4)
        key |= Button_3|Button_4;


    if (key&Button_1 && key&Button_2 && key&Button_3)
        key |= Button_1|Button_2|Button_3;

    if (key&Button_1 && key&Button_2 && key&Button_4)
        key |= Button_1|Button_2|Button_4;

    if (key&Button_1 && key&Button_3 && key&Button_4)
        key |= Button_1|Button_3|Button_4;

    if (key&Button_2 && key&Button_3 && key&Button_4)
        key |= Button_2|Button_3|Button_4;

    if (key&Button_1 && key&Button_2 && key&Button_3 && key&Button_4)
        key |= Button_1|Button_2|Button_3|Button_4;

    Sleep(100);

    return key;
}

void LedSet(int num)
{
    switch(num%4)
    {
        case 0: cout<<"display of the LED ist:"<<"--X--X--"<<endl<<"******************"<<endl; break;
        case 1: cout<<"display of the LED ist:"<<"--X--O--"<<endl<<"******************"<<endl; break;
        case 2: cout<<"display of the LED ist:"<<"--O--X--"<<endl<<"******************"<<endl; break;
        case 3: cout<<"display of the LED ist:"<<"--O--O--"<<endl<<"******************"<<endl; break;
        default: break;
    }
}
