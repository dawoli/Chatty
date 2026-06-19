#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
long long n,ans,head,a[N],vis[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);	
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	head=1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[head] && vis[head]==0){
			ans--;
			vis[head]=1;
			head++;
		}
	}
	cout<<ans;
}
