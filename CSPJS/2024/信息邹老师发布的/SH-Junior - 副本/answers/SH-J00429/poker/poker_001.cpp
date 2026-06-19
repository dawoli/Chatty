#include<bits/stdc++.h>
using namespace std;
int Poker[60],n,ans=52;
string s;
void addPoker(){
	cin>>s;
	int num=0;
	if(s[0]=='C') num+=13;
	else if(s[0]=='H') num+=26;
	else if(s[0]=='S') num+=39;
	if(s[1]=='T') num+=9;
	else if(s[1]=='J') num+=10;
	else if(s[1]=='Q') num+=11;
	else if(s[1]=='K') num+=12;
	else if(s[1]!='A') num+=s[1]-'1';
	Poker[num]=1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--) addPoker();
	for(int i=0;i<52;i++) ans-=Poker[i];
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
