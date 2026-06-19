#include <bits/stdc++.h>
using namespace std;
const int M = 2e5;
int n, a[M], c[M], co[M], maxn;
void solve(int idx, int cur, int len)
{
	int x = 0;
	if(idx == len)
	{
		maxn=max(maxn,cur);
		return;
	}
	co[idx] = 1;
	for(int i = idx-1;i > -1;i -- )
	{
		if(co[i]==1)
		{
			if(a[i] == a[idx]){
				x = a[i];
				break;
			}
			x=0;
		}
	}
	solve(idx+1,cur + x,len);
	co[idx] = 2;
	for(int i = idx-1;i > -1;i -- )
	{
		if(co[i]==2)
		{
			if(a[i] == a[idx]){
				x = a[i];
				break;
			}
			x=0;
		}
	}
	solve(idx+1,cur + x,len);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
    	maxn = 0;
    	cin >> n;
		for (int i = 0;i < n;i++ )
			cin >> a[i];
		solve(0, 0, n);
		cout<<maxn<<endl;
	}
	return 0;
}
