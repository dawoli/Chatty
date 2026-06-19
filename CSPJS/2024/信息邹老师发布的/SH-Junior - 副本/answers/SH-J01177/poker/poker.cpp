#include<bits/stdc++.h>
using namespace std;
string s;
int temp;
char a[4]={'D','C','H','S'};
char b1[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char b2[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char b3[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char b4[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int xiabiao(char x){
	if(x=='A') return 0;
	if(x=='T') return 9;
	if(x=='J') return 10;
	if(x=='Q') return 11;
	if(x=='K') return 12;
	return int(x-'1');
}
int main(){
	freopen("poker.in","r",stdin);
	ssfreopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	int sum=0;
	
	for(int i=1;i<=n;i++){
		cin>>s;
		temp=xiabiao(s[1]);
		if(s[0]==a[0]){
			if(b1[temp]!='0'){
				b1[temp]='0';
				sum++;
			}
			
		}else if(s[0]==a[1]){
			if(b2[temp]!='0'){
				b2[temp]='0';
				sum++;
			}
		}else if(s[0]==a[2]){
			if(b3[temp]!='0'){
				b3[temp]='0';
				sum++;
			}
		}else{
			if(b4[temp]!='0'){
				b4[temp]='0';
				sum++;
			}
		}
		
	}
	printf("%d\n",52-sum);
	return 0;
} 
