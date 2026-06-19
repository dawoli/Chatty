#include<iostream>
#include<cstring>
using namespace std;
int n,cnt;
string s;
bool p[60];
int tst(string s){
	int res=0;
	//s[0]
	if(s[0]=='D') res=39;
	else if(s[0]=='C') res=0;
	else if(s[0]=='H') res=26;
	else if(s[0]=='S') res=13;
	//s[1]
	if(s[1]>='2'&&s[1]<='9') res+=(int)(s[1]-'0');
	else if(s[1]=='A') res+=1;
	else if(s[1]=='T') res+=10;
	else if(s[1]=='J') res+=11;
	else if(s[1]=='Q') res+=12;
	else if(s[1]=='K') res+=13;
	return res;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(p,false,sizeof p);
	cin>>n;
	while(n--){
		cin>>s;
		p[tst(s)]=true;
	}
	for(int i=1;i<=52;i++){
		if(p[i]) cnt++;
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
