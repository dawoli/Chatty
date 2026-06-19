#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m,r,cnt=0;
	cin >> n>> m >> r;
	for(int i=2;i<=n*m;i++){
		int x=0;
		cin >> x;
		if(x>r){
			cnt++;
		}
	}
	if( (cnt/n+1)%2==0 ){
		cout << cnt/n+1 << " " << n-cnt%n << endl;
	}else{
		cout << cnt/n+1 << " " << cnt%n+1 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
