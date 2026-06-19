#include<bits/stdc++.h>
using namespace std;

int n , k , cnt;

string s1;

int num[500005] , f[500005];

string s[500005];

string er(int a){
	string s1 = "";
	while(a > 0){
		s1 += char(a % 2 + 48);
		a /= 2;
	}
	return s1;
}
string xo(string s1 , string s2){
	string s3 = "";
	for(int i = 0 ; i < max(s1.size() , s2.size()) ; i++){
		if(s1[i] != '1' || s2[i] != '1'){
			s3 += '1';
		}
		else{
			s3 += '0';
		}	
	}
	return s3;
}

int sh(string s){
	int n = 0;
	for(int i = s.size() - 1 ; i >= 0 ; i--){
		if(s[i] == '0'){
			continue;
		}
		n += pow(2 , i);
	} 
	return n;
}

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> num[i];
		s[i] = er(num[i]);
	}
	for(int i = 0 ; i < n ; i++){
		if(num[i] == k){
			cnt++;
			f[i] = 1;
			continue;
		}
		int l = num[i];
		for(int j = i - 1 ; j >= 0 ; j--){
			if(f[j] == 1){
				break;
			}
			if(sh(xo(er(l) , s[j])) == k){
				for(int p = j ; p <= i ; p++){
					f[p] = 1;
				}
				cnt++;
				break;
			}
			l = sh(xo(er(l) , s[j]));
		}
	}
	cout << cnt;
	return 0; 
}	
