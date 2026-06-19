#include <bits/stdc++.h>
using namespace std;
int T,n[51],f[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int v[10]={6,2,5,5,4,5,6,3,7,6};
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> n[i];
		memset(f,0,sizeof(f));
		for(int k=2;k<=n[i];k++){
			for(int j=0;j<=9;j++){
				if(k>=v[j] && f[k]!=0 && k-v[j]!=1) f[k]=min(f[k],f[k-v[j]]*10+j); 
				else if(k>=v[j] && f[k]==0 && k-v[j]!=1) f[k]=f[k-v[j]]*10+j;
	        }
	    }
	    if(n[i]==0 || n[i]==1) cout << "-1" << "\n";
	    else cout << f[n[i]] << "\n";
	}
	return 0;	
} 
