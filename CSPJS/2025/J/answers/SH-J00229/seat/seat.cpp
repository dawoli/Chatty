#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n , m , a[1009] , r;
	cin>> n >> m;
	ll cnt = n * m;
	for(int i = 1;i <= cnt;i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + 1 + cnt);
	ll num;
	for(int i = cnt;i >= 1;i--){
		if(a[i] == r){
			num = cnt - i + 1;
		}
	}
	ll ansm , ansn;//Са
	if(num % n == 0){
		ansm = num / n;
		ansn = n;
		cout << ansm << " " << ansn;
		return 0;
	}else{
		ansm = num / n + 1;
		ll b = num % n;//ЪЃ 
	    if(ansm % 2 == 0){
		    ansn = n - b + 1;
	    }else{
		    ansn = b;
	    }
	    cout << ansm <<" "<< ansn;
	    return 0;
	}
	return 0;
} 
