#include<bits/stdc++.h>
using namespace std;
int b[1000000],maxn=0,n,flag,k,biao[10000],count2,count3;
int a[1000000],c[30];
int fang1(int j){
	int count1=c[j-1]*2;
	return count1;
}
void fang(int x){
	for(int i=1;;i++){
		if(x/c[i]==0){
			flag=i;
			break;
		}
	}
	for(int i=flag;i>=1;i--){
		if(x-c[i]>=0){
			x-=c[i];
			a[i]++;
		}
	}
}
bool solve(int l,int r){
	for(int i=l;i<=r;i++){
		fang(b[i]);
	}
	for(int i=1;i<=flag;i++){
		count3+=c[i];
	}
	if(count3==k)return true;
	else return false;
}
bool ce(int l,int r){
	for(int i=l;i<=r;i++){
		if(biao[i]==1)return true; 
	}
	for(int i=l;i<=r;i++){
		biao[i]=1 ;
	}
	return false;
}
void dfs(int i,int j){
	if(i>n||j>n){
		if(maxn<count2)maxn=count2;
		return;
	}
    for(i;i<=n;i++){
    	for(j;j<=n;j++){
    		if(ce(i,j))continue;
    		if(solve(i,j)){
    			count2++;
    			dfs(i+1,j+1);
    			count2--;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	c[1]=1;
	for(int i=2;i<=21;i++){
		c[i]=fang1(i);
	}
	dfs(1,1);
	cout<<count2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

