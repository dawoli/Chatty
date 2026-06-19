#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
struct car{
	int d;
	int v;
	int a;
}cars[100005];
int lights[100005];
int ans1,ans2;
vector<pair<int,int> > ran;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> t;
	while(t--){
		ans1 = 0;
		ans2 = 0;
		ran.clear();
		cin >> n >> m >> l >> v;
		for(int i = 0; i < n; i++){
			cin >> cars[i].d >> cars[i].v >> cars[i].a;
		}
		for(int i = 0; i < m; i++){
			cin >> lights[i];
		}
		sort(lights,lights+m);
		for(int i = 0; i < n; i++){
			if(cars[i].a == 0){
				if(cars[i].v>v){
					int loc = lower_bound(lights,lights+m,cars[i].d)-lights;
					if(loc >= m){
						continue;
					}
					ans1++;
					ran.push_back({loc,m-1});
				}
			}
			else if(cars[i].a > 0){
				int dd = (max(v*v-cars[i].v*cars[i].v,0));dd=(dd)/(2*cars[i].a);dd+=cars[i].d;
				int loc = upper_bound(lights,lights+m,dd)-lights;
				if(loc >= m){
					continue;
				}
				ans1++;
				ran.push_back({loc,m-1});
			}
			else{
				if(cars[i].v <= v){
					continue;
				}
				int dd = (v*v-cars[i].v*cars[i].v);dd=(dd)/(2*cars[i].a);dd+=cars[i].d;
				int loc = lower_bound(lights,lights+m,cars[i].d)-lights;
				if(loc >= m){
					continue;
				}
				int lc = lower_bound(lights,lights+m,dd)-lights-1;
				if(lc < loc){
					continue;
				}
				ans1++;
				ran.push_back({loc,lc});
			}
		}
		if(ans1 == 0){
			cout << ans1 << ' ' << m << '\n';
			continue;
		}
		sort(ran.begin(),ran.end());
		int point = 0,idx = 1;
		ans2 = 1; 
		int maximum = ran[0].second;
		while(idx < ran.size()){
			if(point > maximum){
				ans2++;
				maximum = ran[idx].second;
				point = ran[idx].first;
			}
			while(point == ran[idx].first){
				maximum = min(maximum,ran[idx].second);
				idx++;
				if(idx >= ran.size()){
					break;
				}
			}
			point++;
			
		}
		cout << ans1 << ' ' << m-ans2 << '\n';
	}
	return 0;
} 
