//hawat 2009
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define esc 27
#define cls printf("%c[2J",esc)
#define pos(row,col) printf("%c[%d;%dH",esc,row,col)

char light[]="u2591";
char medium[]="u2592";
char dark[]="u2593";

typedef int MAP[5][5];

MAP _Fu =
{
1,1,1,1,1,
1,1,1,1,1,
1,1,1,1,1,
1,1,1,1,1,
1,1,1,1,1
};

MAP _Cl=
{
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0
};

MAP _0=
{
0,1,1,1,0,
1,0,0,1,1,
1,0,1,0,1,
1,1,0,0,1,
0,1,1,1,0
};
MAP _1=
{
0,0,0,1,0,
0,0,1,1,0,
0,0,0,1,0,
0,0,0,1,0,
0,0,1,1,1
};

MAP _2=
{
1,1,1,1,1,
0,0,0,0,1,
1,1,1,1,1,
1,0,0,0,0,
1,1,1,1,1
};

MAP _3=
{
0,1,1,1,0,
1,0,0,0,1,
0,0,1,1,1,
1,0,0,0,1,
0,1,1,1,0
};

MAP _4=
{
1,0,0,1,0,
1,0,0,1,0,
1,1,1,1,1,
0,0,0,1,0,
0,0,0,1,0
};

MAP _5=
{
1,1,1,1,1,
1,0,0,0,0,
1,1,1,1,1,
0,0,0,0,1,
1,1,1,1,1
};

MAP _6=
{
0,1,1,1,1,
1,0,0,0,0,
1,1,1,1,0,
1,0,0,0,1,
0,1,1,1,0
};

MAP _7=
{
0,1,1,1,1,
0,1,0,0,1,
0,0,0,1,0,
0,0,1,0,0,
0,1,0,0,0
};

MAP _8=
{
0,1,1,1,0,
1,0,0,0,1,
0,1,1,1,0,
1,0,0,0,1,
0,1,1,1,0
};

MAP _9=
{
0,1,1,1,0,
1,0,0,0,1,
0,1,1,1,0,
0,0,0,0,1,
1,1,1,1,0
};

MAP _Do=
{
0,0,0,0,0,
0,0,1,1,0,
0,0,0,0,0,
0,0,1,1,0,
0,0,0,0,0
};
MAP *cyfry[10] = {(MAP *)_0,(MAP *)_1,(MAP *)_2,(MAP *)_3,(MAP *)_4,(MAP *)_5,(MAP *)_6,(MAP *)_7,(MAP *)_8,(MAP *)_9};

wprint(MAP znak,int pozx, int pozy, int delay)
{
int i = 4;
int ii = 4;
for(i=4;i>=0;i--)
for(ii=4;ii>=0;ii--)
{
        pos(ii+pozx,i+pozy);
        lprint(znak[ii][i]);
        usleep(delay);
        fflush(stdout);
}


}

lprint(int znak)
{
        if(znak)
        printf("%s",dark);
        else
        printf("%s",light);
}

int main()
{
setlocale(LC_ALL, "");
    //wprintf("u2593n");


int delay = 0;
cls;
int i = 4;
int ii = 4;
time_t rawtime;
struct tm * tme;


while (1)
{
time ( &rawtime );
tme = localtime ( &rawtime );
int  h1 = tme->tm_hour/10;
int  h2 = tme->tm_hour%10;
int  m1 = tme->tm_min/10;
int  m2 = tme->tm_min%10;
int  s1 = tme->tm_sec/10;
int  s2 = tme->tm_sec%10;

//wprint( _Fu, 3,1,  0);
wprint( *cyfry[h1], 3,1,  delay);
//wprint( _Fu, 3,7,  0);
wprint( *cyfry[h2], 3,7,  delay);
//wprint( _Fu, 3,13,  0);
wprint( _Do, 3,13, delay);
//wprint( _Fu,3,19,  0);
wprint( *cyfry[m1], 3,19,  delay);
//wprint( _Fu,3,25,  0);
wprint( *cyfry[m2], 3,25,  delay);
//wprint( _Fu, 3,1,  0);
wprint( _Do, 3,31,  delay);
//wprint( _Fu, 3,7,  0);
wprint( *cyfry[s1], 3,37,  delay);
//wprint( _Fu, 3,13,  0);
wprint( *cyfry[s2], 3,43,  delay);
//wprint( _Fu,3,19,  0);
//wprint( _Fu, 3,19,  delay);
}
//wprint( _Cl, 3,10,  0);
pos(20,0);

return(0);
}
