#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/*
1
3
4 2 1
3 2 4
5 3 4
3 5 1
*/

int T;
int n;
struct choose{
	int a, b, c, ind = 0;
} inp[100010], stu[100010];
int a, b, c;

bool cmpa(choose l, choose r){
	if(l.ind != 1 || r.ind != 1)return l.ind < r.ind;
	int ml = l.a - max(l.b, l.c);
	int mr = r.a - max(r.b, r.c);
	if(ml == mr){
		return l.a > r.a;
	}else{
		return ml > mr;
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T --){
		cin >> n;
		int na = 0, nb = 0, nc = 0;
		for(int i = 1; i <= n; i ++){
			scanf("%d%d%d", &a, &b, &c);
			inp[i].a = a;
			inp[i].b = b;
			inp[i].c = c;
			if(a >= b && a >= c){
				na ++;
				inp[i].ind = 1;
			}else if(b >= c){
				nb ++;
				inp[i].ind = 2;
			}else{
				nc ++;
				inp[i].ind = 3;
			}
		}
		//cout << na << nb << nc << endl;
		
		if(nb >= na && nb >= nc){
			for(int i = 1; i <= n; i ++){
				stu[i].a = inp[i].b;
				stu[i].b = inp[i].c;
				stu[i].c = inp[i].a;
				stu[i].ind = (inp[i].ind + 2) % 3;
				if(stu[i].ind == 0)stu[i].ind = 3;
			}
		}else if(na >= nb && na >= nc){
			for(int i = 1; i <= n; i ++){
				stu[i].a = inp[i].a;
				stu[i].b = inp[i].b;
				stu[i].c = inp[i].c;
				stu[i].ind = inp[i].ind;
			}
		}else if(nc >= na && nc >= nb){
			for(int i = 1; i <= n; i ++){
				//1 -> 2 2 -> 3 3 -> 1
				stu[i].a = inp[i].c;
				stu[i].b = inp[i].a;
				stu[i].c = inp[i].b;
				stu[i].ind = (inp[i].ind + 1) % 3;
				if(stu[i].ind == 0)stu[i].ind = 3;
			}
		}
		/*for(int i = 1; i <= n; i ++){
			cout <<stu[i].ind << " ";
		}cout << endl;*/
		sort(stu + 1, stu + n + 1, cmpa);
		for(int i = n / 2 + 1; i <= n; i ++){
			if(stu[i].ind == 1){
				if(stu[i].b >= stu[i].c)stu[i].ind = 2;
				else stu[i].ind = 3;
			}
		}
		/*for(int i = 1; i <= n; i ++){
			cout <<stu[i].a <<" " << stu[i].b << " " << stu[i].c <<endl;
		}
		for(int i = 1; i <= n; i ++){
			cout <<stu[i].ind << " ";
		}cout << endl;*/
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			if(stu[i].ind == 1)ans += stu[i].a;
			else if(stu[i].ind == 2)ans += stu[i].b;
			else if(stu[i].ind == 3)ans += stu[i].c;
		}
		//cout << ans << endl;
		printf("%d\n", ans);
	} 
	return 0;
}
