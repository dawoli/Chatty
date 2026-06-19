#include<iostream>
#include<cstdio>
bool own[5][15]={false};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		std::cin>>a>>b;
		int t=5,num=0;
		if(a=='D')t=0;
		else if(a=='C')t=1;
		else if(a=='H')t=2;
		else t=3;
		if(b=='A')num=1;
		else if(b=='T')num=10;
		else if(b=='J')num=11;
		else if(b=='Q')num=12;
		else if(b=='K')num=13;
		else num=b-'0';
		own[t][num]=true;
	}
	int ans=0; 
	for(int i=0;i<=3;i++)
		for(int j=1;j<=13;j++)
			if(!own[i][j])ans++;
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
