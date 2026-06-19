#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;

int T, n, k, q, cnt[N], r, c, tmp, la[N], la_cnt, ans;
vector<int> a[N];

int vis[20][500][50]; // people begin end

void dfs(int ks, int begin){
	if(ks > r && la[la_cnt-1] == c) ans = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=cnt[i]; j++){
			for(int kk = 1; kk < min(cnt[i], j + k - 1); kk++){
				if(vis[i][j][kk]) continue;
				vis[i][j][kk] = 1;
				bool ff = 0;
				for(int l=j; l<=la_cnt; l++){
					if(la[l-j+1] != a[i][l]) ff = 1;
				} if(ff == 0) continue;
				for(int l=j; l<=kk; l++) la[l-j+1] = a[i][l];
				la_cnt =  kk - j + 1;
				dfs(ks+1, kk);
			}
		}
	}
}

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1; i<=n; i++){
			cin>>cnt[i];
			a[i].push_back(-1);
			for(int j=1; j<=cnt[i]; j++){
				cin>>tmp;
				a[i].push_back(tmp);
			}
		}
		for(int i=1; i<=q; i++){
			cin>>r>>c;
			if(r <= 1){
				bool f = 0;
				for(int i=1; i<=n; i++){
					for(int j=1; j<=cnt[i]; j++){ // Ã¿Ò»¸ö 1 
						if(a[i][j] != 1) continue;
//						printf("------------%d, %d------------\n", i, j);
//						cout<<cnt[i]<<" "<<j+k-1<<" "<<min(cnt[i], j + k - 1)<<endl;
						for(int kk=j+1; kk <= (j + k - 1); kk++){
							if(kk > cnt[i]) break;
//							printf("%d %d\n", j, kk);
							if(a[i][kk] == c){
//								printf("%d %d %d\n", i, j, kk);
								f = 1;
								break;
							}
						}
						if(f) break;
					}
					if(f) break;
				}
				if(f) cout<<1<<endl;
				else cout<<0<<endl;
			} else if(n <= 10){
				ans = 0;
				dfs(1, 1);
				cout<<ans<<endl;
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=cnt[i]; j++){
				a[i].pop_back();
			} cnt[i] = 0;
		}
	}
}
