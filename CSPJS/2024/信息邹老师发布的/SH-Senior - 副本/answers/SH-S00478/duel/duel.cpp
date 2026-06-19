#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n,ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int cntx=1;
		while(a[i+1]==a[i]){
			cntx++;
			i++;
		}
		if(cnt<=cntx){
			ans+=cnt;
			cnt=cntx;
		}
		else
			ans+=cntx;
	}
	cout<<n-ans<<endl;
	return 0;
}
