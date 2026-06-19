#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,cnt[100001],ans;
set<pii> st1,st2;
set<pii>::iterator it1,it2;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0,r;i<n;i++){
		cin>>r;cnt[r]++;
	}
	for(int i=0;i<=1e5;i++)
		if(cnt[i])st1.insert((pii){i,cnt[i]});
	while(st1.size()>1){
		it1=it2=st1.begin();it2++;
		if((*it1).second<=(*it2).second)
			st1.erase(it1);
		else{
			pii p=(*it1);
			p.second-=(*it2).second;
			st2.insert(*it2);
			st1.erase(it1);st1.erase(it2);
			st1.insert(p);
		}
	}
	if(!st1.empty()){
		pii p1=(*st1.begin());
		while((!st2.empty())&&p1.first>(*(it2=st2.begin())).first&&p1.second>0){
			pii p2=(*it2);
			if(p1.second>=p2.second){
				st2.erase(it2);
				st2.insert((pii){p1.first,p2.second});
				p1.second-=p2.second;
			}else{
				st2.erase(it2);st2.insert(p1);
				p2.second-=p1.second;p1.second=0;
				st2.insert(p2);
			}
		}
		ans=p1.second;
	}
	for(it1=st2.begin();it1!=st2.end();it1++)ans+=(*it1).second;
	cout<<ans;
	return 0;
} 
