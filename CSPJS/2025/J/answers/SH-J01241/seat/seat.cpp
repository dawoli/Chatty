#include<bits/stdc++.h>
using namespace std;
long a[1000005];
bool cmp(int a,int b)
{
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i =1;i <= n*m;i++)
	{
		
		cin >> a[i];
	}
	int k1 = a[1];
	sort(a+1,a+1+n*m,cmp);
	int l = 1;int r = 1 + n * m;int mid = 0;
	while(l < r)
	{
		mid = (l+r) / 2;
		if(a[mid] <= k1) r = mid;
		else l = mid + 1;
		//cout << l << " " << r << " " << mid << endl;
	}
	//a[mid];
	//cout << r << endl;
	int k = r;
	
	int lie = k / n + 1;
	if(k % n == 0) lie--;
	
	
	int ha = k % n;
	if(ha == 0) ha = n;
	if(lie % 2 == 0)
	{
		ha = n - ha + 1;
	}
	cout << lie << " " << ha << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
