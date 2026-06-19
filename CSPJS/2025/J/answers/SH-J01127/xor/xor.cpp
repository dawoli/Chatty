#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int max_n=500004;
int sum[max_n][30];
int target[30],temp[30];
inline void div(const int a,int *p)
{
	memset(p,0,sizeof(p));
	int n=a;
	int pos=0;
	while(n)
	{
		p[pos++]=n & 1;
		n>>=1;
	}
	return ;
}
inline int get_sum(const int l,const int r,const int pos)
{
	return sum[r][pos]-sum[l-1][pos];
}
inline bool check(int l,int r)
{
	for(int i=0;i<30;i++)
		if((get_sum(l,r,i) & 1) !=target[i])
			return false;
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	div(k,target);
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		div(t,temp);
		for(int j=0;j<30;j++)
			sum[i][j]=sum[i-1][j]+temp[j];
	}
	/*cout<<get_sum(1,2,1);
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=4;j++)
			printf("i=%d j=%d sum=%d\n",i,j,sum[i][j]);
*/
	int ans=0,lim=1;
	for(int r=1;r<=n;r++)
	{
		for(int l=r;l>=lim;l--)
			if(check(l,r))
			{
				lim=r+1;
				r=lim-1;
				ans+=1;
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
}
