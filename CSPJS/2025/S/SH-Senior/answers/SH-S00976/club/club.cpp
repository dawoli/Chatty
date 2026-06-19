#include<bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
int ans[105][105][105]; 
int cont[205][3],n,t;
int sti;
void f(int a,int b,int c){
	int pos=a+b+c+1;
	
	if(a>n/2||b>n/2||c>n/2)return;
	if(pos>n){
		sti=max(sti,ans[a][b][c]);
		//cout<<sti<<endl;
		return;
	}
	//if(ans[a][b][c]<)
	//cout<<pos<<" "<<a<<" "<<b<<" "<<c<<endl;
	ans[a+1][b][c]=max(ans[a+1][b][c],ans[a][b][c]+cont[pos][0]);
	f(a+1,b,c);
	ans[a][b+1][c]=max(ans[a][b+1][c],ans[a][b][c]+cont[pos][1]);
	f(a,b+1,c);
	ans[a][b][c+1]=max(ans[a][b][c+1],ans[a][b][c]+cont[pos][2]);
	f(a,b,c+1);
}
bool check(){
	bool p=false;
	for(int i=1;i<=n;i++)
	    if(cont[i][2]||cont[i][1])p=true;
    return p;
}
int main(){
	fin>>t;
	while(t--){
		fin>>n;
		for(int i=1;i<=n;i++){
			fin>>cont[i][0]>>cont[i][1]>>cont[i][2];
		} 
		memset(ans,0,105*105*105);
		sti=0;
		if(!check()){
			long long stii=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(cont[i][0]<cont[j][0])swap(cont[i][0],cont[j][0]);
					
				}
			}
			for(int i=1;i<=n/2;i++)stii+=cont[i][0];
			fout<<stii;
			continue;
		}
		f(0,0,0);
		fout<<sti<<endl;
	}
	return 0;
}
