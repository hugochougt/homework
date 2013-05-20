#include<stdio.h>
#define SIZE 4
struct student_type{
                    char name[10];
					int num;
					int age;
					char addr[15];
					  }stud[SIZE];
void save()
    {FILE *fp;
	int i;
	if((fp=fopen("stu_list","wb"))==NULL)
      {printf("123\n");
	  return;
	  }
	  for(i=0;i<SIZE;i++)
	     if(fwrite(&stud[i],sizeof(struct student_type),1,fp)!=1)
		   printf("456\n");
		   fclose(fp);  
	 }
void load()
	   {FILE *fp;
	int i;
    fp=fopen("stu_list","rb");
    for(i=0;i<SIZE;i++)
	{
		fread(&stud[i],sizeof(struct student_type),1,fp);
		printf("%-10s %4d %4d %-15s\n",stud[i].name,stud[i].num,stud[i].age,stud[i].addr);
	}

     fclose (fp);
   

}
void main()
{int i,a;
printf("ÇëÊäÈë");
scanf("%d",&a);
if(a==1)
{for(i=0;i<SIZE;i++)
    scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
    save();}
else
 load();
 system("pause");
}

