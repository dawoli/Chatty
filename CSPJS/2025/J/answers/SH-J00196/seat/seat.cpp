#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int score = a[1];
	int lie = 0,pie = 0;
	sort(a + 1,a + (n * m) + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == score){
			int p = i;
			lie = p / n + bool(p % n != 0);
			if(lie % 2 == 1){
				if(p % n != 0)	pie = p % n;
				else pie = n;
			}
			else if(lie % 2 == 0){
				pie = lie * n - p + 1;
			}
			break;
		}
	}
	cout << lie << " " << pie;
	return 0;
 } 
