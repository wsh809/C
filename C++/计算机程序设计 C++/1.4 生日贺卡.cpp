/*
程序要求 
输入收卡人和送卡人的名字，在屏幕上打印出如下祝福话语
****************************************
Reciever

"Happy Birthday to you!"

    sincerely yours Sender
****************************************
知识点
字符串的输入与输出
*/

#include <iostream>
using namespace std;

int main()
{
    char Reciever[20], Sender[20];
    cin.getline(Reciever,20);
    cin.getline(Sender,20);
    cout<<"****************************************"<<endl;
    cout<<endl;
    cout<<Reciever<<endl;
    cout<<"Happy Birthday to you!"<<endl;
    cout<<"sincerely yours Sender"<<endl;
    cout<<"****************************************"<<endl;
    return 0;
}
