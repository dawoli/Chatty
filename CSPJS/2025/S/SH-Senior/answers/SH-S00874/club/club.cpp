#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long

using namespace std;
const int N=1e5+5;

ll n,a[N][4],s[4],nx[N],w[N];
void solve(){
	cin>>n;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[4];
	rep(i,1,n){
		int maxn=-1,maxnn=-2,p1=0,p2=0;
		rep(j,1,3){
			cin>>a[i][j];
			if(a[i][j]>maxn){
				maxnn=maxn;
				p2=p1;
				maxn=a[i][j];
				p1=j;
			}else if(a[i][j]>maxnn){
				maxnn=a[i][j];
				p2=j;
			}
		}
		nx[i]=p2;
		if(q[p1].size()<(n/2)){
			q[p1].push(make_pair(maxn-maxnn,i));
			w[i]=p1;
		}
		else{
			int tmp=q[p1].top().first;
			if(tmp>=maxn-maxnn){
				q[p2].push(make_pair(maxn-maxnn,i));
				w[i]=p2;
			}else{
				int tmprk=q[p1].top().second;
				q[p1].pop();
				q[p1].push(make_pair(maxn-maxnn,i));
				q[nx[tmprk]].push(make_pair(tmp,tmprk));
				w[tmprk]=nx[tmprk];
				w[i]=p1;
			}
		}
	}
	//rep(i,1,n){
	//	rep(j,1,3)cout<<a[i][j]<<' ';
	//	cout<<endl;
	//}
	int ans=0;
	rep(i,1,n)
		ans+=a[i][w[i]];
	//rep(i,1,n)
	//	cout<<w[i]<<endl;
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int TEST=1;
	cin>>TEST;
	while(TEST--)
		solve();
	return 0;
}
