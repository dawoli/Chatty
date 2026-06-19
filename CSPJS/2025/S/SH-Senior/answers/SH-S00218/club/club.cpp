#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool Cmp(int X,int Y){
	return X > Y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		int N,M,Sum = 0;
		int a1[100005],a2[100005],a3[100005],maxn[100005];
		int cnta1 = 0,cnta2 = 0,cnta3 = 0;
		bool f1 = 1;
		scanf("%d",&N);
		M = N / 2;
		memset(maxn,-1,sizeof(maxn));
		for (int i = 1;i <= N;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			maxn[i] = max(max(max(maxn[i],a1[i]),a2[i]),a3[i]);
			if (a2[i] != 0 || a3[i] != 0){
				f1 = 0;
			}
		}
		if (f1){
			sort(a1 + 1,a1 + N + 1,Cmp);
			for (int i = 1;i <= M;i++){
				Sum += a1[i];
			}
			printf("%d",Sum);
			return 0;
		}
		for (int i = 1;i <= N;i++){
			Sum += maxn[i];
		}
		printf("%d",Sum);
	}
	return 0;
}
