#include<bits/stdc++.h>
using namespace std;
int x[100005],cnt[100005],y[100005],ans=0,amount=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int number;
	cin>>number;
	ans=1;
	for(int i=1;i<=number;i++){
		cin>>x[i];
		if(cnt[x[i]]==0){
			amount++;
			y[ans]=x[i];
			ans++;
		}
		cnt[x[i]]++;
	}
	sort(y+1,y+1+ans);
	ans=number;
	for(int i=1;i<amount;i++){
		ans-=min(cnt[y[i+1]],cnt[y[i+2]]);
	}
	cout<<ans;
	return 0;
}

