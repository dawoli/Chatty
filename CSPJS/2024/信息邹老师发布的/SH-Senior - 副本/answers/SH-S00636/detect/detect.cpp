#include<iostream>
#include<cstdio>
struct Node{
	int d,v,a;
}c[100010];
int p[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	std::cin>>T;
	for(int k=1;k<=T;k++){
		int n,m,l,v;
		std::cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
			std::cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)
			std::cin>>p[m];
		int ans=0,sum=0;
		bool r=true,s=true,t=true;
		for(int i=1;i<=n;i++)
			if(c[i].a>0){
				s=false;
				r=false;
			}else if(c[i].a<0){
				t=false;
				r=false;
			}
		if(r)ans=m-1;
		if(s)ans=m-1;
		if(t)ans=m-1;
		if(t){
			for(int i=1;i<=n;i++){
				double s=0;
				s=(v*v-c[i].v*c[i].v)/(2*c[i].a);
				s+=c[i].d;
				if(s<c[i].d)s=c[i].d-1;
				for(int j=m;j>=1;j--){
					if(s<p[j])
						sum++;
					break;
				}
			}
		}else if(s){
			for(int i=1;i<=n;i++){
				double s=0;
				s=(v*v-c[i].v*c[i].v)/(2*c[i].a);
				s+=c[i].d;
				if(c[i].a<0 and s>c[i].d){
					for(int j=1;j<=m;j++){
						if(s>p[j]){
							sum++;
							break;
						}else break;
					} 
				}
			}
		}
		else{	
			for(int i=1;i<=n;i++){
				if(c[i].v>v)sum++;
			}
		}
		for(int i=1;i<=n;i++)
			c[i].d=0,c[i].v=0,c[i].a=0;
		for(int i=1;i<=m;i++)
			p[m]=0;
		if(sum==0)ans++;
		std::cout<<sum<<" ";
		std::cout<<ans;
		std::cout<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
