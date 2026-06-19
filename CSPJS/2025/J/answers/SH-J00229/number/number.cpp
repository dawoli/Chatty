#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string b;
    char a[1000009];
    ll cnts = 0;
    cin >> b;
    char s[1000009];
    for(int i = 0;i < b.size();i++){
    	if(b[i] >= '0' && b[i] <= '9'){
    		s[cnts] = b[i];
			cnts++; 
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '9'){
    		cout<< "9" ;
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '8'){
    		cout<< "8" ;
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '7'){
     		cout<< "7";
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '6'){
    		cout<< "6" ;
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '5'){
    		cout<< "5";
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '4'){
    		cout<< "4" ;
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '3'){
    		cout<< "3";
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '2'){
    		cout<< "2";
		}
    }
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '1'){
    		cout<< "1" ;
		}
	}
    for(int i = 0;i < cnts;i++){
    	if(s[i] == '0'){
    		cout<< "0" ;
		}
	}//½áÊø 
	return 0;
} 
