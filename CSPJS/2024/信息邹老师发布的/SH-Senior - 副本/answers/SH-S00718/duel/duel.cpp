#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
