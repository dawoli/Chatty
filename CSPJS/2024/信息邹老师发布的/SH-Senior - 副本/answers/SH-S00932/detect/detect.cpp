#include<bits/stdc++.h>
#define ll long long
using namespace std;

char opt;
ll T,n,m,L,V;
ll d[100005],v[100005],a[100005],p[100005];

queue <int> cars;

ll read() {
	char c;
	ll x=0,f=1;
	c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') f=0-f;
		c=getchar();
	}
	while(c>='0' && c<='9') {
		x=(x<<3)+(x<<1);
		x+=(c-'0');
		c=getchar();
	}
	return x*f;
}

void workA() {
	int num=0;
	for(int i=1;i<=n;i++) {
		if(v[i]>V && d[i]<=p[m]) num++;
	}
	cout<<num<<" ";
	if(!num) cout<<m<<endl;
	else cout<<m-1<<endl;
}

struct carinfo {
	ll dd,vv,aa;
	int type,id;
} c[100005],ec[100005];

//[ d , L ] exceed     TYPE 1
//( d+(V*V-v*v)/2a , L ] exceed    TYPE 2(a>0)
//[ d , d+(V*V-v*v)/2a ) exceed    TYPE 3(a<0)
bool cmp(carinfo x,carinfo y) {
	if(x.type==1) {
		if(y.type==1) {
			if(x.dd!=y.dd) return x.dd<y.dd;
			return x.id<y.id;
		}
		else if(y.type==2) {
			return (x.dd-y.dd)*2*y.aa<=(V*V-y.vv*y.vv);
		}
		else {
			return 0;
		}
	}
	else if(x.type==2) {
		if(y.type==1) {
			return (y.dd-x.dd)*2*x.aa>(V*V-x.vv*x.vv);
		}
		else if(y.type==2) {
			if((2*x.dd*x.aa*y.aa+(y.aa)*(V*V-x.vv*x.vv))!=(2*y.dd*x.aa*y.aa+(x.aa)*(V*V-y.vv*y.vv)))
				return (2*x.dd*x.aa*y.aa+(y.aa)*(V*V-x.vv*x.vv))<(2*y.dd*x.aa*y.aa+(x.aa)*(V*V-y.vv*y.vv));
			return x.id<y.id;
		}
		else {
			return 0;
		}
	}
	else {
		if(y.type==1) {
			return 1;
		}
		else if(y.type==2) {
			return 1;
		}
		else {
			if((2*x.dd*x.aa*y.aa+(y.aa)*(V*V-x.vv*x.vv))!=(2*y.dd*x.aa*y.aa+(x.aa)*(V*V-y.vv*y.vv)))
				return (2*x.dd*x.aa*y.aa+(y.aa)*(V*V-x.vv*x.vv))<(2*y.dd*x.aa*y.aa+(x.aa)*(V*V-y.vv*y.vv));
			if(x.dd!=y.dd) return x.dd<y.dd;
			return x.id<y.id;
		}
	}
}

int mfind(int tt) {
	int ls=1,rr=m;
	while(ls<=rr) {
		int mid=(ls+rr)>>1;
		if(p[mid]<tt) {
			ls=mid+1;
		}
		else {
			rr=mid-1;
		}
	}
	return ls;
}

void workS() {
	for(int i=1;i<=n;i++) {
		c[i].aa=a[i];
		c[i].dd=d[i];
		c[i].vv=v[i];
		c[i].id=i;
	}
	int num=0;
	for(int i=1;i<=n;i++) {
		if(c[i].aa==0) {    //匀速 
			if(c[i].vv>V) {
				//[ d[i] , L ] exceed    TYPE 1
				if(p[m]>=c[i].dd) {
					num++;
					cars.push(i);
					c[i].type=1;
				}
			}
		}
		else if(c[i].aa>0) {    //加速 
			if(c[i].vv>V) {
				//[ d[i] , L ] exceed    TYPE 1
				if(p[m]>=c[i].dd) {
					num++;
					cars.push(i);
					c[i].type=1;
				}
			}
			else {
				if((V*V-c[i].vv*c[i].vv)<2*c[i].aa*(L-c[i].dd)) {
					//( d[i]+(V*V-v[i]*v[i])/2a[i] , L ] exceed    TYPE 2
					if((p[m]-c[i].dd)*2*c[i].aa>(V*V-c[i].vv*c[i].vv)) {
						num++;
						cars.push(i);
						c[i].type=2;
					}
				}
			}
		}
		else {    //减速 
			if(c[i].vv>V) {
				if((V*V-c[i].vv*c[i].vv)<2*c[i].aa*(L-c[i].dd)) {
					//[ d[i] , L ] exceed    TYPE 1
					if(p[m]>=c[i].dd) {
						num++;
						cars.push(i);
						c[i].type=1;
					}
				}
				else {
					//[ d[i] , d[i]+(V*V-v[i]*v[i])/2a[i] ) exceed    TYPE 3
					int idx=mfind(c[i].dd);
					if((p[idx]-c[i].dd)*2*c[i].aa>(V*V-c[i].vv*c[i].vv)) {
						num++;
						cars.push(i);
						c[i].type=3;
					}
					/*
					for(int j=1;j<=m;j++) {
						if(p[j]<c[i].dd) continue;
						if((p[j]-c[i].dd)*2*c[i].aa>(V*V-c[i].vv*c[i].vv)) {
							num++;
							cars.push(i);
							c[i].type=3;
						}
						break;
					}
					*/
				}
			}
		}
	}
	cout<<num<<" ";
	//[ d[i] , L ] exceed     TYPE 1
	//( d[i]+(V*V-v[i]*v[i])/2a[i] , L ] exceed    TYPE 2(a[i]>0)
	//[ d[i] , d[i]+(V*V-v[i]*v[i])/2a[i] ) exceed    TYPE 3(a[i]<0)
	int cnt=0;
	while(!cars.empty()) {
//		cout<<cars.front()<<" ";
		ec[++cnt]=c[cars.front()];
		cars.pop();
	}
//	cout<<endl;
	sort(ec+1,ec+1+num,cmp);
	int i=1,j=1,ans=0;
	while(i<=n && j<=m) {
		if(ec[i].type!=3) {
			ans++;
			break;
		}
		else {
			while(j<=m && (p[j]-ec[i].dd)*2*ec[i].aa>(V*V-ec[i].vv*ec[i].vv))
				j++;
			while(i<=n) {
				if(ec[i].type!=2) {
					if(ec[i].dd>p[j-1]) break;
				}
				else {
					if((V*V-ec[i].vv*ec[i].vv)>=(p[j-1]-ec[i].dd)*2*ec[i].aa) break;
				}
				i++;
			}
			ans++;
		}
	}
	cout<<m-ans<<endl;
}

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--) {
		memset(ec,0,sizeof(ec));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		while(!cars.empty())
			cars.pop();
		n=read(); m=read(); L=read(); V=read();
//			cout<<n<<endl;
		if(n<=10 && m<=10) opt='S';
		else if(n<=20 && m<=20) opt='M';
		else opt='Q';
		d[1]=read(); v[1]=read(); a[1]=read();
		if(a[1]==0) opt='A';
		else if(a[1]>0) opt='B';
		else opt='C';
		for(int i=2;i<=n;i++) {
			d[i]=read(); v[i]=read(); a[i]=read();
			if(a[i]==0 && opt!='A') opt='Q';
			else if(a[i]>0 && opt!='B') opt='Q';
			else if(a[i]<0 && opt!='C') opt='Q';
		}
		for(int i=1;i<=m;i++) {
			p[i]=read();
		}
//		cout<<"ok\n";
		sort(p+1,p+1+m);
		if(opt=='A') {
			workA();
			continue;
		}
		else {
			workS();
			continue;
		}
	}
	return 0;
}

