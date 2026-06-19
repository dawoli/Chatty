#include <iostream>

using namespace std;
int main(){
	freopen("sticks.in",'r',stdin);
	freopen("sticks.out",'w',stdout);
	int N,k[55];
	cin >> N;
	for(int i=1;i<=N;i++){
		cin>>k[i];
	}
	for(int i=1;i<=N;i++){
		if(k[i]%7==0){
			for(int j=1;j<=k[i]/7;j++){
				cout << '8';
			}
			cout << endl;
		} else if(k[i]%7==1){
			cout << "16";
			for(int j=1;j<=k[i]/7-1;j++){
				cout << '8';
			}
		}else {
			cout << '0' << endl;
		
	}
} 
return 0;
}
