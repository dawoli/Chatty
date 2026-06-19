#include<bits/stdc++.h>
using namespace std;
int T,n[51];
char ans[51][10000];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>n[i];
		if(n[i]%7==0){
			for(int j=0;j<(n[i]/7);++j)
				ans[i][j]='8';
		}
		else
			ans[i][0]='-1';
	}
	for(int i=0;i<T;++i){
		if(ans[i][0]=='-1'&&i<(T-1)){
			cout<<"-1"<<endl;
			continue;
		}
		if(ans[i][0]=='-1'&&i==(T-1)){
			cout<<"-1";
			continue;
		}
		if(i!=(T-1)){
			for(int j=0;j<(n[i]/7);++j){
				if(j<((n[i]/7)-1))
					cout<<ans[i][j];
				else
					cout<<ans[i][j]<<endl;
			}
		}
		if(i==(T-1)){
			for(int j=0;j<(n[i]/7);++j)
				cout<<ans[i][j];
		}
	}
	return 0;
}
