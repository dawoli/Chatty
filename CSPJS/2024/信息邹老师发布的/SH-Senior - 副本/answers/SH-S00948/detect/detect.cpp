#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+9;

int T;
int n, m, L;
float V;
struct Car{
	float d, v, a;
}car[MAXN];
int p[MAXN];
int cnt = 0;
int a = 0;

void chaosu(int i){
	if(car[i].v > V && car[i].a >= 0){
		cnt += 1;
	}
	else if((car[i].v > V && car[i].a < 0)){
		float dis1 = (pow(V,2) - pow(car[i].v,2)) / (2*car[i].a);
		for(int i = 0; i < m; i++){
			if(p[i] < dis1+car[i].d && p[i] >= car[i].d){
				cnt += 1;
				a += 1;
				break;
			}
		}
	}
	else if(car[i].v < V && car[i].a > 0){
		float dis2 = (pow(V,2) - pow(car[i].v,2)) / (2*car[i].a);
		for(int i = 0; i < m; i++){
			if(p[i] > dis2+car[i].d){
				cnt += 1;
				a += 1;
				break;
			}
		}
	}
	
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	for(int q = 1; q <= T; q++){
		scanf("%d%d%d%f", &n, &m, &L, &V);
		for(int i = 0; i < n; i++){
			scanf("%f%f%f", &car[i].d, &car[i].v, &car[i].a);
		}
		for(int j = 0; j < m; j++){
			scanf("%d", &p[j]);
		}
		for(int i = 0; i < n; i++){
			chaosu(i);
		}
		printf("%d %d", cnt, (m-a));
	}

	return 0;
}
