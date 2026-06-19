#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+9;
typedef long long ll;
int n;
int a[MAXN];
bool vst[MAXN];
bool color[MAXN]; // 0 for red; 1 for blue

ll calc(){
	bool vst0=false,vst1=false;
	int idx0=0,idx1=0;
	ll res = 0;
	for(int i=1;i<=n;i++){
		if(color[i]==0&&vst0==false){
			vst0=true;
			idx0=i;
			continue;
		}
		if(color[i]==1&&vst1==false){
			vst1=true;
			idx1=i;
			continue;
		}
		if(color[i]==0&&vst0){
			if(a[i]==a[idx0]) res+=a[i];
			idx0=i;
			continue;
		}
		if(color[i]==1&&vst1){
			if(a[i]	==a[idx1]) res+=a[i];
			idx1=i;
			continue;
		}
	}
	// cout<<"Now color[]:";
	// for(int i=1;i<=n;i++){
	// 	cout<<color[i]<<',';
	// }
	// cout<<endl<<"result:"<<res<<endl;
	return res;
}

ll solve_BF(){
	// cout<<"Now a[]....:";
	// for(int i=1;i<=n;i++) cout<<a[i]<<',';
	// cout<<endl;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans = max(calc(),ans);
			color[j]=1;
			ans = max(calc(),ans);
			color[j]=0;
		}
		color[i]=1;
		for(int j=i+1;j<=n;j++){
			ans = max(calc(),ans);
			color[j]=1;
			ans = max(calc(),ans);
			color[j]=0;
		}
		color[i]=0;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(vst,false,sizeof(vst));
		memset(color,0,sizeof(color));
		bool allDiff = true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(vst[a[i]]) allDiff=false;
			vst[a[i]]=true;
		}
		if(allDiff) {cout<<0<<endl; continue;}
		if(n<=101){
			cout<<solve_BF()<<endl;
			continue;
		}
	}
	return 0;
}
