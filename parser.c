#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("Usage: ./parser [program name] [level]\n");
		exit(0);
	}
	int lev = atoi(argv[2]);
	FILE*fp = fopen(argv[1],"r");
	int i;
	int cnt = 0;
	char c,b;
	int flag = 0,temp=0;
	
	while(fscanf(fp,"%c",&c)!=EOF)
	{
		if(c=='<')
		{
			fscanf(fp,"%c",&c);
			if(c=='/')
				temp=1;
			else
				cnt++;
			if(cnt<=lev)
			{
				for(i=0; i<cnt; i++)
					printf("  ");
				printf("<%c",c);
			}
			flag = 1;
		}
		else if(c=='>')
		{
			if(cnt<=lev)
				printf(">\n");

			if(temp==1)
			{
				cnt--;
				temp=0;
			}
			if(b=='/')
				cnt--;
			flag = 0;
		}
		else
		{
			if(c==' ')
				flag = 0;
			if(cnt<=lev)
			{
				if(flag==1)
					printf("%c",c);
			}
		}
		b=c;
	}
	fclose(fp);
	return 0;
}
