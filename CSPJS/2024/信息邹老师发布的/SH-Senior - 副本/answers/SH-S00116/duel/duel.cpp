#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
int n,a[N];
bool att[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	int id=1;
	for(int i=1;i<=n;++i){
		while(id<=n && !(a[id]>a[i] && att[id]==0)) ++id;
		if(id>n) break;
		if(a[id]>a[i] && att[id]==0){
			att[id]=1;
			++id;
			++ans;
		}
	} 
	cout<<n-ans<<'\n';
	return 0;
} 
