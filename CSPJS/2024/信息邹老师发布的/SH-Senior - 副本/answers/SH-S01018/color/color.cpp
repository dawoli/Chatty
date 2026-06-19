#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int a[100005];
		bool c[100005];
		int lp[1000005]{0};
		int top=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		c[1]=0;
		for(int i=1;i<=n;i++){
			lp[a[i]]++;
		}
		long long sum=0;
		for(int i=1;i<=1000000;i++){
			sum+=(lp[i]-1)*i;
		}
		cout << sum << endl;
	}
	return 0;
}
