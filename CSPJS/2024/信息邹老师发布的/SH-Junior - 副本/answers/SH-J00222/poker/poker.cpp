#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int d=13,c=13,h=13,s=13;
	bool visd[14],visc[14],vish[14],viss[14];
	while(n--){
		char c1,c2;
		int i;
		cin>>c1>>c2;
		int arrint[14]={1,2,3,4,5,6,7,8,9,10,11,12,13};
		char arrchar[14]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
		for(i=0;i<14;i++){
			if(arrchar[i]==c2)break;
		}
		if(c1=='D'){
			if(!visd[i]){
				d--;
				visd[i]=1;
			}
		}
		if(c1=='C'){
			if(!visc[i]){
				c--;
				visc[i]=1;
			}
		}
		if(c1=='H'){
			if(!vish[i]){
				h--;
				vish[i]=1;
			}
		}
		if(c1=='S'){
			if(!viss[i]){
				s--;
				viss[i]=1;
			}
		}
		if(c1=='C'&&c2=='9')c--;
	}
	cout<<c+d+h+s;
	return 0;
}
