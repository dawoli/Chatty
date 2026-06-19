#include<bits/stdc++.h>
using namespace std; 
int t,n,k,q,l[200005],s[100005][200005],r,c,f; 
int main(){
	freopen("chain.in","r",stdin); 
	freopen("chain.out","w",stdout);
	cin>>t; 
	for(int i=1; i<=t; i++){
		cin>>n>>k>>q; 
		for(int j=1; j<=n; j++){
			cin>>l[j]; 
			for(int k=1; k<=l[j]; k++) cin>>s[j][k]; 
		}
		for(int j=1; j<=q; j++){
			cin>>r>>c; 
			f=0; 
			if(r==1){
				for(int k=1; k<=n; k++){
					for(int z=1; z<=l[k]; z++){
						for(int a=2; a<=k; a++){
							if(s[k][z]==1 && s[k][z+a]==c){
								cout<<1<<endl; 
								f=1; 
								break; 
							} 
						}
						if(f==0) cout<<0<<endl; 
						else f=0; 
						break; 
					}
					break; 
				}
			}
			else {
				for(int k=1; k<=n; k++){
					for(int z=1; z<=l[k]; z++){
						if(s[k][n]==c)
						{
							cout<<1<<endl; 
							f=1; 
							break; 
						} 
					}
					if(f==0) cout<<0<<endl; 
					break; 
				}
			}
		}
	}
	fclose(stdin); 
	fclose(stdout); 
}
