#include <bits/stdc++.h>
using namespace std;
int n,ans; 
string s[10010];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	getline(cin,s[0]);
	for(int i=1;i<=n+1;i++){
		getline(cin,s[i]);
	}
	for(int i=1;i<=n+1;i++){
		for(int j=2;j<=n+1;j++){
			if(s[i][1]==s[j][1]){
				if(s[i][2]==s[j][1]){
					ans++;
				}
			}
		}
	}
	int cnt=n-ans;
//	cout<<n<<" "<<ans<<" "<<cnt<<" ";
	cout<<52-cnt<<endl;
	return 0;
}
