#include<bits/stdc++.h>
using namespace std;
const int N=2*10e5+9;
int n,q,sum;
string s[N][2],t[2],temp;
bool find(int i,int j)
{
	for(int k=0;k<s[j][0].size();k++)
		if(t[0][i+k]!=s[j][0][k]) return false;
	return true;
}
void move(int i,int j)
{
	for(int k=0;k<s[j][0].size();k++)
		temp[i+k]=s[j][1][k];
}
bool compare()
{
	for(int i=0;i<temp.size();i++)
		if(temp[i]!=t[1][i]) return false;
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0];
		cin>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[0];
		cin>>t[1];
		for(int i=0;i<t[0].size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(find(i,j))
				{
					temp=t[0];
					move(i,j);
					if(compare()) sum++;
				} 
			}
		}
		cout<<sum;
	}
	return 0;
}
