#include<bits/stdc++.h>

using namespace std;

ifstream fin("arena.in");
ofstream fout("arena.out");
#define cin fin
#define cout fout

#define int long long
#define ssiz(x) (signed)x.size()
const int N=2e5+9;
const int lgN=20;

int a[N],c[N],n,m,lim=1;
int d[lgN][N];
int Solve(int len){
	vector<int> tmp;
	int t=1;while(t<len) t<<=1;
	for(int i=1;i<=len;i++) tmp.push_back(a[i]);
	for(int i=len;i<t;i++) tmp.push_back(-1);
	
	vector<vector<int>> alim;
	alim.push_back(tmp);
	for(int i=0;(1<<i)<t;i++){
		vector<int> cur;
		for(int j=0;j<(t>>(i+1));j++){
			int x=alim.back()[j<<1],y=alim.back()[j<<1|1];
			if(d[i][j]) swap(x,y);
			if(x==-1||x>i) cur.push_back(x);
			else cur.push_back(y);
		}
		alim.push_back(cur);
	}
	
	int ans=0;
	for(int i=0;i<t;i++){
		int flag=1;
//		cout<<" : "<<i<<endl;
		for(int k=0;(1<<k)<t;k++){
			int j=i^(1<<k),pos=i>>(k+1),x=tmp[i],y=alim[k][j>>k];
//			cout<<" :: "<<j<<' '<<k<<' '<<pos<<' '<<x<<' '<<y<<' '<<((d[k][pos])^(i<j))<<endl;
			if((d[k][pos])^(i<j)){
				if(x!=-1&&x<=k) flag=0;
			}else{
				if(y!=-1&&y>k) flag=0;
			}
		}
		if(flag) ans+=i+1;
//		cout<<" :end "<<flag<<endl;
	}
//	cout<<endl;
	
	return ans;
}

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	while(lim<n) lim<<=1;
	for(int i=0;i<__lg(lim);i++){
		int cur=lim>>(i+1);
		for(int j=0;j<cur;j++){
			char ch;
			cin>>ch;
			d[i][j]=ch-'0';
		}
	}
	
	int T;
	cin>>T;
	while(T--){
		int mask[4],ans=0;
		for(int k:{0,1,2,3}) cin>>mask[k];
		for(int i=1;i<=n;i++) a[i]^=mask[i&3];
		for(int i=1;i<=m;i++) ans^=Solve(c[i])*i;
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) a[i]^=mask[i&3];
	}
	
	return 0;
}
