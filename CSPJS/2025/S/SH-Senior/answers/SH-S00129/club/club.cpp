#include <bits/stdc++.h>
using namespace std;
struct apart{
	int a,b,c;
}cl[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t; 
	int n,maxn[100005]={},ta[100005]={},j1=0,j2=0,j3=0,p,cnt=0,ct=0,mid[100005]={},anti[100005]={},m=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		p=n/2;
		for(int j=1;j<=n;j++)
		{
			cin>>cl[j].a>>cl[j].b>>cl[j].c;
			if(cl[j].a>=cl[j].b&&cl[j].a>=cl[j].c) maxn[j]=cl[j].a;
			if(cl[j].b>cl[j].a&&cl[j].b>cl[j].c) maxn[j]=cl[j].b;
			if(cl[j].c>cl[j].b&&cl[j].c>cl[j].a) maxn[j]=cl[j].c;
			if(maxn[j]==cl[j].a) 
			{
				ta[j]=1;
				j1++;
			}
			if(maxn[j]==cl[j].b) 
			{
				ta[j]=2;
				j2++;
			}
			if(maxn[j]==cl[j].c) 
			{
				ta[j]=3;
				j3++;
			}
			ct+=maxn[j];
		}
		if(j1<=p&&j2<=p&&j3<=p)
		{
			cout<<ct<<endl;	
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(cl[j].a>cl[j].b&&cl[j].a<cl[j].c) mid[j]=cl[j].a;
				if(cl[j].a<cl[j].b&&cl[j].a>cl[j].c) mid[j]=cl[j].a;
				if(cl[j].b>=cl[j].a&&cl[j].b<=cl[j].c) mid[j]=cl[j].b;
				if(cl[j].b<=cl[j].a&&cl[j].b>=cl[j].c) mid[j]=cl[j].b;
				if(cl[j].c>cl[j].a&&cl[j].c<cl[j].b) mid[j]=cl[j].c;
				if(cl[j].c<cl[j].a&&cl[j].c>cl[j].b) mid[j]=cl[j].c;
				anti[j]=maxn[j]-mid[j];
			}
			sort(anti,anti+n+1);
			if(j1>p) m=j1-p;
			if(j2>p) m=j2-p;
			if(j3>p) m=j3-p;
			for(int j=1;j<=m;j++)
			{
				ct-=anti[j];	
			}
			cout<<ct<<endl;
		}
		m=0;
		j1=0;
		j2=0;
		j3=0;
		cnt=0;
		ct=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
