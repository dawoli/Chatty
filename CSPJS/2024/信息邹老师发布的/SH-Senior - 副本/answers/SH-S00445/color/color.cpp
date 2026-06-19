#include<bits/stdc++.h>
using namespace std;
struct info{
	bool color;
	int num;
};
info a[1000010];
long long c;
int n,T;
int max(int a1,int a2)
{
	return a1>a2?a1:a2;
}
void dfs(int step,int vis,bool cor)
{
	
	if(step>n)
	{
	c=max(vis,c);
	return;
	}
	a[step].color=cor;
	for(int i=step-1;i>0;i--)
	{
		if(a[i].color==a[step].color)
		{
			if(a[i].num==a[step].num)
			{
				dfs(step+1,vis+a[step].num,0);
				dfs(step+1,vis+a[step].num,1);
				return;
			}
			break;	
		}
	}
			dfs(step+1,vis,0);
			dfs(step+1,vis,1);	
 }

int main()
{
freopen("color2.in","r",stdin);
freopen("color2.out","w",stdout);
cin>>T;
for(;T>0;T--){
cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		
	}
	dfs(1,0,0);
//	dfs(1,0,1);
	cout<<c<<endl;
	c=0;n=0;info a[1000010]={""};
}


return 0;
}



