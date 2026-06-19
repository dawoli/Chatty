#include <bits/stdc++.h>
using namespace std;
int t,rund,n,m,l,v,i,o,big,small,pivot,lst,lst2;
double rc1,rc2,rc3;
long long ans1,ans2;
int d[100001];
int vv[100001];
int a[100001];
int p[100001];
int skips[100001];
int aaa[100001];
double cs[100001][2];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	for (rund = 0;rund<t;rund++){
		ans1=0;ans2=0;
		cin >> n >> m >> l >> v;
		for (i=0;i<n;i++)cin >> d[i] >> vv[i] >> a[i];
		for (i=0;i<m;i++)cin >> p[i];
		lst = 0;
		for (i=0;i<n;i++){
			if (a[i]<0){
				if (vv[i]>v){
					rc1 = (pow(v,2)-pow(vv[i],2))/(2.0*a[i]);
					rc1 += d[i];
					//d[i]-->rc1
					cs[lst][0] = d[i];cs[lst][1] = rc1;
					lst++;
					big = m;small=0;
					pivot = (big+small)/2; 
					while (pivot != small or pivot != big){
						pivot = (big+small)/2;
						if (p[pivot] > rc1)big = pivot;
						else if (p[pivot] < rc1 and p[pivot] >= d[i]){
							ans1++;
							break;
						}
						else{
							small = pivot+1;
						}
					}
				}
			}
			else if(a[i]>=0) {
				rc1 = pow(pow(vv[i],2)+2*a[i]*(p[m-1]-d[i]),0.5);//过最后一个测速器速度 
				if (rc1 > v)ans1++;
				if (a[i] == 0){
					if (vv[i]>v){
						cs[lst][0] = d[i];cs[lst][1] = l;
						lst++;	
					}
				}
				else{
					rc2 = (pow(v,2)-pow(vv[i],2))/(2.0*a[i]);
					rc2 += d[i];
					cs[lst][0] = rc2;cs[lst][1] = l;
					lst++;
				}
			}
			else{
				continue;
			}
		}
		//ans2 a=0only
		if (ans1>0)ans2=m-1;
		else{ans2=m;
		}
		cout << ans1 << " " << ans2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

