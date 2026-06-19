#include <bits/stdc++.h>
using namespace std;

struct student{
	int score;
	bool is_r;
}a[105];
student seat[15][15];

bool cmp (student x,student y){
	return x.score > y.score;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i].score;
		if (i == 1){
			a[i].is_r = 1;
		}
		else{
			a[i].is_r = 0;
		}
	}
	sort (a+1,a+n*m+1,cmp);
	int step = 1;
	int num = 1;
	while (step <= m){
		if (step % 2 == 0){
			for (int i = n; i >= 1; i--){
				seat[i][step].score = a[num].score;
				seat[i][step].is_r = a[num].is_r;
				num++;
			}
		}
		else{
			for (int i = 1; i <= n; i++){
				seat[i][step].score = a[num].score;
				seat[i][step].is_r = a[num].is_r;
				num++;
			}
		}
		step++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (seat[i][j].is_r == 1){
				cout << j << " " << i;
				break;
			}
		}
	}
	return 0;
}
