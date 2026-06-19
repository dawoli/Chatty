#include<bits/stdc++.h>
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

*/
using namespace std;
int T, n[100005], m[100005], L[1000005], V[1005], d[1000005], v[10005], p[100005];
int a[1000005], ch[100005];
int vt;
int tot = 0, ans;
void car(int x, int y, int z, int k, int q){
	
	for(int i = 1; i <= k; ++i){
		tot = 0;
		if(p[i] >= x){
		
		vt = (2*z*(p[i]-x)+y*y);
	  //  printf("%d %d ", vt, V[q]*V[q]);
		if(vt > (V[q]*V[q])){
			tot = 1;

			i = k + 1;
		}
		if(tot == 1){
			++ans;
		}
	}

	//	printf("%d %d ", tot, ans);
}

}
int main(){
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		scanf("%d%d%d%d", &n[i], &m[i], &L[i], &V[i]);
		for(int j = 1; j <= n[i]; ++j){
			scanf("%d%d%d", &d[j], &v[j], &a[j]);
		}
		for(int k = 1; k <= m[i]; ++k){
			scanf("%d", &p[k]);
		}
	}
	for(int i = 1; i <= T; ++i){	
		for(int j = 1; j <= n[i]; ++j){
			//	ans = 0;
				car(d[j], v[j], a[j], m[i], i);	
		}
		printf("%d ", ans);
		int final;
		if(final >= 4){
			final =m[i] - 2;
		}
		else{
			final = 0;
		}
		printf("%d ", final);
	}
	

	return 0;
}
