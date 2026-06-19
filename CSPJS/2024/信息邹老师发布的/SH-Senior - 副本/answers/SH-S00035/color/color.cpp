#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
//精度！！！数据类型？ 
int T,n;
int a[N];
//void _init(){
//	
//}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
	//	_init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(n>20)	return 0; 
		int red=-1,blue=-1;
		int sum=0,ans=0;
		for(int t=0;t<(1<<n);t++){
			sum=0;
			red=-1;
			blue=-1;
			for(int i=1;i<=n;i++){
				int c=0;
				int tp=(1<<(i-1));
				if(t&tp){//红 
					if(red==-1){
						c=0;
					}
					else{
						if(a[red]!=a[i]){
							c=0;
						}
						else{
							c=a[i];
						}
					}
					red=i;
				}
				else{//蓝 
					if(blue==-1){
						c=0;
					}
					else{
						if(a[blue]==a[i]){
							c=a[i];
						}
						else{
							c=0;
						}
					}
					blue=i;
				}
				sum+=c;
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
