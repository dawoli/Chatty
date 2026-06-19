#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
int a[50005];
long long dps(int num,int mx,int sum){
	int an = 0;
		//	cout << num << ' ' << mx << ' ' << sum<<endl;
	if(mx*2 < sum+a[num]){	
		an++;
	}
	if(num == 0){
		//		cout << num << ' ' << mx << ' ' << sum+num<<endl;
		return 0;
	}
	//cout << num<< ' ';
	for(int i = num-1;i >= 1;i--){
		an += dps(i,mx,sum+a[num]);
	//	cout << i << ' '; 
	}
	return an;
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);

		for(int i = 3;i <= n;i++){
			ans += dps(i,a[i],0);
		//	cout << 1;
		//	cout  <<endl<<a[i]<< ":" << i << ":"<< ans<<endl;
	}
	cout << ans;
	return 0;
}
