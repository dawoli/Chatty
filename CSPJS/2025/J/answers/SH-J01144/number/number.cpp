#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
string s;
int t[105];
signed main(){//number
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
