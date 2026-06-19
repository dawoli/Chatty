#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(string a,string b){return a.size()>b.size()||a.size()==b.size()&&a>b;}
struct node
{
	string num;
	ll sum;
	bool operator<(const node& T)const{return cmp(num,T.num);}
};
ll s[10]={6,2,5,5,4,5,6,3,7,6},n,t;
string ans[105];
priority_queue<node>q;
void solveBF()
{
	string inf="",e="",kk;
	for(ll i=1;i<=30;++i)inf+='1';
	fill(ans+1,ans+1+50,inf);
	for(ll i=1;i<10;++i)
	{
		q.push((node){e+char(i+'0'),s[i]});
		kk=e+char(i+'0');
		if(cmp(ans[s[i]],kk))ans[s[i]]=kk;
	}
	for(node u;!q.empty();)
	{
		u=q.top();q.pop();
		if(cmp(u.num,ans[u.sum]))continue;
		for(ll i=0;i<10;++i)
		{
			string k=u.num+char(i+'0');ll sk=u.sum+s[i];
			if(cmp(ans[sk],k))ans[sk]=k,q.push((node){k,sk});
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&t);
	solveBF();
	for(ll i=1;i<=t;++i)
	{
		scanf("%lld",&n);
		if(n<=1)puts("-1");
		else
		{
			if(n<=50)puts(ans[n].c_str());
			else if(n%7==0)
			{
				string k="";
				for(ll i=1;i<=n/7;++i)k+='8';
				puts(k.c_str());
			}
			else if(n%7==1)
			{
				string k="10";
				for(ll i=1;i<=n/7-1;++i)k+='8';
				puts(k.c_str());
			}
			else
			{
				ll r=n%7+42;
				string k=ans[r];
				for(ll i=1;i<=(n-r)/7;++i)k+='8';
				puts(k.c_str());
			}
		}
	}
	return 0;
}

