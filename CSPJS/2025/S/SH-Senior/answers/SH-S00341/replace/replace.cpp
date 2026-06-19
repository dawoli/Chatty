#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int n,k;
string a[N],b[N];
int solve(string s,string y)
{
	int ans=0;
	for(int h=0;h<n;h++)
	{
		string x=s,e=a[h],r=b[h];
		bool t=false;
		int p=0,len=0;
		char o=e[0];
		if(e==x)
		{
			if(r==y)ans++;
		}
		else
		{
			for(int i=0;i<x.length();i++)
			{
				//cout<<x[i]<<"   "<<o<<endl;
				if(x[i]==o)
				{
					int t1=i,t2=0;
					while(x[t1]==e[t2] && t2<=e.length())
					{
						len++;
						t1++,t2++;
					}
				}
				if(len==e.length())
				{
					p=i;
					t=true;
					break;
				}
			}
			if(t==1)
			{
				for(int i=0;i<e.length();i++)
				{
					x[(i+p)]=r[i];
				}
				if(x==y)ans++;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	string x,y;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
