#include<bits/stdc++.h>
using namespace std;
int w,n,a[100005];
bool cmp(int ha,int hb){
	return ha>hb;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> w;
	while(w--){
		ans=0;
		cin >> n;
		for(int i=0;i<n;i++){
			int x,y;
			cin >> a[i] >> y >> x;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n/2;i++)
		ans+=a[i];
		cout << ans << endl;
	}
	return 0;
}
