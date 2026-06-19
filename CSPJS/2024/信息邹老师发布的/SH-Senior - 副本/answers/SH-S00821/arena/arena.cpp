#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[9],c[9],d[9][9],x[9];
int chmp(int Code,int N,int aRdy){
	vector<int> member;
	int nwA[9]={};
	member.clear();
	for(int i=1;i<=aRdy;i++) nwA[i]=a[i];
	for(int i=1;i<=aRdy;i++) member.push_back(i);
	for(int i=aRdy+1;i<=N;i++){
		int nw11=Code%2;
		Code/=2;
		int nw22=Code%2;
		Code/=2;
		nwA[i]=nw11*2+nw22;
		member.push_back(i);
	}
	
	cout<<endl;
	
	int Round=0;
	while(member.size()>1){
		if(member.size()==2){
			if(d[++Round][1]==0){
				if(nwA[member[1]]>=Round){
					return member[1];
				}else{
					return member[2];
				}
			}else{
				if(nwA[member[2]]>=Round){
					return member[2];
				}else{
					return member[1];
				}
			}
		}
		for(int i=0;i<member.size();i++) cout<<member[i]<<" "<<nwA[member[i]]<<endl;
		Round++;
		int Gams=member.size()/2;
		for(int i=1;i<=Gams;i++){
			int pl1,pl2;
			pl1=member[0];
			pl2=member[1];
			for(int i=2;i<member.size();i++) member[i-2]=member[i];
			member.pop_back();
			member.pop_back();
			bool win=0;
			if(d[Round][i]==0){
				if(nwA[pl1]>=Round) win=0;
				else win=1;
			}else{
				if(nwA[pl2]>=Round) win=1;
				else win=0;
			}
			if(win) member.push_back(pl2);
			else member.push_back(pl1);
		}
	}
	return member[1];
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int k;
	if(n<=2) k=1;
	else if(n<=4) k=2;
	else if(n<=8) k=3;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(1<<(k-i));j++){
			char c;
			cin>>c;
			if(c=='1') d[i][j]=1;
			else d[i][j]=0;
		}
	}
	cin>>t>>x[0]>>x[1]>>x[2]>>x[3];
	for(int i=1;i<=n;i++) a[i]^=x[i%4];
	
	int ans=-1919810;
	for(int Ask=1;Ask<=m;Ask++){
		int C=c[Ask],nwN;
		if(C<=2) nwN=2;
		else if(C<=4) nwN=4;
		else if(C<=8) nwN=8;
		int needP=nwN-C;
		bool IsPossible[9]={};
		for(int i=0;i<(1<<(needP*2));i++){
			IsPossible[chmp(i,nwN,C)]=1;
		}
		int nwsum=0;
		for(int i=1;i<=nwN;i++) if(IsPossible[i]) nwsum+=i;
		if(ans==-1919810) ans=nwsum;
		else ans^=(Ask*nwsum);
	}
	cout<<ans<<endl;
	
	return 0;
}
