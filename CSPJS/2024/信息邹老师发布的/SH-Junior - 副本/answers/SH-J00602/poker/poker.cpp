#include<iostream>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string p[52];
	int n=0,k=0;
	cin>>n;
	k=52-n;
	for(int i=0;i<n;i++){
		cin>>p[i];
	
	for(int j=0;j<i;j++){
		for(int y=j+1;y<i;y++){
			if (p[j]==p[y]){
				k++;
			}
		}
	}
}
	cout<<k;
	return 0;
}
