#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l[100010],s[10001][20001];
long long na[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
			na[i]=0;
		}
		for(int i=1;i<=q;i++){
			long long r,c;
			bool ans=0;
			cin>>r>>c;
			for(int j=1;j<=n;j++){
				if(s[j][l[j]]==r&&na[j]<i+1){
					cout<<1<<endl;
					l[j]++;
					s[j][l[j]]=c;
					na[j]=i;
					ans=1;
					break;
				}
			}
			if(!ans)
				cout<<0<<endl;
		}
	}
}
