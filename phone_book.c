#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
main()
{
struct stud
{
long float homei,offi,celli;
char fname[15],lname[20],homec,offc,cellc;
}s,arr[100],temp;
int ch,i,c,k,flag,dis,no;
char nlname[20],nfname[15];
long int recsize;
FILE *fp,*ft;
clrscr();
recsize=sizeof(s);
fp=fopen("pbook.dat","rb+");
while(1)
{
printf("\n\tPress 1 : Add Entry\n\t      2 : Edit Entry\n\t      3 : Delete Entry\n\t      4 : Search for Entry\n\t      5 : Display all Entries\n\t      6 : Exit                   -> ");
scanf("%d",&ch);fflush(stdin);
switch(ch)
{
case 1 :
{
fseek(fp,0,2);
clrscr();
s.homec=NULL;
s.offc=NULL;
s.cellc=NULL;
printf("\n\n\tEnter First Name : ");
scanf("%s",s.fname);
fflush(stdin);
printf("\tEnter Last Name  : ");
scanf("%s",s.lname);
fflush(stdin);
printf("\tEnter Phone Numbers(0 if do not exist)\n");
printf("\t\tHome Phone : ");
scanf("%lf",&s.homei);
fflush(stdin);
printf("\t\tOffice Phone : ");
scanf("%lf",&s.offi);
fflush(stdin);
printf("\t\tMobile Number : ");
scanf("%lf",&s.celli);
fflush(stdin);
if(s.homei == 0)
s.homec='-';
if(s.offi == 0)
s.offc='-';
if(s.celli == 0)
s.cellc='-';
fwrite(&s,recsize,1,fp);
i=0;
rewind(fp);
while(fread(&s,recsize,1,fp)==1)
{
arr[i]=s;
i++;
}
for(c=0;c<i-1;c++)
{
for(k=0;k<i-1;k++)
{
if( strcmp(arr[k].lname,arr[k+1].lname) > 0 )
{
temp=arr[k];
arr[k]=arr[k+1];
arr[k+1]=temp;
}
}
}
rewind(fp);
for(k=0;k<i;k++)
fwrite(&arr[k],recsize,1,fp);
clrscr();
break;
}
case 2 :
{
rewind(fp);
clrscr();
printf("\n\n\tEnter the name to be edited : ");
printf("\n\t\tEnter First Name : ");
scanf("%s",nfname);
fflush(stdin);
printf("\t\tEnter Last Name  : ");
scanf("%s",nlname);
fflush(stdin);
flag=0;
while( fread(&s,recsize,1,fp)==1)
if( (strcmp(s.lname,nlname)==0) && (strcmp(s.fname,nfname)==0) )
flag=1;
if(flag==0)
{
printf("\n\n\t---------- RECORD DO NOT EXIST ----------\n\n ");
break;
}
rewind(fp);
while( fread(&s,recsize,1,fp) == 1)
{
if( strcmp(s.lname,nlname) == 0)
{
if( strcmp(s.fname,nfname) == 0)
{
printf("\n\nEnter new data : ");
s.homec=NULL;
s.offc=NULL;
s.cellc=NULL;
printf("\n\n\tEnter First Name : ");
scanf("%s",s.fname);
fflush(stdin);
printf("\tEnter Last Name  : ");
scanf("%s",s.lname);
fflush(stdin);
printf("\tEnter Phone Numbers(0 if do not exist)\n");
printf("\t\tHome Phone : ");
scanf("%lf",&s.homei);
fflush(stdin);
printf("\t\tOffice Phone : ");
scanf("%lf",&s.offi);
fflush(stdin);
printf("\t\tMobile Number : ");
scanf("%lf",&s.celli);
fflush(stdin);
if(s.homei == 0)
s.homec='-';
if(s.offi == 0)
s.offc='-';
if(s.celli == 0)
s.cellc='-';
fseek(fp,-recsize,1);
fwrite(&s,recsize,1,fp);
break;
}
}
}
i=0;
rewind(fp);
while(fread(&s,recsize,1,fp)==1)
{
arr[i]=s;
i++;
}
for(c=0;c<i-1;c++)
{
for(k=0;k<i-1;k++)
{
if( strcmp(arr[k].lname,arr[k+1].lname) > 0 )
{
temp=arr[k];
arr[k]=arr[k+1];
arr[k+1]=temp;
}
}
}
rewind(fp);
for(k=0;k<i;k++)
fwrite(&arr[k],recsize,1,fp);
clrscr();
break;
}
case 3 :
{
rewind(fp);
ft=fopen("temp.dat","wb++");
clrscr();
printf("\n\n\tEnter the name to be deleted : ");
printf("\n\t\tEnter First Name : ");
scanf("%s",nfname);
fflush(stdin);
printf("\t\tEnter Last Name  : ");
scanf("%s",nlname);
fflush(stdin);
flag=0;
while( fread(&s,recsize,1,fp)==1)
if( (strcmp(s.lname,nlname)==0) && (strcmp(s.fname,nfname)==0) )
flag=1;
if(flag==0)
{
printf("\n\n\t---------- RECORD DO NOT EXIST ----------\n\n ");
break;
}
rewind(fp);
while( fread(&s,recsize,1,fp) == 1)
{
if( (strcmp(s.lname,nlname) != 0) || (strcmp(s.fname,nfname) != 0) )
fwrite(&s,recsize,1,ft);
}
if(flag == 1)
printf("\n\n\t---------- RECORD DELETED ---------- ");
getch();
fclose(fp);
fclose(ft);
remove("pbook.dat");
rename("temp.dat","pbook.dat");
fp=fopen("pbook.dat","rb++");
i=0;
rewind(fp);
while(fread(&s,recsize,1,fp)==1)
{
arr[i]=s;
i++;
}
for(c=0;c<i-1;c++)
{
for(k=0;k<i-1;k++)
{
if( strcmp(arr[k].lname,arr[k+1].lname) > 0 )
{
temp=arr[k];
arr[k]=arr[k+1];
arr[k+1]=temp;
}
}
}
rewind(fp);
for(k=0;k<i;k++)
fwrite(&arr[k],recsize,1,fp);
clrscr();
break;
}
case 4 :
{
rewind(fp);
flag=0;
clrscr();
printf("\n\n\tEnter the name to be searched : ");
printf("\n\t\tEnter First Name : ");
scanf("%s",nfname);
fflush(stdin);
printf("\t\tEnter Last Name  : ");
scanf("%s",nlname);
fflush(stdin);
while( fread(&s,recsize,1,fp)==1)
{
if( (strcmp(s.lname,nlname)==0) && (strcmp(s.fname,nfname)==0) )
{
flag=1;
printf("\n\t-------------Record found--------------- \n");
printf("\n\tName : %-15s%-13s\n",s.lname,s.fname);
if(s.homec == NULL)
printf("\tHome Phone : %-12.0lf",s.homei);
else
printf("\n\tHome Phone : %6c      ",s.homec);
if(s.offc == NULL)
printf("\n\tWork Phone : %-12.0lf",s.offi);
else
printf("\n\tWork Phone : %6c      ",s.offc);
if(s.cellc == NULL)
printf("\n\tMobileNumber : %-12.0lf\n",s.celli);
else
printf("\n\tMobile Number : %6c       \n",s.cellc);
break;
}
}
if(flag==0)
printf("\n\n\t---------- RECORD DO NOT EXIST ----------\n\n ");
break;
}
case 5 :
{
rewind(fp);
no=1;
dis=0;
clrscr();
printf("\n______________________________________________________________________\n");
printf("_____________NAME______________|____HOME____|____WORK____|___MOBILE___|\n");
while(fread(&s,recsize,1,fp)==1)
{
printf("%2d) %-14s%-13s|",no,s.lname,s.fname);no++;
if(s.homec == NULL)
printf("%-12.0lf|",s.homei);
else
printf("%6c      |",s.homec);
if(s.offc == NULL)
printf("%-12.0lf|",s.offi);
else
printf("%6c      |",s.offc);
if(s.cellc == NULL)
printf("%-12.0lf|\n",s.celli);
else
printf("%6c      |\n",s.cellc);
dis++;
if(dis==15)
{
dis=0;
printf("\n\t\t\tHit ENTER to continue ");
getch();
printf("\n\n______________________________________________________________________\n");
printf("_____________NAME______________|____HOME____|____WORK____|___MOBILE___|\n");
}
}
break;
}
case 6 :
{
fclose(fp);
exit(0);
break;
}
default :
printf("\n\n\t-----PLEASE ENTER PROPER CHOICE-----\n ");
}
}
}  
