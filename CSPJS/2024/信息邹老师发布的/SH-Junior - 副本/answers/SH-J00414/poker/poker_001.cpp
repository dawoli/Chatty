#include<bits/stdc++.h>
using namespace std;
bool card[5][15];
short ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	short n;
	cin>>n;
	while(n--){
		char a,b;cin>>a>>b;
		short p,q;
		if(a=='C')p=1;
		else if(a=='D')p=2;
		else if(a=='H')p=3;
		else if(a=='S')p=4;
		if(b=='A')q=1;
		else if(b=='2')q=2;
		else if(b=='3')q=3;
		else if(b=='4')q=4;
		else if(b=='5')q=5;
		else if(b=='6')q=6;
		else if(b=='7')q=7;
		else if(b=='8')q=8;
		else if(b=='9')q=9;
		else if(b=='T')q=10;
		else if(b=='J')q=11;
		else if(b=='Q')q=12;
		else if(b=='K')q=13;
		if(card[p][q]==0){
			ans--;
			card[p][q]=1;
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
