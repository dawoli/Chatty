#include<stdio.h>
//#include<iostream>
using namespace std;
int main()
{
	FILE* inpfile=fopen("poker.in","r");
	FILE* outfile=fopen("poker.out","w");
	int n;
	fscanf(inpfile,"%d\n",&n);
	char c[52]={0};
	for(int i=0;i<n;i++)
	{
		char p,m;
		fscanf(inpfile,"%c%c\n",&p,&m);
		int pn,mn;
		switch(p)
		{
			case 'D':pn=0;break;
			case 'C':pn=13;break;
			case 'H':pn=26;break;
			case 'S':pn=39;break;
		}
		switch(m)
		{
			case 'A':mn=1;break;
			case 'T':mn=10;break;
			case 'J':mn=11;break;
			case 'Q':mn=12;break;
			case 'K':mn=0;break;
			default:mn=m-'0';break; 
		}
		c[mn+pn]=1;
	}
	int cnt=0;
	for(int i=0;i<52;i++)
	{
		if(!c[i])cnt++;
	}
	fprintf(outfile,"%d",cnt);
	return 0;
}
