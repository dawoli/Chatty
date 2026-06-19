#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#define d long double 
using namespace std;
int t,n,m,l,v,ts,tv,ta,tl=200002;
pair<int,int> cid[100001],dp[100001];
struct car{
	d s;//start position
	d v;//V0
	d a;
	d os;//overspeed range start
	d oe;//overspeed range end
	bool dt=0;//detected
}c[100001];
struct detector{
	d p;//position
	vector<int> c;//cars it can detect;
}dt[100001];
struct node{
	int i;//id
	int f;
	int ls;
	int rs;
	int pl;
	int pr;
	vector<int> c;//cars it can detect;
}tn[400004];
void adnd(int n,int l,int r){//treeid,posl,posr
	tn[n].i=n;
	tn[n].f=tn[n].i/2;
	if(n<200002){
		tn[n].ls=n*2;
		tn[n].rs=n*2+1;
		tn[n].pl=tn[tn[n].ls].pl;
		tn[n].pr=tn[tn[n].rs].pr;
	}else{
		tn[n].ls=-1;
		tn[n].rs=-1;
		tn[n].pl=l;
		tn[n].pr=r;
	}
	if(tn[n].f!=0){
		adnd(tn[n].f,tn[n].pl,tn[n].pr);
	}
	return;
}
void adc(int cn,int cl,int cr,int np){
	if(cl<=tn[np].pl&&cr>=tn[np].pr){
		tn[np].c.push_back(cn);
		return;
	}
	if(cl>tn[np].pr||cr<tn[np].pl){
		return;
	}
	if(tn[np].ls!=-1)adc(cn,cl,cr,tn[np].ls);
	if(tn[np].rs!=-1)adc(cn,cl,cr,tn[np].rs);
}
int md(int p,int ni){
	if(tn[ni].pl==tn[ni].pr){
		return tn[ni].pr;
	}
	if(tn[tn[ni].rs].pr>=p&&tn[tn[ni].rs].pl<=p){
		return md(p,tn[ni].rs);
	}
	if(tn[tn[ni].ls].pl<=p){
		return md(p,tn[ni].ls);
	}
	return -1;
	
}
bool idcmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}//get increasing queue
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		scanf("%d%d%d%d",&n,&m,&l,&v);
		int ans1=0,ans2=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ts,&tv,&ta);
//			printf("\n%d\n",i);
//			printf("\n%d %d %d\n",ts,tv,ta);
			c[i].s=ts;
			c[i].v=tv;
			c[i].a=ta;
		}
		for(int i=0;i<m;i++){
			scanf("%d",&ts);			
//			cout<<endl<<ts<<endl;
			dp[i]=make_pair(i,ts);
		}
		sort(dp,dp+m,idcmp);
		for(int i=0;i<m;i++){
			dt[i].p=dp[i].second;
//			cout<<dp[i].second<<endl;
		}
		for(int i=200002;i<200002+m;i++){
			adnd(i,dt[i].p,dt[i].p);
		}
		for(int i=0;i<n;i++){
			if(c[i].v<=v&&c[i].a<=0){
				c[i].os=l+1;
				c[i].oe=l+1;
			}else{
				if(c[i].a!=0){
					int x=((d)(v*v-c[i].v*c[i].v))/((d)(2*c[i].a))+c[i].s;
					if(c[i].v<=v){
						c[i].os=min(l,x);
						c[i].oe=l;
					}else{
						c[i].os=c[i].s;
						c[i].oe=min(l,x);
					}
				}
				else{
					c[i].os=c[i].s;
					c[i].oe=l;
				}
			}
			cid[i]=make_pair(i,c[i].oe);
			adc(i,c[i].os,c[i].oe,1);
		}
		sort(cid,cid+n,idcmp);
		
		for(int j=n-1;j>=0;j--){//car
			int tn=0;
			int mnum=0,mid=-1;
//			cout<<endl;
			
			for(int p=0;p<n;p++){//detector
//				cout<<"1 ";
				for(int k=0;k<n;k++){//car
					if(c[k].dt==0&&c[k].os<=dp[p].second&&c[k].oe>=dp[p].second){
						tn++;
//						cout<<endl<<j<<endl;
					}
				}
				
//				if(c[j].dt==0&&c[j].os<=dp[p].second&&c[j].oe>=dp[p].second){
//					tn++;
////					cout<<endl<<j<<endl;
//				}
			}
			if(tn>=mnum&&c[j].dt==0){
				mnum=tn;
				mid=j;
			}
//			cout<<endl<<mid<<endl;
			if(c[j].dt==0&&mid!=-1){
				ans2++;
//				cout<<endl<<mid<<endl;
			}
//			cout<<endl<<dp[mid].second<<endl;
			if(c[j].dt==0)for(int j=0;j<n;j++){
				if(c[j].os<=dp[mid].second&&c[j].oe>=dp[mid].second){
					c[j].dt=1;
				}
			}
		}
	
		
		
//		for(int i=0;i<n;i++){
//			car tc=c[cid[i].first];
//			if(!tc.dt){
//				int ld=md(tc.oe,1);
//				int mnum=0,mid=0;
//				while(tn[ld].pl>=tc.os&&tn[ld].pr<=tc.oe){
//					int tempid=ld,tempnum=0;
//					while(tempid>0){
//						tempnum+=tn[tempid].c.size();
//						tempid=tn[tempid].f;
//					}
//					if(mnum<=tempnum){
//						mnum=tempnum;
//						mid=ld;
//					}
//					ld--;
//				}
//				if(mid>0){
//					ans2++;
//				}
//				while(mid>0){
//					for(int j=0;j<tn[mid].c.size();j++){
//						c[tn[mid].c[j]].dt=1;
//					}
//					for(int j=0;j<tn[mid].c.size();j++){
//						tn[mid].c.pop_back();
//					}
//				}
//				
//			}
//		}
		for(int i=0;i<n;i++){
			if(c[i].dt){
				ans1++;
			}
		}
//		for(int i=0;i<n;i++){
//			cout<<endl;
//			cout<<c[i].dt<<" "<<c[i].os<<" "<<c[i].oe<<endl;
//		}
		printf("%d %d\n",ans1,ans2);
	}
	fclose(stdin);
	fclose(stdout);
}
/*
1
 5 5 15 3
 0 3 0
 12 4 0
 1 1 4
 5 5 -2
 6 4 -4
 2 5 8 9 15
*/
