#include<iostream>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	short exist;
	cin>>exist;
	bool table[4][13];
	char f,points; 
	short cache;
	while(exist--){
		cin>>f>>points;
		switch(f){
			case 'D':cache=0;break;
			case 'C':cache=1;break;
			case 'H':cache=2;break;
			case 'S':cache=3;break;
		}
		switch(points){
			case 'A':table[cache][0]=true;break;
			case 'T':table[cache][9]=true;break;
			case 'J':table[cache][10]=true;break;
			case 'Q':table[cache][11]=true;break;
			case 'K':table[cache][12]=true;break;
			default:table[cache][points-'0'-1]=true;break;
		}
	}
	short ans=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(!table[i][j])ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

