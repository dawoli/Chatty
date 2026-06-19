#include <iostream>
#include <cstdio>
using namespace std;

int T,n;
int p[100005];
int cnt[20]={6,2,5,5,4,5,6,3,7,6};
int ans[100005],al=0;

void dfs(int k,int num){
	if (num<2){
		if (num==0){
			if (al==0) {
				al=k-1;
				for (int i=1;i<=k-1;i++){
					ans[i]=p[i];
				}	
				//cout<<al;
			}else{
				if (al>k-1) {
					al=k-1;
					for (int i=1;i<=k-1;i++){
						ans[i]=p[i];
					}
				}else if (al==k-1){
					for (int i=1;i<=k-1;i++){
						if (ans[i]==p[i])continue;
						else if (ans[i]>p[i]){
							al=k-1;
							for (int i=1;i<=k-1;i++){
								ans[i]=p[i];
							}
							break;
						}else if (ans[i]<p[i]){
							break;
						}
					}
				}
			}
		}
		return ;
	}
	for (int i=0;i<=9;i++){
		if (k==1 && i==0) continue;
		//cout<<i<<endl;
		if (num-cnt[i]>=0){
			p[k]=i;
			dfs(k+1,num-cnt[i]);
		}
	}
} 

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	/*
	通过搜索 从小王大 搜索
	当成狗后 直接弹出 
	找到最小值 
	*/
	cin>>T;
	for (int t=1;t<=T;t++){
		cin>>n;
		
		dfs(1,n);
		if (al==0) cout<<-1<<endl;
		else{
			for (int i=1;i<=al;i++){
				cout<<ans[i];
			}
			cout<<endl;
		}
		al=0;
	} 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

