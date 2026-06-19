#include<bits/stdc++.h>
using namespace std;
int T;
struct car{
	int d,v,a;
};
double shortsp(int vb,int a,int s){
	double temp = vb*vb + 2*a*s;
	if(temp >= 0)
		return (double)sqrt(temp);
	else return 0;
}
int popcount(int x){
	int ret = 0;
	while(x){
		ret++;
		x &= (x-1);
	}
	return ret;
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	
	while(T){
		T--;
		int n,m;
		
		int L,V;
		cin >> n >>m >>L>> V;
		car vc[100006];
		int plat[100006];
		bool isAtask = true,isBtask = true,isCtask = true;
		int tempm = m;
		set<double> cTask;
		int minnd = L+1,maxnd = 0;
		for(int i = 1;i<=n;i++){
			int di,vi,ai;
			cin >> di >> vi >> ai;
			if(ai!=0) isAtask = false;
			if(ai<=0) isBtask = false;
			if(ai>=0) isCtask = false;
			vc[i]= (car){di,vi,ai};
		}
		int far = 0;
		for(int i = 1;i<=m;i++) {
			cin>> plat[i];
			far = max(far,plat[i]);
		}
		int illegal = 0;
		for(int i =1;i<=n;i++){
			if(vc[i].a == 0){
				if(vc[i].v > V && vc[i].d <=far){
					illegal ++;
					//cout << vc[i].v<<" " <<V<<endl;
				}
			} 
			if(vc[i].a > 0 ) if(far-vc[i].d >= 0){
				illegal += (shortsp(vc[i].v,vc[i].a,far-vc[i].d) <= V?0:1);
				//cout << shortsp(vc[i].v,vc[i].a,far-vc[i].d) <<" " <<V<<endl;
			}
			if(vc[i].a < 0 ) {
				if(vc[i].v <= V) continue;
				if(far <vc[i].d) continue;
				int latestc = *lower_bound(plat+1,plat+1+m,vc[i].d);
				if(cTask.count(latestc)<=0) cTask.insert(latestc);
				illegal += (shortsp(vc[i].v,vc[i].a,(latestc-vc[i].d) )<= V?0:1);
				//cout << shortsp(vc[i].v,vc[i].a,(*lower_bound(plat+1,plat+1+m,vc[i].d))-vc[i].d) <<" " <<V<<endl;
			}
		}
		cout << illegal <<" ";
		if(illegal == 0) cout << m <<endl;
		else if(isAtask)
			cout << m-1 <<endl;
		else if(isBtask)
			cout << m-1 <<endl; 
		else if(n <= 10 && m <=10){
			int ans= 0; 
			for(int kkk =0;kkk<=(1<<(m+1))-1;kkk++){
				vector<double>newplat;
				int y = kkk;
				int sofaraway = 0;
				int nowww = 1;
				while(y){
					if((y&1) == 1) {
						newplat.push_back(plat[nowww]);
						sofaraway = max(sofaraway,plat[nowww]);
					}
					y = (y>>1);
					nowww++;
				}
				
				int ill = 0;
				
				for(int i =1;i<=n;i++){
					if(vc[i].a == 0){
						if(vc[i].v > V && vc[i].d <=sofaraway)
							ill ++;
					} 
					if(vc[i].a > 0 ) if(sofaraway-vc[i].d >= 0)
						ill += (shortsp(vc[i].v,vc[i].a,sofaraway-vc[i].d) <= V?0:1);
					if(vc[i].a < 0 ) {
						if(vc[i].v <= V) continue;
						if(sofaraway <vc[i].d) continue;
						int latestc = *lower_bound(newplat.begin(),newplat.end(),vc[i].d);
						ill += (shortsp(vc[i].v,vc[i].a,(latestc-vc[i].d) )<= V?0:1);
					}
				}
				if(ill == illegal) ans =max(ans,m-popcount(kkk));
			}
			cout << ans <<endl;
		}
		else if(isCtask){
			cout << m-cTask.size() <<endl;
		}
			 
		
	}
	
	
	
	
	return 0;
}
