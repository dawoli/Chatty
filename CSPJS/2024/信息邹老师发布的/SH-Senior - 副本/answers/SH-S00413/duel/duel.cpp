#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,ans = 0;
int a[N];
bool alive[N];
bool att[N];

deque<int> alv;

bool cansolve1(){
	if (n <= 100) return 1;
	else return 0;
}
void solve1(){
	sort(a+1,a+1+n);
	for (int i = 2;i <= n;i++){
		for (int j = i-1;j >= 1;j--){
			if (a[j] < a[i] && alive[j] && att[i] && alive[j]){
				alive[j] = 0;
				att[i] = 0;
			}
		}
	}
	for (int i = 1;i <= n;i++){
		if (alive[i]) ans++;
	}
}

bool cansolve2(){
	for (int i = 1;i <= n;i++){
		if (a[i] > 2) return 0;
	}
	return 1;
}
void solve2(){
	int n1 = 0,n2 = 0;
	for (int i = 1;i <= n;i++){
		if (a[i] == 1) n1++;
		else n2++;
	} 
	if (n1 <= n2) ans = n2;
	else ans = n-n2;
}
void solve(){
	sort(a+1,a+1+n);
	for (int i = 1;i <= n;i++){
		if (!alv.empty() && *alv.begin() < a[i]){
			alv.pop_front();
		}
		alv.push_back(a[i]);
	}
	ans = (int)alv.size();
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		alive[i] = 1;
		att[i] = 1;
	}
	if (cansolve1()) solve1();
	else if (cansolve2()) solve2();
	else solve();
	
	cout<<ans<<endl;
	return 0;
}
