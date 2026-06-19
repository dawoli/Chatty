#include<bits/stdc++.h>
using namespace std;
int n,amount;
string Cards[105]={};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		bool is_insert=1;
		cin>>a;
		for(int i=0;i<amount;i++){
			if(Cards[i]==a){
				is_insert=0;
				break;}}
		if(is_insert){
			Cards[amount++]=a;}	
	}
	cout<<52-amount<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
