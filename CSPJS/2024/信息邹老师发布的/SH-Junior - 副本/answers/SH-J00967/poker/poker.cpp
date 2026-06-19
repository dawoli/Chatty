/*T=10*/
#include<bits/stdc++.h>
using namespace std;
bool poker[20][10]={0};//D1,C2,H3,S4
long long cnt=0;
long long n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		string s;
		cin>>s;
		char fuck=s[1];
		s[1]=s[0];
		s[0]=fuck;
		if(s[0]=='A'){
			if(s[1]=='D'){
				poker[1][1]=1;
			}if(s[1]=='C'){
				poker[1][2]=1;
			}if(s[1]=='H'){
				poker[1][3]=1;
			}if(s[1]=='S'){
				poker[1][4]=1;
			}
		}else if(s[0]=='T'){
			if(s[1]=='D'){
				poker[10][1]=1;
			}if(s[1]=='C'){
				poker[10][2]=1;
			}if(s[1]=='H'){
				poker[10][3]=1;
			}if(s[1]=='S'){
				poker[10][4]=1;
			}
		}else if(s[0]=='J'){
			if(s[1]=='D'){
				poker[11][1]=1;
			}if(s[1]=='C'){
				poker[11][2]=1;
			}if(s[1]=='H'){
				poker[11][3]=1;
			}if(s[1]=='S'){
				poker[11][4]=1;
			}
		}else if(s[0]=='Q'){
			if(s[1]=='D'){
				poker[12][1]=1;
			}if(s[1]=='C'){
				poker[12][2]=1;
			}if(s[1]=='H'){
				poker[12][3]=1;
			}if(s[1]=='S'){
				poker[12][4]=1;
			}
		}else if(s[0]=='K'){
			if(s[1]=='D'){
				poker[13][1]=1;
			}if(s[1]=='C'){
				poker[13][2]=1;
			}if(s[1]=='H'){
				poker[13][3]=1;
			}if(s[1]=='S'){
				poker[13][4]=1;
			}
		}else{
			if(s[1]=='D'){
				poker[s[0]-'0'][1]=1;
			}if(s[1]=='C'){
				poker[s[0]-'0'][2]=1;
			}if(s[1]=='H'){
				poker[s[0]-'0'][3]=1;
			}if(s[1]=='S'){
				poker[s[0]-'0'][4]=1;
			}
		}
	}
	for(int i=1;i<=13;++i){
		for(int j=1;j<=4;++j){
			if(poker[i][j]==0){
				++cnt;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
