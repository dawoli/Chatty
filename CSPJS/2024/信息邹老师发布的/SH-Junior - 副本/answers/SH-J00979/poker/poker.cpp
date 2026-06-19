#include<bits/stdc++.h>
using namespace std;
int n;
bool pok[60];
int ans=52;
char card[2];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	memset(pok,0,sizeof(pok));
	while(n--){
		for(int j=0;j<2;j++){
			cin>>card[j];
		}
		int sum=1;
		if(card[0]=='D'){
			sum+=0;
		}
		if(card[0]=='C'){
			sum+=13;
		}
		if(card[0]=='H'){
			sum+=26;
		}
		if(card[0]=='S'){
			sum+=39;
		}
		if(card[1]=='A'){
			sum++;
		}
		if(card[1]>='2'&&card[1]<='9'){
			sum+=int(card[1]-'0');
		}
		if(card[1]=='J'){
			sum+=10;
		}
		if(card[1]=='Q'){
			sum+=11;
		}
		if(card[1]=='K'){
			sum+=12;
		}
		if(!pok[sum]){
			ans--;
			pok[sum]=1;
		}
	}
	cout<<ans;
	return 0;
}
