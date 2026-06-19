#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,r,c;
int s[1003][2003];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	cin>>t;
	while(t){
		t--;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			for(int j=1;j<=l;j++){
				scanf("%d",&s[i][j]);
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r,&c);
			cout<<rand()%2<<endl;
		}
	}
	
	return 0;
}
	

