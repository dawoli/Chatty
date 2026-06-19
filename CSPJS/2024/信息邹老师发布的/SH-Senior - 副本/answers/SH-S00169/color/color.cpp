#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+2;
int T,n;
int a[maxn];
vector<int>r;
vector<int>b;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		//solve();
		ll t=0,ans=0;
		while(t<(1ll<<n)){
			r.clear();
			b.clear();
			for(int j=1;j<=n;j++){
				ll temp=t;
				if(temp&(1ull<<(j-1)))r.push_back(a[j]);
				else b.push_back(a[j]);
			}
			//cout<<t<<' '<<r.size()<<' '<<b.size()<<endl;
			ll score=0;
			for(int j=r.size()-1;j>0;j--){
				if(r[j]==r[j-1])score+=r[j];
			}
			for(int j=b.size()-1;j>0;j--){
				if(b[j]==b[j-1])score+=b[j];
			}
			ans=max(ans,score);
			t++;
		}
		cout<<ans;
	}
	return 0;
}
