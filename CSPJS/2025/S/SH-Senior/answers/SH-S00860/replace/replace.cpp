#include<bits/stdc++.h>
using namespace std;

int n,q,ans=0;
int l_max,r_min;
string s[200000][2];
string t1,t2,temp;

bool same(int l,int r,int ind)
{
	if(s[ind][0].length()!=r-l+1) return false;
	for(int i=0;i<=r-l;i++)
	{
		if(s[ind][0][i]!=t1[i+l] || s[ind][1][i]!=t2[i+l])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int cnt=0;cnt<q;cnt++)
	{
		ans=0;
		cin>>t1>>t2;
		l_max=0;
		r_min=t1.length()-1;
		while(t1[l_max]==t2[l_max]) l_max++;
		while(t1[r_min]==t2[r_min]) r_min--;
		for(int i=0;i<=l_max;i++)
		{
			for(int j=r_min;j<t1.length();j++)
			{
				for(int k=0;k<n;k++)
				{
					if(same(i,j,k))
					{
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
