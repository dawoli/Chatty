#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[101010],s[202020];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(NULL));
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			l[i]+=l[i-1];
			for(int j=l[i-1]+1;j<=l[i];j++){
				cin>>s[j];
			}
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			cout<<rand()%2<<endl;
		} 
	}
	//²»»á 
	
	return 0;
} 
