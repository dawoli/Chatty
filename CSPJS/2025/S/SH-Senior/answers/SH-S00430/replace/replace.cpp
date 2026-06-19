#include<bits/stdc++.h>
using namespace std;
string s[200010][3];
int b[200010][3],db[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		int s1=s[i][1].size(),s2=s[i][2].size();
		for(int j=0;j<s1;j++)
		{
			if(s[i][1][j]=='b')b[i][1]=j;
		}
		for(int j=0;j<s2;j++)
		{
			if(s[i][2][j]=='b')b[i][2]=j;
		}
		db[i]=b[i][1]-b[i][2];
	}
	if(n<=100&&q<=100)
	{
		while(q--)
		{
			int ans=0;
			string t1,t2;
			cin>>t1>>t2;
			int n1=t1.size(),n2=t2.size();
			if(n1!=n2)
			{
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				int n3=s[i][1].size();
				for(int j=0;j+n3-1<n1;j++)
				{
					string x="",y="",z="";
					x=t1.substr(0,j);
					if(t1.substr(j,n3)==s[i][1])y=s[i][2];
					if(j+n3<n1)
					{
						z=t1.substr(j+n3,n1-(j+n3)+1);
					}
					//cout<<x<<" "<<y<<" "<<z<<endl;
					if(x+y+z==t2)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		while(q--)
		{
			int ans=0;
			string t1,t2;
			cin>>t1>>t2;
			int n1=t1.size(),n2=t2.size();
			if(n1!=n2)
			{
				cout<<0<<endl;
				continue;
			}
			int bb1=0,bb2=0;
			for(int i=0;i<n1;i++)
			{
				if(t1[i]=='b')
				{
					bb1=i;
				}
			}
			for(int i=0;i<n2;i++)
			{
				if(t2[i]=='b')
				{
					bb2=i;
				}
			}
			int dbb=bb1-bb2;
			for(int i=1;i<=n;i++)
			{
				int n3=s[i][1].size();
				if(db[i]==dbb&&bb1>=b[i][1]&&n1>=n3)ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
