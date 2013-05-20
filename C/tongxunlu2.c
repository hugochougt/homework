#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct person
{
    char name[10];
    char mobile[20];
    char fixtelephone[10];
    char Email[20];
    char street[20];
 }person[10];

int k=0;

void print()
{
    int i;
    char ch[20];
    do{
        printf(" 结果:\n姓名        电话                固话         邮件                地址\n");
        for(i=0;i<k;i++)
        {
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
        }
        printf("返回主菜单？（Y/N）");scanf("%s",ch);
    }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}


void creat()
{
    char ch[20];

    printf("\n输入信息:\n");
    do
    {
        printf("\n姓名: ");
        scanf("%s",person[k].name);
        printf("电话: ");
        scanf("%s",person[k].mobile);
        printf("\n固定电话: ");
        scanf("%ls",person[k].fixtelephone);
        printf("\n电子邮件: ");
        scanf("%s",person[k].Email);
        printf("\n住址: ");
        scanf("%s",person[k].street);
            k++;
        printf("\n还想输入信息吗？(y/n): ");
        scanf("%s",ch);
   }while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0);
  print();
}

void del()
{
    int i,j;
    char c[20];
    printf("\n输入你要删除的名字 ：\n");
    printf("名字：");
    scanf("%s",&c);
    for(i=0;i<k;i++)
        if(strcmp(c,person[i].name)==0)
            {
                for(j=i;j<=2;j++)
                    person[j]=person[j+1];
                printf("\t\t\t你成功删除了！ %s\n",c);
                k--;
        }
        else 
            printf("");

    print();
}



void look_1()
{
    int i;
    char a[20],ch[10];
    printf("\n输入你想查看人的名字:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].name,a)==0)
            do{
                printf(" 结果:\n姓名        电话                固话         邮件                地址\n");
                printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
                printf("\n");
                printf("返回上一级？（Y/N）");scanf("%s",ch);
   }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}



void look_2()
{
    int i;
    char a[20],ch[10];
    printf("\n输入你想查看的号码:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].mobile,a)==0)
        do{
            printf(" 结果:\n姓名        电话                固话         邮件                地址\n");
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
            printf("返回上一级？（Y/N）");scanf("%s",ch);
        }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}
          
void look_3()
{
    int i;
    char a[20],ch[10];
    printf("\n输入你想查看固话:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].fixtelephone,a)==0)
        do{
            printf(" 结果:\n姓名        电话                固话         邮件                地址\n");
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
            printf("返回上一级？（Y/N）");scanf("%s",ch);
        }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}



void look_4()
{
    int i;
    char a[20],ch[10];
    printf("\n输入你想查看的Email:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].Email,a)==0)
            do{
                printf(" 结果:\n姓名        电话                固话         邮件                地址\n");
                printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
                printf("\n");
                printf("返回上一级？（Y/N）");scanf("%s",ch);
            }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}

void look_5()
{
    int i;
    char a[20],ch[10];
    printf("\n输入你想查看的住址:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
    if(strcmp(person[i].street,a)==0)
        do{
            printf(" 结果:\n姓名        电话                固话         邮件                地址\n");
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
            printf("返回上一级？（Y/N）");scanf("%s",ch);
        }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}

void look()
 { 
    int a;

    do{
        printf("\n\n");
        printf("                      1.按姓名查询\n\n\n");
        printf("                          2.按电话查询\n\n\n") ;
        printf("                              3.按姓固话查询\n\n\n");
        printf("                                  4.按电Email查询\n\n\n") ;
        printf("                                      5.按地址查询\n\n\n");
        printf("                                          6.返回主菜单\n\n\n") ;
        printf("     ---------------------------------------------------------------------\n\n\n");
        
        printf(" 输入你的选择1-6 : ");
        scanf("%d",&a);
        switch(a){
                case 1:printf("\n");look_1();break;
                case 2:printf("\n");look_2();break;
                case 3:printf("\n");look_3();break;
                case 4:printf("\n");look_4();break;
                case 5:printf("\n");look_5();break;
                case 6:printf("\n");a=0;break;
                default:printf("\n只能选择1-6！\n");
                }
    }while (a!=0);
}

void load()
{
    int i;
    FILE *fp;
    fp=fopen("d:\\xinxi.txt","r");
        if(fp==NULL)
        { 
            printf("不能读取文件.\n");
            exit(0);
        }
    for(i=0;fread(&person[i],sizeof(struct person),1,fp)!=0;i++)
    {
        fscanf(fp,"%s %s %s %s %s\n",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);

        fprintf(fp,"%s %s %s %s %s\n",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street); }  /*按格式读入记录*/
        fclose(fp);
    }     /*关闭文件*/

void save()   
{  
    FILE *fp; int i;
    if((fp=fopen("xinxi.txt","w"))==NULL)
    { 
        printf("不能读取文件.\n");
        exit(0);
    }
    for(i=0;strlen(person[i].name)!=0;i++)
    fprintf(fp,"%s %s %s %s %s\n",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
    fclose(fp);
}
int main()
{
    int a,b;
    printf("\n\n\n\n\n");
    printf("      ******************************************************************\n");
    printf("      *");printf("                      欢迎使用通讯录管理系统                 *\n\n");
    printf("      *");printf("                      学院：管理学院                         *\n\n");
    printf("      *");printf("                      专业：电子商务                         *\n\n");
    printf("      *");printf("                      制作人：苏二平                         *\n\n");
    printf("      *");printf("                      学号：3109004331                       *\n\n");
    printf("      ******************************************************************\n");
    printf("\n\n                                  进入主菜单（1）\n");
    printf("                                      退出（0）\n");
    scanf("%d",&b);
      
    if(b==0)
        exit(0);
    else
        do{
            printf("\n\n\n     --------------------------------------------------------------------\n");
            printf("           ");      
            printf("\t                  个人通讯录");  
            printf("\t\t");
            printf("\n      --------------------------------------------------------------------- \n");  
            printf("             ");       printf("\t                 1.读入数据");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 2.输入信息");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 3.显示信息");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 4.查询信息");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 5.删除信息");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 6.储存数据");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 7.  退出  ");        printf("\t\t\t\t\n\n");
            printf("     ---------------------------------------------------------------------\n");
    
            printf(" 输入你的选择1-7 : \n\n\n");
            scanf("%d",&a);
   
            switch(a){
                case 1:printf("\n");load();break;
                case 2:printf("\n");creat();break;
                case 3:printf("\n");print();break;
                case 4:printf("\n");look();break;
                case 5:printf("\n");del();break;
                case 6:printf("\n");save();break;
                case 7:printf("\n");exit(0);break;
                default:printf("\n只能选择1-7！\n");
            }
   }while(a!=0);
   return 0;
}
