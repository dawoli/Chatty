#include<bits/stdc++.h>
using namespace std;
long double t,n,m,math_count[10],sum;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	while(t--){
		memset(math_count,0,sizeof(math_count));
		sum=0; 
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				string s;
				cin>>s;
				math_count[i]+=(s=="math");
			}
			sum+=math_count[i];
		} 
		cin>>n>>m;
		if(n<=7){
			int j=m;
			long double ans=0;
			for(int i=1;i<=n;i++){
				if(j==6||j==7){
					j++;
					continue;
				}
				if(j==8){
					j=1;
				}
				ans+=math_count[j];
				j++;
			}
			cout<<fixed<<setprecision(0)<<ans<<endl;
		}
		else{
			long double ans=0;
			for(int i=m;i<=7;i++){
				if(i==6||i==7){
					n--;
					continue;
				}
				ans+=math_count[i];
				n--;
			}
			long double tmp=floor(n/7);
			ans+=tmp*sum;
			for(int i=1;i<=((int)(n)%7);i++){
				if(i==6||i==7){
					continue;
				}
				ans+=math_count[i];
			}
			cout<<fixed<<setprecision(0)<<ans<<endl;
		}
	}
	return 0;
}
