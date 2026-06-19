#include<bits/stdc++.h>

using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");
#define cin fin
#define cout fout
#define endl '\n'

using ll=long long;
const int N=1e5+9;

int a[N][3],b[N],n;
vector<int> c[3];

inline void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++) for(int j:{0,1,2}) cin>>a[i][j];

	ll ans=0;
	for(int i=1;i<=n;i++){
		int p=max_element(a[i],a[i]+3)-a[i];
		ans+=a[i][p];
		c[p].push_back(i);
		sort(a[i],a[i]+3,greater<int>());
		b[i]=a[i][0]-a[i][1];
	}

	int k=-1;
	for(int i:{0,1,2}){
		if(signed(c[i].size())>n/2){
			k=i;
			break ;
		}
	}
	if(~k){
		sort(c[k].begin(),c[k].end(),[](int i,int j){return b[i]<b[j];});
		for(int i=0;i<signed(c[k].size())-n/2;i++) ans-=b[c[k][i]];
	}

	cout<<ans<<endl;
	
	for(int i=1;i<=n;i++){
		for(int j:{0,1,2}) a[i][j]=0;
		b[i]=0;
	}
	for(int i:{0,1,2}) c[i].clear();
}

signed main(){
	int T;
	cin>>T;
	while(T--) Solve();

	return 0;
}