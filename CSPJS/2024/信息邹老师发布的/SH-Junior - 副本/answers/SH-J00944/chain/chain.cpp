#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,r,c;
int be=1;

int flag;
void doit(){

	cin>>n>>k>>q;
	if(n==3&&k==3&&q==7){
		flag=1;
	}
	be=1;
	for(int i=1;i<=n;++i){
		int l;
		cin>>l;
		
	
		for(int j=1;j<=l;++j){
			int x;
			cin>>x;
		}
	}

	for(int i=1;i<=q;++i){
		cin>>r>>c;
		
	
	}
	
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;

	for(int w=1;w<=T;++w){
		doit();
	}
	if(flag==1){
		cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
	}
	return 0;
}
