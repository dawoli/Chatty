#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

struct node{
	long long l, r;
} s[N], ss[N];

bool cmp(node i, node j){
	if(i.r == j.r) return i.l < j.l;
	else return i.r < j.r;
}

long long T, n, m, L, V, ans1, ans2;
long long d, v, a, l, r, cnt;
long long p[N], idx, cnts, la;
bool f[N];

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
//	cout<<((float)(3) == (int)(3))<<endl;
//	cout<<((float)(3.1) == (int)(3.1))<<endl;
	cin>>T;
	while(T--){
		ans1 = 0, ans2 = 0;
		l = 0, r = 0, cnt = 0;
		idx = 0, cnts = 0, la = 0;
		cin>>n>>m>>L>>V;
		for(int i=1; i<=n; i++){ // step1: 化为区间 
			cin>>d>>v>>a;
			if(v <= V){ // v0没超速 
				if(a > 0){
					if(((int)(V*V - v*v) / (2*a)) == ((float)(V*V - v*v) / (2*a))) l = d + ceil((V*V - v*v) / (2*a)) + 1;
					else l = d + ceil((V*V - v*v) / (2*a));
					if(l <= L){
						cnt++;
						s[cnt] = {l, L};
//						printf("%d: %d, %d\n", i, l, L);
					}
				}
			} else { // v0超速 
				if(a >= 0){
					cnt++;
					s[cnt] = {d, L};
//					printf("%d: %d, %d\n", i, d, L);
				} else {
					if(((int)(V*V - v*v) / (2*a)) == ((float)(V*V - v*v) / (2*a))) r = min(d + ((V*V - v*v) / (2*a)) - 1, L);
					else r = min(d + ((V*V - v*v) / (2*a)), L);
					cnt++;
					s[cnt] = {d, r};
//					printf("%d: %d, %d\n", i, d, r);
				}
			}
		}
		for(int i=1; i<=m; i++){ // step2: 判断
			cin>>p[i];
		}
		sort(s+1, s+cnt+1, cmp);
		
		
//		for(int i=1; i<=cnt; i++){
//			cout<<s[i].l<<" "<<s[i].r<<endl;
//		}printf("--------------------\n");

		
		ans1 = 0, ans2 = 0, idx = 0;
		for(int i=1; i<=cnt; i++){
			if(p[idx] > s[i].l){
				ans1++;
				continue;
			}
			while(p[idx] < s[i].l && idx < m) idx++;
//			printf("%d: %d %d\n", i, idx, p[idx]);
			if(p[idx] <= s[i].r){
				ans1++;
				while(p[idx+1] < s[i].r && (idx+1) < m) idx++;
				ans2++;
			} else{
				idx--;
			}
		}
		cout<<ans1<<" "<<(m - ans2)<<endl;
	}
	return 0;
}
