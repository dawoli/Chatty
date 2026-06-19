#include <bits/stdc++.h>
using namespace std;
long long n,a1;
long long a[5050],maxn,c,d =1;
long long maxm = 998244353;
long long num = 0;
bool ju = true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n-2;i++){
		if(ju == true){
			c =  a[i] + a[i+1] + a[i+2];
			maxn = max(max(a[i],a[i+1]),a[i+2]);
			
			ju = false;
		}
		if(c > maxn*2){
			num+=1;
		}
		for(int j = i;j<=n-3;j++){
			maxn = max(maxn,a[i+2+j]);
			if((c+a[i+1+j]) > 2*maxn){
				num+=1;
			}
			maxn = max(max(a[i],a[i+1]),a[i+2]);
		}
		c = a[i] + a[i+1] + a[i+2] + a[i+2+d];
		maxn = max(maxn,a[i+2+d]);
		d+=1;
	}
	cout << num % maxm;
	return 0;
} 
