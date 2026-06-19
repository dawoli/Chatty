#include <bits/stdc++.h>
using namespace std;
int n,ans,def[100010],att[100010];
int mi=0,ma=100001;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin>>n;
	ans=n;
	for (int i=1;i<=n;i++){
		int a;cin>>a;
		def[a]++;
		att[a]++;
		mi=min(mi,a);
		ma=max(ma,a);
	}
	att[mi]=0;
	int pos_st=mi;
	for (int i=mi;i<=ma;i++){
		if (att[i]==0) continue;
		while (pos_st<i and att[i]>0){
			if (def[pos_st]>0){
				int cut=min(def[pos_st],att[i]);
				ans-=cut;
				def[pos_st]-=cut;
				att[i]-=cut;
			}
			if (def[pos_st]==0)pos_st++;
		}
	}
	cout<<ans;
	return 0;
}
