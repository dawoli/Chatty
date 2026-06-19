#include <bits/stdc++.h>
using namespace std;
int n,ans=52,vis[55],xu;
string pai;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		xu=0;
		cin >> pai;
		if(pai[0]=='C'){
			xu+=0;
		}else if(pai[0]=='D'){
			xu+=13;
		}else if(pai[0]=='H'){
			xu+=26;
		}else if(pai[0]=='S'){
			xu+=39;
		}
		if(pai[1]=='T'){
			xu+=10;
		}else if(pai[1]=='A'){
			xu+=1;
		}else if(pai[1]=='K'){
			xu+=13;
		}else if(pai[1]=='Q'){
			xu+=12;
		}else if(pai[1]=='J'){
			xu+=11;
		}else{
			xu+=pai[1]-'0';
		}
		if(vis[xu]==0){
			ans--;
			vis[xu]=1;
		}
	}
	cout << ans;
	return 0;
}
