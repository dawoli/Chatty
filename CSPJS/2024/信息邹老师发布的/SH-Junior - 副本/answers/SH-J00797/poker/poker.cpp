#include<bits/stdc++.h>
using namespace std;
int len,cnt,i;
char a,b;
bool j[4][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cnt = 0;
	cin>>len;
	for(int i=0;i<len;i++){
		cin>>b>>a;
		if(b == 'D')     b = '0';
		else if(b == 'C')b = '1';
		else if(b == 'H')b = '2';
		else if(b == 'S')b = '3';
		if(a == 'A')     a = '1';
		else if(a == 'T')a = '9'+1;
		else if(a == 'J')a = '9'+2;
		else if(a == 'Q')a = '9'+3;
		else if(a == 'K')a = '9'+4;
		if(j[b-'0'][a-'1'] == 0){
			j[b-'0'][a-'1'] = 1;
			cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
} 

