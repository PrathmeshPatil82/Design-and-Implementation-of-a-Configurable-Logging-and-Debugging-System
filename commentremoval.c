#include"header.h"
void commentremoval(FILE *pf,FILE *of)
{
	char ch;
	int eof=0;
l:
	while((ch=fgetc(pf))!=EOF)
	{
          if(ch=='/')
	  {
		  ch=fgetc(pf);
		  if(ch=='/')
		  {
			  while(ch!='\n')
			  ch=fgetc(pf);
			  fputc('\n',of);
		  }
              else if(ch=='*')
	      {
		  while((ch=fgetc(pf))!=EOF)
		  {
			  if(ch=='\n')
			  {
				  fputc('\n',of);
			  }
			  if(ch=='*')
			  {
				  ch=fgetc(pf);
				  if(ch=='/')
				  {
					  eof=1;
					  break;
				  }
			  }
		  }
		  if(eof==0)
		  {
		    printf("error: unterminated multiline comment\n");
		    return;
		  }
		  fputc('\n',of);
	      }
		  else
		  {
	            fseek(pf,-2,SEEK_CUR);
		    ch=fgetc(pf);
		    fputc(ch,of);
		    goto l;
		  }
	  }
	  else
	  {
		  fputc(ch,of);
	  }
    }
}	
