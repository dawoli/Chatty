#include <bits/stdc++.h>
using namespace std;
int n, m, p[1010], d[1010], N, ind;


int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	N = n * m;
	for (int i = 0;i < N;++i){
		cin>>d[i];
		p[i] = i;
	}
	for (int x = 0;x < N;++x){
		for (int y = 0;y < N - x;++y){
			if (d[y] < d[y+1]){
				int re = d[y], re2 = p[y];
				d[y] = d[y+1];
				d[y+1] = re;
				p[y] = p[y+1];
				p[y+1] = re2;
			}
		}
	}
	for (int i = 0;i<N;++i){
		if (p[i] == 0){
			ind = i + 1;
		}
	}
	int hang = ind % n, lie = ind / n;
	if (hang != 0){
		lie ++;
	}
	else{
		hang = n; 
	}
	if (lie % 2 == 0){
		hang = n - hang + 1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
 
