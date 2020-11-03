#include <stdio.h>
#include <stdlib.h>
#define Dex 40
int temp,s;
void Readscore(int i,int s,long number[Dex],int score[Dex]);
int Sumaverage(int sum,int s,int score[Dex],float average,int i);
int downorder(int s,int score[Dex],long number[Dex],int (*Print)(long number[Dex],int score[Dex],int s));
int uporder(int s,int score[Dex],long number[Dex],int (*Print)(long number[Dex],int score[Dex],int s));
int upnum(int i,long number[Dex],int score[Dex],int (*Print)(long number[Dex],int score[Dex],int s));
int search(long number[Dex],long x,int s);
int analysis(int i,int s,int score[Dex]);
int Print(long number[],int score[],int s);
int menu()
{
    printf("\n\n   1.Input resord                                 \n");
    printf("   2.Calculate total and average score of course  \n");
    printf("   3.Sort in descending order by score            \n");
    printf("   4.Sort in ascending order by score             \n");
    printf("   5.Sort in ascending order by student's ID      \n");
    printf("   6.Search by student's ID                       \n");
    printf("   7.Statistic analysis                           \n");
    printf("   8.List record                                  \n");
    printf("   9.Exit                                         \n");
    printf("\n\n");
    printf("Please enter your choice:\n");
}
void Readscore(int i,int s,long number[Dex],int score[Dex])
{
    printf("Please input student's ID and score,format as:(20201111 89)\n");
    for(i=0;i<s;i++)
    {
    scanf("%ld %d",&number[i],&score[i]);
    }
    printf("Have stored the data successfully,thanks!\n");
}
int Sumaverage(int sum,int s,int score[Dex],float average,int i)
{   sum=0;
    for(i=0;i<s;i++)
            {
            sum=sum+score[i];}
            printf("总分为:%d\n",sum);
            average=sum*1.00/s;
            printf("平均分为:%.2f\n",average);
}
int uporder(int s,int score[Dex], long number[Dex],int (*Print)(long number[],int score[],int s))//成绩升序
{
    int i,j,k,temp1;
    long temp2;
    printf("按成绩升序为:\n");
    for(i=0;i<s-1;i++)
    {
        k=i;
        for(j=i+1;j<s;j++)
        {
            if(score[j]<score[k])
            {
                k=j;
            }
        }
        if(k!=j)
        {
            temp1=score[k];score[k]=score[i];score[i]=temp1;
            temp2=number[k];number[k]=number[i];number[i]=temp2;
        }
    }
    (*Print)(number,score,s);
}
int downorder(int s,int score[Dex],long number[Dex],int (*Print)(long number[],int score[],int s))//成绩降序
{

    int i,j,k,temp1;
    long temp2;
    printf("按成绩降序为:\n");
    for(i=0;i<s-1;i++)
    {
        k=i;
        for(j=i+1;j<s;j++)
        {
            if(score[j]>score[k])
            {
                k=j;
            }
        }
        if(k!=j)
        {
            temp1=score[k];score[k]=score[i];score[i]=temp1;
            temp2=number[k];number[k]=number[i];number[i]=temp2;
        }
    }
    (*Print)(number,score,s);
}
int upnum(int s,long number[Dex],int score[Dex],int (*Print)(long number[],int score[],int s))
{
     int i,j,k,temp1;
    long temp2;
    for(i=0;i<s-1;i++)
    {
        k=i;
        for(j=i+1;j<s;j++)
        {
            if(number[j]<number[k])
            {
                k=j;
            }
        }
        if(k!=j)
        {
            temp1=score[k];score[k]=score[i];score[i]=temp1;
            temp2=number[k];number[k]=number[i];number[i]=temp2;
        }
    }
    printf("按学号由小到大排列:\n");
   (*Print)(number,score,s);
}
int search(long number[Dex],long x,int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        if(x==number[i])  return i;
    }
     return -1;
}
int analysis(int i,int s,int score[Dex])
{
    int count1=0,count2=0,count3=0,count4=0,count5=0;
    for(i=0;i<s;i++)
    {
        if(score[i]<=100&&score[i]>=90)
            count1++;
        if(score[i]>=80&&score[i]<90)
            count2++;
        if(score[i]>=70&&score[i]<80)
            count3++;
        if(score[i]>=60&&score[i]<70)
            count4++;
        if(score[i]>=0&&score[i]<60)
            count5++;
      }
    printf("成绩优秀人数为%d,优秀率为%.2f%%\n",count1,100.00*(count1)/s);
    printf("成绩良好人数为%d,所占百分比为%.2f%%\n",count2,100.00*(count2)/s);
    printf("成绩中等人数为%d,所占百分比为%.2f%%\n",count3,100.00*(count3)/s);
    printf("成绩及格人数为%d,所占百分比为%.2f%%\n",count4,100.00*(count4)/s);
    printf("成绩不及格人数为%d,所占百分比为%.2f%%\n",count5,100.00*(count5)/s);
}
int Print(long number[],int score[],int s)
{
    int i;
     for(i=0;i<s;i++)
     printf("%ld     %d\n",number[i],score[i]);
}
int  main()
{
    int pos,score[Dex];
    float average;
    int s,i,sum=0;
    long number[Dex],x;
    int d,flag=1;
    do{
    menu();
    scanf("%d",&d);
    if(d==1)
        {
        printf("How many student's?\n");
        scanf("%d",&s);
        Readscore(i,s, number, score);}
    if(d==2)
            Sumaverage(sum,s,score,average,i);
    if(d==3)
             downorder( s,score,number,Print);
    if(d==4)
             uporder( s,score,number,Print);
    if(d==5)
            upnum(s,number,score,Print);
    if(d==6)
            {

    printf("请输入要查询学生的学号:");
    scanf("%ld",&x);
    pos=search(number,x,s);
    if(pos!=-1)
        printf("此学生分数是:%d\n",score[pos]);
    else
        printf("未查询到信息!");}
    if(d==7)
            analysis(i,s,score);
    if(d==8)
        {
                for(i=0;i<s;i++)
                printf("学号%ld\t分数是%d\n",number[i],score[i]);
        }
    if(d==9)
        flag=0;
    }
      while(flag==1);
}
