#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ll n , k , a[5009] , cnt1 = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    	if(a[i] == 1){
    		cnt1++;
		}
	}
	if(cnt1 == n){
		if(k == 0){
			if(n % 2 == 0){
				cout<< n <<endl;
				return 0;
			}else{
				cout<< n - 1 << endl;
				return 0;
			}
		}else if(k == 1){
			if(n % 2 == 1){
				cout<< n <<endl;
				return 0;
			}else{
				cout<< n - 1 << endl;
				return 0;
			}
		}
	}
	return 0;
}//^1µ¥Êý 1Ë«Êý0 
