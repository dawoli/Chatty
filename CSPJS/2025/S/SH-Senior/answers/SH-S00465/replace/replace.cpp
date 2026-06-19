#include<bits/stdc++.h>
using namespace std;
#define N 200005
typedef pair<string,string> pss;
int n,q;
string s1[N],s2[N],t1,t2,pre,suf,mid1,mid2;
map<pss,vector<pss>> mp;
bool ged(string a,string b,int len)
{
	pre="",suf="",mid1="",mid2="";
	int i=0,j=len-1;
	while(a[i]==b[i])
	{
		pre=pre+a[i];
		if(++i>=len) break;
	}
	if(i>=len) return 0;
	while(a[j]==b[j])
	{
		suf=a[j]+suf;
		if(--j<0) break;
	}
	while(i<=j) mid1=mid1+a[i],mid2=mid2+b[i++];
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		if(!ged(s1[i],s2[i],len)) continue;
//		cout<<pre<<'\n'<<suf<<'\n'<<mid1<<'\n'<<mid2<<"\n\n";
		mp[{mid1,mid2}].push_back({pre,suf});
	}
	while(q--)
	{
		cin>>t1>>t2;
		int len=t1.size();
		if(len!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		ged(t1,t2,len);
		int pl=pre.size(),sl=suf.size(),ans=0;
		for(pss pr:mp[{mid1,mid2}])
		{
			int l1=pr.first.size(),l2=pr.second.size();
			if(pl>=l1&&sl>=l2&&pre.substr(pl-l1,pl)==pr.first&&suf.substr(0,l2)==pr.second) ans++;
		}
		cout<<ans<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
