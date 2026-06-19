#include<bits/stdc++.h>
using namespace std;
const int N=100009;
const int M=100009;
const int LL=1000009;
int T;
int n,m,L,V;
int p[N];
int ans,cnt;
int lst[M],num[M];
int o;
bool O;
struct Point{
	int l,r;
} imp[N],point[N];
int ef_r(int a){
	int l=1,r=m,mid;
	while(l<r){
//		cout<<"!";
		mid=(l+r)/2;
		if(p[mid]<a){
			l=mid+1;
		}
		else if(p[mid]==a){
			return mid;
		}
		else{
			r=mid;
		}
	}
	return l;
}
int ef_l(int a){//31181   1,10  5
	int l=1,r=m,mid;
	while(l<r){
//		cout<<"!";
		mid=(l+r)/2;
		if(p[mid]>a){
			r=mid-1;
		}
		else if(p[mid]==a){
			return mid;
		}
		else{
			if(p[mid+1]==a){
				return mid+1;
			}
			if(p[mid+1]<a){
				l=mid+1;
			}
			else{
				return mid;
			}
		}
	}
	if(p[l]>a){
		return 0;
	}
	return l;
}
void mark(int a,int b){//2*log(m)
	int ll=ef_r(a);//60366 68852
//	cout<<b<<endl;
	int rl=ef_l(b);
//	cout<<a<<' '<<b<<endl;
	if(ll>rl){
		return ;
	}
	else{
		point[++o].l=ll;
		point[o].r=rl;
//		cout<<a<<':'<<ll<<"       "<<b<<':'<<rl<<endl;
		return ;
	}
}
bool cmp(Point a,Point b){
	if(a.l<b.l){
		return 1;
	}
	if(a.l>b.l){
		return 0;
	}
	if(a.r<b.r){
		return 1;
	}
	return 0;
}
int dp(){//num_point
	cnt=1;
	lst[1]=0;
	fill(num+1,num+1+o,0);//3
	for(int i=1;i<=o;i++){//2,3 2,5 5,5
		for(int j=1;j<=cnt;j++){
			if(lst[j]<point[i].l){
				lst[j]=point[i].r;
				num[j]++;
				O=1;
				continue;
			}
		}
		if(O==0){
			lst[++cnt]=point[i].r;
			num[cnt]++;
		}
		O=0;
	}
//	cout<<cnt<<endl;
//	cout<<num[1]<<' '<<num[2]<<endl;
	int c=*max_element(num+1,num+cnt);
	return c;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			int d,v,a,s;
			cin>>d>>v>>a;
			if(a==0){
				if(v<=V){
					continue;
				}
				else{
					imp[i].l=d;
					imp[i].r=L;
					//mark(d,L)
				}
				continue;
			}
			s=d+(V*V-v*v)/2/a;    //****
			if(a<0){
				s=d+(V*V-v*v+1)/(2*a);
				imp[i].l=d;   //xiaoshu***
				imp[i].r=s;
				//mark(d,s)
			}
			else{
				s=d+(V*V-v*v)/(2*a)+1;
				imp[i].l=s;
				imp[i].r=L;
				//mark(s,L)
			}
		}
//		cout<<imp[4].l<<' '<<imp[4].r<<endl;
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			mark(imp[i].l,imp[i].r);
		}
		cout<<o<<' ';
		sort(point+1,point+1+o,cmp);
		cout<<m-dp()<<endl;
		o=0;
	}
	return 0;
} 
/*


62978:5       150579:10
51700:3       171479:10
40408:1       168951:10
60366:4       68852:5
35943:1       76957:6
47476:2       60794:3
59020:4       78548:6
81024:7       120491:8
80637:7       122838:9
66114:5       417547:10




nlogm+m

v1=sqrt(s*2a+v0^2)

1.计算s
2.标对应范围m


mark(a,b)

<<1
<<1+1


3.dp算min 

dp:
cnt=1
lst[m],num[m]   结束时间   数量
for(int i=1;i<=n;i++)
	for(int j=1;j<=cnt;j++)
		if(lst[j]<=a[i].l)
	 		lst[j]=a[i].r
	 		num[j]++;
	 		continue;
	lst[++cnt]=a[i].r
	num[cnt]++


return max_element(num+1,num+1+cnt




f[i]=f[i-1]()


ef?
check:



if(a&b)
a&b
else
a|b,cnt++;


5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

2:3  3g2


s<=(V^2-v0^2)/2a

0
4 4
1 4
1 3


[12,15]   15
(2,15]    5 8 9 15
[5,9)    5 8
重叠:a&b
else:a|b






2 2 2 2
-------
----- -
3-1
1 2 2


a加速度
v1瞬时速度
v0初速度 

已知v0 a t 
v1=v0+a*t
s=v0*t+0.5*a*t^2

已知v0 a s
v=sqrt(v0^2+2*a*s)

已知v0 a 
当s=(v1^2-v0^2)/2a
v=v1 

v1=sqrt(s*2a+v0^2)


*/
