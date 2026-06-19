#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],cnt,l=1,r,mid;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	r=n*m;
	cnt=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]<cnt)
		{
			r=mid;
		}
		else if(a[mid]==cnt)
		{
			if(mid%n!=0||(mid%n==0)&&(mid/n==0))cout<<mid/n+1<<" ";
			else cout<<mid/n<<" "; 
			if(mid%n==0)
			{
				if((mid/n)%2==1)cout<<n;
				else cout<<1;
			}
			else
			{
				if((mid/n+1)%2==1)cout<<mid%n;
				else cout<<n-mid%n+1;
			}
			break;
		}
		else l=mid; 
	}
	return 0;
 } 
