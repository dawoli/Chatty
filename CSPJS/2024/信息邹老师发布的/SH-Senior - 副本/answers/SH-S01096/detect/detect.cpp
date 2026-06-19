#include<bits/stdc++.h>
using namespace std;
struct car{
	double d,v,a;
	double strt,nd;
	int sn,en,fl1;
}a[100009];
int T,n,m,L,V,p[100009],ans1=0,ans2=0;
bool cmp(car x,car y){
	return x.sn>y.sn||x.sn==y.sn&&x.en<y.en;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
	    cin>>n>>m>>L>>V;
	    for(int i=1;i<=n;i++){
	    	cin>>a[i].d>>a[i].v>>a[i].a;
	    	if(a[i].v>V){
	    		a[i].strt=a[i].d;
	    		a[i].fl1=1;
	    	}else if(a[i].a>0){
	    		a[i].strt=a[i].d+(V*V-a[i].v*a[i].v)*1.00000/(2.00000*a[i].a);
	    		a[i].fl1=0;
	    	}else{
	    		a[i].strt=1000009;
	    		a[i].fl1=-1;
	    	}
	    	if(a[i].strt==1000009){
	    		a[i].nd=-1;
	    	}else if(a[i].a>=0){
	    		a[i].nd=1000009;
	    	}else{
	    		a[i].nd=a[i].d+(V*V-a[i].v*a[i].v)*1.00000/(2.00000*a[i].a);
	    	}
//	    	cout<<a[i].strt<<" "<<a[i].nd<<endl;
	    }
	    for(int i=1;i<=m;i++){
	    	cin>>p[i];
	    }
	    ans1=n;
	    for(int i=1;i<=n;i++){
	    	a[i].sn=1000009;
	    	for(int j=1;j<=m;j++){
	    		if(a[i].strt<p[j]||a[i].strt==p[j]&&a[i].fl1==1){
	    			a[i].sn=min(a[i].sn,j);
	    		}
	    		if(a[i].nd>p[j]){
	    			a[i].en=max(a[i].en,j);
	    		}
	    	}
	    	if(a[i].sn>a[i].en){
	    		a[i].sn=1000009;
	    		a[i].en=0;
	    		ans1--;
	    	}
//	    	cout<<a[i].sn<<" "<<a[i].en<<endl;
	    }
	    ans2=m;
	    sort(a+1,a+n+1,cmp);
	    for(int i=1;i<=n;i++){
//	    	for(int k=1;k<=L;k++){
//	    		if(k>=a[i].sn&&k<=a[i].en){
//	    			cout<<"*";
//	    		}else{
//	    			cout<<" ";
//	    		}
//	    	}
//	    	cout<<endl;
            if(a[i].sn!=a[i+1].sn){
            	ans2--;
            	if(a[i+1].sn==1000009){
            		break;
            	}
            }
	    }
	    cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
