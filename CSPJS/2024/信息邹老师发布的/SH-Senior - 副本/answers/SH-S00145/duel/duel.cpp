#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt[N],ans;
int main(){
	freopen("duel.in","r",stdin),freopen("duel.out","w",stdout);
	cin>>n;
    for(int x;n--;){
    	cin>>x,cnt[x]++;
	}
	for(int i=1;i<N;i++){
		ans=max(ans,cnt[i]);
	}
	cout<<ans;
}
