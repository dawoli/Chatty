#include<bits/stdc++.h>
using namespace std;
int n,d[20],c[20],h[20],s[20],cnt;
char color,number;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>color>>number;
		if(number<65)number-=49;
		else if(number=='T')number-=75;
		else if(number=='J')number-=64;
		else if(number=='Q')number-=70;
		else if(number=='K')number-=63;
		else number-=65;
		if(color=='D')d[number]=1;
		else if(color=='C')c[number]=1;
		else if(color=='H')h[number]=1;
		else s[number]=1;
	}
	if(n==1){
		cout<<"51";
		return 0;
	}
for(int i=0;i<13;i++){
		if(d[i]==0)cnt++;
		if(c[i]==0)cnt++;
		if(h[i]==0)cnt++;
		if(s[i]==0)cnt++;
	}
	cout<<cnt;
	return 0;
}
