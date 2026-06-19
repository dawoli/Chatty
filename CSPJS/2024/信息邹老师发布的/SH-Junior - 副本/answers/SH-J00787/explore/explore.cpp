#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ten year's OI all in vain , no long long see forefathers
ll T , n , m , k , x0 , y0 , d0 , x1 , y1 , cnt;
bool ex[1001][1001];
bool iex[1001][1001];
char p;
void step1(){
	if(d0 == 0) x1 = x0 , y1 = y0 + 1;
	if(d0 == 1) x1 = x0 + 1, y1 = y0;
	if(d0 == 2) x1 = x0 , y1 = y0 - 1;
	if(d0 == 3) x1 = x0 - 1, y1 = y0;
}
int main(){
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	cin >> T;
	for(int I = 0; I < T ; I++){
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		memset(ex , false , sizeof(ex));
		memset(iex , false , sizeof(iex));
		iex[x0][y0] = 1;
		cnt = 1;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> p;
				if(p == '.') ex[i][j] = true;
			}
		}
		for(int i = 0 ; i < k ; i++){
			step1();
			if(ex[x1][y1]){
				x0 = x1 , y0 = y1;
				if(!iex[x1][y1]){
					iex[x1][y1] = true;
					cnt++;
				}
			}
			else d0 = (d0 + 1) % 4;
		}
		cout << cnt << "\n";
	}
}
