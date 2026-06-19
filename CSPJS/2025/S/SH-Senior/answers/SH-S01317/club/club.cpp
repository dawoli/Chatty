#include<bits/stdc++.h>
using namespace std;
int n ;
const int N  =1e5 + 9;
struct person{
	int a[3];
}p[N];
vector <int> c[3];
bool cmp(const person &a,const person &b){
	return max(a.a[0],max(a.a[1],a.a[2])) > max(b.a[0],max(b.a[1],b.a[2]));
}
void solve(){
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++){
		cin >> p[i].a[0] >> p[i].a[1] >> p[i].a[2];
		sum += max(p[i].a[0],max(p[i].a[1],p[i].a[2]));
	}
	cout << sum << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) 
		solve();
	return 0; 
} 
