#include<bits/stdc++.h>
using namespace std;
#define N 20

int n,ans = 52;
bool p[N][4];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		char k,c;
		int pk = 1,hs;
		cin>>k>>c;
		if(c == 'A'){
			pk = 1;
		}
		else if(c == 'T'){
			pk = 10;
		}
		else if(c == 'J'){
			pk = 11;
		}
		else if(c == 'Q'){
			pk = 12;
		}
		else if(c == 'K'){
			pk = 13;
		}
		else{
			pk = c - '0';
		}
		
		if(k == 'D'){
			hs = 1;
		}
		else if(k == 'C'){
			hs = 2;
		}
		else if(k == 'H'){
			hs = 3;
		}
		else{
			hs = 4;
		}
		
		if(!p[pk][hs]){
			p[pk][hs] = true;
			ans--;
		}
	}
	printf("%d",ans);
	return 0; 
} 
