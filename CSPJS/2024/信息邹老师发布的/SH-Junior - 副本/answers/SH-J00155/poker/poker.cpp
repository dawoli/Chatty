#include<bits/stdc++.h>
using namespace std;

long long num,mvp;
int iq[5][14] = {0};
string s;

int mq(){
	if(s[1] == 'A'){
		return 1;	
	}
	else if(s[1] == '2'){
		return 2;			
	}
	else if(s[1] == '3'){
		return 3;			
	}
	else if(s[1] == '4'){
		return 4;			
	}
	else if(s[1] == '5'){
		return 5;			
	}
	else if(s[1] == '6'){
		return 6;			
	}
	else if(s[1] == '7'){
		return 7;			
	}
	else if(s[1] == '8'){
		return 8;		
	}
	else if(s[1] == '9'){
		return 9;		
	}
	else if(s[1] == 'T'){
		return 10;		
	}
	else if(s[1] == 'J'){
		return 11;		
	}
	else if(s[1] == 'Q'){
		return 12;		
	}
	else if(s[1] == 'K'){
		return 13;		
	}
	
} 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>num;
	for(int i = 1;i <= num;i++){
		cin>>s; 
		mvp = mq();
		if(s[0] == 'D'){
			iq[1][mvp] = 1;
		}
		else if(s[0] == 'C'){
			iq[2][mvp] = 1;
		}
		else if(s[0] == 'H'){
			iq[3][mvp] = 1;
		}
		else{
			iq[4][mvp] = 1;
			cout<<endl;
		}
	}
	mvp = 0;
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 13;j ++){
			if(iq[i][j] == 0){
				mvp++; 
			}
		}
	}
	cout<<mvp;
	return 0;
}
