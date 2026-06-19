#include<bits/stdc++.h>
using namespace std;
int flow_clor;
int n,ans;
string ss;
bool aa[15][5];
int colour_check(){
	if(ss[0]=='S')
	return 4;
	if(ss[0]=='H')
	return 3; 
	if(ss[0]=='C')
	return 2;
	if(ss[0]=='D')
	return 1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ss;
		if(ss[1]=='T'){
		flow_clor=colour_check();
			aa[10][flow_clor]=1;
		}
		else if(ss[1]>='2'&&ss[1]<='9')
		{
			flow_clor=colour_check();
			aa[ss[1]-'0'][flow_clor]=1;
		}
		else if(ss[1]=='A'){
			flow_clor=colour_check();
			aa[1][flow_clor]=1; 
		}
		else if(ss[1]=='J'){
			flow_clor=colour_check();
			aa[11][flow_clor]=1;
		}
		else if(ss[1]=='Q'){
			flow_clor=colour_check();
			aa[12][flow_clor]=1;
		}
		else if(ss[1]=='K'){
			flow_clor=colour_check();
			aa[13][flow_clor]=1;
		}
	}
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(aa[i][j]==0)
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
