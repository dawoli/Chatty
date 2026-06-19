#include <iostream>
using namespace std;
int a[10002];
int main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++) if(a[j]<a[i]) swap(a[i],a[j]);
		for(int j=i+2;j<=n;j++) if(a[j]<a[i+1]) swap(a[i+1],a[j]);
		ans+=a[i]+a[i+1];
		a[i+1]=a[i]+a[i+1];
	}
	cout << ans << endl;
	return 0;
}

