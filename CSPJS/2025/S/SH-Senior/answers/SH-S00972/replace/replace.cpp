#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,ch1,ch2;
ll n,q,work1,work2,work3,work4,ret,st,en;
ll Hash1[3200][3200],Hash2[3200][3200];
ll has1(string hstr)
{
	ret=0;
	for(int j=0;j<hstr.length();j++)
	{
		ret+=hstr[j];
		ret*=137;
		ret%=3013; 
	}
	return ret;
}
ll has2(string hstr)
{
	ret=0;
	for(int j=0;j<hstr.length();j++)
	{
		ret+=hstr[j];
		ret*=101;
		ret%=2999; 
	}
	return ret;
}
void Work(string str1,string str2)
{
	ch1="";
	ch2="";
	st=-1;
	en=0;
	for(int j=0;j<str1.length();j++)
	{
		if(str1[j]!=str2[j])
		{
			if(st==-1) st=j;
			en=j;
			ch1+=str1[j];
			ch2+=str2[j];
		}
		else
		{
			ch1+=" ";
			ch2+=" ";
		}
	}
	ch1=ch1.substr(st,en-st+1);
	ch2=ch2.substr(st,en-st+1);
	//cout<<ch1<<" "<<ch2<<endl;
	work1=has1(ch1);
	work2=has1(ch2);
	work3=has2(ch1);
	work4=has2(ch2);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<endl;
		cin>>s1>>s2;
		if(s1==s2)
		{
			Hash1[3199][3199]++;
			Hash2[3199][3199]++; 
			continue;
		}
		Work(s1,s2);
		//if(ch1=="m"&&ch2=="d")
		//{
		//	cout<<i<<endl;
		//}
		Hash1[work1][work2]++;
		Hash2[work3][work4]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		if(s1==s2)
		{
			printf("%lld",Hash1[3199][3199]);
			continue;
		}
		Work(s1,s2);
		if(s1!=s2) printf("%lld\n",min(Hash1[work1][work2],Hash2[work3][work4]));
	}
	return 0;
 } 
