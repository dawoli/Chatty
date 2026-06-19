#include<stdio.h>
using namespace std;
int d[]={6,2,5,5,4,5,6,3,7,6};
int s[]={0, 0, 1, 7, 4, 2, 5, 8, 10, 18, 22, 20, 28, 58, 88, 108, 188, 200, 208, 288, 588, 888, 1088, 1888, 2008, 2088, 2888, 5888, 8888, 10888, 18888, 20088, 20888, 28888, 58888, 88888, 108888, 188888, 200888, 208888};
int pcsd=0;
int main()
{
	FILE* inpfile=fopen("sticks.in","r");
	FILE* outfile=fopen("sticks.out","w");
	int opn;
	fscanf(inpfile,"%d\n",&opn);
	for(int op=0;op<opn;op++)
	{
		int n=0;
		fscanf(inpfile,"%d\n",&n);
		if(n<=1){
			fprintf(outfile,"-1\n");
			continue;
		}
		
		int cnt8=(n-32)/8;
		if(n<32)cnt8=0;
		n-=8*cnt8; 
		if(s[n]!=0)fprintf(outfile,"%d",s[n]);
		for(int i=0;i<cnt8;i++)fprintf(outfile,"8");
		fprintf(outfile,"\n");
		
	}	
	
	return 0;
}
