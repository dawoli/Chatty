#include <bits/stdc++.h>
using namespace std;
int ans,t,n,rnd,i,o,p,th;
int a[200001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	for (rnd=0;rnd<t;rnd++){
		ans = 0;
		cin >> n;
		for (i=0;i<n;i++){
			cin >> a[i];
		}
		for (i=0;i<n-1;i++){
			th = a[i];
			for (p=i+1;p<n;p++){
				if (th == a[p]){
					ans += th;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

 
