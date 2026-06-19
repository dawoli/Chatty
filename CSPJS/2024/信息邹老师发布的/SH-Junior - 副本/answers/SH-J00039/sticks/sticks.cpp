#include <bits/stdc++.h>
using namespace std;
    int t,n[51];
    int main(){
    	freopen ("sticks.in","r",stdin);
    	freopen ("sticks.out","w",stdout);
    	cin>>t;
    	for (int i=1;i<=t;i++){
    		cin>>n[i];
		}
		for (int i=1;i<=t;i++){
			if (n[i]<8){
				if (n[i]==1) cout<<"-1";
				else if (n[i]==2) cout<<"1";
				else if (n[i]==3) cout<<"7";
				else if (n[i]==4) cout<<"4";
				else if (n[i]==5) cout<<"2";
				else if (n[i]==6) cout<<"9";
				else cout<<"8";
			}
			else if (n[i]==8) cout<<"10";
				else if (n[i]==9) cout<<"18";
				else if (n[i]==10) cout<<"25";
				else if (n[i]==11) cout<<"20";
				else if (n[i]==12) cout<<"28";
				else if (n[i]==13) cout<<"80";
				else if (n[i]==16) cout<<"188";
				else if (n[i]==17) cout<<"200";
				else if (n[i]==18) cout<<"208";
				else if (n[i]==19) cout<<"288";
				else if (n[i]==20) cout<<"688";
			else if (n[i]%7==0){
				for (int j=1;j<=n[i]/7;j++){
					cout<<"8";
				}
			}
			else if (n[i]%7==1){
				cout<<"10";
				for (int j=1;j<=n[i]/7-1;j++){
					cout<<"8";
				}
			}
			else if (n[i]%7==2){
				cout<<"1";
				for (int j=1;j<=n[i]/7;j++){
					cout<<"8";
				}
			}
			else if (n[i]%7==3){
				cout<<"200";
				for (int j=1;j<=n[i]/7-2;j++){
					cout<<"8";
				}
			}
			else if (n[i]%7==4){
				cout<<"20";
				for (int j=1;j<=n[i]/7-1;j++){
					cout<<"8";
				}
			}
			else if (n[i]%7==5){
				cout<<"2";
				for (int j=1;j<=n[i]/7;j++){
					cout<<"8";
				}
			}
			else if (n[i]%7==6){
				cout<<"6";
				for (int j=1;j<=n[i]/7;j++){
					cout<<"8";
				}
			}
				
			else cout<<"-1";
			if (i!=t) cout<<endl;
		}
    	return 0;
	}
