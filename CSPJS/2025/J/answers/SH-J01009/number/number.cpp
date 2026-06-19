#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;

int f[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length(),cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(f,f+l);
	for(int i=l-1;i>=0;i--){
		if(cnt==0)	break;
		else{
			cout<<f[i];
			cnt--;
		}
	}
	return 0;
} 

