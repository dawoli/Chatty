#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string s[200001][4];
int n,q,ans[200001],duiyin[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		string qqq=s[i][0],www=s[i][1];
		if(qqq.size()!=www.size())
		{
			continue;
		}
		int flag=0;
		for(int j=0;j<s[i][0].size();j++)
		{
			if(s[i][0][j]!=s[i][1][j]&&s[i][0][j+1]!=s[i][1][j+1])
			{
				s[i][2]+=s[i][0][j];
				s[i][3]+=s[i][1][j];
				if(j==0)
				{
					duiyin[i]=0;
				}
				else if(s[i][0][j-1]==s[i][1][j-1])
				{
					duiyin[i]=j;
				}
			}
			else if(s[i][0][j]!=s[i][1][j]&&s[i][0][j+1]==s[i][1][j+1])
			{
				flag++;
				if(flag==2)
				{
					duiyin[i]=-1;
					break;
				}
				s[i][2]+=s[i][0][j];
				s[i][3]+=s[i][1][j];
			}
		}
		if(flag==2)
		{
			s[i][2]="";
			s[i][3]="";
		}
	}
	for(int i=1;i<=q;i++)
	{
		string l,x,bu,bu1;
		cin>>l>>x;
		if(l.size()!=x.size())
		{
			continue;
		}
		int flag,dy;
		for(int j=0;j<l.size();j++)
		{
			if(l[j]!=x[j]&&l[j+1]!=x[j+1])
			{
				bu+=l[j];
				bu1+=x[j];
				if(j==0)
				{
					dy=0;
				}
				else if(l[j-1]==x[j-1])
				{
					dy=j;
				}
			}
			else if(l[j]!=x[j]&&l[j+1]==x[j+1])
			{
				flag++;
				if(flag==2)
				{
					break;
				}
				bu+=l[j];
				bu1+=x[j];
			}
		}
		if(flag==2)
		{
			continue;
		}
		//cout<<dy<<endl;
		for(int j=1;j<=n;j++)
		{
			if(bu==s[j][2]&&bu1==s[j][3]&&bu!=""&&bu1!=""&&s[j][2]!=""&&s[j][3]!="")
			{
				bool flag1=1;
				for(int k=0;k<s[j][1].size();k++)
				{
					//cout<<l[k+dy-duiyin[j]];
					if(dy<duiyin[j])
					{
						flag1=0;
						break;
					}
					if(l[k+dy-duiyin[j]]!=s[j][0][k])
					{
						flag1=0;
						break;
					}
				}
			//	cout<<endl;
				for(int k=0;k<s[j][1].size();k++)
				{
					//cout<<x[k+dy-duiyin[j]];
					if(dy<duiyin[j])
					{
						flag1=0;
						break;
					}
					if(x[k+dy-duiyin[j]]!=s[j][1][k])
					{
						flag1=0;
						break;
					}
				}
			//	cout<<endl;
				if(flag1==1)
				{
					ans[i]++;
					//cout<<j<<endl;
				}
			}
		}
	//	cout<<dy<<endl;
	}
/*	for(int i=1;i<=n;i++)
	{
		cout<<s[i][2]<<s[i][3]<<endl;
	}*/
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
