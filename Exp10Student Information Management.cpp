#include <stdio.h>
#include <stdlib.h>
struct sNode{
char id[20];
char name[20];
char gender[20];
char phone[20];
char email[20];
};
void deleteStudent() 
{
FILE *fRead, *fWrite;
char *TextFile;
char c;
int Delete_Id, temp = 1;
TextFile="output.txt";
fRead = fopen(TextFile, "r");
rewind(fRead);
printf("\nDelete Student with ID: ");
scanf("%d", &Delete_Id);
Delete_Id=Delete_Id+1;
fWrite = fopen("copy.c", "w");
c = getc(fRead);
while (c != EOF)
{
c = getc(fRead);
if (c == '\n')
temp++;
if (temp != Delete_Id)
{
putc(c, fWrite);
}
}
fclose(fRead);
fclose(fWrite);
remove(TextFile);
rename("copy.c", TextFile);
}
void Export_Profile(struct sNode profile)
{
FILE *fPtr1;
fPtr1=fopen("output.txt","a+");
if (fPtr1 == NULL)
{
printf("Error in opening file\n");
exit(-1);
}
fprintf(fPtr1,"%10s %10s %10s %10s %10s\n", profile.id, profile.name,
profile.gender, profile.phone, profile.email);
fclose(fPtr1);
}
void print_Profile()
{

FILE *fPtr1;
struct sNode profile;
fPtr1=fopen("output.txt","r");
if (fPtr1 == NULL)
{
printf("Error in opening file\n");
exit(-1);
}
while(!feof(fPtr1))
{
fscanf(fPtr1,"%10s %10s %10s %10s %10s\n", profile.id, profile.name,
profile.gender, profile.phone, profile.email);
printf("%10s %10s %10s %10s %10s\n", profile.id, profile.name,
profile.gender, profile.phone, profile.email);
}
fclose(fPtr1);
}
void newStudent() 
{
int x;
struct sNode st;
printf("\n===Add New Student Profile===");
printf("\n\nPlease enter the following Student information.");
printf("\n\nStudent ID: ");
scanf("%s", st.id);
printf("Name\t: ");
fflush(stdin);
fgets(st.name,20,stdin);
for(x=0 ; x<20 ; x++)
{
if(st.name[x] == '\n')
st.name[x] = '\0';
}
printf("Gender\t: ");
scanf("%s", st.gender);
printf("Phone\t: ");
scanf("%s", st.phone);
printf("Email\t: ");
scanf("%s", st.email);
Export_Profile(st);
}
void menu() 
{
int n;
printf("\n**********************************************");
printf("\nMAIN MENU-Student INFORMATION SYSTEM");
printf("\n**********************************************");
printf("\n1. Add Student Profile");
printf("\n2. Delete Student Profile");
printf("\n3. Export All Profiles to 'output.txt'");
printf("\n4. Exit");
printf("\n**********************************************");
printf("\nPlease enter your option< 1 / 2 / 3 / 4 >: ");

scanf("%d", &n);
switch(n)
{
case 1:
newStudent();
break;
case 2:
deleteStudent();
break;
case 3:
print_Profile();
break;
case 4:
exit(0);
}
}
int main(void)
{
int a;
FILE *fp;
fp= fopen("output.txt","w");
fclose(fp);
for(a=0;;a++)
{
menu();
}
return 0;
}
