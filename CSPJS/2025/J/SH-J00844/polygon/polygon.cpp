#include<iostream>
#define max my_max
#define int unsigned long long
using namespace std;
const int M=998244353;
int n,a[5005],ans=0,add=0,cnt=0,nx=0,bx=0;
template<typename T>T my_max(const T &A,const T &B)
{
	return A>B?A:B;
}
void dfs(int no)
{
	if(no>n)
	{
		if(cnt>=3&&add>2*nx)ans++;
		ans%=M;
		return;
	}
	add+=a[no];
	cnt++;
	bx=nx;
	nx=max(nx,a[no]);
	dfs(no+1);
	add-=a[no];
	cnt--;
	nx=bx;
	dfs(no+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}