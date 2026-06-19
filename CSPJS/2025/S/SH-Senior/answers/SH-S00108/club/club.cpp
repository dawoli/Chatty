#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read(){
	TN rst=0;bool mns=0;
	char ch=getchar();
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')mns=1,ch=getchar();
	while(isdigit(ch))rst=rst*10+(ch^48),ch=getchar();
	return mns?-rst:rst;
}
int TestCase=1;
inline void main_init();
inline void main_solve();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	TestCase=read<int>();
	main_init();
	do main_solve();while(--TestCase);
}
inline void main_init(){

}
int n,a[100005][3];
vector<int> id[3];
inline int submx(int u,int o){
	int mx=0;
	if(o!=0)mx=max(mx,a[u][0]);
	if(o!=1)mx=max(mx,a[u][1]);
	if(o!=2)mx=max(mx,a[u][2]);
	return mx;
}
inline void main_solve(){
	n=read<int>();
	id[0].clear();
	id[1].clear();
	id[2].clear();
	int ans=0;
	for(int i=1;i<=n;++i){
		a[i][0]=read<int>();
		a[i][1]=read<int>();
		a[i][2]=read<int>();
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			id[0].push_back(i);
			ans+=a[i][0];
		}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			id[1].push_back(i);
			ans+=a[i][1];
		}else{
			id[2].push_back(i);
			ans+=a[i][2];
		}
	}
	for(int o=0;o<3;++o){
		if(id[o].size()<=(n>>1))continue;
		sort(id[o].begin(),id[o].end(),[&](int u,int v){
			return submx(u,o)-a[u][o]>submx(v,o)-a[v][o];
		});
		for(int i=0;i<id[o].size()-(n>>1);++i)
			ans+=submx(id[o][i],o)-a[id[o][i]][o];
		break;
	}
	cout<<ans<<'\n';
}

