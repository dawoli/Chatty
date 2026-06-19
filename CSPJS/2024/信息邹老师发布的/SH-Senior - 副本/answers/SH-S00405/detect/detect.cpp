#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, p, v, a, detector[100010], L, V;
vector<int> recorded[100010];
//4*(1+1+100010*4+1+1)=4*400044=1600000
double pos0[100010], pos1[100010];
//200020*8=1600000
int bucketsort[100010];
int ans1, ans2;

//formula:  (V2)^2-(V1)^2/(2*acc)
bool cmp(vector<int> i, vector<int> j){
	return i.size()>j.size();
}


int main() {

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t; cin>>t;

    while(t--){

        ans1=0; ans2=0;

        cin >> n >> m >> L >> V;
        //cout << "----------1----------\n";
        for(int i=1;i<=n;i++){
            cin >> p >> v >> a;
            if(v>V && a>=0){
                pos0[i]=p;
                pos1[i]=L;
            }
            else if(v<=V && a<=0){
                pos0[i] = -1;
                pos1[i] = -1;
            }
            else if(a<0){
                pos0[i] = p;
                pos1[i] = (V*V-v*v)/(2.0*a)+p; // position when the car exceeds the speed limit aka chaosus
            }
            else if(a>0){
                pos0[i] = (V*V-v*v)/(2.0*a)+p;
                pos1[i] = L;
            }
        }
        //cout << "----------2----------\n";
        for(int i=1;i<=m;i++){
            cin >> detector[i];
        }

		//cout << "----------3----------\n";
        for(int i=1; i<=n;i++){
        	//printf("%d: ",i);
            bool first=true;
            for(int j=1; j<=m; j++){
            	//cout << j << ", ";
                if(detector[j]>=pos0[i] && detector[j] <= pos1[i]){
                    recorded[j].push_back(i);
                    bucketsort[i]++;
                    if(first){ans1++;first=false;}
                }
            }
            //cout << endl;
        }

        cout << ans1 << " ";

        sort(recorded+1, recorded+1+m, cmp);
        for(int j=1;j<=m;j++) {
			bool flag=true;
	        for(int i=0; i<recorded[j].size();i++){
		       	bucketsort[recorded[j][i]]--;
		       	//cout << bucketsort[recorded[j][i]] << " ";
				if(bucketsort[recorded[j][i]] == 0){
			     	flag=false;
			        for(int k=0;k<=i;k++){
			            bucketsort[recorded[j][k]]++;
					}
			        break;
				}
			}
			if(flag)ans2++;
		}
        cout << ans2 << endl;



    }

    return 0;
}
