#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,a[N],cnt[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		res=max(res,cnt[a[i]]);
	}
	cout<<res<<endl;
	return 0;
}
