#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5,MAXM=1e5+5,MAXL=1e6+5,MAXV=1e3+5,INF=0x3f3f3f3f;
int T,N,M,L,V;
pair<int,int> car[MAXN],carA[MAXN];
pair<int,pair<int,int>> carB[MAXN],carC[MAXN];
int p[MAXL],sump[MAXL];
bool vis[MAXN];
bool leftcmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>>b){
	if(a.second.first==b.second.first) return a.second < b.second;
	return a.second.first < b.second.first;
}
bool rightcmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>>b){
	if(a.second.second==b.second.second) return a.first < b.first;
	return a.second.second < b.second.second;
}
void init(){
	for(int i=0;i<MAXL;++i){
		p[i]=0;
		sump[i]=0;
	}
	for(int i=0;i<MAXN;++i){
		car[i]=make_pair(-INF,-INF);
		carB[i]=make_pair(-INF,make_pair(-INF,-INF));
		carC[i]=make_pair(-INF,make_pair(-INF,-INF));
		carA[i]=make_pair(-INF,-INF);
		vis[i]=0;
	}
}
void solve(){
	cin >> N >> M >> L >> V;
	for(int i=1;i<=N;++i){
		int d,v,a;
		cin >> d >> v >> a;
		if(a==0){
			if(v>V) car[i]=make_pair(d,L);
			else N--,i--;
		}
		else if(a>0){
			if(v>V) car[i]=make_pair(d,L);
			else{
//				int x=floor(((double)(V*V-v*v))/(2*a));
				int x=(V*V-v*v)/(2*a);
//				cout << ((double)(V*V-v*v))/(2*a) << endl;
				if(d+x+1>L) N--,i--;
				else car[i]=make_pair(d+x+1,L);
			}
		}
		else{
			if(v<=V) N--,i--;
			else{
				int x=ceil(((double)(V*V-v*v))/(2*a));
//				cout << ((double)(V*V-v*v))/(2*a) << endl;
				car[i]=make_pair(d,min(d+x-1,L));
			}
		}
	}
//	for(int i=1;i<=N;++i) cout << car[i].first << ' ' << car[i].second << endl;
//	cout << "---------1----------";
	for(int i=1;i<=M;++i){
		int x;
		cin >> x;
		p[x]=1;
	}
	sump[0]=p[0];
	for(int i=1;i<=L;++i) sump[i]=p[i]+sump[i-1]; 
//	for(int i=0;i<=L;++i) cout << sump[i];
//	cout << endl;
	int ans1=0,ans2=0,cnt=0;
	for(int i=1;i<=N;++i){
		if(sump[car[i].second]-sump[car[i].first-1]>=1){
			ans1++;
			carB[++cnt]=make_pair(cnt,car[i]);
			carC[cnt]=make_pair(cnt,car[i]);
		}
	}
	cout << ans1 ;
	
	sort(carB+1,carB+cnt+1,leftcmp);
	sort(carC+1,carC+cnt+1,rightcmp);
//	for(int i=1;i<=cnt;++i){
//		cout << carB[i].second.first << carB[i].second.second << carC[i].second.first << carC[i].second.second << endl;
//	}
	int pb=1,pc=1,cnt2=0;
	while(pb<=cnt && pc<=cnt){
		while(vis[carC[pc].first]) pc++;
		while(vis[carB[pb].first]) pb++;
		pair<int,int> b=carB[pb].second,c=carC[pc].second;
		cout << b.first << c.first << b.second << c.second << endl;
		if(b.first==c.first && b.second==c.second){
			carA[++cnt2]=b;
			vis[carB[pb].first]=1;
			pb++;
			pc++;
		}
		else{
			vis[carB[pb].first]=1;
			pb++;
		}
//		cout << pb << pc<<endl;
		if(pb==cnt||pc==cnt) break;
	}
//	for(int i=1;i<=cnt2;++i) cout << carA[i].first << ' ' << carA[i].second << endl;
}
int main(){
	freopen("detect1.in","r",stdin);
//	freopen("detect.out","w",stdout);
	
	cin >> T;
	for(int t=1;t<=T;++t){
		init();
		solve();
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
