#include<iostream>
using namespace std;
int t,n,q,k,l[1010],s[1010][1010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k>>q;
		int r,c;
		for(int j=1;j<=n;j++){
			cin>>l[i];
			for(int x=1;x<=l;x++){
				cin>>s[j][x];
			}
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			if(r%2==1)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
