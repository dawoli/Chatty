#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t , n , cnt[4] , lmit , sum;
struct node{
	ll d1 , d2 , d3 ;
	ll mx1 , id1;
	ll mx2 , id2;
	ll mx3 , id3;
} to[100009] , ex[50009] , ex2[26009];
bool cmp1(node a,node b){
	return a.mx1 - a.mx2 > b.mx1 - b.mx2 || a.mx1 - a.mx2 == b.mx1 - b.mx2 && a.mx2 < b.mx2; 
}
bool cmp2(node a,node b){
	return a.mx2 - a.mx3 > b.mx2 - b.mx3 || a.mx2 - a.mx3 == b.mx2 - b.mx3 && a.mx3 < b.mx3; 
}
bool cmp3(node a,node b){
	return a.mx3 > b.mx3; 
}
void dodo(ll x){
	if(to[x].d3 >= to[x].d1){
		if(to[x].d1 >= to[x].d2){
			to[x].mx1 = to[x].d3;
			to[x].id1 = 3;
			to[x].mx3 = to[x].d2;
			to[x].id3 = 2;
			to[x].mx2 = to[x].d1;
			to[x].id2 = 1;
		}
		else if(to[x].d3 >= to[x].d2){
			to[x].mx1 = to[x].d3;
			to[x].id1 = 3;
			to[x].mx2 = to[x].d2;
			to[x].id2 = 2;
			to[x].mx3 = to[x].d1;
			to[x].id3 = 1;
		}
		else{
			to[x].mx2 = to[x].d3;
			to[x].id2 = 3;
			to[x].mx1 = to[x].d2;
			to[x].id1 = 2;
			to[x].mx3 = to[x].d1;
			to[x].id3 = 1;
		}
	} 
	else if(to[x].d3 <= to[x].d1){
		if(to[x].d3 >= to[x].d2){
			to[x].mx2 = to[x].d3;
			to[x].id2 = 3;
			to[x].mx3 = to[x].d2;
			to[x].id3 = 2;
			to[x].mx1 = to[x].d1;
			to[x].id1 = 1;
		}
		else if(to[x].d1 >= to[x].d2){
			to[x].mx3 = to[x].d3;
			to[x].id3 = 3;
			to[x].mx2 = to[x].d2;
			to[x].id2 = 2;
			to[x].mx1 = to[x].d1;
			to[x].id1 = 1;
		}
		else{
			to[x].mx3 = to[x].d3;
			to[x].id3 = 3;
			to[x].mx1 = to[x].d2;
			to[x].id1 = 2;
			to[x].mx2 = to[x].d1;
			to[x].id2 = 1;
		}
	} 
}
int main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		lmit = n / 2;
		memset(cnt,0,sizeof(cnt));
		sum = 0;
		for(ll i = 1; i <= n; i++){
			scanf("%lld",&to[i].d1);
			scanf("%lld",&to[i].d2);
			scanf("%lld",&to[i].d3);
			dodo(i);
		}
		sort(to+1,to+n+1,cmp1);
		ll exn = 0 , exn2 = 0;
		for(ll i = 1; i <= n; i++){
			if(cnt[to[i].id1] + 1 <= lmit){
				cnt[to[i].id1]++;
				sum += to[i].mx1;
			}
			else{
				ex[++exn]=to[i];
			}
		}
		if(exn == 0){
			printf("%lld",sum);
			cout << endl;
			continue;
		}
		sort(ex+1,ex+exn+1,cmp2);
		for(ll i = 1; i <= exn; i++){
			if(cnt[ex[i].id2] + 1 <= lmit){
				cnt[ex[i].id2]++;
				sum += ex[i].mx2;
			}
			else{
				ex2[++exn2]=ex[i];
			}
		}
		if(exn2 == 0){
			printf("%lld",sum);
			cout << endl;
			continue;
		}
		sort(ex2+1,ex2+exn2+1,cmp3);
		for(ll i = 1; i <= exn2; i++){
			if(cnt[ex2[i].id3] + 1 <= lmit){
				cnt[ex2[i].id3]++;
				sum += ex2[i].mx3;
			}
		}
		printf("%lld",sum);
		cout << endl;
		continue;
	}
	return 0;
} 
