
#include<stdio.h>
void main( )  
{    
    struct {
         char initial;                     /* 姓*/  
         int age;                            /* 年龄*/
         int grade;                        /* 考分*/
        } boy , girl;                      /*两个结构体变量*/
   boy.initial = 'R';
   boy.age = 17;
   boy.grade = 75;
   girl.age = boy.age - 1;         
   girl.grade = 82;
   girl.initial = 'H';
   printf("%c is %d years old and got a grade of %d\n",
           girl.initial,    girl.age,    girl.grade);
   printf("%c is %d years old and got a grade of %d\n",
           boy.initial,   boy.age,   boy.grade);
}