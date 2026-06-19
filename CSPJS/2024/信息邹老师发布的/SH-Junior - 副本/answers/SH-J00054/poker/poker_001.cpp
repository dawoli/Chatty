#include<bits/stdc++.h>
using namespace std;
bool playingcard[100]={false};
int n;
string cardss;
int numm;
void play(string cards){
	if(cards[0]=='D'){
		if(cards[1]=='A'){
			playingcard[1]=true;
		}
		else if(cards[1]=='2'){
			playingcard[2]=true;
		}
		else if(cards[1]=='3'){
			playingcard[3]=true;
		}
		else if(cards[1]=='4'){
			playingcard[4]=true;
		}
		else if(cards[1]=='5'){
			playingcard[5]=true;
		}
		else if(cards[1]=='6'){
			playingcard[6]=true;
		}
		else if(cards[1]=='7'){
			playingcard[7]=true;
		}
		else if(cards[1]=='8'){
			playingcard[8]=true;
		}
		else if(cards[1]=='9'){
			playingcard[9]=true;
		}
		else if(cards[1]=='T'){
			playingcard[10]=true;
		}
		else if(cards[1]=='J'){
			playingcard[11]=true;
		}
		else if(cards[1]=='Q'){
			playingcard[12]=true;
		}
		else if(cards[1]=='K'){
			playingcard[13]=true;
		}
	}
	else if(cards[0]=='C'){
		if(cards[1]=='A'){
			playingcard[14]=true;
		}
		else if(cards[1]=='2'){
			playingcard[15]=true;
		}
		else if(cards[1]=='3'){
			playingcard[16]=true;
		}
		else if(cards[1]=='4'){
			playingcard[17]=true;
		}
		else if(cards[1]=='5'){
			playingcard[18]=true;
		}
		else if(cards[1]=='6'){
			playingcard[19]=true;
		}
		else if(cards[1]=='7'){
			playingcard[20]=true;
		}
		else if(cards[1]=='8'){
			playingcard[21]=true;
		}
		else if(cards[1]=='9'){
			playingcard[22]=true;
		}
		else if(cards[1]=='T'){
			playingcard[23]=true;
		}
		else if(cards[1]=='J'){
			playingcard[24]=true;
		}
		else if(cards[1]=='Q'){
			playingcard[25]=true;
		}
		else if(cards[1]=='K'){
			playingcard[26]=true;
		}
	}
	else if(cards[0]=='H'){
		if(cards[1]=='A'){
			playingcard[27]=true;
		}
		else if(cards[1]=='2'){
			playingcard[28]=true;
		}
		else if(cards[1]=='3'){
			playingcard[29]=true;
		}
		else if(cards[1]=='4'){
			playingcard[30]=true;
		}
		else if(cards[1]=='5'){
			playingcard[31]=true;
		}
		else if(cards[1]=='6'){
			playingcard[32]=true;
		}
		else if(cards[1]=='7'){
			playingcard[33]=true;
		}
		else if(cards[1]=='8'){
			playingcard[34]=true;
		}
		else if(cards[1]=='9'){
			playingcard[35]=true;
		}
		else if(cards[1]=='T'){
			playingcard[36]=true;
		}
		else if(cards[1]=='J'){
			playingcard[37]=true;
		}
		else if(cards[1]=='Q'){
			playingcard[38]=true;
		}
		else if(cards[1]=='K'){
			playingcard[39]=true;
		}
	}
	else if(cards[0]=='S'){
		if(cards[1]=='A'){
			playingcard[40]=true;
		}
		else if(cards[1]=='2'){
			playingcard[41]=true;
		}
		else if(cards[1]=='3'){
			playingcard[42]=true;
		}
		else if(cards[1]=='4'){
			playingcard[43]=true;
		}
		else if(cards[1]=='5'){
			playingcard[44]=true;
		}
		else if(cards[1]=='6'){
			playingcard[45]=true;
		}
		else if(cards[1]=='7'){
			playingcard[46]=true;
		}
		else if(cards[1]=='8'){
			playingcard[47]=true;
		}
		else if(cards[1]=='9'){
			playingcard[48]=true;
		}
		else if(cards[1]=='T'){
			playingcard[49]=true;
		}
		else if(cards[1]=='J'){
			playingcard[50]=true;
		}
		else if(cards[1]=='Q'){
			playingcard[51]=true;
		}
		else if(cards[1]=='K'){
			playingcard[52]=true;
		}
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cardss;
		play(cardss);
	}
	for(int i=1;i<=52;i++){
		if(playingcard[i]==false){
			numm++;
		}
	}
	cout<<numm<<endl;
	return 0;
}
