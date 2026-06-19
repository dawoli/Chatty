// Problem URL: https://iai.sh.cn/problem/1239
// Finish Time: 2026/5/23 11:02:22 TLE 60pts
// Start Time: 2026/5/23 10:31:03

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
int a[300005];
ll ans;
void merge_sort(int *a,int l,int r)
{
	if(r-l<=1) return;
	int mid=l+((r-l)>>1);
	merge_sort(a,l,mid),merge_sort(a,mid,r);
	int tmp[300005]={};
	int i=l,j=mid,k=l;
	while(i<mid&&j<r)
	{
		if(a[i]<=a[j])
			tmp[k++]=a[i++];
		else
		{
			ans+=mid-i;
			tmp[k++]=a[j++];
		}
	}
	while(i<mid) tmp[k++]=a[i++];
	while(j<r) tmp[k++]=a[j++];
	for(int i=l; i<r; ++i) a[i]=tmp[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i];
	merge_sort(a,1,n+1);
	cout<<ans;
	return 0;
}