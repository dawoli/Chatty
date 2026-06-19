#include<bits/stdc++.h> 
using namespace std;


int t;
int n,k,q;
int len;
int rj,cj;
int c[1010];
int result[500020];
int a[1010][2020];
int b[100000][2];

bool dfs(int lunshu,int s,int up){
	if(lunshu==1){
		for(int i=0;i<n;i++){
			if(i!=up){
				for(int j=0;j<c[i];j++){
					if(a[i][j]==s){
						int t=find(a[i],a[i]+c[i],cj)-a;
						if(t>j and t<c[i] and t-j+1<=k){
							return true;
						}
					}
				}
			}
		}
		return false;
	}else{
		for(int i=0;i<n;i++){
			if(i!=up){
				for(int j=0;j<c[i];j++){
					if(a[i][j]==s){
						for(int v=0;v<k;v++){
							return dfs(lunshu-1,a[i][j+v],i);
						}
					}
				}
			}
		}
		return false;
	}
}

int main(){
	
	
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>len;
			c[i]=len; 
			for(int v=0;v<len;v++){
				cin>>a[j][v];
			}		
		}
		for(int j=0;j<q;j++){
			cin>>b[j][0]>>b[j][1];
			if(dfs(b[j][0],1,-1)){
				result[i]=1;
			}else{
				result[i]=0;
			}
		}
		for(int j=0;j<q;j++){
			cout<<result[j]<<endl;
		} 
	}
	
	
	return 0;
}
