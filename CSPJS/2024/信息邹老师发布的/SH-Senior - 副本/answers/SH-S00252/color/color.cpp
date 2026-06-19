#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool v[200010];
int n;
int posr,posb;
long long cal(int num){
	long long res=0;
	posr=0;
	posb=0;
	for(int i=1;i<=n;i++){
		v[i]=num%2;
		num/=2;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			res+=(a[i]==a[posr])*a[i];
			posr=i;
		}
		else{
			res+=(a[i]==a[posb])*a[i];
			posb=i;
		}
	}
	return res;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.our","w",stdout);
	int t;
	cin >> t;
	while(t--){
		long long ans=0;
		cin >> n;
		if(n<=15){//1-4
			for(int i=1;i<=n;i++){
				cin >> a[i];
			}
			for(int i=0;i<1<<n;i++){
				ans=max(ans,cal(i));
			}
			cout << ans << endl;
		}
		else{//other
			for(int i=1;i<=n;i++){
				cin >> a[i];
			}
			
		}
	}
		

	return 0;
}

