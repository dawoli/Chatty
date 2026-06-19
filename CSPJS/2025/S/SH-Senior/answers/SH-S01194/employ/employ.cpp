//摄影员精神 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int n,m;
bool k=1;
string s;
int arr[510]={};
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='1')k=0;
		cin>>arr[i];
	}
	if(k==1){
		int Aans=1;
		for(int i=2;i<=n;i++){
		    Aans*=i;
		    Aans%=MOD;
		}
		cout<<Aans;
		return 0;
	}
	return 0;
}
