// Problem URL: https://www.luogu.com.cn/problem/P1908
// Finish Time: 2026/2/24 10:01:32 AC
// Start Time: 2026/2/24 09:18:55

#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;
typedef long long int ll;
int n,a[MAXN];
ll ans=0;
void merge_sort(int a[],int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	int temp[MAXN];
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
		{
			ans+=mid-i+1;
			temp[k++]=a[j++];
		}
	}
	while(i<=mid) temp[k++]=a[i++];
	while(j<=r) temp[k++]=a[j++];
	for(int i=0;i<k;i++)
		a[l+i]=temp[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	merge_sort(a,1,n);
	cout<<ans;
	return 0;
}