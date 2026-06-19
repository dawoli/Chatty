#include<bits/stdc++.h>
using namespace std;
int n;string t;
bool has[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>t;
		int num=0;
		if(t[0]=='D');
		if(t[0]=='H') num++;
		if(t[0]=='S') num+=2;
		if(t[0]=='C') num+=3;
		num*=13;
		if(t[1]=='A') num++;
		if('2'<=t[1]&&t[1]<='9') num+=t[1]-'0';
		if(t[1]=='T') num+=10;
		if(t[1]=='J') num+=11;
		if(t[1]=='Q') num+=12;
		if(t[1]=='K') num+=13;
		has[num]=1;
	}
	int cnt=0;
	for(int i=1;i<=52;i++){
		if(!has[i]) cnt++;
	}
	cout<<cnt<<endl;
}
