#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
typedef long long ll;
int T;
struct node{
	int d,v,a,l,r;
}car[N];
int det[N];
int cut[N];
bool choose[N];
void fill(int l,int r){
	for(int i=l;i<=r;i++){
		cut[i]++;
		choose[i]=1;
	}
}

void clear(){
	for(int i=1;i<=N;i++){
		car[i].a=0;car[i].d=0;car[i].v=0;car[i].l=-1;car[i].r=-1;det[i]=0;cut[i]=0;choose[i]=0;
	}
}


int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int quiz=1;quiz<=T;quiz++){
		int n,m,l,v,overspeed=0,less=0;
		clear();
		cin>>n>>m>>l>>v;
		v=v*v;
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=1;i<=m;i++) cin>>det[i];
		cout<<endl;
		for(int i=1;i<=n;i++){
			int dd=car[i].d,vv=car[i].v*car[i].v,aa=car[i].a;
			if(aa==0){
				if(vv>v){
					overspeed++;
					int pl=1;
					while(det[pl]<dd) pl++;
					car[i].l=pl;
					car[i].r=m;
					fill(pl,m);
//					cout<<i<<" "<<pl<<" "<<m<<endl;
//					cout<<i<<" "<<car[i].l<<" "<<car[i].r<<endl; 
				}
			}
			if(aa>0){
				int pl=1,pr=m;
				while(det[pl]<dd){
					pl++;
				}
				
				if(2*aa*(det[m]-dd)+vv<=v) continue;
				while(pl<pr){
					
					int mid=(pl+pr)>>1;
					int midv=2*aa*(det[mid]-dd)+vv;
					if(midv>v) pr=mid;
					if(midv<=v) pl=mid+1;
//					cout<<pl<<" "<<pr<<endl;
				}
				overspeed++;
				car[i].l=pl;
				car[i].r=m;
				fill(pl,m);
				
//				cout<<i<<" "<<pl<<" "<<m<<endl;
//				cout<<i<<" "<<car[i].l<<" "<<car[i].r<<endl;
			}
			if(aa<0){
				if(vv<=v) continue;
				int pl=1,pr=m;
				while(det[pl]<dd) pl++;
				car[i].l=pl;
				int store=pl;
				while(pl<pr){
					int mid=(pl+pr+1)>>1;
					int midv=2*aa*(det[mid]-dd)+vv;
//					cout<<mid<<" "<<midv<<endl;
					if(midv>v) pl=mid;
					if(midv<=v) pr=mid-1;
//					cout<<pl<<":"<<2*aa*(det[pl]-dd)+vv<<" "<<pr<<":"<<2*aa*(det[pr]-dd)+vv<<endl;
				}	
				car[i].r=pr;
				if(2*aa*(det[car[i].r]-dd)+vv==v){
					pr--;
					car[i].r=pr;
				}
//				cout<<endl<<i<<" "<<pl<<":"<<2*aa*(det[pl]-dd)+vv-v<<" "<<pr<<":"<<2*aa*(det[pr]-dd)+vv-v<<endl<<endl;
				int c1=2*aa*(det[car[i].l]-dd)+vv,c2=2*aa*(det[car[i].r]-dd)+vv;
//				overspeed++;
//				cout<<i<<" "<<car[i].l<<":"<<c1<<" "<<car[i].r<<":"<<c2<<endl;
				if(c1>v && c2>v){
					overspeed++;
					fill(store,pr);
					
//					cout<<i<<" "<<store<<" "<<pr<<endl;
//					cout<<i<<" "<<pl<<":"<<2*aa*(det[pl]-dd)+vv-v<<" "<<pr<<":"<<2*aa*(det[pr]-dd)+vv-v<<endl;
				}
				
			}
		}
		cout<<overspeed<<" ";
//		cout<<endl;
//		for(int i=1;i<=m;i++) cout<<cut[i]<<" ";
//		cout<<endl;
		if(cut[1]>cut[2]) less++;
		if(cut[m]>cut[m-1]) less++;
		
		for(int i=2;i<m;i++){
			if(cut[i-1]<cut[i] && cut[i]>=cut[i+1]){
				less++;
				choose[i]=0;
			}
		}
//		for(int i=1;i<=n;i++){
//			int check=0;
//			for(int J=car[i].l;J<=car[i].r;J++){
//				check+=choose[J];
//			}
//			if(check>=car[i].r-car[i].l+1) less++;
//		}
//		for(int i=1;i<=m;i++) less+=choose[i]; 
		if(m==1 && cut[m]>0) less=1;
		cout<<m-less;
	}
	return 0;
} 
