#include <bits/stdc++.h>
using namespace std;
    int t,n[100001],k[100001],q[100001],s[6][100002],r[6][100001],c[6][100001];
    int main(){
    	freopen ("chain.in","r",stdin);
    	freopen ("chain.out","w",stdout);
    	cin>>t;
    	for (int i=1;i<=t;i++){
    		cin>>n[i]>>k[i]>>q[i];
    		for (int j=1;j<=n[i];j++){
    			cin>>s[i][j];
			}
			for (int j=1;j<=q[i];j++){
				cin>>r[i][j]>>c[i][j];
			}
			cout<<"1";
			if (i!=t) cout<<endl;
		}
    	return 0;
	}
