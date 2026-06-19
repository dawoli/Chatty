#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct toty{
	string s1,s2;
}team[200005];
struct tots{
	string t1,t2;
}qr[200005];
int isFound(string a,string b)
{
	bool ans=true;
	int an=0;
	int f=a.size();
	for(int i=0;i<=b.size()-f+1;i++)
	{
		ans=true;
		for(int j=0;j<=f-1;j++)
		{
			if(a[j]==b[i+j]&&ans) ans=true;
			else ans=false;
		}
		if(ans) an++;
	}
	cout<<an;
	return an;
}
string instead(string a,string b,string c,int times)
{
	string x="",y="",z="";
	int g[2000005]={};
	bool ans=true;
	int an=0;
	int f=a.size();
	for(int i=0;i<=b.size()-f+1;i++)
	{
		int ind=0;
		ans=true;
		for(int j=0;j<=f-1;j++)
		{
			if(a[j]==b[i+j]&&ans)
			{
				ans=true;
				ind=i;
			}
			else ans=false;
		}
		if(ans)
		{
			an++;
			g[an]=ind;
		}
	}
	
	string gi="";
	for(int i=1;i<=isFound(a,b);i++)
	{
		x="",y="",z="";
		for(int j=0;j<=g[i]-1;j++)
		{
			x+=b[j];
		}
		for(int j=0;j<=f-1;j++)
		{
			y+=c[j];
		}
		for(int j=g[i]+f;j<=b.size()-1;j++)
		{
			z+=b[j];
		}
		gi=x+y+z;
		cout<<gi<<" ";
		if(times==i) return gi;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt=0;
	string x,y,z;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>team[i].s1>>team[i].s2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qr[i].t1>>qr[i].t2;
	}
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=isFound(team[j].s1,qr[i].t1);k++)
			{
				if(instead(team[j].s1,qr[i].t1,team[j].s2,k)==qr[i].t2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
