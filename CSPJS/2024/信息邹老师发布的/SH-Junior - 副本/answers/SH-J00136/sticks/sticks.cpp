#include<bits/stdc++.h>
using namespace std;
int bl[10]={6,2,5,5,4,5,6,3,7,6};
int n=0;
int mi=10000001;
void dfs(int tol,int res){
	if((n-tol)>0){
		for(int i=0;i<10;i++){
			if(res==0&&i==0){
				continue;
			}
			dfs(tol+bl[i],res*10+i);
		}
	}
	else if((n-tol)<0){
		return;
	}
	else{
		mi=min(res,mi);
	}	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int jj=1;jj<=T;jj++){
		cin>>n;
		mi=10000001;
		dfs(0,0);
		if(mi==10000001){
			cout<<-1<<endl;
		}
		else{
			cout<<mi<<endl;
		}
	}
	return 0;
}
