#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int T,n,sticks[15],dabiao[100];
void init(){
	sticks[0] = 6;
	sticks[1] = 2;
	sticks[2] = 5;
	sticks[3] = 5;
	sticks[4] = 4;
	sticks[5] = 5;
	sticks[6] = 6;
	sticks[7] = 3;
	sticks[8] = 7;
	sticks[9] = 6;
	dabiao[0] = -1;
	dabiao[1] = -1;
	dabiao[2] = 1;
	dabiao[3] = 7;
	dabiao[4] = 4;
	dabiao[5] = 2;
	dabiao[6] = 6;
	dabiao[7] = 8;
	dabiao[8] = 10;
	dabiao[9] = 18;
	dabiao[10] = 23;
	dabiao[11] = 20;
	dabiao[12] = 28;
	dabiao[13] = 68;
	dabiao[14] = 88;
	dabiao[15] = 108;
	dabiao[16] = 188;
	dabiao[17] = 206;
	dabiao[18] = 208;
	dabiao[19] = 288;
	dabiao[20] = 688;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	init();
	cin >> T;
	for(int i=1;i<=T;i++){
		cin >> n;
		if(n<=20){
			cout << dabiao[n] << endl;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout << 8;
			}
			cout << endl;
		}
		else if(n%7==1&&n!=1){
			cout << "10";
			for(int i=1;i<=n/7-1;i++){
				cout << 8;
			}
			cout << endl;
		}
		else if(n%7==2&&n!=2){
			cout << 1;
			for(int i=1;i<=n/7;i++){
				cout << 8;
			}
			cout << endl;
		}
		else if(n%7==3&&n!=3){
			cout << "206";
			for(int i=1;i<=n/7-2;i++){
				cout << 8;
			}
			cout << endl;
		}
		else if(n%7==4&&n!=4){
			cout << "208";
			for(int i=1;i<=n/7-2;i++){
				cout << 8;
			}
			cout << endl;
		}
		else if(n%7==5&&n!=5){
			cout << "288";
			for(int i=1;i<=n/7-2;i++){
				cout << 8;
			}
			cout << endl;
		}
		else if(n%7==6&&n!=6){
			cout << "688";
			for(int i=1;i<=n/7-2;i++){
				cout << 8;
			}
			cout << endl;
		}
	} 

	return 0;
} 
