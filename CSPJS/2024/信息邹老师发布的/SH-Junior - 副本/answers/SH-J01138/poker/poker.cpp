#include<bits/stdc++.h>
using namespace std;
int cnt;
int fangpian[14],caohua[14],hongtao[14],heitao[14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string op;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op[0]=='D'){
			if(op[1]>='2'&&op[1]<='9'){
				fangpian[op[1]-'0']=1;
			}
			else if(op[1]=='A'){
				fangpian[1]=1;
			}
			else if(op[1]=='T'){
				fangpian[10]=1;
			}
			else if(op[1]=='J'){
				fangpian[11]=1;
			}
			else if(op[1]=='Q'){
				fangpian[12]=1;
			}
			else if(op[1]=='K'){
				fangpian[13]=1;
			}
		}
		else if(op[0]=='C'){
			if(op[1]>='2'&&op[1]<='9'){
				caohua[op[1]-'0']=1;
			}
			else if(op[1]=='A'){
				caohua[1]=1;
			}
			else if(op[1]=='T'){
				caohua[10]=1;
			}
			else if(op[1]=='J'){
				caohua[11]=1;
			}
			else if(op[1]=='Q'){
				caohua[12]=1;
			}
			else if(op[1]=='K'){
				caohua[13]=1;
			}
		}
		else if(op[0]=='H'){
			if(op[1]>='2'&&op[1]<='9'){
				hongtao[op[1]-'0']=1;
			}
			else if(op[1]=='A'){
				hongtao[1]=1;
			}
			else if(op[1]=='T'){
				hongtao[10]=1;
			}
			else if(op[1]=='J'){
				hongtao[11]=1;
			}
			else if(op[1]=='Q'){
				hongtao[12]=1;
			}
			else if(op[1]=='K'){
				hongtao[13]=1;
			}
		}
		else if(op[0]=='S'){
			if(op[1]>='2'&&op[1]<='9'){
				heitao[op[1]-'0']=1;
			}
			else if(op[1]=='A'){
				heitao[1]=1;
			}
			else if(op[1]=='T'){
				heitao[10]=1;
			}
			else if(op[1]=='J'){
				heitao[11]=1;
			}
			else if(op[1]=='Q'){
				heitao[12]=1;
			}
			else if(op[1]=='K'){
				heitao[13]=1;
			}
		}
	}
	for(int i=1;i<=13;i++){
		if(!fangpian[i]){
			cnt++;
		}
		if(!caohua[i]){
			cnt++;
		}
		if(!hongtao[i]){
			cnt++;
		}
		if(!heitao[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
