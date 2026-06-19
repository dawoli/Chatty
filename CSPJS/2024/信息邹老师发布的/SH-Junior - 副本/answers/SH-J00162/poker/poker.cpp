#include<bits/stdc++.h>
using namespace std;
int main(){
	//*
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	/**/
	int n,itype,ivalue,ans=0;
	bool poker[9][18];
	for(int i=0;i<9;i++){
	    for(int j=0;j<18;j++){
	    	poker[i][j]=false;
		}
	}
	cin>>n;
	char type,value;
	for(int i=0;i<n;i++){
		cin>>type>>value;
		switch(type){
			case 'D':
				itype=1;
				break;
			case 'C':
				itype=2;
				break;
			case 'H':
				itype=3;
				break;
			case 'S':
				itype=4;
				break;
			default:
				cout<<"你不是说合法的吗QAQ"<<endl;
				return 0;
		}
		if('2'<=value&&value<='9'){
			ivalue=value-'0';
		}else
		switch(value){
			case 'A':
				ivalue=1;
				break;
			case 'T':
				ivalue=10;
				break;
			case 'J':
				ivalue=11;
				break;
			case 'Q':
				ivalue=12;
				break;
			case 'K':
				ivalue=13;
				break;
			default:
				cout<<"你不是说合法的吗QAQ"<<endl;
				return 0;
		}
		if(!poker[itype][ivalue]){
			poker[itype][ivalue]=true;
			ans++;
		}
	}
	cout<<52-ans;
}
