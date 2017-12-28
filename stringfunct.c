#include<stdio.h>
#include<string.h>
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
int xstrlen(char*p)
{
    static int l=0;
    if(*p=='\0')
    {
        printf("the len of the given string is %d",l);
    }
    else
    {
        l++;
        p++;
        xstrlen(p);
    }
    return(l);
}
void xstrlwr(char*p)
{
    while(*p!='\0')
    {
        if(*p>=65&&*p<=90)
        {
            *p=*p+54;
        }
        p++;
    }
    printf("%s",p);
}
void xstrupr(char*p)
{
    while(*p!='\0')
    {
        if(*p>=119&&*p<=122)
        {
            *p=*p-54;
        }
        p++;
    }
    printf("%s",p);
}
/*void xstrcat(char*t,char*s)///
{

}*/
void xstrcpy(char*t,char*s)
{
    while(*s!='\0')
    {
        *t=*s;
        t++;
        s++;
    }
    *t='\0';
    printf("the source is %s and target is %s",s,t);
}
void xstrcmp(char*t,char*s)
{
    int m=0;
    while(*s!='\0')
    {
        if(*s==*t)
        {
            s++;
            t++;
        }
        else
        {
            m++;
        }
    }
    printf("If m=0 then both are same and if it is non zer then they are different.\n");
    printf("the value of m is %d",m);
}
/*void xstrcmpi(char*t,char*s)///
{

}*/
void xstrchr(char c,char *p)
{
    int m=0;
    while(*p!='\0')
    {
        if(c==*p)
        {
            printf("the character %c is found at %d location of string %s\n",c,m,p);
        }
        else
        {
            m++;
        }
    }
    printf("Element not found\n");
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
    char ch,choice;
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
                xstrlen(b);
                break;
            case 2:
                xstrlwr(b);
                break;
            case 3:
                xstrupr(b);
                break;
            /*case 4:
                printf("Enter the target string \n");
                xgets(u);
                printf("This is what you entered %s",u);
                xstrcat(u,b);
                break;*/
            case 5:
                printf("Enter the target string \n");
                fflush(stdin);
                xgets(u);
                printf("This is what you entered %s",u);
                xstrcpy(u,b);
                break;
            case 6:
                printf("Enter the target string \n");
                fflush(stdin);
                xgets(u);
                printf("This is what you entered %s",u);
                xstrcmp(u,b);
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
