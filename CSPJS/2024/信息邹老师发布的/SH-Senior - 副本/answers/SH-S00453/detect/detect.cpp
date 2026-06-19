#include<bits/stdc++.h>//先随便写一点分 
//16:57-15 
//T2尝试2修改精度 
//17:15 34第一次二分
// 50
//
using namespace std;
int T;
int n,m;
double L,V;
int p[100005];
struct tt{
	double wei;
	double v;
	double a;
	bool chaosu;
    int jzuo;
	int jyou;
}che[100005];
struct seg{
	int l;
	int r;
	friend bool operator<(seg a, seg b){
		return a.r<b.r;
	}
}e[100005];
int cnt=0;
#define eps 0.00001//需要检查 
int f(double x){
	if(x<-eps) return 1;
	if(x>=p[m]-eps) return m+1;
	for(int k=2;k<=m;k++){
		if(x<p[k]-eps && x>p[k-1]-eps){
			return k;
		}
	}
	return m+1;
}
int bukeshan;
int ydd,jizuo,jiyou;

int el, er,mid;//二分l，二分r 
int chazhao(double mu){
	if(p[m]<mu) return m+1;
	el=1,er=m;
					
	while(el!=er){
		mid=(el+er)>>1;
		if(p[mid]>=mu){
			er=mid;
		}
		else{
			el=mid+1;
		}
	}
	return el;
}
void jiancha(){
	for(int i=1;i<=n;i++){
			cout<<i<<"|"<<che[i].jzuo<<" "<<che[i].jyou<<"\n";
		}
	return ;
}
int chazhao2(double mu){
	//最后一个比这个小的
	if(p[1]>=mu) return -3;
	el=1,er=m;
	while(el!=er){
		//cout<<el<<" "<<er<<endl;
		mid=(el+er+1)>>1;
		if(p[mid]<mu-eps){
			el=mid;
		}
		else{
			er=mid-1;
		}
	} 
	return el;
}
int tp;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int h8=1;h8<=T;h8++){
		//memset(chaopan,0,sizeof(chaopan));
		double qjl, qjr;
		//cout<<"数据"<<h8<<endl;
		
		cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>che[i].wei>>che[i].v>>che[i].a;
			che[i].chaosu=che[i].jzuo=che[i].jyou=0;
	    }
	    for(int i=1;i<=m;i++) cin>>p[i];
	    for(int i=1;i<=n;i++){
	    	if(che[i].a==0){  
	            
				if(che[i].v>V){
					qjl=che[i].wei;
					qjr=L+1;
					//cout<<"["<<qjl<<" , "<<qjr<<"sb"<<"\n"; 
					//找到第一个满足这个条件的
					tp=chazhao(qjl-eps);
					if(tp==m+1){
						che[i].chaosu=0;
						continue;
					}
					che[i].chaosu=1;
				    che[i].jzuo=tp;
				    che[i].jyou=m;
				    //cout<<el<<" "<<m<<endl;
				}
			}
			if(che[i].a<0){
			    //cout<<"<0"<<"\n";
				if(che[i].v<=V){
					che[i].chaosu=0;
					//cout<<"不超速"<<"\n";
				}
				else{
					qjl=che[i].wei;
					qjr=qjl+((V*V-che[i].v*che[i].v)/2)/che[i].a;//肯定>=0 
					//cout<<"["<<qjl<<" , "<<qjr<<")"<<"\n"; 
					tp=chazhao(qjl-eps);
					if(tp==m+1){
						che[i].chaosu=0;
						continue;
					}
					che[i].jzuo=tp;
					//找到最后一个比这个小的 
					tp=chazhao2(qjr-eps);
					che[i].jyou=tp;
				}
			}
			if(che[i].a>0){
				//cout<<"加速度>0"<<"\n";
				if(che[i].v>V){
					qjl=che[i].wei;
					qjr=L+1;
					tp=chazhao(qjl-eps); 
					if(tp==m+1){
						che[i].chaosu=0;
						continue;
					}
					che[i].chaosu=1;
				    che[i].jzuo=tp;
				    che[i].jyou=m;
				}
				  else if(che[i].v==V){
					qjl=che[i].wei;
					qjr=L+1;
					//cout<<"("<<qjl<<" , "<<qjr<<"sb"<<"\n";
					tp=chazhao(qjl+eps); 
					if(tp==m+1){
						che[i].chaosu=0;
						continue;
					}
					che[i].chaosu=1;
				    che[i].jzuo=tp;
				    che[i].jyou=m;
				}
				  else if(che[i].v<V){
					qjl=che[i].wei+((V*V-che[i].v*che[i].v)/2)/che[i].a;
					qjr=L+1;
					//cout<<"("<<qjl<<" , "<<qjr<<"sb"<<"\n";
					tp=chazhao(qjl+eps); 
					if(tp==m+1){
						che[i].chaosu=0;
						continue;
					}
					che[i].chaosu=1;
				    che[i].jzuo=tp;
				    che[i].jyou=m;
				
				}
			}
			
		//	for(int u=1;u<=m;u++) cout<<chaopan[i][u];
			//cout<<"\n";
			
		}
		/*for(int i=1;i<=n;i++){
			if(che[i].a>eps){
				for(int j=1;j<=m;j++){
				    if(chaopan[i][j]) che[i].jyou=j;
				}
				for(int j=m;j>=1;j--){
				    if(chaopan[i][j]) che[i].jzuo=j;
				}	
		    }
		}*/
		
		//写到50分 
		
		
		
		for(int i=1;i<=n;i++){
		//	if(che[i].chaosu){
			if(che[i].jzuo>0 && che[i].jyou>0 && che[i].jzuo<=che[i].jyou){
				cnt++;
				e[cnt].l=che[i].jzuo;
				e[cnt].r=che[i].jyou;
				    //cout<<"车"<<i<<"超速"<<" "<<jizuo<<" "<<jiyou<<"\n";
				}
			else{
				che[i].chaosu=0;
			}
		//	}
		}
		if(cnt==0){
			cout<<0<<" "<<m<<"\n";
			continue;
		}
		sort(e+1,e+cnt+1);
		
		//jiancha();
		bukeshan=0;
		//右端点最左 
		ydd=e[1].r;  bukeshan++;
		
		//cout<<cnt<<"\n";
		
		for(int j=2;j<=cnt;j++){
			if(e[j].l>ydd){
				ydd=e[j].r;
				//cout<<"新的"<<ydd<<endl; 
				bukeshan++;
			}
		}
		//cout<<bukeshan<<"\n";
		cout<<cnt<<" "<<m-bukeshan<<"\n";
		
		
			
			
	}
	
	
	
	return 0;
}
