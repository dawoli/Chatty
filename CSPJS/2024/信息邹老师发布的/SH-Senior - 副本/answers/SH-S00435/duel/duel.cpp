#include<bits/stdc++.h>

using namespace std;
int n;
int a[100007];
int vis[100007];
int ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]&&vis[j]==0){
				vis[j]=1;
				ans++;
				break;
			}
		}
	}
	cout<<n-ans;
	return 0;
}
