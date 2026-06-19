#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int d,v,a;
struct Driver{
	int started;
	int ended;
	int d,v,a;
};
Driver driver[100005];
bool cmp(Driver a,Driver b){
	return a.started<b.started;
}
int start(int a,int b, int c){
	if(b>V){
		return a;
	}
	else{
		if(c>0){
			float startpoint=((float)V*(float)V-(float)b*(float)b)/(2*(float)c)+(float)a;
			if(startpoint>L)return L+1;
			return ceil(startpoint);
		}
		return L+1;
	}
}
int end(int a,int b,int c){
	if(b>V){
		if(c>=0){
			return L;
		}
		else{
			float endpoint=((float)V*(float)V-(float)b*(float)b)/(2*(float)c)+(float)a;
			if(endpoint>L)return L;
			return floor(endpoint);
		}
	}
	else{
		if(c<=0){
			return a;
		}
		else{
			float startpoint=((float)V*(float)V-(float)b*(float)b)/(2*(float)c)+(float)a;
			if(startpoint<=L)return L;
			else return a;
		}
	}
}
int T;
int observer[100005];bool used[100005];
int diffnum[100005];
int ans=0,usednum=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		usednum=0;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++){
			driver[j].started=0;
			driver[j].ended=0;
		}
		for(int j=1;j<=n;j++){
			cin>>driver[j].d>>driver[j].v>>driver[j].a;
			
		}
		for(int j=1;j<=m;j++){
			used[j]=0;
			cin>>observer[j];
		}
		for(int j=1;j<=n;j++){
			int k=1;
			while(observer[k]<start(driver[j].d,driver[j].v,driver[j].a))k++;
			driver[j].started=k;
			k=m;
			while(observer[k]>end(driver[j].d,driver[j].v,driver[j].a))k--;
			driver[j].ended=k;
		}
		ans=n;
		
		for(int j=1;j<=m;j++){
			diffnum[i]=0;
		}
		for(int j=1;j<=n;j++){
			if(driver[j].started>driver[j].ended){
				ans--;
				driver[j].started=0;
				driver[j].ended=0;
			}
		}
		sort(driver+1,driver+n+1,cmp);
		for(int j=1;j<=n;j++){
			diffnum[driver[j].started]++;
			diffnum[driver[j].ended]--;
		}
		for(int j=1;j<=n;j++){
			if(diffnum[driver[j].started]<=0&&driver[j].started==driver[j].ended&&driver[j].started!=0)usednum++;
		}
		bool current=1;
		for(int j=1;j<=m;j++){
			if(!current&&diffnum[j]<=0){
				current=1;
			}
			else if(current&&diffnum[j]>0){
				current=0;
				usednum++;
			}
		}
		cout<<ans<<" "<<m-usednum<<endl;
	}
	return 0;
} 
