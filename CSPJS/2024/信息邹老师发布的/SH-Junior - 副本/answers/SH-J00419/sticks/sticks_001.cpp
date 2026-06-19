#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

int T,n;
int ans[30];

void build_ans()
{
	ans[2]=1;
	ans[3]=7;
	ans[4]=4;
	ans[5]=2;
	ans[6]=6;
	ans[7]=8;
	
	ans[8]=10; 
	ans[9]=18;
	ans[10]=22;
	ans[11]=20;
	ans[12]=28;
	ans[13]=68;
	ans[14]=88;
	
	ans[15]=108;
	ans[16]=188;
	ans[17]=200;
	ans[18]=208;
	ans[19]=288;
	ans[20]=688;
	ans[21]=888;
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	build_ans();
	
	while(T--)
	{
		cin>>n;
		if(n==1)cout<<"-1"<<endl;
		else if(n<=14)cout<<ans[n]<<endl;
		else
		{
			cout<<ans[(14+n%7)]; //前面先处理掉 
			n=(n-14-n%7)/7; //后面就全都是8 
			while(n>=20)
			{
				cout<<"88888888888888888888";
				n-=20;
			}
			while(n--)cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}
