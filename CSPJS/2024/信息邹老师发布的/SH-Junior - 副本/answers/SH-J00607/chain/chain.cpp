#include<bits/stdc++.h>
using namespace std;
int T;
int n,k;
int l[2001];
int s[1001][2001];
int q;
int r,c,a;
void op(int r_,int tl,int ne){
	if(a==0)
		for(int i=1;i<=n;i++){
			if(i==ne)
				continue;
			for(int j=2;j<=l[i];j++){
				if(s[i][j]==tl){
					if(r_==1){
						for(int m=j-1;m>=1&&j-m<k;m--){
							if(s[i][m]==1){
								a=1;i=n;j=l[i];m=0;
							}
						}
					}
					else{
						for(int m=j-1;m>=1&&j-m<k;m--){
							op(r_-1,s[i][m],i);
						}
					}
				}
			}
		}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
				cin>>s[i][j];
		}
		for(int q_=1;q_<=q;q_++){
			cin>>r>>c;
			a=0;
			op(r,c,0);
			cout<<a<<endl;
		}
	}
	return 0;
}
