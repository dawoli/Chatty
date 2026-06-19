#include <bits/stdc++.h>
using namespace std;
int n,cnt;
char s[50][5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i];
		++cnt;
		for(int j=0;j<i;++j){
			if(strcmp(s[i],s[j])==0){
				--cnt;
				break;
			}
		}
	}
	cout<<52-cnt<<endl;
	return 0;
}
