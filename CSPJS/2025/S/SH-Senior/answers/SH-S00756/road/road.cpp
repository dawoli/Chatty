#include<bits/stdc++.h>
using namespace std;
int n,m,k,x;
struct bi{
	int u,v;
	long long w;
}ba[2000010];
struct te{
	int ct;
	int l[1020];
}t[1020];
struct cu{
	int c;
	long long  a[1010];
}cn[15];
int cnt,cnt1,cnt2,cnt3;
bool cmp(bi o,bi p){
	return o.w > p.w;
}
long long ans;
bool f[1020];
bool la(int o,int p){
//	cout << t[o].ct<< " " << o<<endl;
	f[o] = 1;
	for(int j = 1;j <= t[o].ct;j++){
//		cout << t[o].l[j] << endl;
		if(t[o].l[j] == p){
			return true;
		}
		else if(t[o].l[j] != 0 && !f[t[o].l[j]]){
			if(la(t[o].l[j],p)){
				return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	ans = 0;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%lld",&ba[i].u,&ba[i].v,&ba[i].w);
		t[ba[i].u].ct++;
		t[ba[i].u].l[t[ba[i].u].ct] = ba[i].v;
		t[ba[i].v].ct++;
		t[ba[i].v].l[t[ba[i].v].ct] = ba[i].u;
		ans += ba[i].w;
	}
	cnt = m;
	cnt1 = n;
	for(int i = 1;i <= k;i++){
		scanf("%d",&cn[i].c);
		cnt1++;
		for(int j = 1;j <= n;j++){
			scanf("%lld",&cn[i].a[j]);
			cnt++;
			ba[cnt].u = cnt1;
			ba[cnt].v = j;
			ba[cnt].w = cn[i].a[j];
			ans += ba[cnt].w;
			t[ba[cnt].u].ct++;
			t[ba[cnt].u].l[t[ba[cnt].u].ct] = ba[cnt].v;
			t[ba[cnt].v].ct++;
			t[ba[cnt].v].l[t[ba[cnt].v].ct] = ba[cnt].u;
		}
	}
	cnt3 =cnt - (n + k - 1);
	sort(ba +1,ba + cnt +1,cmp);
	for(int i = 1;i <= cnt;i++){
//		cout << ba[i].u <<" " <<ba[i].v <<"  " <<ba[i].w<<endl;
		memset(f,0,sizeof(f));
		f[0] = 1;
		for(int j = 1;j <= t[ba[i].u].ct;j++){
			if(t[ba[i].u].l[j] == ba[i].v){
				t[ba[i].u].l[j] = 0;
				x = j;
				break;
			}
		}
		if(la(ba[i].u,ba[i].v)){
//			cout << ba[i].u <<" " <<ba[i].v <<" " <<ba[i].w<<endl;
			cnt2++;
			ans -= ba[i].w;
			for(int j = 1;j <= t[ba[i].v].ct;j++){
				if(t[ba[i].v].l[j] == ba[i].u){
					t[ba[i].v].l[j] = 0;
					break;
				}
			}
			
		}
		
		else{
			t[ba[i].u].l[x] = ba[i].v;
		}
//		cout <<ans <<endl;
		if(cnt2 == cnt3){
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
