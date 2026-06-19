#include <bits/stdc++.h>
using namespace std;
int n;
bool poker[7][15];
int ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		ans --;
		char num = a[1];
		int numbers=0;
		if(num == 'A'){
			numbers = 1;
		}else if(num == 'K'){
			numbers = 13;
		}else if(num == 'Q'){
			numbers = 12;
		}else if(num == 'J'){
			numbers = 11;
		}else if(num == 'T'){
			numbers = 10;
		}else if(num == '9'){
			numbers = 9;
		}else if(num == '8'){
			numbers = 8;
		}else if(num == '7'){
			numbers = 7;
		}else if(num == '6'){
			numbers = 6;
		}else if(num == '5'){
			numbers = 5;
		}else if(num == '4'){
			numbers = 4;
		}else if(num == '3'){
			numbers = 3;
		}else if(num == '2'){
			numbers = 2;
		}
		if(a[0] == 'S'){
		    if(poker[0][numbers]) ans ++;	
			poker[0][numbers] = 1;
		}else if(a[0] == 'H'){
			if(poker[1][numbers])ans ++;
			poker[1][numbers] = 1; 
		}else if(a[0] == 'D'){
			if(poker[2][numbers])ans ++;
			poker[2][numbers] = 1;
		}else if(a[0] == 'C'){
			if(poker[3][numbers])ans ++;
			poker[3][numbers] = 1;
		}
	}
	cout<<ans; 
	return 0;
}
