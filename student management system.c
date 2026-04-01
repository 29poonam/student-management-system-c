#include <stdio.h>
#include <stdlib.h>

 struct student
  { int id;
    char name[30];
    int age;
   };
   int getNextId()
   {
       FILE *fp;
       struct student s;
       int lastId=0;
       fp=fopen("student.dat","rb");
       if(fp==NULL)
        return 1;
       else
       {
           while(fread(&s,sizeof(s),1,fp))
           {
               lastId=s.id;
           }
        }
        fclose(fp);
        return lastId+1;
    }
    void addStudent()
    {
        struct student s;
        FILE *fp;
        fp=fopen("student.dat","ab");
        s.id=getNextId();
        printf("\n\t\tStudent Id :%d\n",s.id);
        printf("\t\t\tEnter the name :\n");
        scanf("%s",s.name);
        printf("\t\t Enter the age :\n");
        scanf("%d",&s.age);
        if(s.age<=0|| s.age>120)
        {
            printf("\t\t Invalid Age!\n");
            return;
        }
        fwrite(&s,sizeof(s),1,fp);
        fclose(fp);
        printf("\n\t\t====================================");
        printf("\n\t\t**** Student Added Successfully ****");
        printf("\n\t\t====================================\n");
        printf("\n\t\t Press Enter To Continue.......\n");
        getchar();
        getchar();

    }
    void displayStudent()
    {
        struct student s;
        FILE *fp;
        fp=fopen("student.dat","rb");
        if(fp==NULL)
        {
            printf("\n\t\t No Record Found\n");
            return;
        }
        printf("\n\t\t==================================================");
        printf("\n\t\t%-10s %-20s %-10s","ID","NAME","AGE");
        printf("\n\t\t==================================================\n");
        while(fread(&s,sizeof(s),1,fp))
        {
            printf("\t\t%-10d %-20s %-10d\n",s.id,s.name,s.age);
        }
        fclose(fp);
        printf("\n\t\t Press Enter Continue...\n");
        getchar();
        getchar();
    }
    void searchStudent()
    {
        struct student s;
        FILE *fp;
        int id, found=0;
        fp=fopen("student.dat","rb");
        if(fp==NULL)
        {
            printf("\n\t\tNo Record Found\n");
            return;
        }
        printf("\t\t Enter The Id :\n");
        scanf("%d",&id);
        while(fread(&s,sizeof(s),1,fp))
        {
            if(s.id==id)
            {
                printf("\n\t\t Student Found\n");
                printf("\t\t**********************\n");
                printf("\t\t ID    :%d\n",s.id);
                printf("\t\t NAME  :%s\n",s.name);
                printf("\t\t AGE   :%d\n",s.age);
                printf("\t\t**********************\n");
                found=1;
            }
            }
            if(found==0)
            {
                printf("\t\t Student Not Found...\n");
            }
            fclose(fp);
             printf("\n\t\t Press Enter Continue...\n");
             getchar();
             getchar();

        }
        void deleteStudent()
        {
            struct student s;
            FILE *fp,*tp;
            int id,found=0;
            char confirm;
            fp=fopen("student.dat","rb");
            tp=fopen("temporary.dat","wb");
            printf("\t\t Enter The ID Want To Delete:\n");
            scanf("%d",&id);
            printf("\n\t\t Are You Sure? (Y/N) :\n");
            scanf(" %c",&confirm);
            if(confirm!='y'&&confirm!='Y')
                return;
            while(fread(&s,sizeof(s),1,fp))
            {
                if(id==s.id)
                {
                    found=1;
                }
                else
                {
                   fwrite(&s,sizeof(s),1,tp) ;
                }
            }
            fclose(fp);
            fclose(tp);
            remove("student.dat");
            rename("temporary.dat","student.dat");
            if(found)
                printf("\t\t Student Deleted Successfuly\n");
            else
                printf("\t\t Student Not Found\n");
             printf("\n\t\t Press Enter Continue...\n");
             getchar();
             getchar();

        }
        void updateStudent()
        {
            struct student s;
            FILE *fp,*tp;
            int id,found=0,ch;
            fp=fopen("student.dat","rb");
            tp=fopen("temporary.dat","wb");
            printf("\t\t Enter ID to Update:\n");
            scanf("%d",&id);
            while(fread(&s,sizeof(s),1,fp))
            {
                if(id==s.id)
                {
                    printf("\n\t\t 1. UPDATE NAME");
                    printf("\n\t\t 2. UPDATE AGE\n");
                    printf("\n  \t\t Enter Your Choice :\n");
                    scanf("%d",&ch);
                    if(ch==1)
                    {
                        printf("\t\t Enter  New Name :\n");
                        scanf("%s",s.name);
                    }
                  else  if(ch==2)
                    {
                        printf("\t\t Enter New Age :\n ");
                        scanf("%d",&s.age);
                    }
                   found=1;
                    }
                    fwrite(&s,sizeof(s),1,tp);
                }
                fclose(fp);
                fclose(tp);
                remove("student.dat");
                rename("temporary.dat","student.dat");
                if(found)
                    printf("\t\t << Student Updated Successfully.>>\n");
                else
                    printf("\t\t Studnet Not Found.\n");
                     printf("\n\t\\t Press Enter Continue...\n");
                    getchar();
                     getchar();
        }
        void countStudent()
        {
            FILE *fp;
            struct student s;
            int count=0;
            fp=fopen("student.dat","rb");
            while(fread(&s,sizeof(s),1,fp))
            {
                count++;
            }
            fclose(fp);
            printf("================================================================\n");
            printf("\n\t\t\ Total Student :%d\n",count);
            printf("================================================================\n");
             printf("\n\t\t Press Enter Continue...\n");
             getchar();
             getchar();
        }

int main()
{
    int choice;
    while(1)
    {
        system("cls");
    printf("\n\t======================================================");
    printf("\n\t         STUDENT MANEGMENT SYSTEM");
    printf("\n\t======================================================");
    printf("\n\t\t  1.ADD STUDENT");
    printf("\n\t\t  2.DISPLAY STUDENT");
    printf("\n\t\t  3.SEARCH STUDENT");
    printf("\n\t\t  4.UPDATE STUDENT");
    printf("\n\t\t  5.DELETE STUDENT");
    printf("\n\t\t  6.COUNT STUDENT");
    printf("\n\t\t  7. EXIT\n");
    printf("\n\n\t\t Enter Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:addStudent();break;
        case 2:displayStudent();break;
        case 3:searchStudent();break;
        case 4:updateStudent();break;
        case 5:deleteStudent();break;
        case 6:countStudent();break;
        case 7:printf("\n\t\t --THANKU FOR USING STUDENT MANEGMENT SYSTEM--\n");
            exit(0);break;
        default:
        printf("\t\t  InValid Choice\n");
    }
    }


    return 0;
}
