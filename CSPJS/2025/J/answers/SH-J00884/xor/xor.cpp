#include <iostream>
using namespace std;

const int MAXN=5*1e5+10;
int a[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,now=0,ans=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		now=a[i]^now;
		if(now==k)
		{
			ans++;
			now=0;
		}
	}
	cout << ans << endl;
	return 0;
}
