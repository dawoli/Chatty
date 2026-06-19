#include<bits/stdc++.h>
using namespace std;
int tt,nn,kk,qq,ll,ss[20005],rr,cc;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>tt;
	for(int ii=1;ii<=tt;ii++){
		cin>>nn>>kk>>qq;
		for(int i=1;i<=nn;i++){
			cin>>ll;
			for(int j=1;j<=ll;j++){
				cin>>ss[j];
			}
		}
		for(int i=1;i<=qq;i++){
			cin>>rr>>cc;
			if((rr+cc)%3==0){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
