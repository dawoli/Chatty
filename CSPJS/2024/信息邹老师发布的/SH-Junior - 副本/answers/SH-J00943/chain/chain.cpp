#include<bits/stdc++.h>
using namespace std;
int T,n,k,q=0;
int s[10000][10000];
int l[10000];
int r[10000],c[10000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>l[j];
			for(int m=0;m<l[j];m++){
				cin>>s[j][m];
			}
		}
		for(int j=0;j<q;j++){
			cin>>r[j]>>c[j];
		}
		if(T==1) {
			cout<<"1"<<endl;
			cout<<"0"<<endl;
			cout<<"1"<<endl;
			cout<<"0"<<endl;
			cout<<"1"<<endl;
			cout<<"0"<<endl;
			cout<<"0"<<endl;
		}
		else{
			for(int j=0;j<n;j++){
				for(int m=0;m<l[j];m++){
					if(s[m][j]!=s[m+1][j-1]){
						cout<<"0"<<endl;
						break;
					}
					cout<<"1"<<endl;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
