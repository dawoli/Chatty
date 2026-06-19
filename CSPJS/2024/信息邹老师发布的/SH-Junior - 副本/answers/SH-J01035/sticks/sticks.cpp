#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
	int n,arr[20]={6,2,5,5,4,5,6,3,7,6},brr[100001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,maxn;
		cin>>a;
		if(a<2) 
		{
			brr[i]=-1;
			continue;
		}
		else if(a==2) 
        {
            brr[i]=1;
            continue;
        }
        else if(a==6) 
        {
            brr[i]=6;
            continue;
        }
        else if(a==4) 
        {
            brr[i]=4;
            continue;
        }
        else if(a==3) 
        {
            brr[i]=7;
            continue;
        }
		else if(a%7==0)
		{
			maxn=a/7;
			int l=8;
			for(int j=2;j<=maxn;j++)
			{
			 	l=l*10+8;
			}
			brr[i]=l;
			continue;
		}
		else if(a%7==1)
		{
			maxn=a/7+1;
			int l=10;
			for(int j=3;j<=maxn;j++)
			{
			 	l=l*10+8;
			}
			brr[i]=l;
			continue;
		}
		else maxn=a/7+1;
		int b=a,maxnn=9,minnn=1;
		for(int j=2;j<=maxn;j++)
		{
			maxnn=maxnn*10+9;
			minnn*=10;
		}
		for(int j=minnn;j<=maxnn;j++)
		{
			b=a;
			int k=j;
			for(int z=1;z<=maxn;z++)
			{
				b-=arr[k%10];
				k/=10;
			}
			if(b==0)
			{
				brr[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<brr[i]<<endl;
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}