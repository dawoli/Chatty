#include<bits/stdc++.h>
using namespace std;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int p[12]={0,1,2,3,4,5,6,7,8,9,10,11};
	int cntttt=0;
	do{
		int outttt=0;
		int went[11]={};
		for(int i=1;i<=n;i++){
			if(c[p[i]]>outttt){
				if(s[i-1]-48)continue;
				else{
					int preout=outttt;
					outttt++;
					went[i]=true;
					//cout<<"inced "<<i<<'\n';
						for(int j=i+1;j<=n;j++){
							if(c[p[j]]<=outttt&&!went[j]){
								went[j]=true;
								outttt++;
								//cout<<"inced "<<i<<' '<<j<<' '<<c[j]<<' '<<outttt<<'\n';
							}
						}
				}
			}
			else{
				went[i]=true;
					//cout<<"inced "<<i<<'\n';
						for(int j=i+1;j<=n;j++){
							if(c[p[j]]<=outttt&&!went[j]){
								went[j]=true;
								outttt++;
								//cout<<"inced "<<i<<' '<<j<<' '<<c[j]<<' '<<outttt<<'\n';
							}
						}
			}
		}
		//cout<<"finally,"<<outttt<<'\n';
		cntttt+=(outttt<=n-m); 
	}while(next_permutation(p+1,p+n+1));
	cout<<cntttt<<'\n';
}
