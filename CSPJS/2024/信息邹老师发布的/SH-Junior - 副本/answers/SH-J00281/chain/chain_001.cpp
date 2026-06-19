#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l,flag,s[200000],start[100000],len[100000];
void dfs(int beg,int dep,int prev){
	if(dep>r||flag==1) return;
	for(int i=0;i<n;i++){
		if(i!=prev){
			for(int j=0;j<len[i];j++){
				if(s[start[i]+j]==beg){
					for(int p=j+1;p<=min(j+k-1,len[i]-1);p++){
						if(dep==r&&s[start[i]+p]==c){
							flag=1;
							return;
						}
						else dfs(s[start[i]+p],dep+1,i);
					}
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k>>q;
		start[0]=0;
		for(int j=0;j<n;j++){
			cin>>l;
			len[j]=l;
			if(j<n-1) start[j+1]=start[j]+l;
			for(int p=0;p<l;p++){
				cin>>s[start[j]+p];
			}
		}
		for(int j=0;j<q;j++){
			flag=0;
			cin>>r>>c;
			dfs(1,1,-1);
			cout<<flag<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
