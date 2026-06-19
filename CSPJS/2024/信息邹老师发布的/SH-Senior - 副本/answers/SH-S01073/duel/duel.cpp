#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+7;
int n,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	int q=1,ans=n;
	for(int i=1;i<=n;++i){
		if(a[i]>a[q]){
			ans--;
			q++;
		}
	}
	cout<<ans;
	return 0;
}

