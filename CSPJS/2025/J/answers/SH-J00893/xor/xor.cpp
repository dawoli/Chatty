#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,k;
const int N=5e5+10,K=3e2;
int a[N];
int xos[N];
vector<pair<int,int>> v;
bool cmp(pii x,pii y){
	if(x.second!=y.second) return x.second<y.second;
	return x.first<y.first;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xos[i]=xos[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<(xos[j]^xos[i])<<"\n";
			if((xos[j]^xos[i-1])==k)
				v.push_back(make_pair(i,j));
		}
	}
	sort(v.begin(),v.end(),cmp);
	long long ans=0;
	int now=0;
	for(auto x:v){
//		cout<<x.first<<" "<<x.second<<"\n";
		if(x.first>now){
			ans++;
			now=x.second;
		}
	}
	cout<<ans;
	return 0;
}
