#include<iostream>
#include<algorithm>
#include<string.h>
#define PLEASE return
#define AC 0
using namespace std;

struct p{
	int g[5];
	int v[5];
};

int t, n, ans = 0;
p a[110000];
p s[5][110000];
int l[5] = {0};

bool cmp(const p &x, const p & y){
	return x.v[3] - x.v[2] > y.v[3] - y.v[2];
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int z = 0; z < t; z++){
		cin >> n;
		memset(l, 0, sizeof(l));
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i].g[j];
				a[i].v[j] = a[i].g[j];
			}
			sort(a[i].v + 1, a[i].v + 4);
			for(int j = 1; j <= 3; j++){
				if(a[i].g[j] == a[i].v[3]){
					s[j][l[j]++] = a[i];
				}
			}
			ans += a[i].v[3];
		}
		for(int i = 1; i <= 3; i++){
			if(l[i] > n / 2){
				sort(s[i], s[i] + l[i], cmp);
//				for(int j = 0; j < l[i]; j++){
//					cout << s[i][j].g[1] << ' ' << s[i][j].g[2] << ' ' << s[i][j].g[3] << ' ';
//					cout << s[i][j].v[1] << ' ' << s[i][j].v[2] << ' ' << s[i][j].v[3] << endl;
//				}
				while(l[i] > n / 2){
					ans -= s[i][l[i] - 1].v[3] - s[i][l[i] - 1].v[2];
					l[i]--;
				}
			}
		}
		cout << ans << endl;
	}
	
	
	PLEASE AC;
}
