#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool card[4][14];
void input_card(char a,char b) {
	int it1,it2;
	switch(a) {
		case 'D':
			it1=0;
			break;
		case 'C':
			it1=1;
			break;
		case 'H':
			it1=2;
			break;
		case 'S':
			it1=3;
			break;
	}
	if(b>='2'&&b<='9')
		it2=b-'0';
	else 
	{
		switch(b) 
		{
			case 'A':
				it2=1;
				break;
			case 'T':
				it2=10;
				break;
			case 'J':
				it2=11;
				break;
			case 'Q':
				it2=12;
				break;
			case 'K':
				it2=13;
				break;	
		}
	}
	card[it1][it2]=true;
	return ;
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	memset(card,false,sizeof(card));
	for(int i=1; i<=n; i++) {
		cin>>s;
		input_card(s[0],s[1]);
	}
	int ans=0;
	for(int i=0;i<4;i++)
		for(int j=1;j<=13;j++)
			if(!card[i][j])
				ans++;
	printf("%d",ans);	
	return 0;
}
