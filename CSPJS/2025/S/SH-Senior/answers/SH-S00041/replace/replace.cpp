#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,q;
struct ssss
{
	int delta,k,length;
}s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int x=-1,y=-1;
		for(int j=0;j<s1.size();j++)
		{
			if(s1[j]=='b')
			{
				x=j;
				if(y!=-1)
					break;
			}
			if(s2[j]=='b')
			{
				y=j;
				if(x!=-1)
					break;
			}
		}
		s[i].delta=y-x;
		s[i].k=x;
		s[i].length=s1.size();
//		cout<<x<<" "<<y<<" "<<y-x<<"\n";
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		int x=-1,y=-1;
		for(int j=0;j<t1.size();j++)
		{
			if(t1[j]=='b')
			{
				x=j;
				if(y!=-1)
					break;
			}
			if(t2[j]=='b')
			{
				y=j;
				if(x!=-1)
					break;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(y-x==s[j].delta&&x>=s[j].k&&t1.size()>=s[j].length&&x<=(t1.size()-s[j].length+s[j].k))
			{
				ans++;
//				if(i==12)
//					cout<<y-x<<" "<<s[j].delta<<" "<<x<<" "<<s[j].k<<" "<<(t1.size()-s[j].length+s[j].k)<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
6 1
ab ba
aab aba
aaab aaba
ba ab
aba baa
baa bab
aaab aaba

*/
