#include <bits/stdc++.h>
std::string s[60];
int n,ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>s[i];
		ans++;
		for(int j=i-1;j>=1;j--){
			if(s[j]==s[i]){
				ans--;
				break;
			}
		}
	}
	std::cout<<52-ans;
	return 0;
}
