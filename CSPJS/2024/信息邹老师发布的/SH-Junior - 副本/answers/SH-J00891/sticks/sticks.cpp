#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,string> dp1,dp2;//1没有前导0，2有前导0 
ll t,n,maxn,a[100];
string strnow;
bool com(string str1,string str2)
{
	if(str1.length()!=str2.length()) return str1.length()<str2.length();
	else return str1<str2;
}
void Dp()
{
	dp1[1]="-1";
	dp2[1]="-1"; 
	dp1[2]="1";
	dp2[2]="1";
	dp1[3]="7";
	dp2[3]="7";
	dp1[4]="4";
	dp2[4]="4";
	dp1[5]="2";
	dp2[5]="2";
	dp1[6]="6";
	dp2[6]="0";
	dp1[7]="8";
	dp2[7]="8";
	for(int i=8;i<=maxn;i++)
	{
		dp1[i]="1"+dp2[i-2];
		strnow="7"+dp2[i-3];
		if(com(strnow,dp1[i])) dp1[i]=strnow;
		strnow="4"+dp2[i-4];
		if(com(strnow,dp1[i])) dp1[i]=strnow;
		strnow="2"+dp2[i-5];
		if(com(strnow,dp1[i])) dp1[i]=strnow;
		strnow="6"+dp2[i-6];
		if(com(strnow,dp1[i])) dp1[i]=strnow;
		strnow="8"+dp2[i-7];
		if(i!=8&&com(strnow,dp1[i])) dp1[i]=strnow;
		dp2[i]="1"+dp2[i-2];
		strnow="7"+dp2[i-3];
		if(com(strnow,dp2[i])) dp2[i]=strnow;
		strnow="4"+dp2[i-4];
		if(com(strnow,dp2[i])) dp2[i]=strnow;
		strnow="2"+dp2[i-5];
		if(com(strnow,dp2[i])) dp2[i]=strnow;
		strnow="0"+dp2[i-6];
		if(com(strnow,dp2[i])) dp2[i]=strnow;
		strnow="8"+dp2[i-7];
		if(i!=8&&com(strnow,dp2[i])) dp2[i]=strnow;
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	//cout<<dp2[13];
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	Dp();
	for(int i=1;i<=t;i++) cout<<dp1[a[i]]<<endl;
	return 0;
} 
