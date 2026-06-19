#include<bits/stdc++.h>
#define int long long
using namespace std;
struct no{
	int x,y,z;
}o[200010];
bool cmp(no u,no v){
	return u.x < v.x;
}
int t,n,m,l,v,x,y,z,d[100010];
set<int> s,p;
set<int>::iterator it;
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	for(int op = 1;op <= t;op++){
		int j = 1,cnt = 0,ans1 = 0,ans2 = 0,sum = 0;
		cin >> n >> m >> l >> v;
		for(int i = 1;i <= n;i++){
			cin >> x >> y >> z;
			if(y <= v && ceil(sqrt(max(0LL,y * y + 2 * (l - x) * z))) <= v) continue;
			if(y > v && ceil(sqrt(max(0LL,y * y + 2 * (l - x) * z))) > v){
				sum += 2;
				o[sum - 1] = (no){x,sum,0},o[sum] = (no){l + 1,sum,1};
				continue;
			}
			if(y <= v){
				sum += 2;
				o[sum - 1] = (no){x + (v * v - y * y) / (2 * z) + 1,sum,0},o[sum] = (no){l + 1,sum,1};
			}
			else{
				sum += 2;
				o[sum - 1] = (no){x,sum,0},o[sum] = (no){x + ceil(1.0 * (v * v - y * y) / (2 * z)),sum,1};
			}
		}
		for(int i = 1;i <= m;i++) cin >> d[i];
		d[m + 1] = l + 1;
		for(int i = 1;i <= sum;i += 2){
			if(*lower_bound(d + 1,d + m + 2,o[i].x) < o[i + 1].x) ans1++;
		}
		sort(o + 1,o + sum + 1,cmp);
		for(int i = 1;i <= m;i++){
			s.clear();
			while(j <= sum && o[j].x <= d[i]){
				if(o[j].z == 0) s.insert(o[j].y);
				else{
					if(p.count(o[j].y)){
						ans2++;
						p.clear();
					}
				}
				j++;
			}
			for(it = s.begin();it != s.end();++it) p.insert(*it);
		}
		if(p.size()) ans2++;
		p.clear();
		cout << ans1 << " " << m - ans2 << endl;
	}
	return 0;
}
