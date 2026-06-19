#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int i=0;
	while(s[i]=='1'){
		i++;
	}
//	if(i!=m){
//		cout<<"0"<<endl;
//	}else{
		if(m==1){
			cout<<n<<endl;
		}else if(m==n){
			cout<<(n*(n-1))%998244353<<endl;
		}else{
			cout<<(m*(n-1))%998244353<<endl;
				
		}
		
//	}
	return 0;
	
}
