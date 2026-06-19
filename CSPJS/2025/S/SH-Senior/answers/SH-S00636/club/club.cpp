#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

int t;
struct node{
	ll x,y,z,ax,ay,az;
};
bool cmp1(node x,node y){
	if(x.ax != y.ax) return x.ax < y.ax;
	return max(x.ay,x.az) > max(y.ay,y.az);
}
bool cmp2(node x,node y){
	if(x.ay != y.ay) return x.ay < y.ay;
	return max(x.ax,x.az) > max(y.ax,y.az);
}
bool cmp3(node x,node y){
	if(x.az != y.az) return x.az < y.az;
	return max(x.ax,x.ay) > max(y.ax,y.ay);
}
void solve(){
	int n;
	ll sum = 0,c1 = 0,c2 = 0,c3 = 0;
	cin >> n;
	vector<node> a1,a2,a3;
	for(int i = 1;i <= n;i++){
		ll u,v,w;
		cin >> u >> v >> w;
		node o;
		o.x = u,o.y = v,o.z = w;
		o.ax = u - max(v,w),o.ay = v - max(u,w),o.az = w - max(u,v);
		if(o.ax > max(o.ay,o.az)){
			a1.push_back(o);
		}
		else if(o.ay > o.az){
			a2.push_back(o);
		}
		else{
			a3.push_back(o);
		}
	}
	while(!a1.empty() || !a2.empty() || !a3.empty()){
		sort(a1.begin(),a1.end(),cmp1);
		for(int i = a1.size() - 1;i >= 0 && c1 < n / 2;i--,c1++){
			sum += a1[i].x;
			a1.pop_back();
		}
		while(!a1.empty()){
			for(int it = a1.size() - 1;it >= 0;it--){
				auto i = a1[it];
				if((i.ay > i.az && c2 < n / 2) || c3 >= n / 2) a2.push_back(i);
				else a3.push_back(i);
				a1.pop_back();
			}
		}
		sort(a2.begin(),a2.end(),cmp2);
		for(int i = a2.size() - 1;i >= 0 && c2 < n / 2;i--,c2++){
			sum += a2[i].y;
			a2.pop_back();
		}
		while(!a2.empty()){
			for(int it = a2.size() - 1;it >= 0;it--){
				auto i = a2[it];
				if((i.ax > i.az && c1 < n / 2) || c3 >= n / 2) a1.push_back(i);
				else a3.push_back(i);
				a2.pop_back();
			}
		}
		sort(a3.begin(),a3.end(),cmp3);
		for(int i = a3.size() - 1;i >= 0 && c3 < n / 2;i--,c3++){
			sum += a3[i].z;
			a3.pop_back();
		}
		while(!a3.empty()){
			for(int it = a3.size() - 1;it >= 0;it--){
				auto i = a3[it];
				if((i.ax > i.ay && c1 < n / 2) || c2 >= n / 2) a1.push_back(i);
				else a2.push_back(i);
				a3.pop_back();
			}
		}
	}
	cout << sum << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
