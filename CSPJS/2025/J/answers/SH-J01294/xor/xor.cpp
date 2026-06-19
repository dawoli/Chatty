#include<bits/stdc++.h>
using namespace std;
int n,k,mat[50005],x[50005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>mat[i];
	int l,r; l=1,r=1;
	while(r<=n){
		x[r]=mat[r];
		if(x[r]==k){
			l=r+1; ans++;
		}
		else{
			for(int i=l;i<r;i++){
				x[i]=x[i]^mat[r];
				if(x[i]==k){
					l=r+1; ans++;
					break;
				}
			}
		}
		r++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
