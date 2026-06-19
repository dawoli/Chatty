#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N],ans,b[N],c[N],d[N],cnt;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(!b[a[i]]){
			d[++cnt] = a[i];
		}
		b[a[i]]++;
		c[a[i]]++;
	}
	sort(d + 1,d + cnt + 1);
	for(int i = 1,j = 2; i <= cnt&&j <= cnt; i++){
		while(!c[d[j]]||j <= i){
			j++;
		}
		if(j > cnt){
			break;
		}
		while(b[d[i]]){
			b[d[i]]--;
			if(c[d[i]]){
				c[d[i]]--;
			} 
			c[d[j]]--;
			if(!c[d[j]]){
				j++;
			}
			if(j > cnt){
				break;
			}
		} 
	}
	for(int i = 1; i <= cnt; i++){
		ans += b[d[i]];
	}
	printf("%d",ans);
    return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136

3
1 2 2
*/
