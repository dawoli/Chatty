#include <bits/stdc++.h>
using namespace std;
int t,n,opt[1010][1010],a[10]={6,2,5,5,4,5,6,3,7,6}; 
int bj(int x,int y){
	int lx=opt[x][0],ly=opt[y][0];
	if(lx>ly){
		return 1;
	}
	if(lx<ly){
		return 0;
	}
	for(int i=1;i<=lx;++i){
		if(opt[x][i]>opt[y][i]){
			return 1;
		}else if(opt[x][i]<opt[y][i]){
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	opt[2][0]=1,opt[2][1]=1;
	opt[3][0]=1,opt[3][1]=7;
	opt[4][0]=1,opt[4][1]=4;
	opt[5][0]=1,opt[5][1]=2;
	opt[6][0]=1,opt[6][1]=6;
	opt[7][0]=1,opt[7][1]=8;
	cin>>t;
	for(int _=1;_<=t;++_){
		cin>>n;
		if(n==1){
			cout<<-1;
		}
		for(int i=8;i<=n;++i){
			int flag=1;
			for(int j=0;j<10;++j){
				if(i>=a[j]&&i-a[j]!=1){
					if(flag==1){
						opt[i-a[j]][++opt[i-a[j]][0]]=j;
						memcpy(opt[i],opt[i-a[j]],sizeof(opt[i-a[j]]));
						flag=0;
					}else{
						opt[i-a[j]][++opt[i-a[j]][0]]=j;
						if(bj(i,i-a[j])){
							opt[i][0]=opt[i-a[j]][0];
							for(int k=1;k<=opt[i-a[j]][0];++k){
								opt[i][k]=opt[i-a[j]][k];
							}
							memcpy(opt[i],opt[i-a[j]],sizeof(opt[i-a[j]]));
						}
					}
					opt[i-a[j]][opt[i-a[j]][0]--]=0;
				}
			}
		}
		for(int i=1;i<=opt[n][0];++i){
			cout<<opt[n][i];
		}
		cout<<endl;
	}
	return 0;
}
