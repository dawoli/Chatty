#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T, n, a[200001];
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &a[i]);
		}
		cout << endl;
	}
	return 0;
}
