#include<bits/stdc++.h>
using namespace std;

int t,n;
int ans[110]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int qianzhui[110]={88,108,188,200,208,288,688};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=14){
			cout<<ans[n]<<"\n";
			continue;
		}
		int djk=n/7;
		int op=n%7;
		string ans="";
		cout<<qianzhui[op]; djk-=2;
		for(int i=1;i<=djk;i++) cout<<'8';
		cout<<"\n";
	}
	return 0;
}
