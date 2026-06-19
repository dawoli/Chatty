#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
struct mem{
	int a1,a2,a3;
	int mx,mn,mi;
	int v,mxa,mia,mna; 
}a[MAXN];
int cnt[4];
bool cmp(mem x,mem y){
	return x.v>y.v;
}
void init(){
	for(int i=0;i<MAXN;++i){
		a[i].a1=0;
		a[i].a2=0;
		a[i].a3=0;
		a[i].mx=0;
		a[i].mn=0;
		a[i].mi=0;
		a[i].v=0;
	}
	cnt[1]=0;
	cnt[2]=0;
	cnt[3]=0;
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		a[i].mx=max(a[i].a1,max(a[i].a2,a[i].a3));
		a[i].mn=min(a[i].a1,min(a[i].a2,a[i].a3));
		a[i].mi=a[i].a1+a[i].a2+a[i].a3-a[i].mx-a[i].mn;
		a[i].v=a[i].mx-a[i].mi;
		if(a[i].mx==a[i].a1) a[i].mxa=1;
		else if(a[i].mx==a[i].a2) a[i].mxa=2;
		else a[i].mxa=3;
		if(a[i].mi==a[i].a1) a[i].mia=1;
		else if(a[i].mi==a[i].a2) a[i].mia=2;
		else a[i].mia=3;
	}
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n;++i){
		if(cnt[a[i].mxa]==n/2){
			cnt[a[i].mia]++;
			ans+=a[i].mi;
		}
		else{
			cnt[a[i].mxa]++;
			ans+=a[i].mx;
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin >> t;
	for(int i=1;i<=t;++i){
		init();
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
