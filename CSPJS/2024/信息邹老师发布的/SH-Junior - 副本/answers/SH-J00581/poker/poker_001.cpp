#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
char s[62][12];
int main(){
	freopen("poker.in","r","in");
	freopen("poker.out","w","out");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		ans-=1;
		for(int j=-1;j<i;j++){
			if(s[i][1]==s[j][1]){
				if(s[i][0]==s[i][0]){
					ans+=1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
