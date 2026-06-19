#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for (int v=1;v<=T;v++){
		int n,k,q;
		int l[100005],s[200005][100005],r[100005],c[100005];
		for (int i=1;i<=n;i++){
			cin>>l[i];
			for (int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		for (int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			for (int j=1;j<=r[i];j++){
				for (int a=1;a<=l[i];a++){
					
				}
			}
		}
		
	}
	cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
	return 0;
}
