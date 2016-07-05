#include<stdio.h>
#define STNUM   5  
 
struct   xscj
{
    char xh[5];
    float cj[2];
    float av;
};
 
float ave(float x,float y)
{  float a;
   a=(x+y)/2.0;
   return a;
}
 
void main()
{ 
  struct xscj xs[4]={{"01",70,80},  {"02",78,67},{"03",56,78},  {"04",90,80}};
  int i;
  for (i=0;i<4;i++)
  { 
    xs[i].av = ave(xs[i].cj[0],xs[i].cj[1]);
    printf("%s,%5.1f,%5.1f,%5.1f\n",xs[i].xh, xs[i].cj[0],xs[i].cj[1],xs[i].av);
  }
}