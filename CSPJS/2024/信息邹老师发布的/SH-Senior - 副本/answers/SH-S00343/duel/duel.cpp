#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct guai{
	int neng;
	bool flag;
}r[N];

bool cmp(guai x, guai y){
	return x.neng < y.neng;
}

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &r[i].neng);
		r[i].flag = 1;
	}
	sort(r+1, r+n+1, cmp);
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(r[j].neng > r[i].neng && r[i].neng != -1 && r[j].flag){
				r[i].neng = -1;
				r[j].flag = 0;
				break;
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(r[i].neng != -1){
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
