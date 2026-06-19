#include<bits/stdc++.h>
using namespace std;

int n, m;

struct node{
	int id, v;
}a[105];

bool cmp(node x, node y){
	return x.v > y.v;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i ++){
		cin >> a[i].v;
		a[i].id = i;
	}
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i ++){
		if (a[i].id == 1){
			if (i%n == 0){
				cout << i/n << " " << ((i/n)%2 == 1 ? n : 1);
			}else{
				cout << i/n+1 << " " << ((i/n+1)%2 == 1 ? i%n : (n-i%n+1));
			}
			return 0;
		}
	}
	return 0;
} 
