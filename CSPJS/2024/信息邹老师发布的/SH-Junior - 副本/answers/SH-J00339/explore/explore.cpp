#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,x,y;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k;
		for(int i=0;i<k;i++){
			cin>>x>>y>>d;
			if(n==1){
				if(m==1){
					cout<<1<<endl;
					continue;
				}
				else if(m==2){
					if((y==1)&&((d==0)||(k>=4))){
						cout<<2;
					}
					if((y==2)&&((d==2)||(k>=4))){
						cout<<2;
					}
				}
			}
		}
	}
	return 0;
}
