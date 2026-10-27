#include"header.h"
void macroreplacement(FILE *pf,FILE *of)
{
	char a[20];
	int i=0,m;
	char os[50][100],rs[50][100];
	char ch;
	int macro=0;

	while((ch=fgetc(pf))!=EOF)
	{
		if(ch=='a')
		{
			ch=fgetc(pf);
			i=0;
			while(ch!=' ' && ch!=EOF && i<19)
			{
				a[i]=ch;
				i++;
				ch=fgetc(pf);
			}
			a[i]='\0';

			if(strcmp(a,"define")==0)
			{
				int i=0;m=0;
				while((ch=fgetc(pf))!=' ')
				{
					os[macro][i]=ch;
					i++;
				}
				os[macro][i]='\0';
				while(ch ==' ')
				{
					ch = fgetc(pf);
				}

				while(ch != '\n')
				{
					rs[macro][m]=ch;
					m++;
					ch=fgetc(pf);
				}

				rs[macro][m]='\0';
				macro++;
				if(macro>=10)
					break;
			}
		}
	}

	rewind(pf);

	char word[50];
	int w=0;
	int instring=0;
	int inchar=0;

	while((ch=fgetc(pf))!=EOF)
	{
		if(ch =='"' && !inchar)
		{
			instring=!instring;
			fputc(ch,of);
			continue;
		}

		if(ch =='\'' && !instring)
		{
			inchar=!inchar;
			fputc(ch,of);
			continue;
		}

		if(instring || inchar)
		{
			fputc(ch,of);
			continue;
		}

		if(ch =='#')
		{
			char dir[20];
			int y=0;
			while((ch=fgetc(pf))!='\n' && ch!=EOF && y<19 && ch!=' ')
			{
				dir[y++]=ch;
			}
			dir[y]='\0';

			if(strcmp(dir,"define")==0)
			{
				while((ch=fgetc(pf))!='\n' && ch!= EOF);
				fputc('\n',of);
			}

			else
			{
				fputc('#',of);
				fprintf(of,"%s",dir);
				while((ch=fgetc(pf))!='\n' && ch!=EOF)
				{
					fputc(ch,of);
				}
				fputc('\n',of);
			}

		}

		else
			if((ch>='a' && ch <='z') || ( ch >='A' && ch<='z') || (ch>= '0' && ch<='9'))
			{
				word[w]=ch;
				w++;
			}
			else
			{
				if(w>0)
				{
					word[w]='\0';

					int flag=0;
					for(int x=0;x<macro;x++)
					{
						if(strcmp(word,os[x])==0)
						{
							fprintf(of,"%s",rs[x]);
						}
					}
					if(!flag)
					{
						fprintf(of,"%s",word);
					}
					w=0;
				}
				fputc(ch,of);
			}
	       }
       }



