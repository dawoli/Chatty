#include<stdio.h>

long n,res=1000000000,ress[50]={},ns[50]={};
short my_list[7]={6,2,5,4,6,3,7},my_num[7]={0,1,2,4,6,7,8};

bool dfs(long m,long sum,long number)
{
	if(sum==n)
	{
		if(number<res)
			res=number;
		return(1);
	}
	else if(sum>n)
		return(0);
	bool flag=0;
	if(m!=0)
	{
		for(int i=0;i<7;i++)
			if(dfs(m+1,sum+my_list[i],number*10+my_num[i]))
				flag=1;
	}
	else
		for(int i=1;i<7;i++)
			if(dfs(m+1,sum+my_list[i],number*10+my_num[i]))
				flag=1;
	return(flag);
}

int main()
{
	FILE * fp_out=fopen("sticks.out","w");
	FILE * fp_in=fopen("sticks.in","r");
	long t,i,j; 
	fscanf(fp_in,"%ld",&t);
	for(i=0;i<t;i++)
	{
		res=1000000000;
		fscanf(fp_in,"%ld",&n);
		if(n<2)
		{
			fprintf(fp_out,"-1\n");
			ress[i]=-1;
			continue; 
		}
		for(j=0;j<i;j++)
			if(n==ns[j])
			{
				fprintf(fp_out,"%ld",ress[j]);
				break;
			}
		if(j==i)
		{
			if(!dfs(0,0,0))
			{
				fprintf(fp_out,"-1\n");
				ress[i]=-1;
			}
			else
			{
				fprintf(fp_out,"%ld\n",res);
				ress[i]=res;
			}
			ns[i]=n;
		}
	}
	fclose(fp_in);
	fclose(fp_out);
	return(0);
}
