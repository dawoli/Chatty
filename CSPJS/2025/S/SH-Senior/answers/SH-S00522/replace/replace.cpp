#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n,q;
struct data
{
	int b,len;
};
struct node
{
    int b,l,r;
	bool operator<(const node &o)const
	{
		return l<o.l;
	}	
};
map<int,vector<int> > sl,sr;
set<int> bs;
data fix(string s)
{
	return {s.find("b"),s.size()};
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		data t1,t2;
		node nd;
		cin>>s1>>s2;
		t1=fix(s1);
		t2=fix(s2);
		nd.b=t1.b-t2.b;
		nd.l=min(t1.b,t2.b);
		nd.r=-(t1.len-min(t1.b,t2.b));
		sl[nd.b].push_back(nd.l);
		sr[nd.b].push_back(nd.r);
		bs.insert(nd.b);
	}
	for(auto it=bs.begin();it!=bs.end();it++)
	{
		sort(sl[*it].begin(),sl[*it].end());
		sort(sr[*it].begin(),sr[*it].end());
	}
	while(q--)
	{
		int b,tb,left,right;
		string s1,s2;
		data t1,t2;
		cin>>s1>>s2;
		t1=fix(s1);
		t2=fix(s2);
		b=t2.b-t1.b;
		tb=min(t1.b,t2.b);
		right=upper_bound(sl[b].begin(),sl[b].end(),tb)-sl[b].begin()-1;
		left=lower_bound(sr[b].begin(),sr[b].end(),tb-t1.len)-sr[b].begin();
		cout<<right-left+1<<endl;
	}
	return 0;
}
/*
2 1
ab ba
aab aba
ab ba
*/
