#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[100005],maxx=0,mx=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mx<a[i]){
			mx=a[i];
		}
		cnt[a[i]]++;
	}
	for(int i=1;i<=mx;i++){
		if(maxx<cnt[i]){
			maxx=cnt[i];
		} 
	}
	cout<<maxx<<endl;
	return 0;
}
