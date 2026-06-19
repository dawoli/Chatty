#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,x,r,c;
string s[100005];
bool flag;
void dfs(int num,int idx,char last){
	if(num==r){
		if(last-'0'==c) flag=true;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==idx) continue;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]==last){
				for(int w=j+1;w<s[i].size()&&w-j+1<=k;w++){
					dfs(num+1,i,s[i][w]);
					if(flag) return;
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=0;i<100005;i++) s[i]="";
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>x;
				s[i]+=(x+'0');
			}
		}
		while(q--){
			cin>>r>>c;
			flag=false;
			for(int i=1;i<=n;i++){
				for(int j=0;j<s[i].size();j++){
					if(s[i][j]=='1'){
						for(int w=j+1;w<s[i].size()&&w-j+1<=k;w++){
							dfs(1,i,s[i][w]);
							if(flag) break;
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(flag) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
	}
	return 0;
}
