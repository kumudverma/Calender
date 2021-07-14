#include<stdio.h>
struct date 
{
    int d,m,y;
    char *s;
};
bool leapyear(int y);
int calender(int r,int q,int y)
{
    const char weekday[7][20]={{"M"},{"T"},{"W"},{"T"},{"F"},{"S"},{"Sun"}};
    char A[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(leapyear(y))
    A[1]=29;
    int i,j=1,p,k=0;
    r=r%7;
    p=r;
    for(i=0;i<7;i++)
    {
        printf("%4s",weekday[i]);
    }
    printf("\n");
   switch (r)
    {
        case 0:
        printf("%4d",j);
        break;
        case 1:
        printf("%8d",j);
        break;
        case 2:
        printf("%12d",j);
        break;
        case 3:
        printf("%16d",j);
        break;
        case 4:
        printf("%20d",j);
        break;
        case 5:
        printf("%24d",j);
        break;
        case 6:
        printf("%28d",j);
        printf("\n");
        p=-1;
        break;
    }
    j++;
    p++;
    while(k<A[q-1]-1)
    {
        printf("%4d",j);
        j++;
        p++;
        if(p==7)
        {
            printf("\n");
            p=0;
        }
        k++;
    }
}
bool leapyear(int y)
{
    if(y%100!=0&&y%4==0||y%400==0)
    return 1;
    else
    return 0;
}
int diff(struct date a, struct date b)
{
    int days,c=0;
    const char A[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        days=a.d-b.d;
        if(a.m>=b.m)
        {
            c=0;
            while(c<(a.m-b.m))
            {
                days+=A[b.m-1+c];
                c++;
            }
            if(leapyear(a.y)&&a.m>2&&a.y!=b.y)
            {
                days+=1;
            }
            if(leapyear(b.y)&&b.m<3)
            {
                days+=1;
            }
            if(a.y!=b.y)
            {
            days+=365;
                c=1;
                while(a.y!=(b.y+c))
                {
                    if(leapyear(b.y+c))
                    days+=366;
                    else
                    days+=365;
                    c++;
                }
            }
            
        }
        else
        {
            c=0;
            while((b.m+c)<13)
            {
                days+=A[b.m+c-1];
                c++;
            }
            c=0;
            while(c<a.m-1)
            {
                days+=A[c];
                c++;
            }
            if(leapyear(a.y)&&a.m>2)
            days+=1;
            else if(leapyear(b.y)&&b.m<3)
            days+=1;
            c=1;
            while((b.y+c)<a.y)
            {
                if(leapyear(b.y+c))
                days+=366;
                else
                days+=365;
                c++;
            }
        }
        //printf("\n Diffrence between days is:%d\n",days);
    return days;
}
int main()
{
    int days,r;
    struct date d1,d2;
    d1.d=3;
    d1.m=8;
    d1.y=2020;
    d1.s="monday";
    printf(" Enter year and month");
    scanf("%d%d",&d2.y,&d2.m);
    d2.d=1;
    if(d1.y>d2.y)
    {
        days=diff(d1,d2);
        r=days%7;
        calender(7-r,d2.m,d2.y);
    }
    else if(d1.y<d2.y)
    {
        days=diff(d2,d1);
        r=days%7;
        calender(r,d2.m,d2.y);
    }
    else
    {
        if(d1.m>d2.m)
        {
            days=diff(d1,d2);
            r=days%7;
            calender(7-r,d2.m,d2.y);
        }
        else if(d1.m<d2.m)
        {
            days=diff(d2,d1);
            r=days%7;
            calender(r,d2.m,d2.y);
        }
        else
        {
            days=d2.d-d1.d;
            if(days<0)
            days=7+days;
            calender(days,d2.m,d2.y);
        }
    }
    
    
}
