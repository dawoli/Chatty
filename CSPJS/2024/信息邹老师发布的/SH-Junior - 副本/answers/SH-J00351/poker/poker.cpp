#include <bits/stdc++.h>

using namespace std;

bool Checkpoker[5][14];
int n;
string s;
int a,b;
int ans=52;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			Checkpoker[i][j]=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0] == 'D'){
			a=1;
		} else if(s[0] == 'C'){
			a=2;
		} else if(s[0] == 'H'){
			a=3;
		} else if(s[0] == 'S'){
			a=4;
		}
		
		if(s[1] == 'A'){
			b=1;
		} else if('2'<=s[1] && s[1]<='9'){
			b=int(s[1]-'0');
		} else if(s[1] == 'T'){
			b=10;
		} else if(s[1] == 'J'){
			b=11;
		} else if(s[1] == 'Q'){
			b=12;
		} else if(s[1] == 'K'){
			b=13;
		}
		
		Checkpoker[a][b]=true;
	}
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(Checkpoker[i][j]){
				ans--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
