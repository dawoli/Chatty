#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[8],nn,an,ans;
string s;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		for(int i=0;i<=7;i++){
			a[i]=0;
		}
		an=0;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin>>s;
				if(s=="math"){
					a[i]++;
					an++;
				}
			}
		}
		cin>>n>>m;
		ans+=an*(n/7);
		n%=7;
		for(int i=1;i<=n;i++){
			if(i+m>8){
				m-=7;
			}
			ans+=a[i+m-1];
		}
		cout<<ans<<endl;
	}
} 
