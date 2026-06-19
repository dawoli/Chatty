#include<bits/stdc++.h>
using namespace std;
int a,cnt[100110];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cnt[a]++;
	}
	int fl1=0;
	for(int i=1;i<=100010;i++){
		if(!fl1&&cnt[i])ans=cnt[i],fl1=1;
		if(fl1&&cnt[i]){
			ans=max(0,ans-cnt[i])+cnt[i];
		}
	}
	cout<<ans;
	
	return 0;
}
