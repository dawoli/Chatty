#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
vector<int>nxt1[200005],nxt2[200005];
int now1[200005],now2[200005];
int l[200005];
string t1,t2;
int w1,w2;
int solve()
{
	if(w1!=w2)return 0;
	int f=1,e=w1;
	while(t1[f]==t2[f])f++;
	while(t1[e]==t2[e])e--;
//	cout<<f<<" "<<e<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		now1[i]=0;
		now2[i]=0;
		if(e-f+1>l[i])continue;
		int end=min(f+l[i]-1,w1);
		for(int j=max(1,e-l[i]+1);j<=end;j++)
		{
			while(now1[i]&&s1[i][now1[i]+1]!=t1[j])now1[1]=nxt1[i][now1[i]];
			while(now2[i]&&s2[i][now2[i]+1]!=t2[j])now2[1]=nxt2[i][now2[i]];
			if(s1[i][now1[i]+1]==t1[j])now1[i]++;
			if(s2[i][now2[i]+1]==t2[j])now2[i]++;
			if(now1[i]==l[i]&&now2[i]==l[i])ans++;
			if(now1[i]==l[i])now1[i]=nxt1[i][now1[i]];
			if(now2[i]==l[i])now2[i]=nxt2[i][now2[i]];
			if(l[i]-now1[i]>end-j||l[i]-now2[i]>end-j)break;
		}
//		cout<<i<<" "<<ans<<"\n";
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].size();
		s1[i]=' '+s1[i],s2[i]=' '+s2[i];
		nxt1[i].push_back(0);
		nxt1[i].push_back(0);
		nxt2[i].push_back(0);
		nxt2[i].push_back(0);
		for(int j=2;j<=l[i];j++)
		{
			while(now1[i]&&s1[i][now1[i]+1]!=s1[i][j])now1[i]=nxt1[i][now1[i]];
			while(now2[i]&&s2[i][now2[i]+1]!=s2[i][j])now2[i]=nxt2[i][now2[i]];
			if(s1[i][now1[i]+1]==s1[i][j])now1[i]++;
			if(s2[i][now2[i]+1]==s2[i][j])now2[i]++;
			nxt1[i].push_back(now1[i]);
			nxt2[i].push_back(now2[i]);
		}
	}
	while(q--)
	{
		cin>>t1>>t2;
		w1=t1.size(),w2=t2.size();
		t1=' '+t1,t2=' '+t2;
		cout<<solve()<<"\n";
	}
	return 0;
}
