#include<iostream>
using namespace std;

int t, n, m, k;
short a[1500][1500];

bool step(int x, int y){
	if(x > n || y > m){
		return 0;
	}
	if(x < 1 || y < 1){
		return 0;
	}
	if(a[x][y] == 1){
		return 0;
	}
	return 1;
} 

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int x, y, d;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		char s;
		for(int j = 1; j <= n; j++){
			for(int g = 1; g <= m; g++){
				cin >> s;
				if(s == 'x'){
					a[j][g] = 1;
				}else{
					a[j][g] = 0;
				}
			}
		}
		
		int u, v;
		for(int j = 0; j < k; j++){
			u = x;
			v = y;
			a[u][v] = 2;
			switch (d){
			    case 0:{
				    v++;
				    break;
			    }
			    case 1:{
			    	u++;
					break;
				}
				case 2:{
					v--;
					break;
				}
				case 3:{
					u--;
					break;
				}
		    }
		    if(step(u, v)){
		    	x = u;
		    	y = v;
		    	a[x][y] = 2;
			}else{
				d = (d + 1) % 4;
			}
		}
		
		int ans = 0;
		for(int j = 1; j <= n; j++){
			for(int g = 1; g <= m; g++){
				if(a[j][g] == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
//		for(int i = 1; i <= n; i++){
//		    for(int j = 1; j <= m; j++){
//		    	cout << a[i][j];
//		    }
//		    cout << endl; 
//	    }
	}

	
	return 0;
} 
