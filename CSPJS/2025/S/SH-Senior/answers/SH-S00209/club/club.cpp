#include<bits/stdc++.h>
using namespace std;
struct club{
	int k[4]={0,0,0,0};
	int x;//x为第一部门满意度； 
	int y;
	int z;
	int change,del,now;
	int pp,qq;//now为当前部门，change为要改变至的部门，del为减小的值 pp为改前满意度，pp为改后 
};
bool cmp(club al,club be){
	return al.del<be.del;
}
club a[100005],d[100005],e[100005],f[100005];
int dc,ec,fc;//依次为三个部门的员工 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin>>ttt;
	for(int zz=1;zz<=ttt;zz++){
	int n;
	cin>>n;
	dc=0,ec=0,fc=0;
	for(int i=1;i<=100005;i++){
		a[i].x=0;
		a[i].y=0;
		a[i].z=0;
		a[i].change=0;
		a[i].del=0;
		a[i].pp=0;
		a[i].qq=0;
		a[i].now=0;
	}
	for(int i=1;i<=100005;i++){
		d[i].x=0;
		d[i].y=0;
		d[i].z=0;
		d[i].change=0;
		d[i].del=0;
		d[i].pp=0;
		d[i].qq=0;
		d[i].now=0;
	}
	for(int i=1;i<=100005;i++){
		e[i].x=0;
		e[i].y=0;
		e[i].z=0;
		e[i].change=0;
		e[i].del=0;
		e[i].pp=0;
		e[i].qq=0;
		e[i].now=0;
	}
	for(int i=1;i<=100005;i++){
		f[i].x=0;
		f[i].y=0;
		f[i].z=0;
		f[i].change=0;
		f[i].del=0;
		f[i].pp=0;
		f[i].qq=0;
		f[i].now=0;
	}
	for(int i=1;i<=n;i++){
	//排序 
	cin>>a[i].x>>a[i].y>>a[i].z;
	if(a[i].x>a[i].y){
		if(a[i].y>a[i].z){
			a[i].k[1]=1,a[i].k[2]=2,a[i].k[3]=3;
		}
		else{
			a[i].k[3]=2;
			if(a[i].x>a[i].z)
			a[i].k[1]=1,a[i].k[2]=3;
			else a[i].k[1]=3,a[i].k[2]=1;
		}
	}
	else{
		if(a[i].y<a[i].z){
			a[i].k[1]=3,a[i].k[2]=2,a[i].k[3]=1;
		}
		else{
			a[i].k[1]=2;
			if(a[i].z>a[i].x)a[i].k[2]=3,a[i].k[3]=1;
			else a[i].k[2]=1,a[i].k[3]=3;
		}
	}
		a[i].now=a[i].k[1];
		a[i].change=a[i].k[2];
		int ll=a[i].now,mm=a[i].change;
		if(ll==1)ll=a[i].x;
		else if(ll==2)ll=a[i].y;
		else if(ll==3)ll=a[i].z;
		if(mm==1)mm=a[i].x;
		else if(mm==2)mm=a[i].y;
		else if(mm==3)mm=a[i].z;
		a[i].pp=ll,a[i].qq=mm;
		a[i].del=ll-mm;//cout<<a[i].del<<endl;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		int tp=a[i].now;
		sum+=a[i].pp;
		if(tp==1){
			dc++;
			d[dc].x=a[i].x;
			d[dc].y=a[i].y;
			d[dc].z=a[i].z;
			d[dc].pp=a[i].pp;
			d[dc].qq=a[i].qq;
			d[dc].change=a[i].change;
			d[dc].del=a[i].del;
			d[dc].now=a[i].now;
		}
		if(tp==2){
			ec++;
			e[ec].x=a[i].x;
			e[ec].y=a[i].y;
			e[ec].z=a[i].z;
			e[ec].pp=a[i].pp;
			e[ec].qq=a[i].qq;
			e[ec].change=a[i].change;
			e[ec].del=a[i].del;
			e[ec].now=a[i].now;
		}
		if(tp==3){
			fc++;
			f[fc].x=a[i].x;
			f[fc].y=a[i].y;
			f[fc].z=a[i].z;
			f[fc].pp=a[i].pp;
			f[fc].qq=a[i].qq;
			f[fc].change=a[i].change;
			f[fc].del=a[i].del;
			f[fc].now=a[i].now;
		}
	}//把所有人放在第一志愿
	//for(int j=1;j<=dc;j++)cout<<d[j].pp<<" ";cout<<endl;
	//for(int j=1;j<=ec;j++)cout<<e[j].pp<<" ";cout<<endl;
	//for(int j=1;j<=fc;j++)cout<<f[j].pp<<" ";cout<<endl;
	int mx=max(max(dc,ec),fc);
	if(max(max(dc,ec),fc)<=n/2){
		cout<<sum<<endl;continue;
	} 
	sort(d+1,d+1+dc,cmp);
	sort(e+1,e+1+ec,cmp);
	sort(f+1,f+1+fc,cmp);//按照变化后满意度减少量，给这些社员从小到大排序，优先选择差量小的调配 
	int dell=mx-n/2;
	if(mx==dc){
		for(int i=1;i<=dell;i++){
			sum-=d[i].del;//cout<<d[i].del<<" "<<d[i].now<<"->"<<d[i].change<<endl;
		}
	}
	if(mx==ec){
		for(int i=1;i<=dell;i++){
			sum-=e[i].del;//cout<<e[i].del<<" "<<e[i].now<<"->"<<e[i].change<<endl;;
		}
	}
	if(mx==fc){
		for(int i=1;i<=dell;i++){
			sum-=f[i].del;//cout<<f[i].del<<" "<<f[i].now<<"->"<<f[i].change<<endl;;
		}
	}cout<<sum<<endl;	
	}
	return 0;
}
//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
