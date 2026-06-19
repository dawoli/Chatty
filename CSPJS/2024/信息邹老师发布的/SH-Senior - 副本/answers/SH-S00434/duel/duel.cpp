#include<bits/stdc++.h>
using namespace std;
int rList[100009];
int n;
int nxt(bool *died, bool *used, int depth){
	if (depth > n)
		return 0;
	bool *d, *u, flag = 0;
	int min = 100000, num, aCnt = n;
	for (int i = 0; i < n; i ++){
		aCnt -= died[i];
		for (int j = 0; j < n; j ++){
			if (i == j)
				continue;
			if (died[i] || used[i] || died[j])
				continue;
			if (rList[i] > rList[j]){
				flag = 1;
				d = died;
				u = used;
				u[i] = 1;
				d[j] = 1;
				num = nxt(d, u, depth + 1);
				if (num < min){
					min = num;
				}
			}
		}
	}
	if (flag == 0){
		return aCnt;
	}
	else{
		return min;
	}
}
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	bool died[100009], used[100009];
	cin >> n;
	int r;
	for (int i = 0; i < n; i++){
		cin >> r;
		rList[i] = r;
		died[i] = 0;
		used[i] = 0;
	}
	//----- main -----
	int depth = 0;
	cout << nxt(died, used, depth);
	return 0;
}

