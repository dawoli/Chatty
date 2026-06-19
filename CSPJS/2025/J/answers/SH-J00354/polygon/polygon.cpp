#include<bits/stdc++.h>
using namespace std;
int num;
int stick;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>num;
	if(num<=2||num>5000){
		cout<<0<<endl; 
	}
	else{
		for(int i=0;i<num;i++){
		cin>>stick;
		stick=stick+stick;
		}
		if(stick>=stick){
			cout<<2*num-1<<endl;
		}
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
