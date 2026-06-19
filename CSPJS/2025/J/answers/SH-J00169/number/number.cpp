#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char p[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=1;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			p[cnt]=s[i];
			cnt++;
		}
	}
	sort(p+1,p+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<p[i];
	}
	return 0;
}
