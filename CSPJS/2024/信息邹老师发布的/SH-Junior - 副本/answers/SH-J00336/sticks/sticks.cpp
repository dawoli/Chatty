#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
string f[110];
ll n,T;
inline void solve(){
	cin>>n;
	if(n<=21&&f[n]=="-1"){
		cout<<-1<<endl;
		return;
	}
	vector<ll> ans;
	while(n>=22){
		ans.push_back(8);
		n-=7;
	}
	for(auto c:f[n])
		ans.push_back(c-'0');
	sort(ans.begin(),ans.end());
	for(ll i=0;i<ans.size();i++)
		if(ans[i]){
			swap(ans[0],ans[i]);
			break;
		}
	for(auto x:ans)
		cout<<x;
	cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	f[0]="-1",f[1]="-1",f[2]="1",f[3]="7",f[4]="4",f[5]="2",f[6]="6",f[7]="8";
	f[8]="10",f[9]="18",f[10]="22",f[11]="20",f[12]="28",f[13]="80",f[14]="88";
	f[15]="108",f[16]="188",f[17]="200",f[18]="208",f[19]="288",f[20]="808",f[21]="888";
	cin>>T;
	while(T--)
		solve();
	return 0;
}
