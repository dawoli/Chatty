#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int a[N],w[N],ans,cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	set<int> s;
	int n;
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	if(s.size()==n){
		cout<<1;
		return 0;
	}
	if(s.size()==1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	int ok=1;
	for(int i=1;i<=n+1;i++){
		if(a[i]!=a[i-1]){
			w[cnt]=i-ok;
		    cnt++;
		    ok=i;
		}
		else continue;
	}
	cnt=s.size();
	for(int i=2;i<=cnt;i++){
		if(w[i]>=w[i-1]) ans-=w[i-1];
		else ans-=w[i];
	}
	cout<<ans;
	return 0;
}
