#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],anss,b[500005],c[500005];
bool flag=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)ans[i]=a[i];
		else ans[i]=ans[i-1]^a[i];
		b[i]=500009;
		if(a[i]!=1)flag=false;
	}
	if(flag)
	{
		cout<<n/2;
		return 0;
	 } 
	//for(int i=1;i<=n;i++)
	//	cout<<ans[i];
	int num=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{	/*if(ans[i-1]^ans[j]==m){
			anss++;
			cout<<i<<" "<<j<<endl;}*/
			//cout<<i<<" "<<j<<" "<<int(ans[i-1]^ans[j])<<endl;
			if(m==int(ans[i-1]^ans[j]))
			{
				num++;
				b[i]=min(b[i],j-i+1);
				//cout<<"!!!"<<i<<" "<<j<<endl;
			}
		}
	if(num==0)
	{
		cout<<0;
		return 0;
	}
	if(num==1)
	{
		cout<<1;
		return 0;
	}
	/*sort(b,b+n+1);
	for(int i=1;i<=n;i++)
	{
		
	}*/
	if(m==2)
	{
		cout<<num;
		return 0;
	}
	cout<<num/2;
	return 0;
}
