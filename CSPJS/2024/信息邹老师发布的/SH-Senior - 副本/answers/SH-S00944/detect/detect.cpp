#include<bits/stdc++.h>
using namespace std;
int n,m,d[100010],L,v[100010],a[100010];
int p[100010],V,T;
int nxt[1000010],pre[1000010];
int main(){
//	freopen("detect.in","r",stdin);
//	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		
		int er=1;
		for(int i=0;i<=L;i++){
			if(i==p[er]){
				nxt[i]=pre[i]=i;
				er++;
			}else{
				pre[i]=er;nxt[i]=er+1;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				//走到l开始超速
				double l=max(d[i]*1.0,d[i]+(V*V-v[i]*v[i])*0.5/a[i]);
				if(l>=L);//没被派到超速
				else{
					if(nxt[(int)ceil(l)]>m);//没拍到
					else{ int aa=m-nxt[(int)ceil(l)]+1;cnt++;}//有aa个拍到了
				} 
			}else if(a[i]==0){
				if(v[i]<=V);//nothing
				else{
					int aa=m-nxt[d[i]]+1;cnt++;
				}
			}else if(a[i]<0){
				//走到l停止超速 
				double l=max(d[i]*1.0,d[i]+(V*V-v[i]*v[i])*0.5/a[i]);
				if(l>L){int aa=m-nxt[d[i]]+1;cnt++;}//全程超速 
				else if(nxt[(int)ceil(l)]==nxt[d[i]]);//没拍到
				else{ int aa=pre[(int)floor(l)]-nxt[d[i]]+1;cnt++;}//aa个
			}
		}
		cout<<cnt<<endl;
	}
}
