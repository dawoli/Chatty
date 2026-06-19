#include<iostream>
using namespace std;
int main()
{
    freopen("joseph.in","r",stdin);
	freopen("joseph.out","w",stdout);
	int n,l,cnt1=0,cnt2=1;
	cin>>n>>l;
	bool mark[n+1]={0},flag=0;
	int b[n+1],cnt3=n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]; 
	}
	for(int i=1; ;i++)
	{
		if(mark[i]==0)cnt1++;
		if(cnt1==b[cnt2]){cnt3--;mark[i]==1;flag=1;cnt2++;}
		if(cnt2==l)cnt2=1;
		if(cnt3==1){cout<<i;break;}
		if(flag==1){i=1;flag=0;}
	}
	return 0;
}
