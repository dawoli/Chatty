#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
int n;
int a[100005],b[100005],c[100005];

bool fa=0,fb=0,fc=0;
bool cmp(int a,int b){
	return a>b;
}
void solve1(){
	if(fa){
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout << ans << endl;
		return ;
	}
	if(fb){
		sort(b+1,b+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
		cout << ans << endl;
		return ;
	}
	if(fc){
		sort(c+1,c+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=c[i];
		}
		cout << ans << endl;
		return ;
	}
}

void solve2(){
	priority_queue<pii> qa,qb,qc;
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]){
			if(c[i]>a[i]) qc.push({c[i],i});
			else qa.push({a[i],i});
		}else{
			if(c[i]>b[i]) qc.push({c[i],i});
			else qb.push({b[i],i});
		}
	}
	long long ans=0;
	int cnta=0;
	while(!qa.empty()&&cnta<n/2){
		cnta++;
		ans+=qa.top().first;
		//cout << 'a' << ans << endl;
		qa.pop();
	}
	if(!qa.empty()){
		while(!qa.empty()){
			int t=qa.top().second;
			if(b[t]>c[t]) qb.push({b[t],t});
			else qc.push({c[t],t});
			qa.pop();
		}
	}
	int cntb=0;
	while(!qb.empty()&&cntb<n/2){
		cntb++;
		ans+=qb.top().first;
		//cout << 'b' << ans << endl;
		qb.pop();
	}
	if(!qb.empty()){
		while(!qb.empty()){
			int t=qb.top().second;
			qc.push({c[t],t});
			qb.pop();
		}
	}
	int cntc=0;
	while(!qc.empty()&&cntc<n/2){
		cntc++;
		ans+=qc.top().first;
		//cout << 'c' << ans << endl;
		qc.pop();
	}
	cout << ans << endl;
	
}
int resu,tmrs;
void dfs(int now,int csa,int csb,int csc){
	if(now==n+1){
		resu=max(resu,tmrs);
	}
	if(csa<n/2){
		tmrs+=a[now];
		dfs(now+1,csa+1,csb,csc);
		tmrs-=a[now];
	}
	if(csb<n/2){
		tmrs+=b[now];
		dfs(now+1,csa,csb+1,csc);
		tmrs-=b[now];
	}
	if(csc<n/2){
		tmrs+=c[now];
		dfs(now+1,csa,csb,csc+1);
		tmrs-=c[now];
	}
}
void solve3(){
	resu=tmrs=0;
	dfs(1,0,0,0);
	cout << resu << endl;
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
		if(a[i]) fa=1;
		if(b[i]) fb=1;
		if(c[i]) fc=1;
	}
	if(1*fa+fb+fc==1){
		solve1();
	}else if(n<=16) solve3();
	else solve2();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--) solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
