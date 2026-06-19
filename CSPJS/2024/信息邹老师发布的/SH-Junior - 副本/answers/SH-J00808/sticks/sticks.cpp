#include<bits/stdc++.h>
using namespace std;
int t,n,l,s[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int l=(n+6)/7,flag=0;	
		if(l==1){
			switch(n){
				case 1:cout<<"-1\n";break;
				case 2:cout<<"1\n";break;
				case 3:cout<<"7\n";break;
				case 4:cout<<"4\n";break;
				case 5:cout<<"2\n";break;
				case 6:cout<<"6\n";break;
				case 7:cout<<"8\n";break;
			}
			continue;
		}
		for(int i=1;i<=9&&flag==0;i++){
			if(s[i]+(l-1)*7>=n){
				flag=i;
			}
		}
		int rem=(s[flag]+(l-1)*7)-n;
		cout<<flag;
		for(int i=l-1;i>=1;i--){
			if(rem==0){
				cout<<"8";
			}
			else if(rem>1&&i==1){
				int rem2=7-rem;
				for(int j=0;j<=9;j++){
					if(rem2==s[j]){
						cout<<j;j=10;
					}
				}
			}
			else{
				cout<<"0";rem--;
			}
		}
		cout<<endl;
	}
	return 0;
}
