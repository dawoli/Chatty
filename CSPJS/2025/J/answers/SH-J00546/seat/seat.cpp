#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
ll a[N];
ll n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int mix = n*m;
	for(ll i=1; i<=mix; i++){
		cin >> a[i];
	}
	int xr = a[1];
	sort(a+1,a+mix+1,greater<long long>());
	for(ll i=1; i<=mix; i++){
		if(a[i]==xr)	xr = i;
	}
	if(xr==1){
		cout << "1 1" << endl;
		return 0;
	}
	int flag = 0; 
	for(int i=1,j=1,z=2;;z++){
		if(flag==0){
			if(j>=n){
				i++;
				j=n;
				flag = 1;
			}else{
				j++;
			}
		}else if(flag==1){
			if(j<=1){
				i++;
				j=1;
				flag = 0;
			}else{
				j--;
			}
		}
		if(z==xr){
			cout << i << " " << j;
			break;
		}
	}
	return 0;
}
