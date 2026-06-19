#include<bits/stdc++.h>

using namespace std;

const int maxN=200000;
int A[maxN+5];
int n;
int T;

//dfs
const int maxdfs=200000;
int blue[maxdfs+5];
int red[maxdfs+5];
int bluel=1;
int bluer=0;
int redl=1;
int redr=0;
long long Cdfs=0;
int dfs(int idx){
	//printf("idx=%d\n", idx);  //DEL
	if(idx==n+1){
		long long cnt=0;
		for(int i=2;i<=bluer;i++){
			if(blue[i]==blue[i-1]){
				cnt+=blue[i];
			}
		}
		for(int i=2;i<=redr;i++){
			if(red[i]==red[i-1]){
				cnt+=red[i];
			}
		}
		Cdfs=max(Cdfs,cnt);
		return 0;
	}
	
	//如果将idx放入blue
	blue[++bluer]=A[idx];
	dfs(idx+1);
	bluer--;
	//如果将idx放入red
	red[++redr]=A[idx];
	dfs(idx+1);
	redr--; 
	
	return 0;
}

int main(){
	
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		scanf("%d", &n);
		for(int j=1;j<=n;j++){
			scanf("%d", &A[j]);
		}
		
		//如果用暴力dfs
		bluer=0;
		redr=0;
		Cdfs=0;//init 
		dfs(1);
		printf("%lld\n", Cdfs);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
