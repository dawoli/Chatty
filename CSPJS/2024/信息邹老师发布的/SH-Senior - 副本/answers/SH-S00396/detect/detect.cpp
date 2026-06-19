#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T, n, m, L, V, ans, cnt, d[100001], v[100001], a[100001], p[100001];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i=1; i<=n; i++){
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
		}
		for(int i=1; i<=m; i++){
			scanf("%d", &p[i]);
		}
		for(int i=1; i<=n; i++){
			if(v[i] > V){
				ans++;
				for(int j=d[i]; j<=L; j++){
					if(p[j]){
						
					}
				}
			}else if(v[i]*v[i]+2*a[i]*(L-d[i]) > V*V){
				ans++;
				
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
