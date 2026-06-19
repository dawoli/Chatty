#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
pair <int, int> a[1000];
int n, m;
bool cmp(pair<int, int> x , pair<int, int> y)
{
	return x.first > y.first;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n;
	cin >> m;
	int t1;
	cin >> t1;
	a[1] = {t1, 1};
	for(int i = 2; i <= n * m; i++)
	{
		cin >> t1;
		a[i] = {t1, 0};
	}
	sort(a + 1, a + n * m + 1, cmp);
	int num;
	for(int i = 1; i <= n * m; i++)
	{
//		cout << a[i].first<< " " << a[i].second <<endl;
		if(a[i].second == 1)
		{
			num = i;
		}
	}
//	cout << num;
//	cout << endl;
	num--;
	int lie, hang;//nÐÐ 
	lie = num / n + 1;
	if(lie % 2 == 1)
	{
		hang = num % n + 1;
	}
	else
	{
		hang = n - num % n;
	}
	cout << lie << " " << hang;
	return 0;
 } 
 
/*
3 3
94 95 96 97 98 99 100 93 92
*/
