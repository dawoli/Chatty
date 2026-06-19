#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int dp[MAXN][7];
int T;
int sNums[7]={6,2,5,4,6,3,7};
char nums[7]={'0','1','2','4','6','7','8'};
bool cmp(int x,int y){
	int lX=0,lY=0,numX[7],numY[7];
	int minX,minY;
	for(int i=0;i<7;i++){
		numX[i]=dp[x][i],numY[i]=dp[y][i]; 
		lX+=numX[i],lY+=numY[i];
	}
	if(lX>lY) return 1;
	else if(lX<lY) return 0;
	else{
		for(int i=1;i<7;i++)
			if(numX[i]){
				minX=i;
				numX[i]--;
				break;
			}
		for(int i=1;i<7;i++)
			if(numY[i]){
				minY=i;
				numY[i]--;
				break;
			}
		if(minX>minY) return 1;
		else if(minX<minY) return 0;
		else{
			for(int i=0;i<7;i++)
				if(numX[i]<numY[i]) return 1;
				else if(numX[i]>numY[i]) return 0;
			return 0;
		} 
	}
}
void output(int x){
	int numX[7],minX;
	for(int i=0;i<7;i++)
		numX[i]=dp[x][i]; 
	for(int i=1;i<7;i++)
		if(numX[i]){
			minX=i;
			numX[i]--;
			break;
	}
	cout<<nums[minX];
	for(int i=0;i<7;i++)
		for(int j=1;j<=numX[i];j++) cout<<nums[i];
	cout<<endl;
	return;
} 
void solve(){
	memset(dp,0x0f,sizeof(dp));
	for(int i=0;i<7;i++) dp[0][i]=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<7;j++){
			int lstPos=i-sNums[j];
			if(lstPos>=0){
				for(int k=0;k<7;k++)
					if(k==j) dp[n+1][k]=dp[lstPos][k]+1;
					else dp[n+1][k]=dp[lstPos][k];
				if(cmp(i,n+1))
					for(int k=0;k<7;k++)
						dp[i][k]=dp[n+1][k];
			}
		} 
	if(dp[n][0]==0x0f0f0f0f) cout<<-1<<endl;
	else output(n);
	return;
}
int main(){
	cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
