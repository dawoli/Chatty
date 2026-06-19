#include<bits/stdc++.h>
using namespace std;
long long cnt=0,n,r[100009];
multiset<long long> gs;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>r[i],gs.insert(r[i]);
	}
	multiset<long long>::iterator it;
	multiset<long long>::iterator it2;
	it=gs.end(),it--;
	if(*it<=2){
		int cnt2=0;
		for(it=gs.begin();it!=gs.end();it++){
			if(*it==2) break;
			cnt++;
		}
		cout<<n-min(cnt,n-cnt);
		return 0;
	}
	while(gs.size()!=0){
		it2=gs.begin();
		for(it=gs.begin();it!=gs.end();it++){
			if(*it>*it2){
				cnt++;
				gs.erase(it);
				gs.erase(it2);
				break;
			}
		}
		it=gs.begin();
		it2=gs.end(),it2--;
		if(*it==*it2) break;
	}
	if(gs.size()==1) cnt++;
	cout<<n-cnt;
	return 0;
} 
