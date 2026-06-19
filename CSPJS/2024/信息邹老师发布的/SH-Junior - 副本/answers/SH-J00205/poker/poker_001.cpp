#include<stdio.h>
#include<string.h>

int main()
{
	bool list[4][14]={};
	long n,i,x,y;
	char in[8]={},in2;
	FILE * fp_in=fopen("poker.in","r"),*fp_out=fopen("poker.out","w");
	fscanf(fp_in,"%ld\n",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp_in,"%c%s\n",&in2,in);
		if(in2=='D')
			x=0;
		else if(in2=='C')
			x=1;
		else if(in2=='H')
			x=2;
		else
			x=3;
		if(in[0]=='J')
			y=11;
		else if(in[0]=='Q')
			y=12;
		else if(in[0]=='K')
			y=13;
		else if(in[0]=='T')
			y=10;
		else if(in[0]=='A')
			y=1;
		else if(strlen(in)==1)
			y=in[0]-48;
		else
			y=(in[0]-48)*10+in[1]-48;
		list[x][y]=1;
	}
	long cnt=0;
	for(x=0;x<4;x++)
		for(y=1;y<14;y++)
			if(list[x][y]==0)
				cnt++;
	fprintf(fp_out,"%ld",cnt);
	fclose(fp_out);
	fclose(fp_in);
	return(0);	
}
