#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,q,i,p1,p2,ans,lh,b[MAXN],S[MAXN];
string s1[MAXN],s2[MAXN],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(i = 1;i <= n;i++)cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>t1>>t2;
		ans = 0;
		lh = t1.length();
		for(i = 0;i < lh;i++)b[i] = (t1[i] == t2[i])?0:1,S[i+1] = b[i]+S[i];
		for(i = 1;i <= n;i++)
		{
			if(s1[i].length() < S[lh])continue;
			p1 = t1.find(s1[i],0),p2 = t2.find(s2[i],0);
			while(p1 >= 0 && p1 < lh && p2 >= 0 && p2 < lh)
			{
				if(p1 == p2)
				{
					p1 += s1[i].length();
					ans++;
					p1++,p2++;
					p1 = t1.find(s1[i],p1),p2 = t2.find(s2[i],p2);
				}
				else
				{
					if(p1 < p2)while(p1 >= 0 && p1 < lh && p1 < p2)p1 = t1.find(s1[i],p1);
					else while(p2 >= 0 && p2 < lh && p2 < p1)p2 = t2.find(s2[i],p2);
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
