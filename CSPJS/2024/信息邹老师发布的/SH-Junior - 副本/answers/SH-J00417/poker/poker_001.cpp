#include <bits/stdc++.h>
using namespace std;
int n,m,ans=52;
string a[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		string b;
		bool flag=false;
		cin>>b;
		for(int i=0;i<m;i++){
			if(a[i]==b) {
				flag=true;
				break;
			}
		}
		if(!flag){
			a[m]=b;
			ans--,m++;
		}
	}
	cout<<ans;
	return 0;
} 
