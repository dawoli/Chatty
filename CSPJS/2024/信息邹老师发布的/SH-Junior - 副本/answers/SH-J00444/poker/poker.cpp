#include<bits/stdc++.h>
using namespace std;
string s[100];
string s1[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s[i];
	}
	long long l = 0;
	for(int i = 0;i < n;i++){
		bool f = true;
		for(int j = 0;j < l;j++){
			if(s[i] == s1[j]){
				f = false;
			}
		}
		if(f){
			s1[l] = s[i];
			l++;
		}
	}
	cout << 52-l;
} 
