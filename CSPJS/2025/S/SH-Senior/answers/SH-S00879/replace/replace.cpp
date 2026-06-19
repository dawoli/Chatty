#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,q,ans;
struct s{
	string s1,s2;
	int len,st,ed;
}t[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		int st,ed;
		cin>>t[i].s1>>t[i].s2;
		int len=t[i].s1.length();
		for(st=0;st<len;st++) if(t[i].s1[st]!=t[i].s2[st]) break;
		for(ed=len-1;ed>=0;ed--) if(t[i].s1[ed]!=t[i].s2[ed]) break;
		t[i].st=st;
		t[i].ed=ed;
		t[i].len=len;
	}
	for(int j=0;j<q;j++)
	{
		ans=0;
		string a,b;
		int st,ed;
		cin>>a>>b;
		int len=a.length();
		if(len!=b.length())
		{
			cout<<0<<endl;
			continue;
		}
		for(st=0;st<len;st++) if(a[st]!=b[st]) break;
		for(ed=len-1;ed>=0;ed--) if(a[ed]!=b[ed]) break;
		for(int i=0;i<n;i++)
		{
			if(ed-st!=t[i].ed-t[i].st) continue;
			if(st-t[i].st<0||t[i].len-t[i].ed>len-ed) continue;
			int tlen=t[i].len;
			int tst=t[i].st;
			bool ad=true;
			for(int k=1;k<=(tlen+1)/2;k++)
			{
				if(a[st-tst+k-1]!=t[i].s1[k-1]||b[st-tst+k-1]!=t[i].s2[k-1])
				{
					ad=false;
					break;
				}
				if(a[st-tst+tlen-k]!=t[i].s1[tlen-k]||b[st-tst+tlen-k]!=t[i].s2[tlen-k])
				{
					ad=false;
					break;
				}
			}
			if(ad) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
