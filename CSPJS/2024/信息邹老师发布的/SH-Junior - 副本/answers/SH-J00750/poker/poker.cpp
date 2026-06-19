#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[4][13],index1,index2,cnt=0,n;
	string Middle;
		cin>>n;
		cin>>index1; 
		for(int j=0;j<=4;j++){
		for(int k=0;k<13;k++){
			if(arr[j][k]=0)
				cnt++;
			}
		}
		for(int i=0;i<2;i++){
		if(Middle[i]=='A') index1=0;
		else if(Middle[i]=='T') index1=9;
		else if(Middle[i]=='J') index1=10;
		else if(Middle[i]=='Q') index1=11;
		else if(Middle[i]=='K') index1=12;
		else index1=Middle[i];
		
		if(Middle[0]='C') index2=0;
		else if(Middle[i]=='H') index2=1;
		else if(Middle[i]=='S') index2=2;
		else if(Middle[i]=='D') index2=3;
		arr[index2][index1]=0;
	}
	arr[Middle[0]][Middle[1]]=1;
	for(int j=0;j<=4;j++){
		for(int k=0;k<13;k++){
			if(arr[j][k]=0)
				cnt++;
			}
		}
	cout<<52-n<<endl;
	return 0;
}

 
