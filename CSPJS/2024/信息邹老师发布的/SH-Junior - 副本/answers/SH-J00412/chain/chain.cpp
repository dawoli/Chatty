#include<bits/stdc++.h>

using namespace std;
int t;
int a[100007][2007];
int l[100007];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l[j];
			for(int h=1;h<=l[j];h++){
				cin>>a[j][h];
			}
		}
		for(int g=1;g<=q;g++){
			int r,c;
			cin>>r>>c;
			if(r==1){
				bool flag=0;
				for(int b=1;b<=n;b++){
					if(flag==1){
						break;
					} 
					int onenum=-1;
					int cnum=-1;
					for(int j=1;j<=l[b];j++){
						if(a[b][j]==1){
							onenum=j;
						}
						if(a[b][j]==c){
							cnum=j;
						}
						if(onenum!=-1&&cnum!=-1&&cnum>onenum&&cnum-onenum+1<=k){
							cout<<"1"<<endl;
							flag=1;
							break;
						}
					}
				}
				if(flag==0){
					cout<<"0"<<endl;
				}
			}	
			else{
				cout<<"0"<<endl;
			}
		}
	}
	return 0;
} 
