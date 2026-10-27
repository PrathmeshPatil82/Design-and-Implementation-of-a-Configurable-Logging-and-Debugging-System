#include"header.h"
void headerfile(FILE *pf,FILE *of)
{ 
	char a[20],ch;
	int j=0;

	while((ch=fgetc(pf))!=EOF)
	{
          if ( ch =='#')
	  {
		  ch=fgetc(pf);
		  j=0;
		  while(ch!='<' && ch !=EOF && j<19)
		  {
		    a[j]=ch;
		    j++;
		    ch=fgetc(pf);
		  }
		  a[j]='\0';

		  if(strcmp(a,"include")==0)
		  {
		    char path[100]="/usr/include/";
		    char s[30];
		    int k=0;
		    while((ch=fgetc(pf))!='>' && ch!= EOF && k<29)
		    {
		      s[k]=ch;
		      k++;
		    }
		    s[k]='\0';
		    strcat(path,s);
		    char lc;
		    FILE *lf;
		    lf=fopen(path,"r");
		    if(lf==0)
		    {
		      printf("header file not found\n");
		      return;
		    }

		    while((lc=fgetc(lf))!=EOF)
		    {
			fputc(lc,of);
		    }
		    fclose(lf);
		  }
		  else
		  {
			  fputc('#',of);
			  for(int i=0;i<j;i++)
			  {
			    fputc(a[i],of);
			  }
			  fputc(ch,of);
		  }
	  }
	  else
	  {
		  fputc(ch,of);
	  }
    }
}
