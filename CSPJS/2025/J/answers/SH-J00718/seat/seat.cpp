#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,p;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	x = a[1];
	sort(a + 1,a + n * m + 1,greater<int>());
	for(int i = 1;i <= n * m;i++) if(a[i] == x) p = i;
	int kkk = (p - 1) / n;
	int rest = p - kkk * n;
	if(kkk % 2) cout << (kkk + 1) << ' ' << (n - rest + 1) << endl;
	else cout << (kkk + 1) << ' ' << rest << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
