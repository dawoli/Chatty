#include<bits/stdc++.h>
using namespace std;
string ans[100005],f[100005],tmp;//ans不带前导0，f带 
const int a[10]={6,2,5,5,4,5,6,3,7,6};
const string num[10]={"0","1","2","3","4","5","6","7","8","9"};
int t,n;
bool cmp(string x,string y)
{
	if(x.length()==y.length()) return x<y;
	return x.length()<y.length(); 
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ans[0]="-1";
	ans[1]="-1";
	f[2]="1";ans[2]="1";
	f[3]="7";ans[3]="7";
	f[4]="4";ans[4]="4";
	f[5]="2";ans[5]="2";
	f[6]="0";ans[6]="6";
	f[7]="8";ans[7]="8";
	f[8]="01";ans[8]="10";
	for(int i=9;i<100005;i++)
	{
		f[i]="0"+f[i-a[0]];
		ans[i]="1"+f[i-a[1]];
		for(int j=0;j<10;j++)
		{
			tmp=num[j]+f[i-a[j]];
			if(cmp(tmp,f[i])) f[i]=tmp;
		}
		for(int j=1;j<10;j++)
		{
			tmp=num[j]+f[i-a[j]];
			if(cmp(tmp,ans[i])) ans[i]=tmp;
		}
	}
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}
