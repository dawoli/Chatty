#include<bits/stdc++.h>
using namespace std;
int r[101000] , a[101000] , ri;
int main(){
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	int n,maxx=0,j=0,ret=0,sum=0,sec=0,minn=999999;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> ri;
		a[i] = ri;
		if(r[ri] == 0){
			sum++;
		}
		r[ri]++;
		if(maxx < ri){
			maxx = ri;
			sec = maxx;
		}if(minn > ri){
			minn = ri;
		}
	}if(sum == n){
		cout << 1;
		return 0;
	}if(maxx == 1){
		cout << r[1];
		return 0;
	}
	if(maxx == 2){
		if(r[1] >= r[2]){
			cout << abs(r[1]-r[2])+r[2];
		}else{
			cout << abs(r[1]-r[2])+r[1];
		}return 0;
	}if(n<=30){
		if(sum >= 3){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(a[i] != a[j]){
						for(int k=i;k<n;k++){
							a[k] = a[k+1];
						}for(int h=j;h<n;h++){
							a[h-1] = a[h];
						}
						ret++;
					}
				} 
			}if(r[maxx] = 1) cout << ret - r[maxx];
			else cout << ret - r[sec];
		}else if(sum <= 2){
			if(r[minn] >= r[maxx]){
				cout << abs(r[maxx] - r[minn]) + r[maxx];
			}else{
				cout << abs(r[maxx] - r[minn]) + r[minn];
			}	
		}
	}
	return 0;
}
