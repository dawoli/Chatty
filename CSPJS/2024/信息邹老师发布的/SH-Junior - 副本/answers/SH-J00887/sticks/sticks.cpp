#include<bits/stdc++.h>
using namespace std;
string ls[100001];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ls[0]="-1";
	ls[1]="-1";
	ls[2]="1";
	ls[3]="7";
	ls[4]="4";
	ls[5]="2";
	ls[6]="6";
	ls[7]="8";
	ls[8]="10";
	ls[9]="18"; 
	ls[10]="22";
	ls[11]="20";
	ls[12]="28";
	ls[13]="68";
	ls[14]="88";
	ls[15]="108";
	ls[16]="188"; 
	ls[17]="200";
	ls[18]="208";
	ls[19]="288";
	ls[20]="688";
	ls[21]="888";
	for (int i=22;i<100001;i++){
		ls[i]=ls[i-7]+'8'; 
	}
	int t;
	cin>>t;
	while (t--){
		int a;
		cin>>a;
		cout<<ls[a]<<endl;
	}
	return 0;
} 
