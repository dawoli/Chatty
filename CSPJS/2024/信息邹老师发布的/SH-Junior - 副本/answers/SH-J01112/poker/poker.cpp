#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string s[n+1];
	int ans=52-n;
	string a;
	for(int i=0;i<=n;i++){
		getline(cin,a);
		s[i]=a;
		for(int j=0;j<i;j++){
			if(s[i]==s[j]){
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
