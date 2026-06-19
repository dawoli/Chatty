#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n, k;
int a[maxn], qzh[maxn];
void solvea(){
	cout << n / 2 << '\n';
	exit(0);
}
void solveb(){
	if(k == 0){
		int num = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0) num++;
			else if(a[i] == 1 && a[i + 1] == 1) num++;
		}
		
		cout << num << '\n';
	}else{
		int num = 0;
		for(int i = 1;  i <= n; i++){
			if(a[i] == 1) num++;
		}
		
		cout << num << '\n';
	}
	exit(0);
}
int qz_xor[maxn];
void solvec(){
	for(int i = 1; i <= n; i++){
		qz_xor[i] = qz_xor[i - 1] ^ a[i];
	}
	
	int lst = 1, num = 0;
	for(int i = 1; i <= n; i++){
		if(i < lst) continue;
		for(int j = lst; j <= i; j++){
			if((qz_xor[i] ^ qz_xor[j - 1]) == k){
				num++;
				lst = i + 1;
//				printf("i:%d, j:%d, qz[%d]:%d, qz[%d]:%d\n", i, j, i, qz_xor[i], j - 1, qz_xor[j - 1]);
				break;
			}
		}
	}
	
	cout << num << '\n';
	exit(0);
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	bool flaga = true, flagb = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) flaga = false;
		if(a[i] > 1) flagb = false;
	}
	
	if(flaga && k == 0) solvea();
	
	if(flagb && k <= 1) solveb();
	
	if(n <= 1000) solvec();
}
/*
a[l~r]的异或和=k -> qzh[r] ^ qzh[l-1] = k

……
若有所思 
思不出来
陷入沉思
放弃思考 
*/
