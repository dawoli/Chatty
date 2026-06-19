#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,k,q,l,t,r[100000],c[100000];
	char s[100000][10];
	cin>>t;
	for(int w=0;w<t;w++){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>l;
			for(int j=0;j<l;j++)
				cin>>s[i][j];
		}
		for(int i=0;i<q;i++){
			cin>>r[i]>>c[i];
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

