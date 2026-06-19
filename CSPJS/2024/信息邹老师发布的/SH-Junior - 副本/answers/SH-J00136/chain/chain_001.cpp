#include<bits/stdc++.h>
using namespace std;
int a[10002][20002];
int b[10002][2];
int l[10002];
int n,k,q;
bool if_;
void dfs(int begin1,int round,int people,int task){
	if(round==b[task][0]){
		if(b[task][1]==begin1&&round==b[task][0]){
			if_=true;
			return;
		}
		else{
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(i==people){
			continue;
		}
		else{
			for(int o=0;o<l[i]-1;o++){
				for(int f=o+1;(f<l[i])&&(f-o<k);f++){
					if(a[i][o]==begin1&&(f-o<k)){
						dfs(a[i][f],round+1,i,task);
					}
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int jj=1;jj<=T;jj++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(l,0,sizeof(l));
		if_=false;
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>l[i];
			for(int j=0;j<l[i];j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<q;i++){
			cin>>b[i][0]>>b[i][1];
		}
		for(int i=0;i<q;i++){
			if_=false;
			dfs(1,0,-1,i);
			if(if_){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
