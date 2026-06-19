#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	int n,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}

