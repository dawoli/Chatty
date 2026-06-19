#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[15][5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]>='2'&&s[1]<='9'){
				a[s[1]-'0'][1]++;
			}else if(s[1]=='A'){
				a[1][1]++;
			}else if(s[1]=='T'){
				a[10][1]++;
			}else if(s[1]=='J'){
				a[11][1]++;
			}else if(s[1]=='Q'){
				a[12][1]++;
			}else if(s[1]=='K'){
				a[13][1]++;
			}
		}
		if(s[0]=='S'){
			if(s[1]>='2'&&s[1]<='9'){
				a[s[1]-'0'][2]++;
			}else if(s[1]=='A'){
				a[1][2]++;
			}else if(s[1]=='T'){
				a[10][2]++;
			}else if(s[1]=='J'){
				a[11][2]++;
			}else if(s[1]=='Q'){
				a[12][2]++;
			}else if(s[1]=='K'){
				a[13][2]++;
			}
		}
		if(s[0]=='H'){
			if(s[1]>='2'&&s[1]<='9'){
				a[s[1]-'0'][3]++;
			}else if(s[1]=='A'){
				a[1][3]++;
			}else if(s[1]=='T'){
				a[10][3]++;
			}else if(s[1]=='J'){
				a[11][3]++;
			}else if(s[1]=='Q'){
				a[12][3]++;
			}else if(s[1]=='K'){
				a[13][3]++;
			}
		}
		if(s[0]=='C'){
			if(s[1]>='2'&&s[1]<='9'){
				a[s[1]-'0'][4]++;
			}else if(s[1]=='A'){
				a[1][4]++;
			}else if(s[1]=='T'){
				a[10][4]++;
			}else if(s[1]=='J'){
				a[11][4]++;
			}else if(s[1]=='Q'){
				a[12][4]++;
			}else if(s[1]=='K'){
				a[13][4]++;
			}
		}
	}
	int num=0;
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]==0){
				num++;
			}
		}
	}
	printf("%d", num);
	return 0;
}
