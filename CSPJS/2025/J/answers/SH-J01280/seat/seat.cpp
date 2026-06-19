#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n;
	cin >> m;
	int r;
	long long a[10010];
	for(int i = 1;i <= n*m;i+=1){
		cin >> a[i];
	}
	r = a[1];
	//
	
	//
	int sum = 0;
	for(int i = 1;i <= n*m;i+=1){
		if(a[i] > r){ 
			sum+=1;
		}
	}
	//
	int lie = 1;
	int hang = 1;
	while(sum >= 0){
		if(hang == n+1){
			hang-=n;
			lie+=1;
			if(lie%2 == 0){
				hang = n;
			}
			if(lie%2 == 1){
				hang = 1;
			}
		}else if(hang == 0){
			lie+=1;
			hang+=1;
			if(lie%2 == 0){
				hang = n;
			}
			if(lie%2 == 1){
				hang = 1;
			}
		}
		if(sum == 0) break;
		if(lie%2 == 0 && sum > 0){
			sum-=1;
			hang-=1;
		}else if(lie%2 == 1 && sum > 0){
			sum-=1;
			hang+=1;
		}
	}
	cout << lie << " " << hang;
	//
	return 0;
}
