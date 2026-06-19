#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long t, n, asum, bsum, csum, ap, bp, cp, maxx;
struct sl{
	long long num, id;
};
struct student{
	long long al, bl, cl;
}a[N];
struct node{
	long long costa, costb, f, s, t;
}c[N];
bool cmp(sl a, sl b){
	return a.num < b.num;
}
void solve(){
	cin >> n;
	asum = 0;
	bsum = 0;
	csum = 0;
	ap = 0;
	bp = 0;
	cp = 0;
	maxx = 0;
	long long d[N];
	priority_queue<pair<long long, long long>> pqa;
	priority_queue<pair<long long, long long>> pqb;
	priority_queue<pair<long long, long long>> pqc;
	for(int i = 1; i <= n; i++){
		sl temp[3];
		cin >> a[i].al >> a[i].bl >> a[i].cl;
		temp[0].num = a[i].al;
		temp[0].id = 0;
		temp[1].num = a[i].bl;
		temp[1].id = 1;
		temp[2].num = a[i].cl;
		temp[2].id = 2;
		sort(temp,temp+3, cmp);
		c[i].costa = temp[1].num - temp[2].num;
		c[i].costb = temp[0].num - temp[1].num;
		c[i].f = temp[2].id;
		c[i].s = temp[1].id;
		c[i].t = temp[0].id;
		maxx += temp[2].num;
		if(temp[2].id == 0){
			pqa.push({c[i].costa, i});
			d[i] = 0;
			ap++;
		}
		else if(temp[2].id == 1){
			pqb.push({c[i].costa, i});
			d[i] = 0;
			bp++;
		}
		else if(temp[2].id == 2){
			pqc.push({c[i].costa, i});
			d[i] = 0;
			cp++;
		}
		while(ap > (n/2) || bp > (n/2) || cp > (n/2)){
			int tempid, tempnum, go;//the number getting changed
			if(ap > (n / 2)){
				tempnum = pqa.top().first; 
				tempid =  pqa.top().second; 
				ap--; 
				pqa.pop(); 
			}
			else if(bp > (n / 2)){
				tempnum = pqb.top().first; 
				tempid =  pqb.top().second; 
				bp--; 
				pqb.pop();
			}
			else if(cp > (n / 2)){
				tempnum = pqc.top().first; 
				tempid =  pqc.top().second; 
				cp--; 
				pqc.pop();
			}
			tempnum += c[tempid].costa;
			maxx += c[tempid].costa;
			if(d[tempid] == 0){
				d[tempid] = 1;
				go = c[tempid].s; 
			} 
			else if(d[tempid] == 1){
				d[tempid] = 2;
				go = c[tempid].t; 
			}  
			if(go == 0){
				ap++;
				pqa.push({tempnum, go}); 
			}
			else if(go == 1){
				bp++;
				pqb.push({tempnum, go}); 
			} 
			else if(go == 2){
				cp++;
				pqc.push({tempnum, go}); 
			} 
		} 
	
	}
	cout << maxx << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
