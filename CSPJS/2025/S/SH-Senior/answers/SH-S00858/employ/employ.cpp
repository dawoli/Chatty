#include<bits/stdc++.h>
using namespace std;
int n,m;//人数 想雇佣的人数
vector<bool> difficult;//当天是否困难
vector<int> people;///每个人的耐心
int ans;
bool check(vector<int> now){
	vector<int> p;
	p=people;
	int call=0;
	for(int i=0;i!=n;i++){
		if(difficult[i]==false and p[now[i]]>0){
			call++;
		}
		else{
			for(int j=0;j!=n;j++){
				p[j]--;
			}
		}
	}
	return call>=m;
}
void all(vector<bool> used,vector<int> now){
	if(now.size()==n){
		if(check(now)){
			ans++;
		}
		return;
	}
	for(int i=0;i!=n;i++){
		if(used[i]==false){
			now.push_back(i);
			used[i]=true;
			all(used,now);
			now.pop_back();
			used[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	vector<bool> used;
	vector<int> now;
	cin>>n>>m;
	for(int i=0;i!=n;i++){
		used.push_back(false);
		char a;
		cin>>a;
		if(a=='0'){
			difficult.push_back(true);
		}
		else{
			difficult.push_back(false);
		}
	}
	for(int i=0;i!=n;i++){
		int a;
		cin>>a;
		people.push_back(a);
	}
	ans=0;
	all(used,now);
	cout<<ans;
	return 0;
}

