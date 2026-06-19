#include<bits/stdc++.h>
using namespace std;
const int Max_n=60;
int n,cnt,ans;
string s[Max_n];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cnt++;
		for(int j=i-1;j>=1;j--){
			if(s[j]==s[i]){
				cnt--;
				break;
			}
		}
	}
	ans=52-cnt;
	cout<<ans<<endl;
	return 0;
}
