#include <bits/stdc++.h>
using namespace std;
pair<int, bool> p[101];
int n, m, x, y, cur;
bool up = false;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	p[1].second = 1;
	for(int i = 1; i <= n * m; i++){
		cin>>p[i].first;
	}
	sort(p + 1, p + n * m + 1, greater<pair<int, bool>>());
	cur = x = y = 1;
	while(true){
		if(p[cur].second){
			cout<<y<<' '<<x<<endl;
			return 0;
		}
		if(up && x == 1){
			y++;
			up = 0;
		}else if(!up && x == n){
			y++;
			up = 1;
		}else if(up){
			x--;
		}else{
			x++;
		}
		cur++;
	}
	return 0;
} 
