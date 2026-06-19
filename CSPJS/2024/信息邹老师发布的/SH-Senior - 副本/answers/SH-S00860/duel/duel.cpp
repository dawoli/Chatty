#include<bits/stdc++.h> 
using namespace std;
int n,r[100005];
bool a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n,cmp);
	int j=n;
	for(int i=n-1;i>=1;i--){
		if(!a[i]){
			while(a[j]&&j>i&&r[j]!=r[i]) j--;
			if(r[i]>r[j]) {
				a[j]=true;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!a[i]) ans++;
	}
	cout<<ans;
	return 0;
}
