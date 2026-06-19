#include<bits/stdc++.h>
using namespace std;

bool ext[100][50];
//extij表示数字i 花色j是否出现过
//D:1
//C:2
//H:3
//S:4 


int n;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout); 
	int ans=52;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int num,cor;//第一位是颜色 
		if(s[1]=='A')num=1;
		else if(s[1]=='T')num=10;
		else if(s[1]=='J')num=11;
		else if(s[1]=='Q')num=12;
		else if(s[1]=='K')num=13;
		else num=int(s[1]-'0');
		
		if(s[0]=='D')cor=1;
		if(s[0]=='C')cor=2;
		if(s[0]=='H')cor=3;
		if(s[0]=='S')cor=4;
		
		//cout<<num<<" "<<cor<<"\n";
		
		if(not ext[num][cor]){
			ans--;
		}
		ext[num][cor]=1;
		
	}
	cout<<ans;
}
/*
4
DQ
H3
DQ
DT
*/
