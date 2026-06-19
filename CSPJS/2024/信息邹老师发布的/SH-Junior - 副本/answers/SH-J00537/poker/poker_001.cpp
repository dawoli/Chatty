#include<bits/stdc++.h>
using namespace std;
int ans=52;
bool checkk[100][100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char col,num;
		cin>>col>>num;
		checkk[int(col)][int(num)]=true;
	}
	int cnt=0;
	for(int i=1;i<=99;i++){
		for(int j=1;j<=99;j++){
			if(checkk[i][j]) cnt++;
		}
	}
	cout<<ans-cnt<<endl;
}
