#include<bits/stdc++.h>
using namespace std;
int n,k,q,l,r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int times=0;times<t;times++){
		cin>>n>>k>>q;
		int s[n][200005];
		for(int i=0;i<n;i++){
			cin>>l;
			s[i][0]=l;
			for(int j=1;j<=l;j++)
				cin>>s[i][j]; 
		}
		for(int i=0;i<q;i++){
			bool flag=false;
			cin>>r>>c;
			for(int j=0;j<n;j++)
				for(int m=1;m<=s[j][0];m++){
					if(s[j][m]==1)
					for(int n=m+2;n<m+k;n++)
						if(s[j][n]==c) flag=true;
				}
			if(flag) cout<<"1";
			else cout<<"0";
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
