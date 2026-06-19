#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,m,a[N],ap[N],c[N],T,x[300][4];
bool okA(){
	for(int i=1;i<=m;i++){
		int cp=c[i];
		while(cp>=2){
			if(cp%2!=0) return false;
			cp/=2;
		} 
	}
	return true;
}
vector<int> d[N];
ll ansA[N],now[N];
void solveA(){
	ll k=0,nowA=1;
	for(k=1;k<=100;k++){
		nowA*=2;
		if(nowA>=n) break;
	}
	for(int r=1;r<=k;r++){
		nowA/=2;
		for(int i=1;i<=nowA;i++){
			char input;
			cin>>input;
			d[r].push_back(input-'0');
		}
	}
	cin>>T;
	for(int i=0;i<4;i++) cin>>x[1][i];
	for(int i=1;i<=n;i++) a[i]=ap[i]^x[1][i%4];
	nowA=1;
	ll cnt1=1;
	for(int i=1;i<=k;i++) nowA*=2;
	ansA[1]=1;
	for(int i=1;i<=nowA;i++) now[i]=i;
	for(int r=1;r<=k;r++){
		nowA/=2; cnt1*=2;
		for(int i=1;i<=nowA;i++){
			if(d[r][i-1]==0){
				if(a[now[i*2-1]]>=r) now[i]=now[i*2-1];
				else now[i]=now[i*2];
			}else{
				if(a[now[i*2]]>=r) now[i]=now[i*2];
				else now[i]=now[i*2-1];
			}
		}
		ansA[cnt1]=now[1];
	}
	ll anslst=0;
	for(ll i=1;i<=m;i++) anslst^=(i*ansA[c[i]]);
	cout<<anslst<<endl; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ap[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	if(okA())
		solveA();
	return 0;
} 
