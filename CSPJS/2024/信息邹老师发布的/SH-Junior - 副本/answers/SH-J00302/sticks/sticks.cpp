#include<bits/stdc++.h>
using namespace std;
int n[55],tmp[55];
char ans[55][55];
int cnt[13]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
	}
	for(int i=1;i<=t;i++){
		if(n[i]%7==0){
			tmp[i]=n[i]/7;
			for(int j=1;j<=tmp[i];j++){
					ans[i][j]='8';
				}
			}
		}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=tmp[i];j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
