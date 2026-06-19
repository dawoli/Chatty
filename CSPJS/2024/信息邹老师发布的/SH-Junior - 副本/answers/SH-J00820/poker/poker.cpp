#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
map<string,int> cnt;
int main(){
	freopen("poker.in","r",stdin);
 	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string nw;
		cin>>nw;
		if(cnt[nw]==1) continue;
		ans--;
		cnt[nw]=1;
	}
	cout<<ans<<endl;
	return 0;
}
