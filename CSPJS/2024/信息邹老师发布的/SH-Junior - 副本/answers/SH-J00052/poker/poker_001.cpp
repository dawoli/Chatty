#include<bits/stdc++.h>
using namespace std;
char color[4]={'D','C','H','S'},num[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
bool c[4][52];
int cnt=52;
void f(string s) {
	int a,b;
	for(int i=0;i<4;i++) if(s[0]==color[i]) a=i;
	for(int i=0;i<52;i++) if(s[1]==num[i]) b=i;
	if(!c[a][b]) cnt--;
	c[a][b]=true;
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string card[52]={};
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>card[i];
		f(card[i]);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
