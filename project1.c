#include"header.h"
void main(int argc,char **argv)
{
  if(argc!=2)
  {
   printf("usage: / mypreprocsssor file.c\n");
   return ;
  }

  FILE *fp,*of;
  char a[20];
  strcpy(a,argv[1]);
  fp=fopen(argv[1],"r");
  int i=0;
  for(i=0;a[i];i++)
	  a[i-1]='i';

  of=fopen(a,"w");
  if(fp==0)
  {
   printf("file not present\n");
   return;
  }

  FILE *t1,*t2;
  t1=fopen("temp1.txt","w+");
  t2=fopen("temp2.txt","w+");

  commentremoval(fp,t1);
  rewind(t1);
  macroreplacement(t1,t2);
  rewind(t2);
  headerfile(t2,of);
  fclose(fp);
  fclose(t1);
  fclose(t2);
  fclose(of);


  remove("temp1.txt");
  remove("temp2.txt");

  printf("preprocessing done...\n");
  return;
}
