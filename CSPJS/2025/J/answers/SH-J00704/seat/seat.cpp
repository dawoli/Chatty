#include<bits/stdc++.h>
using namespace std;
const int N = 110;
struct Node {
	int id, s;
} a[N];
bool cmp(Node x, Node y)
{
	return x.s > y.s;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n * m; i++)
	{
		cin>>a[i].s;
		a[i].id = i; 
	}
	sort(a + 1, a + n * m + 1, cmp);
	int seat;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i].id == 1)
		{
			seat = i;
			break;
		}
	}
	int c = (seat - 1) / n + 1;
	int r;
	if (c % 2 == 0)
	{
		r = n - seat % n + 1;
		if (seat % n == 0)
		{
			r = 1;
		}
	}
	else
	{
		r = seat % n;
		if (seat % n == 0)
		{
			r = n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
