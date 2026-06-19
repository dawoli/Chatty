#include<iostream>
#include<fstream>
using namespace std;
int row(char a){
	if(a=='D')return 0;
	else if(a=='C')return 1;
	else if(a=='H')return 2;
	else if(a=='S')return 3;
}
int column(char a){
	if(a=='A')return 0;
	else if(a=='2')return 1;
	else if(a=='3')return 2;
	else if(a=='4')return 3;
	else if(a=='5')return 4;
	else if(a=='6')return 5;
	else if(a=='7')return 6;
	else if(a=='8')return 7;
	else if(a=='9')return 8;
	else if(a=='T')return 9;
	else if(a=='J')return 10;
	else if(a=='Q')return 11;
	else if(a=='K')return 12;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,sum=52;
	bool j[52]={};
	cin>>n;
	while(n--){
		char a,b;
		cin>>a>>b;
		j[row(a)*13+column(b)]=1;
	}
	for(int i=0;i<52;i++){
		sum-=j[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
//D C H S
//A 2 3 4 5 6 7 8 9 T J Q K
