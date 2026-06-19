#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char a[1005][1005];
int cnt = 0;
set <pair<int,int> > s;
void dfs(int x,int y,int d){
	if (cnt == k){
		cout << s.size() << endl;
		return ;
	}
	if (d == 0 && y + 1 <= m && a[x][y+1] == '.'){
		y++;
		s.insert({x,y});
	}
	else if (d == 1 && x + 1 <= n && a[x+1][y] == '.'){
		x++;
		s.insert({x,y});
	}
	else if (d == 2 && y - 1 > 0 && a[x][y-1] == '.'){
		y--;
		s.insert({x,y});
	}
	else if (d == 3 && x - 1 > 0 && a[x-1][y] == '.'){
		x--;
		s.insert({x,y});
	}
	else {
		d = (d+1) % 4;
	}
	cnt++;
	dfs(x,y,d);
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				cin >> a[i][j];
			}
		}
		for (auto i : s){
			s.erase(i);
		}
		s.insert({1,1});
		dfs(x,y,d);
	}
	return 0;
} 
