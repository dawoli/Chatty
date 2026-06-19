#include<bits/stdc++.h>
using namespace std;
int n,a[100009],ans,cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	for(int i=1;i<n;){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
//				cout<<i<<" "<<j<<endl;
//				vis[j]++;
				ans++; i++;
			}
		}
		break;
	}
	cout<<n-ans<<endl;
	return 0;
} 
