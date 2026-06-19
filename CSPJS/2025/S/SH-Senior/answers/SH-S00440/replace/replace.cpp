#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct node{
	int ll1;
	int rr1;
	int ll2;
	int rr2;
};
node num[200005];
int ans=0;
void check(int now,int l1,int r1,int l2,int r2,int po1,int po2)
{
	int llimit=min(l1,l2);
	int rlimit=min(r1,r2);
	int ll=num[now].ll1;
	int rr=num[now].rr1;
	int lll=num[now].ll2;
	int rrr=num[now].rr2;
	if(lll>llimit||rrr>rlimit||ll>llimit||rr>rlimit) return;
	if(ll+rr==lll+rrr&&ll+rr==abs(po2-po1)) ans++;
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int t=1;t<=n;t++)
	{
		string s;
		string s1;
		cin>>s>>s1;
		int l=0,r=0;
		int l1=0;
		int r1=0;
		int flag=0;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]=='a'&&flag==0) l1++;
			else if(s1[i]=='a'&&flag==1) r1++;
			else
			{
				flag=1;
			}
		}
		flag=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='a'&&flag==0) l++;
			else if(s[i]=='a'&&flag==1) r++;
			else
			{
				flag=1;
			}
		}
		num[t]={l,r,l1,r1};
	}
	for(int t=1;t<=q;t++)
	{
		int flag=0;
		ans=0;
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;
		int l1=0;
		int r1=0;
		int l2=0;
		int r2=0;
		int po1=0;
		int po2=0;
		flag=0;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]=='a'&&flag==0) l1++;
			else if(s1[i]=='a'&&flag==1) r1++;
			else
			{
				flag=1;
				po1=i;
			}
		}
		flag=0;
		for(int i=0;i<s2.length();i++)
		{
			if(s2[i]=='a'&&flag==0) l2++;
			else if(s2[i]=='a'&&flag==1) r2++;
			else
			{
				flag=1;
				po2=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			check(i,l1,r1,l2,r2,po1,po2);
		}
		cout<<ans<<endl;
	}
}
