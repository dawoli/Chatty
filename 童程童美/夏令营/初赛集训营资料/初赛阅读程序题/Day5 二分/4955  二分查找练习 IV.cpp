#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N], n, x;
int Search(int l, int r, int x)
{
	if(l == r)
		return l;
	int mid = (l+r+1)/2;
	if(a[mid] <= x)
		return Search(mid, r, x);
	else
		return Search(l, mid-1, x);
}
int main()
{
	cin >> n >> x;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];//输入升序整数序列 
	int ans = Search(1, n, x);
	if(a[ans] == x)
		cout << ans;
	else
		cout << -1;
	return 0;
}

