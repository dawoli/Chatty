#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,cnt,cartag[100005],pcnt,pre_close_cnt,close_cnt;
bool flag_A,close[100005],cartag2[100005];
vector<int> ptag[100005];
struct moni{
	int pos,id;
}p[100005];
bool cmp(moni a,moni b){
	return a.pos<b.pos;
}
struct node{
	int d,v,a;
}car[100005];
int get_v2_v0as(int v0,int a,int s){
	return v0*v0+2*a*s;
}
void check(){
	for(int i=1;i<=n;i++){
		bool chao=0;
		int a=car[i].a,d=car[i].d,v0=car[i].v;
		for(int j=1;j<=m;j++){
			if(close[j])continue;
			if(p[j].pos<car[i].d||-v0*v0>2*a*(p[j].pos-d))continue;//after or have stop
			int vnow2=get_v2_v0as(v0,a,p[j].pos-d);
			if(vnow2>v*v){
				pcnt++;
				break;
			}
		}
	}
	if(pcnt==cnt){
		close_cnt=max(close_cnt,pre_close_cnt);
	}
}
void dfs(int x){
	if(x==m+1){
		check();
		return;
	}
	close[x]=1;
	pre_close_cnt++;
	dfs(x+1);
	pre_close_cnt--;
	close[x]=0;
	dfs(x+1);
}

void solve_A(){
	for(int i=1;i<=n;i++){
		bool chao=0;
		int a=car[i].a,d=car[i].d,v0=car[i].v;
		for(int j=1;j<=m;j++){
			if(p[j].pos<car[i].d||-v0*v0>2*a*(p[j].pos-d))continue;//after or have stop
			int vnow2=get_v2_v0as(v0,a,p[j].pos-d);
			if(vnow2>v*v){
				chao=1;
				cartag[i]++;
				ptag[j].push_back(i);
			}
		}
		if(chao)cnt++;
	}
	cout<<cnt<<" ";
	sort(p+1,p+1+m,cmp);
	for(int i=1;i<=m;i++){
		bool ok=1;
		for(int j=0;j<ptag[p[i].id].size();j++){
			if(cartag[ptag[i][j]]&&!cartag2[ptag[i][j]]){
				ok=0;
				break;
			}
		}
		if(ok){
			pcnt++;
		}else{
			for(int j=0;j<ptag[p[i].id].size();j++){
				cartag2[ptag[i][j]]=1;
			}
		}
	}
	cout<<pcnt<<"\n";
}
void clean_ptag(){
	for(int i=1;i<=m;i++){
		if(!ptag[i].empty()){
			for(int j=0;j<ptag[i].size();j++){
				ptag[i][j]=0;
			}
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		bool chao=0;
		int a=car[i].a,d=car[i].d,v0=car[i].v;
		for(int j=1;j<=m;j++){
			if(p[j].pos<car[i].d||-v0*v0>2*a*(p[j].pos-d))continue;//after or have stop
			int vnow2=get_v2_v0as(v0,a,p[j].pos-d);
			if(vnow2>v*v){
				chao=1;
				cartag[i]++;
				ptag[j].push_back(i);
			}
		}
		if(chao)cnt++;
	}
	cout<<cnt<<" ";
//	dfs(1);
//	cout<<close_cnt<<"\n";
	sort(p+1,p+1+m,cmp);//fail
	cnt=0;
	for(int i=1;i<=m;i++){
		if(ptag[i].empty()){
			cnt++;
			continue;
		}
		bool ok=1;
		for(int j=0;j<ptag[p[i].id].size();j++){
			if(cartag[i]<2)ok=0;
		}
		if(ok){
			cnt++;
			for(int j=0;j<ptag[p[i].id].size();j++){
				cartag[j]--;
			}
//			cout<<p[i].id<<" ";
		}
	}
//	cout<<endl;
	cout<<cnt<<"\n";
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	/*
	to clean:
	int t,n,m,l,v,cnt,cartag[100005],pcnt,close_cnt,pre_close_cnt;
	bool close[100005],cartag2[100005];

	*/
	while(t--){
		memset(cartag,0,sizeof(cartag));
		memset(cartag2,0,sizeof(cartag2));
		memset(p,0,sizeof(p));
		clean_ptag();
		flag_A=pcnt=close_cnt=pre_close_cnt=cnt=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			int d,v,a;
			cin>>d>>v>>a;
			if(a!=0)flag_A=0;
			car[i]=node{d,v,a};
		}
		for(int i=1;i<=m;i++){
			p[i].id=i;
			cin>>p[i].pos;
		}
		if(flag_A)solve_A();
		else solve();
	}
	return 0;
}
