#include<bits/stdc++.h>
using namespace std;
string s[200001][3],t1,t2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1];
		cin>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string ss;
		cin>>t1;
		cin>>t2;
		for(int i=1;i<=n;i++) 
		{
			//cout<<i<<endl;
			ss=s[i][1]+"#"+t1;
			int l=ss.length(),pi[10001]={0},j;
			vector<int> mat;
			for(int k=1;k<l;k++)
			{
				j=pi[k-1];
				while(j>0 && ss[j]!=ss[k]) j=pi[j-1];
				if(ss[k]==ss[j]) j++;
				pi[k]=j;
			}
			for(int k=s[i][1].length()+1;k<l;k++)
			{
				if(pi[k]==s[i][1].length()) mat.push_back(k-s[i][1].length()*2);
			}
			for(int k=0;k<mat.size();k++) 
			{
				//cout<<mat[k]<<endl;
				int f=1;
				for(int x=0;x<mat[k];x++) 
				{
					if(t1[x]!=t2[x])
					{
						f=0;
						break;
					}
				}
				if(f)
				{
					for(int x=mat[k];x<mat[k]+s[i][1].length();x++)
					{
						if(s[i][2][x-mat[k]]!=t2[x])
						{
							f=0;
							break;
						}
					}
					//cout<<11<<endl;
				}
				if(f)
				{
					for(int x=mat[k]+s[i][1].length();x<t1.length();x++) 
					{
						if(t1[x]!=t2[x])
						{
							f=0;
							break;
						}
					}
					//cout<<22<<endl;
				}
				if(f) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
