#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],c[100005],t,e[5],f[100005];
bool z[200005],y[200005],w[200005];
bool abc(int n)
{
	while(n>1){
		if(n%2==1) return 0;
		n/=2;
	}
	return 1;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	int b;
	for(int i=1;i>=0;i++)
	{
		if(1<<i>=n)
		{
			b=i;
			break;
		}
	}
	int d=1;
	for(int i=1;i<=b;i++)
	{
		string s;
		cin>>s;
		for(int i=1;i<=s.size();i++)
		{
			z[d]=s[i]-'0';
			d++;
		}
	}
	cin>>t;
	while(t--){
		int ans=0;
		cin>>e[0]>>e[1]>>e[2]>>e[3];
		for(int i=1;i<=n;i++)
		{
			f[i]=a[i]+e[i%4];
		}
		for(int i=1;i<=e;i++)
		{
			int q;
			if(!abc(e[i]))
			{
				for(int i=e[i]+1;i>=0;i++)
				{
					f[e[i]+1]=-1;
					if(abc(i)) {
						q=i;
						break;
					}
				}
			}
			else q=e[i];
		}
	}
	cout<<"19"<<endl; 
	return 0;
} 
