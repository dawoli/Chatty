#include<iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
	    int n;
        cin>>n;
        if(n=2){
        	int a,b,c;
        	cin>>a>>b>>c;
        	int d,e,f;
        	cin>>d>>e>>f;
        	int g,h,i,j,k,l;
        	g=a+e;
        	h=a+f;
        	i=b+d;
        	j=b+f;
        	k=c+d;
        	l=c+e;
        	int max=0;
        	if(g>=h&&g>=i&&g>=j&&g>=k&&g>=l)max=g;
        	if(h>=g&&h>=i&&h>=j&&h>=k&&h>=l)max=h;
        	if(i>=h&&i>=g&&i>=j&&i>=k&&i>=l)max=i;
        	if(j>=h&&j>=i&&j>=g&&j>=k&&j>=l)max=j;
        	if(k>=h&&k>=i&&k>=j&&k>=g&&k>=l)max=k;
        	if(l>=h&&l>=i&&l>=j&&l>=k&&l>=g)max=l;
        	cout<<max<<"\n";
		}
		if(n=4){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
        	int dd,ee,ff;
        	cin>>dd>>ee>>ff;
        	int gg,hh,ii;
        	cin>>gg>>hh>>ii;
        	int jj,kk,ll;
        	cin>>jj>>kk>>ll;
        	
        	
        	int ad1,ad2,ad3,ad4;
        	ad1=aa+dd+hh+kk;
        	ad2=aa+dd+hh+ll;
        	ad3=aa+dd+ii+kk;
        	ad4=aa+dd+ii+ll;
        	int ag1,ag2,ag3,ag4;
        	ag1=aa+gg+ee+kk;
        	ag2=aa+gg+ee+ll;
        	ag3=aa+gg+ff+kk;
        	ag4=aa+gg+ff+ll;
        	int aj1,aj2,aj3,aj4;
        	aj1=aa+jj+ee+hh;
        	aj2=aa+jj+ee+ii;
        	aj3=aa+jj+ff+hh;
        	aj4=aa+jj+ff+ii;
        	
        	
        	int be1,be2,be3,be4;
        	be1=bb+ee+gg+jj;
        	be2=bb+ee+gg+ll;
        	be3=bb+ee+ii+jj;
        	be4=bb+ee+ii+ll;
        	int bh1,bh2,bh3,bh4;
        	bh1=bb+hh+dd+jj;
        	bh2=bb+hh+dd+ll;
        	bh3=bb+hh+ff+jj;
        	bh4=bb+hh+ff+ll;
        	int bk1,bk2,bk3,bk4;
        	bk1=bb+kk+dd+gg;
        	bk2=bb+kk+dd+ii;
        	bk3=bb+kk+ff+gg;
        	bk4=bb+kk+ff+ii;
        	
        	
        	int cf1,cf2,cf3,cf4;
        	cf1=cc+ff+gg+kk;
        	cf2=cc+ff+gg+jj;
        	cf3=cc+ff+hh+kk;
        	cf4=cc+ff+hh+jj;
        	int ci1,ci2,ci3,ci4;
        	ci1=cc+ii+dd+kk;
        	ci2=cc+ii+dd+jj;
        	ci3=cc+ii+ee+kk;
        	ci4=cc+ii+ee+jj;
        	int cl1,cl2,cl3,cl4;
        	cl1=cc+ll+gg+ee;
        	cl2=cc+ll+gg+dd;
        	cl3=cc+ll+hh+ee;
        	cl4=cc+ll+hh+dd;
        	
        	
        	
        	
        	int dg1,dg2,dg3,dg4;
        	dg1=bb+dd+gg+kk;
        	dg2=bb+dd+gg+ll;
        	dg3=cc+dd+gg+kk;
        	dg4=cc+dd+gg+ll;
        	int dj1,dj2,dj3,dj4;
        	dj1=bb+dd+jj+hh;
        	dj2=bb+dd+jj+ii;
        	dj3=cc+dd+jj+hh;
        	dj4=cc+dd+jj+ii;
        	
        	
        	int eh1,eh2,eh3,eh4;
        	eh1=aa+ee+hh+jj;
        	eh2=aa+ee+hh+ll;
        	eh3=cc+ee+hh+jj;
        	eh4=cc+ee+hh+ll;
        	int fi1,fi2,fi3,fi4;
        	fi1=bb+ff+ii+jj;
        	fi2=bb+ff+ii+kk;
        	fi3=aa+ff+ii+jj;
        	fi4=aa+ff+ii+kk;
        	
        	
        	int ek1,ek2,ek3,ek4;
        	ek1=aa+ee+kk+gg;
        	ek2=aa+ee+kk+ii;
        	ek3=cc+ee+kk+gg;
        	ek4=cc+ee+kk+ii;
        	int fl1,fl2,fl3,fl4;
        	fl1=bb+ff+ll+gg;
        	fl2=bb+ff+ll+hh;
        	fl3=aa+ff+ll+gg;
        	fl4=aa+ff+ll+hh;
        	
        	int gj1,gj2,gj3,gj4;
        	gj1=bb+ee+gg+jj;
        	gj2=bb+ff+gg+jj;
        	gj3=cc+ee+gg+jj;
        	gj4=cc+ff+gg+jj;
        	int hk1,hk2,hk3,hk4;
        	hk1=aa+dd+hh+kk;
        	hk2=aa+ff+hh+kk;
        	hk3=cc+dd+hh+kk;
        	hk4=cc+ff+hh+kk;
        	int il1,il2,il3,il4;
        	il1=aa+dd+ii+ll;
        	il2=aa+ee+ii+ll;
        	il3=bb+dd+ii+ll;
        	il4=bb+ee+ii+ll;
        	
        	int maxx;
        	if(ad1>=ad2&&ad1>=ad3&&ad1>=ad4&&ad1>=ag1&&ad1>=ag2&&ad1>=ag3&&ad1>=ag4&&ad1>=aj1&&ad1>=aj2&&ad1>=aj3&&ad1>=aj4&&ad1>=be1&&ad1>=be2&&ad1>=be3&&ad1>=be4&&ad1>=bh1&&ad1>=bh2&ad1>=bh3&&ad1>=bh4&&ad1>=bk1&&ad1>=bk2&&ad1>=bk3&&ad1>=bk4&&ad1>=cf1&&ad1>=cf2&&ad1>=cf3&&ad1>=cf4&&ad1>=ci1&&ad1>=ci2&&ad1>=ci3&&ad1>=ci4&&ad1>=cl1&&ad1>=cl2&&ad1>=cl3&&ad1>=cl4&&ad1>=dg1&&ad1>=dg2&&ad1>=dg3&&ad1>=dg4&&ad1>=dj1&&ad1>=dj2&&ad1>=dj3&&ad1>=dj4&&ad1>=eh1&&ad1>=eh2&&ad1>=eh3&&ad1>=eh4&&ad1>=ek1&&ad1>=ek2&&ad1>=ek3&&ad1>=ek4&&ad1>=fi1&&ad1>=fi2&&ad1>=fi3&&ad1>=fi4&&ad1>=fl1&&ad1>=fl2&&ad1>=fl3&&ad1>=fl4&&ad1>=gj1&&ad1>=gj2&&ad1>=gj3&&ad1>=gj4&&ad1>=hk1&&ad1>=hk2&&ad1>=hk3&&ad1>=hk4&&ad1>=il1&&ad1>=il2&&ad1>=il3&&ad1>=il4)maxx=ad1;
        	if(ad2>=ad1&&ad2>=ad3&&ad2>=ad4&&ad2>=ag1&&ad2>=ag2&&ad2>=ag3&&ad2>=ag4&&ad2>=aj1&&ad2>=aj2&&ad2>=aj3&&ad2>=aj4&&ad2>=be1&&ad2>=be2&&ad2>=be3&&ad2>=be4&&ad2>=bh1&&ad2>=bh2&ad2>=bh3&&ad2>=bh4&&ad2>=bk1&&ad2>=bk2&&ad2>=bk3&&ad2>=bk4&&ad2>=cf1&&ad2>=cf2&&ad2>=cf3&&ad2>=cf4&&ad2>=ci1&&ad2>=ci2&&ad2>=ci3&&ad2>=ci4&&ad2>=cl1&&ad2>=cl2&&ad2>=cl3&&ad2>=cl4&&ad2>=dg1&&ad2>=dg2&&ad2>=dg3&&ad2>=dg4&&ad2>=dj1&&ad2>=dj2&&ad2>=dj3&&ad2>=dj4&&ad2>=eh1&&ad2>=eh2&&ad2>=eh3&&ad2>=eh4&&ad2>=ek1&&ad2>=ek2&&ad2>=ek3&&ad2>=ek4&&ad2>=fi1&&ad2>=fi2&&ad2>=fi3&&ad2>=fi4&&ad2>=fl1&&ad2>=fl2&&ad2>=fl3&&ad2>=fl4&&ad2>=gj1&&ad2>=gj2&&ad2>=gj3&&ad2>=gj4&&ad2>=hk1&&ad2>=hk2&&ad2>=hk3&&ad2>=hk4&&ad2>=il1&&ad2>=il2&&ad2>=il3&&ad2>=il4)maxx=ad2;
        	if(ad3>=ad2&&ad3>=ad1&&ad3>=ad4&&ad3>=ag1&&ad3>=ag2&&ad3>=ag3&&ad3>=ag4&&ad3>=aj1&&ad3>=aj2&&ad3>=aj3&&ad3>=aj4&&ad3>=be1&&ad3>=be2&&ad3>=be3&&ad3>=be4&&ad3>=bh1&&ad3>=bh2&ad3>=bh3&&ad3>=bh4&&ad3>=bk1&&ad3>=bk2&&ad3>=bk3&&ad3>=bk4&&ad3>=cf1&&ad3>=cf2&&ad3>=cf3&&ad3>=cf4&&ad3>=ci1&&ad3>=ci2&&ad3>=ci3&&ad3>=ci4&&ad3>=cl1&&ad3>=cl2&&ad3>=cl3&&ad3>=cl4&&ad3>=dg1&&ad3>=dg2&&ad3>=dg3&&ad3>=dg4&&ad3>=dj1&&ad3>=dj2&&ad3>=dj3&&ad3>=dj4&&ad3>=eh1&&ad3>=eh2&&ad3>=eh3&&ad3>=eh4&&ad3>=ek1&&ad3>=ek2&&ad3>=ek3&&ad3>=ek4&&ad3>=fi1&&ad3>=fi2&&ad3>=fi3&&ad3>=fi4&&ad3>=fl1&&ad3>=fl2&&ad3>=fl3&&ad3>=fl4&&ad3>=gj1&&ad3>=gj2&&ad3>=gj3&&ad3>=gj4&&ad3>=hk1&&ad3>=hk2&&ad3>=hk3&&ad3>=hk4&&ad3>=il1&&ad3>=il2&&ad3>=il3&&ad3>=il4)maxx=ad3;
        	if(ad4>=ad2&&ad4>=ad3&&ad4>=ad1&&ad4>=ag1&&ad4>=ag2&&ad4>=ag3&&ad4>=ag4&&ad4>=aj1&&ad4>=aj2&&ad4>=aj3&&ad4>=aj4&&ad4>=be1&&ad4>=be2&&ad4>=be3&&ad4>=be4&&ad4>=bh1&&ad4>=bh2&ad4>=bh3&&ad4>=bh4&&ad4>=bk1&&ad4>=bk2&&ad4>=bk3&&ad4>=bk4&&ad4>=cf1&&ad4>=cf2&&ad4>=cf3&&ad4>=cf4&&ad4>=ci1&&ad4>=ci2&&ad4>=ci3&&ad4>=ci4&&ad4>=cl1&&ad4>=cl2&&ad4>=cl3&&ad4>=cl4&&ad4>=dg1&&ad4>=dg2&&ad4>=dg3&&ad4>=dg4&&ad4>=dj1&&ad4>=dj2&&ad4>=dj3&&ad4>=dj4&&ad4>=eh1&&ad4>=eh2&&ad4>=eh3&&ad4>=eh4&&ad4>=ek1&&ad4>=ek2&&ad4>=ek3&&ad4>=ek4&&ad4>=fi1&&ad4>=fi2&&ad4>=fi3&&ad4>=fi4&&ad4>=fl1&&ad4>=fl2&&ad4>=fl3&&ad4>=fl4&&ad4>=gj1&&ad4>=gj2&&ad4>=gj3&&ad4>=gj4&&ad4>=hk1&&ad4>=hk2&&ad4>=hk3&&ad4>=hk4&&ad4>=il1&&ad4>=il2&&ad4>=il3&&ad4>=il4)maxx=ad4;
        	if(ag1>=ad2&&ag1>=ad3&&ag1>=ad4&&ag1>=ad1&&ag1>=ag2&&ag1>=ag3&&ag1>=ag4&&ag1>=aj1&&ag1>=aj2&&ag1>=aj3&&ag1>=aj4&&ag1>=be1&&ag1>=be2&&ag1>=be3&&ag1>=be4&&ag1>=bh1&&ag1>=bh2&ag1>=bh3&&ag1>=bh4&&ag1>=bk1&&ag1>=bk2&&ag1>=bk3&&ag1>=bk4&&ag1>=cf1&&ag1>=cf2&&ag1>=cf3&&ag1>=cf4&&ag1>=ci1&&ag1>=ci2&&ag1>=ci3&&ag1>=ci4&&ag1>=cl1&&ag1>=cl2&&ag1>=cl3&&ag1>=cl4&&ag1>=dg1&&ag1>=dg2&&ag1>=dg3&&ag1>=dg4&&ag1>=dj1&&ag1>=dj2&&ag1>=dj3&&ag1>=dj4&&ag1>=eh1&&ag1>=eh2&&ag1>=eh3&&ag1>=eh4&&ag1>=ek1&&ag1>=ek2&&ag1>=ek3&&ag1>=ek4&&ag1>=fi1&&ag1>=fi2&&ag1>=fi3&&ag1>=fi4&&ag1>=fl1&&ag1>=fl2&&ag1>=fl3&&ag1>=fl4&&ag1>=gj1&&ag1>=gj2&&ag1>=gj3&&ag1>=gj4&&ag1>=hk1&&ag1>=hk2&&ag1>=hk3&&ag1>=hk4&&ag1>=il1&&ad1>=il2&&ag1>=il3&&ag1>=il4)maxx=ag1;
        	if(ag2>=ad2&&ag2>=ad3&&ag2>=ad4&&ag2>=ag1&&ag2>=ad1&&ag2>=ag3&&ag2>=ag4&&ag2>=aj1&&ag2>=aj2&&ag2>=aj3&&ag2>=aj4&&ag2>=be1&&ag2>=be2&&ag2>=be3&&ag2>=be4&&ag2>=bh1&&ag2>=bh2&ag2>=bh3&&ag2>=bh4&&ag2>=bk1&&ag2>=bk2&&ag2>=bk3&&ag2>=bk4&&ag2>=cf1&&ag2>=cf2&&ag2>=cf3&&ag2>=cf4&&ag2>=ci1&&ag2>=ci2&&ag2>=ci3&&ag2>=ci4&&ag2>=cl1&&ag2>=cl2&&ag2>=cl3&&ag2>=cl4&&ag2>=dg1&&ag2>=dg2&&ag2>=dg3&&ag2>=dg4&&ag2>=dj1&&ag2>=dj2&&ag2>=dj3&&ag2>=dj4&&ag2>=eh1&&ag2>=eh2&&ag2>=eh3&&ag2>=eh4&&ag2>=ek1&&ag2>=ek2&&ag2>=ek3&&ag2>=ek4&&ag2>=fi1&&ag2>=fi2&&ag2>=fi3&&ag2>=fi4&&ag2>=fl1&&ag2>=fl2&&ag2>=fl3&&ag2>=fl4&&ag2>=gj1&&ag2>=gj2&&ag2>=gj3&&ag2>=gj4&&ag2>=hk1&&ag2>=hk2&&ag2>=hk3&&ag2>=hk4&&ag2>=il1&&ag2>=il2&&ag2>=il3&&ag2>=il4)maxx=ag2;
		    if(ag3>=ad2&&ag3>=ad3&&ag3>=ad4&&ag3>=ag1&&ag3>=ag2&&ag3>=ad1&&ag3>=ag4&&ag3>=aj1&&ag3>=aj2&&ag3>=aj3&&ag3>=aj4&&ag3>=be1&&ag3>=be2&&ag3>=be3&&ag3>=be4&&ag3>=bh1&&ag3>=bh2&ag3>=bh3&&ag3>=bh4&&ag3>=bk1&&ag3>=bk2&&ag3>=bk3&&ag3>=bk4&&ag3>=cf1&&ag3>=cf2&&ag3>=cf3&&ag3>=cf4&&ag3>=ci1&&ag3>=ci2&&ag3>=ci3&&ag3>=ci4&&ag3>=cl1&&ag3>=cl2&&ag3>=cl3&&ag3>=cl4&&ag3>=dg1&&ag3>=dg2&&ag3>=dg3&&ag3>=dg4&&ag3>=dj1&&ag3>=dj2&&ag3>=dj3&&ag3>=dj4&&ag3>=eh1&&ag3>=eh2&&ag3>=eh3&&ag3>=eh4&&ag3>=ek1&&ag3>=ek2&&ag3>=ek3&&ag3>=ek4&&ag3>=fi1&&ag3>=fi2&&ag3>=fi3&&ag3>=fi4&&ag3>=fl1&&ag3>=fl2&&ag3>=fl3&&ag3>=fl4&&ag3>=gj1&&ag3>=gj2&&ag3>=gj3&&ag3>=gj4&&ag3>=hk1&&ag3>=hk2&&ag3>=hk3&&ag3>=hk4&&ag3>=il1&&ag3>=il2&&ag3>=il3&&ag3>=il4)maxx=ag3;
		    if(ag4>=ad2&&ag4>=ad3&&ag4>=ad4&&ag4>=ag1&&ag4>=ag2&&ag4>=ag3&&ag4>=ad1&&ag4>=aj1&&ag4>=aj2&&ag4>=aj3&&ag4>=aj4&&ag4>=be1&&ag4>=be2&&ag4>=be3&&ag4>=be4&&ag4>=bh1&&ag4>=bh2&ag4>=bh3&&ag4>=bh4&&ag4>=bk1&&ag4>=bk2&&ag4>=bk3&&ag4>=bk4&&ag4>=cf1&&ag4>=cf2&&ag4>=cf3&&ag4>=cf4&&ag4>=ci1&&ag4>=ci2&&ag4>=ci3&&ag4>=ci4&&ag4>=cl1&&ag4>=cl2&&ag4>=cl3&&ag4>=cl4&&ag4>=dg1&&ag4>=dg2&&ag4>=dg3&&ag4>=dg4&&ag4>=dj1&&ag4>=dj2&&ag4>=dj3&&ag4>=dj4&&ag4>=eh1&&ag4>=eh2&&ag4>=eh3&&ag4>=eh4&&ag4>=ek1&&ag4>=ek2&&ag4>=ek3&&ag4>=ek4&&ag4>=fi1&&ag4>=fi2&&ag4>=fi3&&ag4>=fi4&&ag4>=fl1&&ag4>=fl2&&ag4>=fl3&&ag4>=fl4&&ag4>=gj1&&ag4>=gj2&&ag4>=gj3&&ag4>=gj4&&ag4>=hk1&&ag4>=hk2&&ag4>=hk3&&ag4>=hk4&&ag4>=il1&&ag4>=il2&&ag4>=il3&&ag4>=il4)maxx=ag4;
		    if(ad1>=ad2&&ad1>=ad3&&ad1>=ad4&&ad1>=ag1&&ad1>=ag2&&ad1>=ag3&&ad1>=ag4&&ad1>=aj1&&ad1>=aj2&&ad1>=aj3&&ad1>=aj4&&ad1>=be1&&ad1>=be2&&ad1>=be3&&ad1>=be4&&ad1>=bh1&&ad1>=bh2&ad1>=bh3&&ad1>=bh4&&ad1>=bk1&&ad1>=bk2&&ad1>=bk3&&ad1>=bk4&&ad1>=cf1&&ad1>=cf2&&ad1>=cf3&&ad1>=cf4&&ad1>=ci1&&ad1>=ci2&&ad1>=ci3&&ad1>=ci4&&ad1>=cl1&&ad1>=cl2&&ad1>=cl3&&ad1>=cl4&&ad1>=dg1&&ad1>=dg2&&ad1>=dg3&&ad1>=dg4&&ad1>=dj1&&ad1>=dj2&&ad1>=dj3&&ad1>=dj4&&ad1>=eh1&&ad1>=eh2&&ad1>=eh3&&ad1>=eh4&&ad1>=ek1&&ad1>=ek2&&ad1>=ek3&&ad1>=ek4&&ad1>=fi1&&ad1>=fi2&&ad1>=fi3&&ad1>=fi4&&ad1>=fl1&&ad1>=fl2&&ad1>=fl3&&ad1>=fl4&&ad1>=gj1&&ad1>=gj2&&ad1>=gj3&&ad1>=gj4&&ad1>=hk1&&ad1>=hk2&&ad1>=hk3&&ad1>=hk4&&ad1>=il1&&ad1>=il2&&ad1>=il3&&ad1>=il4)maxx=ad1;
        	if(ad2>=ad1&&ad2>=ad3&&ad2>=ad4&&ad2>=ag1&&ad2>=ag2&&ad2>=ag3&&ad2>=ag4&&ad2>=aj1&&ad2>=aj2&&ad2>=aj3&&ad2>=aj4&&ad2>=be1&&ad2>=be2&&ad2>=be3&&ad2>=be4&&ad2>=bh1&&ad2>=bh2&ad2>=bh3&&ad2>=bh4&&ad2>=bk1&&ad2>=bk2&&ad2>=bk3&&ad2>=bk4&&ad2>=cf1&&ad2>=cf2&&ad2>=cf3&&ad2>=cf4&&ad2>=ci1&&ad2>=ci2&&ad2>=ci3&&ad2>=ci4&&ad2>=cl1&&ad2>=cl2&&ad2>=cl3&&ad2>=cl4&&ad2>=dg1&&ad2>=dg2&&ad2>=dg3&&ad2>=dg4&&ad2>=dj1&&ad2>=dj2&&ad2>=dj3&&ad2>=dj4&&ad2>=eh1&&ad2>=eh2&&ad2>=eh3&&ad2>=eh4&&ad2>=ek1&&ad2>=ek2&&ad2>=ek3&&ad2>=ek4&&ad2>=fi1&&ad2>=fi2&&ad2>=fi3&&ad2>=fi4&&ad2>=fl1&&ad2>=fl2&&ad2>=fl3&&ad2>=fl4&&ad2>=gj1&&ad2>=gj2&&ad2>=gj3&&ad2>=gj4&&ad2>=hk1&&ad2>=hk2&&ad2>=hk3&&ad2>=hk4&&ad2>=il1&&ad2>=il2&&ad2>=il3&&ad2>=il4)maxx=ad2;
        	if(ad3>=ad2&&ad3>=ad1&&ad3>=ad4&&ad3>=ag1&&ad3>=ag2&&ad3>=ag3&&ad3>=ag4&&ad3>=aj1&&ad3>=aj2&&ad3>=aj3&&ad3>=aj4&&ad3>=be1&&ad3>=be2&&ad3>=be3&&ad3>=be4&&ad3>=bh1&&ad3>=bh2&ad3>=bh3&&ad3>=bh4&&ad3>=bk1&&ad3>=bk2&&ad3>=bk3&&ad3>=bk4&&ad3>=cf1&&ad3>=cf2&&ad3>=cf3&&ad3>=cf4&&ad3>=ci1&&ad3>=ci2&&ad3>=ci3&&ad3>=ci4&&ad3>=cl1&&ad3>=cl2&&ad3>=cl3&&ad3>=cl4&&ad3>=dg1&&ad3>=dg2&&ad3>=dg3&&ad3>=dg4&&ad3>=dj1&&ad3>=dj2&&ad3>=dj3&&ad3>=dj4&&ad3>=eh1&&ad3>=eh2&&ad3>=eh3&&ad3>=eh4&&ad3>=ek1&&ad3>=ek2&&ad3>=ek3&&ad3>=ek4&&ad3>=fi1&&ad3>=fi2&&ad3>=fi3&&ad3>=fi4&&ad3>=fl1&&ad3>=fl2&&ad3>=fl3&&ad3>=fl4&&ad3>=gj1&&ad3>=gj2&&ad3>=gj3&&ad3>=gj4&&ad3>=hk1&&ad3>=hk2&&ad3>=hk3&&ad3>=hk4&&ad3>=il1&&ad3>=il2&&ad3>=il3&&ad3>=il4)maxx=ad3;
        	if(ad4>=ad2&&ad4>=ad3&&ad4>=ad1&&ad4>=ag1&&ad4>=ag2&&ad4>=ag3&&ad4>=ag4&&ad4>=aj1&&ad4>=aj2&&ad4>=aj3&&ad4>=aj4&&ad4>=be1&&ad4>=be2&&ad4>=be3&&ad4>=be4&&ad4>=bh1&&ad4>=bh2&ad4>=bh3&&ad4>=bh4&&ad4>=bk1&&ad4>=bk2&&ad4>=bk3&&ad4>=bk4&&ad4>=cf1&&ad4>=cf2&&ad4>=cf3&&ad4>=cf4&&ad4>=ci1&&ad4>=ci2&&ad4>=ci3&&ad4>=ci4&&ad4>=cl1&&ad4>=cl2&&ad4>=cl3&&ad4>=cl4&&ad4>=dg1&&ad4>=dg2&&ad4>=dg3&&ad4>=dg4&&ad4>=dj1&&ad4>=dj2&&ad4>=dj3&&ad4>=dj4&&ad4>=eh1&&ad4>=eh2&&ad4>=eh3&&ad4>=eh4&&ad4>=ek1&&ad4>=ek2&&ad4>=ek3&&ad4>=ek4&&ad4>=fi1&&ad4>=fi2&&ad4>=fi3&&ad4>=fi4&&ad4>=fl1&&ad4>=fl2&&ad4>=fl3&&ad4>=fl4&&ad4>=gj1&&ad4>=gj2&&ad4>=gj3&&ad4>=gj4&&ad4>=hk1&&ad4>=hk2&&ad4>=hk3&&ad4>=hk4&&ad4>=il1&&ad4>=il2&&ad4>=il3&&ad4>=il4)maxx=ad4;
            cout<<maxx<<"\n";   
	    }
    }
}

  
