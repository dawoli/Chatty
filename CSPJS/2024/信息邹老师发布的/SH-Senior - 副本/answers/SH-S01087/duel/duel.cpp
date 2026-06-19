#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,k,a[N],top,ans,cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		a[k]++;
		top=max(top,k);
	}
	for(int i=0;i<=top;i++){
		ans+=min(cnt,a[i]);
		cnt=max(0,cnt-a[i]);
		cnt+=a[i];
	}
	cout<<n-ans;
	return 0;
} 
