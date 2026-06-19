#include <cstdio>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int no = 1;
	int score;
	scanf("%d", &score);
	for(int i = 2; i <= n * m; i++){
		int x;
		scanf("%d", &x);
		if(x > score){
			no++;
		}
	}
	int l = no / n + (no % n != 0), h;
	if(l % 2 == 1){
		h = no % n;
		if(h == 0){
			h = n;
		}
	}
	else{
		h = n + 1 - no % n;
		if(h == n + 1){
			h = 1;
		}
	}
	printf("%d %d", l, h);
} 
