#include<bits/stdc++.h>
using namespace std;
int t,n,mat[100005][4],chan1[100005],chan2[100005],chan3[100005],l1,l2,l3,ans;
void change1(int k){
	sort(chan1+1,chan1+l1+1);
	for(int i=1;i<=k;i++) ans-=chan1[i];
	return ;
}

void change2(int k){
	sort(chan2+1,chan2+l2+1);;
	for(int i=1;i<=k;i++) ans-=chan2[i];
	return ;
}
void change3(int k){
	sort(chan3+1,chan3+l3+1);
	for(int i=1;i<=k;i++) ans-=chan3[i];
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(chan1,0,sizeof(chan1));
		memset(chan2,0,sizeof(chan2));
		memset(chan3,0,sizeof(chan3));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				cin>>mat[i][j];
			}
			int a=max(max(mat[i][0],mat[i][1]),mat[i][2]);
			int sum=0,llm=999,llk; mat[i][3]=a;
			for(int j=0;j<=2;j++){
				if(a-mat[i][j]==0){
					if(llm=999) llm=j;
					else {
						sum=0; break;
					}	
				}
				else if(sum==0)
					sum=a-mat[i][j];
				else 
					if(a-mat[i][j]<sum)
						sum=a-mat[i][j];
			}
			if(llm==0) chan1[++l1]=sum;
			if(llm==1) chan2[++l2]=sum;
			if(llm==2) chan3[++l3]=sum;
		}
		for(int i=1;i<=n;i++) ans+=mat[i][3];
		
		if(l1>n/2){
			change1(l1-n/2);
		}
		if(l2>n/2){
			change2(l2-n/2);
		}
		if(l3>n/2){
			change3(l3-n/2);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
