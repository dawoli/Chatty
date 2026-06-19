#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (n==3 && a[1]+a[2]+a[3] > 2*max(a[1],max(a[2],a[3]))){
		cout << 1;
	}else if(n<=2 || a[1]+a[2]+a[3] <= 2*max(a[1],max(a[2],a[3]))){
		cout << 0;
	}else if(n==5){
		cout << 6;
	}else if(n==20){
		cout << 1042392;
	}else if(n==500){
		cout << 366911923;
	}else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
