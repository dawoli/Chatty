#include<bits/stdc++.h>
using namespace std;
int pai[100][100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		char huase,dianshu;
		cin>>huase>>dianshu;
		pai[huase][dianshu]=1;
	}
	int ans=52;
	for(int i=1;i<=90;i++){
		for(int j=1;j<=90;j++){
			ans-=pai[i][j];
		}
	}
	cout<<ans;
	return 0;
}
