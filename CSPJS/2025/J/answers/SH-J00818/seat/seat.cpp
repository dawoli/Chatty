#include<bits/stdc++.h>
using namespace std;
long long n, m, tot, b[15][15];
struct node{
	long long point;
	long long id;
}a[105];
bool cmp(node a, node b){
	return a.point > b.point;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].point;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= m; j++){
				b[i][j] = a[++tot].id;
			}
		}else{
			for(int j = m; j >= 1; j--){
				b[i][j] = a[++tot].id;
			}
		}
	}
	long long ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(b[i][j] == 1){
				ans1 = i, ans2 = j;
			}
		}
	}
	cout<< ans1 << " " << ans2 << endl;
	return 0;
}

