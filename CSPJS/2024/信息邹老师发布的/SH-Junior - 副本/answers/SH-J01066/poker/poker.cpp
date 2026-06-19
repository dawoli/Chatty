#include<bits/stdc++.h>
using namespace std;
bool d[60],c[60],h[60],ss[60];
int sum=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]=='D'){
			int shu;
			if(s[1]=='A'){
				shu=1;
			}
			else if(s[1]=='T'){
				shu=10;
			}
			else if(s[1]=='J'){
				shu=11;
			}
			else if(s[1]=='Q'){
				shu=12;
			}
			else if(s[1]=='K'){
				shu=13;
			}
			else{
				shu=int(s[1]-'0');
			}
			d[shu]=true;
		}
		if(s[0]=='C'){
			int shu;
			if(s[1]=='A'){
				shu=1;
			}
			else if(s[1]=='T'){
				shu=10;
			}
			else if(s[1]=='J'){
				shu=11;
			}
			else if(s[1]=='Q'){
				shu=12;
			}
			else if(s[1]=='K'){
				shu=13;
			}
			else{
				shu=int(s[1]-'0');
			}
			c[shu]=true;
		}
		if(s[0]=='H'){
			int shu;
			if(s[1]=='A'){
				shu=1;
			}
			else if(s[1]=='T'){
				shu=10;
			}
			else if(s[1]=='J'){
				shu=11;
			}
			else if(s[1]=='Q'){
				shu=12;
			}
			else if(s[1]=='K'){
				shu=13;
			}
			else{
				shu=int(s[1]-'0');
			}
			h[shu]=true;
		}	
		if(s[0]=='S'){
			int shu;
			if(s[1]=='A'){
				shu=1;
			}
			else if(s[1]=='T'){
				shu=10;
			}
			else if(s[1]=='J'){
				shu=11;
			}
			else if(s[1]=='Q'){
				shu=12;
			}
			else if(s[1]=='K'){
				shu=13;
			}
			else{
				shu=int(s[1]-'0');
			}
			ss[shu]=true;
		}					
	}
	for(int i=1;i<=13;i++){
		if(d[i]==false){
			continue;
		}
		sum++;
	}
	for(int i=1;i<=13;i++){
		if(c[i]==false){
			continue;
		}
		sum++;
	}
	for(int i=1;i<=13;i++){
		if(h[i]==false){
		    continue;
		}
		sum++;
	}
	for(int i=1;i<=13;i++){
		if(ss[i]==false){
			continue;
		}
		sum++;
	}	
	cout<<52-sum<<endl;
	return 0;		
}
