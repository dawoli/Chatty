#include<bits/stdc++.h>
using namespace std;
const int N=59;
string po[N];
int cnt[N][N],cn;//i号花色数字为j的扑克牌个数 
//1为D，2为C，3为H，4为S 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>po[i];
	for(int i=1;i<=n;i++){
		char f=po[i][0];
		char num=po[i][1];
		int id,nu;
		if(num=='T') nu=10;
		else if(num=='J') nu=11;
		else if(num=='Q') nu=12;
		else if(num=='K') nu=13;
		else if(num=='A') nu=1;
		else nu=num-'0';
		if(f=='D') id=1;
		else if(f=='C') id=2;
		else if(f=='H') id=3;
		else id=4;
		cnt[id][nu]++;
	} 
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!cnt[i][j]) cn++;
		}
	}
	cout<<cn;
	return 0;
}
