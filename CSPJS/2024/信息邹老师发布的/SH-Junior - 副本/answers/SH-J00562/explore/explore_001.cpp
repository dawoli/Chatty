#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	string s;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		cin>>s;
		if(m==1){
			cout<<1<<endl;
		}
		else{
			if(y0==1){
				if(s[1]=='.' && d0==0){
					cout<<2<<endl;
				}
				else{
					cout<<1<<endl;
				}
			}
			if(y0==2){
				if(s[0]=='.' && d0==2){
					cout<<2<<endl;
				}
				else{
					cout<<1<<endl;
				}
			}
		}
		
	}
	
	return 0;
}

