#include <iostream> 
#include <cstdio>
using namespace std;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])) cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++) cout<<i;
	}
	return 0;
}
