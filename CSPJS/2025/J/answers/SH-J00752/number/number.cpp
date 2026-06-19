#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int l=s.size(),t=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	for(int i=1;i<=t;i++){
		if(a[i]==9) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==8) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==7) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==6) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==5) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==4) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==3) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==2) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==1) cout<<a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]==0) cout<<a[i];
	}
	return 0;
}

