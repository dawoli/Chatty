#include<bits/stdc++.h>
using namespace std;
int a[100005];
int x[15];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
		int cnt=n/7;
		for(int i=1;i<=cnt;i++){
			cout<<8;
		}
		cout<<endl;	
		}else{
			int cnt=n/7-1;
			cout<<1<<0;
			for(int i=1;i<=cnt;i++){
			cout<<8;
		}
		cout<<endl;
		}
		
	}
	return 0;
}
