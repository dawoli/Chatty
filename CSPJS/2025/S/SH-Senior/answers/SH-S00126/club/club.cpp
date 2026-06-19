#include<bits/stdc++.h>
using namespace std;
int n,t;
struct mem{
	int x[4];
	int mini;//如果将这一条边换组，它的最小差值是几 
	int maxnum;//最大值在哪一组 
}p_[100004];
int satis;//最大满意值 
int num[4];//这种状态下三个小组各多少人
int trip[100004][4],tot[4];//最小差值堆 
void add(int x,int cnt,int w){
	trip[w][cnt]=x;
	while(w/2!=0){
		if(trip[w/2][cnt]>trip[w][cnt]){
			swap(trip[w/2][cnt],trip[w][cnt]);
			w/=2;
		}
		else{
			break;
		}
	}
	return ;
}
void change(int cnt,int x){
	int w=tot[cnt],l=1;
	while(l*2<=w){
		if(l*2+1>w){
			trip[l][cnt]=trip[l*2][cnt];
			l=l*2;
		}
		if(trip[l*2][cnt]<trip[l*2+1][cnt]){
			trip[l][cnt]=trip[l*2][cnt];
			l*=2;
		}
		else{
			trip[l][cnt]=trip[l*2+1][cnt];
			l=l*2+1;
		}
	}
	add(x,cnt,l);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(trip,20005,sizeof(trip));
		satis=0;
		memset(tot,0,sizeof(tot));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			p_[i].mini=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p_[i].x[1]>>p_[i].x[2]>>p_[i].x[3];
			if(p_[i].x[1]>p_[i].x[3]&&p_[i].x[1]>p_[i].x[2]){
				p_[i].maxnum=1;
				p_[i].mini=min((p_[i].x[1]-p_[i].x[2]),(p_[i].x[1]-p_[i].x[3]));
			}
			else if(p_[i].x[3]>p_[i].x[2]){
				p_[i].maxnum=3;
				p_[i].mini=min((p_[i].x[3]-p_[i].x[2]),(p_[i].x[3]-p_[i].x[1]));
			}
			else{
				p_[i].maxnum=2;
				p_[i].mini=min((p_[i].x[2]-p_[i].x[1]),(p_[i].x[2]-p_[i].x[3]));
			}
		}
		for(int i=1;i<=n;i++){
			int k=p_[i].maxnum;//这个人对哪组最满意
			if(num[k]<n/2){//没满员 
				satis+=p_[i].x[k];
				num[k]++;
				tot[k]++;
				add(p_[i].mini,k,tot[k]);
			} 
			else{//换组了 
				if(p_[i].mini<=trip[1][k]){
					satis+=p_[i].x[k]-p_[i].mini;
				}
				else{
					satis=satis+p_[i].x[k]-trip[1][k];
					change(k,p_[i].mini);
				}
			}
		}
		cout<<satis<<endl; 
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
//如何替换换组插值-堆来着 
