
#include  <stdio.h>
#include  <string.h>
void  fun ( char *w,  int  m )
{  char  s, *p1 , *p2 ;
    p1=w;   p2=w+m-1;
    while(p1<p2)
    {   s=*p1++;   *p1=*p2-- ; *p2=s;    }
}
int main( )
{  char    a[ ]="1234567";
    fun ( a , (int) strlen(a) );
    puts(a);
    return 0;
}