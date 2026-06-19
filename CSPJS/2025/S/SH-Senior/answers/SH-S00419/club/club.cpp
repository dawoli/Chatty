#include<bits/stdc++.h>
#include<cstdio>
#define endl '\n'
using namespace std;
int n;
struct node{
	int b, c, d;
	int mx, promax;	
}a[100010];
int max(int x, int y, int z){
	return max(x, max(y, z));	
}
bool cmp(node x, node y){
	return x.promax+y.mx > x.mx+y.promax;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			scanf("%d%d%d", &a[i].b, &a[i].c, &a[i].d);
			a[i].promax = max(a[i].b, a[i].c, a[i].d);
			if(a[i].promax == a[i].b){
				a[i].mx = max(a[i].c, a[i].d);
			}else if(a[i].promax == a[i].c){
				a[i].mx = max(a[i].b, a[i].d);
			}else if(a[i].promax == a[i].d){
				a[i].mx = max(a[i].b, a[i].c);
			}
		}
		sort(a+1, a+n+1, cmp);
		int ans = 0;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for(int i=1; i<=n; ++i){
			int mx = max(a[i].b, a[i].c, a[i].d);
			if(mx == a[i].b){
				if(cnt1<n/2){
					ans+=mx; 
					cnt1++;
				}else{
					if(a[i].c>=a[i].d) cnt2++;
					else cnt3++;
					ans+=max(a[i].c, a[i].d);
				}
			}else if(mx == a[i].c){
				if(cnt2<n/2){
					ans+=mx;
					cnt2++;
				}else{
					if(a[i].b>=a[i].d) cnt1++;
					else cnt3++;
					ans+=max(a[i].b, a[i].d);	
				}
			}else if(mx == a[i].d){
				if(cnt3<n/2){
					ans+=mx;
					cnt3++;
				}else{
					if(a[i].b>=a[i].c) cnt1++;
					else cnt2++;
					ans+=max(a[i].b, a[i].c);	
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

