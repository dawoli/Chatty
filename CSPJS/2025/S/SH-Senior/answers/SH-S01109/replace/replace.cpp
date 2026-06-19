#include<bits/stdc++.h>
using namespace std;

int n,q,l,r,cnt;
pair<string,string> a[200001];
string s1,s2,temp;
bool flag;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	while(q--)
	{
		cnt = 0;
		cin>>s1>>s2;
		if(s1.length() != s2.length()) 
		{
			cout<<0<<'\n';
			continue;
		}
		l=0;r=s1.length()-1;
		while(s1[l]==s2[l] && l<n) l++;
		while(s1[r]==s2[r] && r>l) r--;
		for(int i=0;i<=l;i++)
		{
			for(int j=n-1;j>=r;j--)
			{
				for(int ind=1;ind<=n;ind++)
				{
					if(int(a[i].first.length())==r-l+1)
					{
						flag = 1;
						for(int k=0;k<int(a[i].first.length());k++)
						if(s1[l+k]!=a[i].first[k] || s2[l+k]!=a[i].second[k])
						{
							flag = 0;
							break;
						}
						
					}
					cnt += int(flag);
				}
			}
		}
		cout<<flag<<'\n';
	}
	
	
	return 0;
}
