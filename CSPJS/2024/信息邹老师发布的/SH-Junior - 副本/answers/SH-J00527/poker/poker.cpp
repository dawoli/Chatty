#include<bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
char cards[55][2];
	
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cards[i];
		for(int j=1;j<i;j++){
			if(cards[i][0]==cards[j][0]&&cards[i][1]==cards[j][1]){
				cnt++;
			}
		}
	}
	cout<<52+cnt-n;
	return 0;
} 
