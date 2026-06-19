#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,ans;
bool flaga=true;
string s;
int c[505];
bool cho[505];
/*bool cmp(int a,int b){
	return a>b;
}*/
void dfs(int def,int days,int acc){
	if(days==n && acc>=m) {
		//cout<<"¡Ì"<<endl;
		ans++;
		return ;
	}
	/*for(int i=1;i<=n;i++){
		if(c[i]<def) def++;
	}*/
	for(int i=1;i<=n;i++){
		if(cho[i]) continue;
		if(c[i]>def && s[days]=='1'){
			cho[i]=true;
			//cout<<i<<" ";
			dfs(def,days+1,acc+1);
			cho[i]=false;
		}
		else{
			if(c[i]<=def){
				cho[i]=true;
				//cout<<i<<" ";
				dfs(def+1,days+1,acc);
				cho[i]=false;
			}
			else{
				if(s[days]=='0'){
					cho[i]=true;
					//cout<<i<<" ";
					dfs(def+1,days+1,acc);
					cho[i]=false;
				}		
			}
		
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		//if(c[i]!=1) flaga=false;
	}
	/*if(flaga){
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(c[i]<i) {
				cout<<i-1<<endl;
				break;
			}
		}
	}*/
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
/*
3 2
101
1 1 2
*/
