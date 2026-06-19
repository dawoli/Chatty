#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> a[i];
	int s = a[1];	
	sort(a+1,a+1+n*m);
	
	int cnt = 0;
	for(int i = n*m;i >= 1;i--){
		cnt++;
		b[cnt] = a[i];
	}
	int num = 0;
	int c,r,r1; 
	int x;
	for(int i = 1;i <= n*m;i++){  //¶Ôb±éÀú 
		num++;
		if(b[i] == s){
			r1 = num%(n*2);
			if(r1 > n){
				r = n*2-r1+1;
				x = r1-n;
			}else{
				r= r1;
				x = r1;
			}
			
			c = (num-x)/n +1;
			break;
		}
		
	}

	cout <<c << " " << r;
	return 0;
} 
