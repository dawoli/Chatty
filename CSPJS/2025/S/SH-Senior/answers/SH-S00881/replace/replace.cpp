#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
string s1[200005],s2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i = 1;i <= q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		t1=" "+t1;
		t2=" "+t2;
		long long cnt=0;
		for(int j = 1;j<= l1;j++)
		{
			if(t1[j-1]!=t2[j-1])break;
			for(int k = 1;k <= n;k++)
			{
				if(j-1+s1[k].size()>l1)continue;
				string t3=t1.substr(j,s1[k].size());
				if(t3!=s1[k])continue;
				string t4=t1.substr(1,j-1),t5=t1.substr(j+s1[k].size(),l1-j-s1[k].size()+1);
				if(t4+s1[k]+t5==t2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
