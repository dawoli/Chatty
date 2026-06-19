#include<bits/stdc++.h>
using namespace std;
const int N=100009;
string str[N];
int r,n;
bool flag=0; 
void dfs(int ro,int be){
	if(!ro){
		if(be!=r) return;
		else{
			cout<<1<<endl;
            flag=1;
		}
	}
	string num;
	num[0]=char(be+'0');
	for(int i=1;i<=n;i++){
		if(str[i].find(num)) dfs(ro-1,be);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	int k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++) cin>>str[i][j];
	}
	for(int i=1;i<=q;i++){
		int l;
		cin>>l>>r;
	    dfs(l,r);
	    if(flag){
	    	flag^=1;
	    	continue;
		}
	    cout<<0<<endl;
	}
	return 0;
}

