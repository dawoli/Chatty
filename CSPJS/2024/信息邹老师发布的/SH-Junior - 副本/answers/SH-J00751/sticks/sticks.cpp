#include<bits/stdc++.h>
using namespace std;
string f[100005];
bool cmp(string a,string b)
{
	int l1=a.length(),l2=b.length();
	if(l1==l2)
		return a<b;
	else
		return l1<l2;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	f[2]="1";
	f[3]="7";
	f[4]="4";
	f[5]="2";
	f[6]="6";
	f[7]="8";
	f[8]="16";
	f[9]="18";
	for(int i=10;i<=100000;i++)
	{
		string tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
		string n6="0",n2="1",n3="7",n4="4",n5="2",n7="8";
		tmp1=f[i-2]+n2;
		tmp2=f[i-3]+n3;
		tmp3=f[i-4]+n4;
		tmp4=f[i-5]+n5;
		tmp5=f[i-6]+n6;
		tmp6=f[i-7]+n7;
		f[i]=tmp1;
		if(cmp(tmp2,f[i]))
			f[i]=tmp2;
		if(cmp(tmp3,f[i]))
			f[i]=tmp3;
		if(cmp(tmp4,f[i]))
			f[i]=tmp4;
		if(cmp(tmp5,f[i]))
			f[i]=tmp5;
		if(cmp(tmp6,f[i]))
			f[i]=tmp6;
	}
	while(T--)
	{
		int n;
		cin>>n;
		if(n<2)
		{
			cout<<-1<<"\n";
			continue;
		}
		else
			cout<<f[n]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
