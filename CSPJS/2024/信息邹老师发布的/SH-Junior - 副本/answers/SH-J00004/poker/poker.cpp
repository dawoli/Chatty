#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,arr[4][13],index1,index2,count=0;
	string Middle;
	cin>>n;
	for(int j=0;j<4;j++){
		for(int k=0;k<13;k++){
			arr[j][k]=0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>Middle;

		if(Middle[1]=='A') index1=0;
		else if(Middle[1]=='T') index1=9;
		else if(Middle[1]=='J') index1=10;
		else if(Middle[1]=='Q') index1=11;
		else if(Middle[1]=='K') index1=12;
		else if(Middle[1]=='1') index1=0;
		else if(Middle[1]=='2') index1=1;
		else if(Middle[1]=='3') index1=2;
		else if(Middle[1]=='4') index1=3;
		else if(Middle[1]=='5') index1=4;
		else if(Middle[1]=='6') index1=5;
		else if(Middle[1]=='7') index1=6;
		else if(Middle[1]=='8') index1=7;
		else if(Middle[1]=='9') index1=8;

		
		if(Middle[0]=='C') index2=0;
		else if(Middle[0]=='H')	index2=1;
		else if(Middle[0]=='S') index2=2;
		else if(Middle[0]=='D') index2=3;
		
		arr[index2][index1]=1;
	}
	for(int j=0;j<4;j++){
		for(int k=0;k<13;k++){
			if(arr[j][k]==0){
				count++;
			}
		}
	}
	cout<<count<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
