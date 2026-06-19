#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[100005];
int b[100005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	int be=0;
	ans=n;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			be+=b[a[i-1]];
		}
		if(be>0){
			be--;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

