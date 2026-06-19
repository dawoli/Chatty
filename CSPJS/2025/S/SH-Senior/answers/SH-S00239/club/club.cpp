#include<iostream>
#include<algorithm>
int a1[100001],a2[100001],a3[100001];
int i1,i2,i3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		int ans=0;
		int minx=20001,miny=20001,minz=20001,x,y,z;
		for(int i=0;i<n;i++){
			int a,b,c;
			std::cin>>a>>b>>c;
			if(a>=b&&a>=c){
				ans+=a;
				a1[i1++]=a-std::max(b,c);
				int xx=a-std::min(b,c);
				if(xx<minx){
					minx=xx;
					x=std::max(b,c)-std::min(b,c);
				}
			}
			else if(b>=a&&b>=c){
				ans+=b;
				a2[i2++]=b-std::max(a,c);
				int yy=b-std::min(a,c);
				if(yy<miny){
					miny=yy;
					y=std::max(a,c)-std::min(a,c);
				}
			}
			else{
				ans+=c;
				a3[i3++]=c-std::max(a,b);
				int zz=c-std::min(a,b);
				if(zz<minz){
					minz=zz;
					z=std::max(a,b)-std::min(a,b);
				}
			}
		}
		if(i1>n/2){
			std::sort(a1,a1+i1);
			for(int i=0;i<i1-n/2;i++)ans-=a1[i];
			if(n%2){
				if(i2==0||i3==0)ans-=x;
			}
		}
		if(i2>n/2){
			std::sort(a2,a2+i2);
			for(int i=0;i<i2-n/2;i++)ans-=a2[i];
			if(n%2){
				if(i1==0||i3==0)ans-=y;
			}
		}
		if(i3>n/2){
			std::sort(a3,a3+i3);
			for(int i=0;i<i3-n/2;i++)ans-=a3[i];
			if(n%2){
				if(i1==0||i2==0)ans-=z;
			}
		}
		i1=0,i2=0,i3=0;
		std::cout<<ans<<"\n";
	}
	return 0;
}
//100'
