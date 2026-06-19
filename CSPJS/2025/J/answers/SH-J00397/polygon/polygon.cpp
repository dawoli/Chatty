#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int l;
	int max;
	long long xnt;
	int a[10010];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>a[i+1]){
			max=a[i];
		}
		l += a[i];
	}
	//cout << max ;
	//cout << l;
	if(n>=3 && l>(max*2)){
		xnt++;
	}
	cout << xnt;
	return 0;
}
