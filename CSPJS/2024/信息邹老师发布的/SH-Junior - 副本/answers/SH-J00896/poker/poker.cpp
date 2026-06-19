#include<bits/stdc++.h>
using namespace std;
int n;
int b[55];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	string s;
	while(n--){
		cin>>s;
		int a=1;
		if(s[0]=='C') a+=13;
		if(s[0]=='H') a+=26;
		if(s[0]=='S') a+=39;
		if(isdigit(s[1])){
			a+=s[1]-'0'-1;
		} 
		else if(s[1]=='T'){
			a+=9;
		}
		else if(s[1]=='J'){
			a+=10;
		}
		else if(s[1]=='Q'){
			a+=11;
		}
		else if(s[1]=='K'){
			a+=12;
		}
		b[a]++;
	}
	int cnt=0;
	for(int i=1;i<=52;i++){
		if(!b[i])cnt++;
	}
	printf("%d",cnt);
	return 0;
}
