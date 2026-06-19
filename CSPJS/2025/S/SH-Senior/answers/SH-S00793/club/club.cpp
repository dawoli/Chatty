#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
int cnt[5];
struct peo{
	int a,b,c;
	int fir,se,need;
} x[N];

bool cmp(peo tx,peo ty){
	return tx.need > ty.need;
}

int find(peo &t,int id){
	if(id == 1) return t.a;
	if(id == 2) return t.b;
	/*if(id == 3) */return t.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> x[i].a >> x[i].b >> x[i].c;
			int id = 1,maxn = x[i].a,maxn2 = x[i].b;
			x[i].fir = 1;
			if(x[i].b > maxn){
				id = 2;
				maxn = x[i].b;
				
				x[i].fir = 2;
			}
			if(x[i].c > maxn){
				id = 3;
				maxn = x[i].c;
				
				x[i].fir = 3;
			}
			
			if(id == 1){
				if(x[i].b > x[i].c){
					x[i].se = 2;
					maxn2 = x[i].b;
				}else{
					x[i].se = 3;
					maxn2 = x[i].c;
				}
			}
			
			if(id == 2){
				if(x[i].a > x[i].c){
					x[i].se = 1;
					maxn2 = x[i].a;
				}else{
					x[i].se = 3;
					maxn2 = x[i].c;
				}
			}
			
			if(id == 3){
				if(x[i].a > x[i].b){
					x[i].se = 1;
					maxn2 = x[i].a;
				}else{
					x[i].se = 2;
					maxn2 = x[i].b;
				}
			}
			
			x[i].need = maxn-maxn2;
		}
		
		sort(x+1,x+n+1,cmp);
		
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			const int fir = x[i].fir,se = x[i].se/*,ne = x[i].need*/;
			//cout << x[i].a << " " << x[i].b << " " << x[i].c << endl;
			if(cnt[fir] >= n/2){
				cnt[se]++;
				ans+=find(x[i],se);
			}else{
				cnt[fir]++;
				ans+=find(x[i],fir);
			}
			
		}
		//cout << "ans:";
		cout << ans << endl;
	}
	
	return 0;
}
