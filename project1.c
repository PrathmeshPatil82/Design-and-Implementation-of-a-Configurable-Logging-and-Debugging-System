#include"header.h"
void main(int argc,char **argv)
{
   if(argc!=2)//checks if command line arguments give right or not
        {
                printf("usage:./mypreprocessor file.c\n");
                return;
        }

	FILE*fp,*of;//fp opens abc.c file //of is for output file abc.i
	char a[20];
	strcpy(a,argv[1]);//copies abc.c file name
	fp=fopen(argv[1],"r");//opens in read mode
	int i=0;
	for(i=0;a[i];i++);
	a[i-1]='i';//converts file abc.c to abc.i


	of=fopen(a,"w");// opens my abc.i output file


	if(fp==0) // checks if file is present ot not
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

      printf("preprocessing done.....\n");
      return;

}
