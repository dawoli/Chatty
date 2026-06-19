#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b , k[109] , R , c=1,r=1;
bool cmp(const int &a,const int &b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> a >> b;
	for(int i = 1;i <= a * b; i++){
		cin >> k[i];
	}
	R = k[1];
	sort(k+1,k + a*b + 1,cmp);
	for (int i = 1;i <= a*b; i++){
		if (k[i] == R){
			cout << r << " " <<  c;
			return 0;
		}
		if (r % 2 == 1){
			c++;
		}else{
			c--;
		}
		if(c > a || c < 1){
			if (r % 2 == 1){
				c--;
			}else{
				c++;
			}
			r++;
		}
	}
	return 0;
}
