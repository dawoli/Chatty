#include<bits/stdc++.h>
using namespace std;
#define N 100005//注意设置大小
typedef long long ll;

int n,ct;
map<int,pair<int,int>> mp;
vector<int> vec;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		mp[t].first++;
	}
	
	for(pair<int,pair<int,int>> p:mp) vec.push_back(p.first);
	
	for(int i=1;i<vec.size();++i){
		int index=1;
		while(1){
			if(i-index<0) break;
			if(mp[vec[i]].first>=mp[vec[i-index]].first+mp[vec[i-index]].second){
				mp[vec[i]].first-=(mp[vec[i-index]].first+mp[vec[i-index]].second),mp[vec[i]].second+=(mp[vec[i-index]].first+mp[vec[i-index]].second);
				mp[vec[i-index]].first=0,mp[vec[i-index]].second=0;
			}
			else if(mp[vec[i]].first>=mp[vec[i-index]].first){
				mp[vec[i-index]].second-=(mp[vec[i]].first-mp[vec[i-index]].first),mp[vec[i-index]].first=0;
				mp[vec[i]].second+=mp[vec[i]].first,mp[vec[i]].first=0;
			}
			else{
				mp[vec[i-index]].first-=mp[vec[i]].first;
				mp[vec[i]].second+=mp[vec[i]].first,mp[vec[i]].first=0;
			}
			index++;
			if(mp[vec[i]].first==0) break;
		}
	}
	for(pair<int,pair<int,int>> p:mp) ct+=(p.second.first+p.second.second);
	cout<<ct<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


