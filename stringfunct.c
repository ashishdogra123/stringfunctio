#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void xgets(char*p)
{
    scanf("%c",p);
    if(*p=='\n')
    {
        *p='\0';
    }
    else
    {
        p++;
        xgets(p);
    }
}
int xstrlen(char*q)
{
    int l=0;
    while(*q!='\0')
    {
        q++;
        l++;
    }
    return(l);
}
void xstrlwr(char*p)
{
    char *q=p;
    while(*p!='\0')
    {
        if(*p>=65&&*p<=90)
        {
            *p=*p+32;
        }
        p++;
    }
    printf("%s",q);
}
void xstrupr(char*p)
{
    char *q=p;
    while(*p!='\0')
    {
        if(*p>=97&&*p<=122)
        {
            *p=*p-32;
        }
        p++;
    }
    printf("%s",q);
}
void xstrcat(char*t,char*s)
{
    int l;
    char *q=s;
    l=xstrlen(s);
    s=s+l;
    while(*t!='\0')
    {
        *s=*t;
        s++;
        t++;
    }
    *s='\0';
    printf("%s\n",q);
}
void xstrcpy(char*t,char*s)
{
    char *p=t,*q=s;
    while(*s!='\0')
    {
        *t=*s;
        t++;
        s++;
    }
    *t='\0';
    printf("the source is %s and target is %s",q,p);
}
void xstrcmp(char*t,char*s)
{
    int m=0;
    while(*s!='\0')//loop doesn't mean that you have to increment the value then only they will implement if you not give any value they will keep rotating on the same place.
    {
        if(*s==*t)
        {
            s++;
            t++;
        }
        else
        {
            m++;
            break;
        }
    }
    printf("If m=0 then both are same and if it is non zero then they are different.\n");
    printf("the value of m is %d",m);
}
/*void xstrcmpi(char*t,char*s)///
{

}*/
void xstrchr(char c,char *p)
{
    char *q=p;
    int m=1,l;
    l=xstrlen(p);
    while(*p!='\0')
    {
        if(c==*p)
        {
            printf("the character %c is found at %d location of string %s\n",c,m,q);
            break;
        }
        else
        {
            m++;
            p++;
        }
    }
    if(m>l)
    {
        printf("Element is not found");
    }
}
/*void xstrstr(char*s,char *p)///
{

}*/
void xstrrev(char*p)
{
    int l,i;
    l=xstrlen(p);
    p=p+l;
    for(i=0;i<=l;i++)
    {
        printf("%c",*p);
        p--;
    }
}
int main()
{
    char a[20];
    char tar[20];
    char *b,*u;
    char ch;
    int choice,j;
    b=a;
    u=tar;
    printf("Enter the string\t");
    xgets(b);
    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1.string lenght\n2.convert string to lowercase\n3.convert string to uppercase\n4.string catenation\n5.string copy\n6.string comparison\n7.find character in the string\n8. reverse the string\n9. exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                j=xstrlen(b);
                printf("the len of the given string is %d",j);
                break;
            case 2:
                xstrlwr(b);
                break;
            case 3:
                xstrupr(b);
                break;
            case 4:
                printf("Enter the target string \n");
                fflush(stdin);
                xgets(u);
                printf("This is what you entered %s\n",u);
                xstrcat(u,b);
                break;
            case 5:
                printf("Enter the target string \n");
                fflush(stdin);
                xgets(u);
                printf("This is what you entered %s\n",u);
                xstrcpy(u,b);
                break;
            case 6:
                printf("Enter the target string \n");
                fflush(stdin);
                xgets(u);
                printf("This is what you entered %s\n",u);
                xstrcmp(b,u);
                break;
            case 7:
                printf("this is source string %s\n",b);
                printf("enter the character you want to search");
                fflush(stdin);
                scanf("%c",&ch);
                printf("This is what you entered %c",ch);
                xstrchr(ch,b);
                break;
            case 8:
                xstrrev(b);
                break;
            case 9:
                exit(1);
                break;
        }
    }
    return 0;
}
