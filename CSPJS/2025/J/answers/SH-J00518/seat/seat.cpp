#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,p = 1,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a,a+n*m+1);
	for(int i = m * n;i >= 1;i--)
	{
		if(a[i] == r) break;
		p++;
	}
	l = p / n;
	if(p % n != 0)l++;
	if(l % 2 == 0){
		h = n - p % n;
		if(p % n != 0)h++;
	} 
	else {
		h = p % n;
		if(p % n == 0)h = n;
	}
	cout << l << " " << h;
	return 0;
} 
