#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[100005],b[100005],c[100005];
struct node{
	int s,t,id;
	bool operator <(const node &x)const{
		return s > x.s;
	}
};
priority_queue<node> q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		ans = 0;
		for (int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] >= b[i] and a[i] >= c[i])
				q1.push({a[i]-max(b[i],c[i]),a[i],i});
			else if (b[i] >= a[i] and b[i] >= c[i])
				q2.push({b[i]-max(a[i],c[i]),b[i],i});
			else if (c[i] >= a[i] and c[i] >= b[i])
				q3.push({c[i]-max(a[i],b[i]),c[i],i});
		}
		while (!(q1.empty())){
			if (q1.size() > n/2) ans -= q1.top().s;
			ans += q1.top().t;
			q1.pop();
		}
		while (!(q2.empty())){
			if (q2.size() > n/2) ans -= q2.top().s;
			ans += q2.top().t;
			q2.pop();
		}
		while (!(q3.empty())){
			if (q3.size() > n/2) ans -= q3.top().s;
			ans += q3.top().t;
			q3.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
