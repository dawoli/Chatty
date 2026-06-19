#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],rs,sz,rn=0,rm=1;
bool drt=1;
bool cmp(const int &One,const int &Two)
{
	return One>Two;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	sz=n*m;
	for(int i=1;i<=sz;i++)
	{
		cin>>a[i];
	}
	rs=a[1];
	sort(a+1,a+sz+1,cmp);
	for(int i=1;i<=sz;i++)
	{
		if(drt)rn++;
		else rn--;
		if(rn>n&&drt==1)
		{
			drt=0;
			rn--;
			rm++;
		}
		else if(rn<1&&drt==0)
		{
			drt=1;
			rn++;
			rm++;
		}
		if(a[i]==rs)break;
	}
	cout<<rm<<' '<<rn<<endl;
	return 0;
}