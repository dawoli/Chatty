#include<bits/stdc++.h>
using namespace std;
int ans[8]={1e9,-1,1,7,4,2,0,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		if(!n%7){
			for(int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
		else if(n%7!=1){
			int x=ans[n%7];
			cout<<x;
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<endl;
		}
		else{
		    cout<<"10";
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<endl;	
		}
    }
	return 0;
}
