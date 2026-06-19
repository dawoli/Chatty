#include<bits/stdc++.h>
using namespace std;
int n,m,last,ans;
map<int,int> mp;
set<int> s;
set<int>::iterator it,itt;
bool flag=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);b
		flag|=mp[m];
		mp[m]++;
		s.insert(m);
	}
	if(!flag){
		cout<<1<<endl;
		return 0;
	}
	itt=s.begin();
	itt++;
	for(it=s.begin();it!=s.end();it++,itt++){
		if(itt==s.end()){
			last+=mp[*it];
			continue;
		}
		if(mp[*itt]>mp[*it]){
			last=max(0,last-mp[*itt]+mp[*it]);
		}
		else{
			last+=mp[*it]-mp[*itt];
		}
	}
	cout<<last<<endl;
	return 0;
} 
