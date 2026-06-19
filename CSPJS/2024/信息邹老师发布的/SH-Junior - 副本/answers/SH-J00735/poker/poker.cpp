#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
struct node{
	char h;
	char d;
}poker[60];
char hs[5]={'0','C','S','H','D'};
char ds[14]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
bool vis[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>poker[i].h>>poker[i].d;
	}
	for(int i=0;i<n;i++){
		for(int h=1;h<=4;h++){
			for(int d=1;d<=13;d++){
				if(poker[i].h==hs[h] && poker[i].d==ds[d]){
					vis[(h-1)*13+d]=true;
				}
				else{
					continue;
				}
			}
		}
	}
	for(int i=1;i<=52;i++){
		if(vis[i]==0){
			cnt++;
		}
	}
	cout<<cnt;
} 
