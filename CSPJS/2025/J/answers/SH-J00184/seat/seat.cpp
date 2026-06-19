#include<bits/stdc++.h>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int a[110];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int t, rank = 0;
	t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == t){
			rank = i;
			break;
		}
	}
	int p = rank % n, q = rank / n;
	if(p == 0){
		if(q % 2 == 1){
			cout << q << " " << n;
			return 0;
		}
		else{
			cout << q << " 1";
			return 0;
		}
	}
	else{
		if(q % 2 == 0){
			cout << q + 1 << " " << p;
			return 0;
		}
		else{
			cout << q + 1 << " " << n + 1 - p;
		}
	}
	return 0;
}
