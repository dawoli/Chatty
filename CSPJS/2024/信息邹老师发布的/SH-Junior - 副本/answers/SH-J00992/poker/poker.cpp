#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n;
	cin>>n;
	int youwu[57]={};
	for(int i=1;i<=n;i++){
		char poker[3];
		int num=0;
		cin>>poker[1]>>poker[2];
		if(poker[1]=='D'){
			num+=0;
		}else if(poker[1]=='C'){
			num+=13;
		}else if(poker[1]=='H'){
			num+=26;
		}else{
			num+=39;
		}
		if(poker[2]=='A'){
			num+=1;
		}else if(poker[2]=='T'){
		    num+=10;		
		}else if(poker[2]=='J'){
		    num+=11;		
		}else if(poker[2]=='Q'){
		    num+=12;		
		}else if(poker[2]=='K'){
		    num+=13;		
		}else{
			num+=poker[2]-48;
		}
		youwu[num]=1;
	} 
	int sum=52;
	for(int i=1;i<=52;i++){
		if(youwu[i]==1){
			sum--;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

