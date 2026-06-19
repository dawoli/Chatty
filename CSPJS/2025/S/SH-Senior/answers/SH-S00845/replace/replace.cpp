#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+8; 
int n,q,ans;
string dic[N][2];string str1,str2,str3;

string strcut(string s,int st,int len)
{
	string ans1="";
	for(int i=st;i<st+len;i++)
	{
		ans1+=s[i];
	}
	return ans1;
}


string strcut1(string s,int st,bool flag)
{
	string ans1="";
	if(flag==0)
	{
		for(int i=0;i<st;i++)
		{
			ans1+=s[i];
		}
	}
	else
	{
		for(int i=st;i<s.size();i++)
		{
			ans1+=s[i];
		}
	}
	return ans1;
}

int solve(string a,string b)
{
	ans=0;
	for(int i=0;i<a.size();i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(strcut(a,i,dic[j][0].size())==dic[j][0])
			{
				if(i+dic[j][0].size()-1<a.size())
				{
					str3=strcut1(a,i,0)+dic[j][1]+strcut1(a,i+dic[j][0].size(),1);
					//cout<<str3<<endl;
					if(str3==str2) ans++;
				}
			}
		}
	}
	return ans;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>dic[i][0]>>dic[i][1];
	}
	while(q--)
	{
		cin>>str1>>str2;
		cout<<solve(str1,str2)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
