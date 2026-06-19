#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,r[100005],step,k;
int h[100005],a[100005],g[100005],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> r[i];
	sort(r + 1,r + n + 1);
	r[0] = -1;
	for(int i = 1;i <= n;i++){
		h[r[i]]++;
		g[r[i]]++;
		if(r[i] != r[i - 1]) a[++step] = r[i];
	}
	k = 2;
	for(int l = 1;l < step;l++){
		if(k < l + 1) k = l + 1;
		while(h[a[l]] > 0 && k <= step){
			if(g[a[k]] <= h[a[l]]){
				h[a[l]] -= g[a[k]];
				g[a[k]] = 0;
				k++;
			}
			else {
				g[a[k]] -= h[a[l]];
				h[a[l]] = 0;
			}
		}
		if(k > step) break;
	}
	for(int i = 1;i <= step;i++){
		ans += h[a[i]];
	}
	cout << ans;
	return 0;
}
