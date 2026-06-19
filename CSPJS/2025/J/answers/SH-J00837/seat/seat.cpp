#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[107];
	int lth = n * m;
	for(int i = 1; i <= lth ; i ++)
	{
		cin >> a[i];
	}
	int sc = a[1], nod;
	sort(a+1,a+1+lth,cmp);
	for(int i = 1; i <= lth ; i ++)
	{
		if(a[i] == sc)nod = i;
	}
	int hang, lie;
	hang = nod%n;
	if(hang == 0)hang = n;;
	lie = nod / m;
	if(nod % m != 0)lie++;
//	cout << sc << ' '  << nod << ' '<< hang << ' ' << lie;
	if(lie % 2 ==0)
	{
		hang = n-hang+1;
	}
	cout << lie << ' ' << hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
