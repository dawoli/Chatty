#include<bits/stdc++.h>
using namespace std;
long long int a[8];
string b;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	long long int t;
	cin >> t;
	while(t--){
		long long int n,m,i,j,s,x,y,ans,ss;
		ss=0;
		for(i=1; i<=5; i++){
			a[i]=0;
			for(j=0; j<8; j++){
				cin >> b;
				if(b=="math")
					a[i]++;
			}
			ss+=a[i];
//			printf("%lld\n",a[i]);
		}
		cin >> m >> n;
		s=m;
		x=7-n+1;
		s-=x;
		ans=0;
		for(i=n; i<=7; i++)
			ans+=a[i];
		y=s%7;
		s-=y;
		for(i=1; i<=y; i++)
			ans+=a[i];
		ans+=(ss*(s/7));
		cout << ans << "\n";
	}	
	return 0;
} 
