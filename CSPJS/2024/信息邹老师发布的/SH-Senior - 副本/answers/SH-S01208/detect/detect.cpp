#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int INF = 1E6 + 1;
class Car
{
    public:
    int v0, acc, d0;
    vector<double> velocities;
    bool will_overspeed = false;
    int overspeed_begin = INF, overspeed_end = INF;

    Car() : v0(0), acc(0), d0(0) {}

    Car(int d, int v, int a) : v0(v), acc(a), d0(d)
    {
        this->velocities = vector<double>(1, v0);
    }
};

int calc_v(vector<Car>& cars, vector<int>& detectors, int V)
{
    int ans = 0;
    for (auto& car : cars)
    {    
        if (car.acc <= 0 && car.v0 <= V)
            continue;
        if (car.acc == 0 && car.v0 > V && car.d0 <= *detectors.rbegin())
        {
            car.will_overspeed = true;
            for (auto d : detectors)
                if (d >= car.d0){ car.overspeed_begin = d; break;}
            continue;
        }
        for (int i = 0, d = detectors[i]; i < detectors.size(); i++, d = detectors[i])
            if (d >= car.d0 && (car.acc > 0 || car.v0 > V))
            {
                double f = car.v0 * car.v0 + 2 * car.acc * (d - car.d0);
                if ( f < 0 )
                {
                    if (car.will_overspeed && i > 0)  
                        if (*car.velocities.rbegin() > V)
                            car.overspeed_end = detectors[i - 1];
                    
                    
                    car.velocities.push_back(0);
                    continue;
                }
                double v = sqrt(f);
                if (v > V){car.will_overspeed = true; car.overspeed_begin = ( car.overspeed_begin == INF) ? d : car.overspeed_begin;}
                if ( v <= V && car.will_overspeed && *car.velocities.rbegin() > V) car.overspeed_end = detectors[i - 1];
                car.velocities.push_back(v);
            }
    }
    for (auto& car : cars) if (car.will_overspeed) ans++;
/*    cout << "Overspeed cars: " << endl;
    for (auto& car : cars)
    {    
        if (car.will_overspeed == false) continue;
        cout << "v0: " << car.v0 << " acc: " << car.acc << " d0 " << car.d0;
        cout << " velocities: ";
        for (auto v : car.velocities)
            cout << v << " ";
        cout << endl;
    }
*/   
    return ans;
}

int minimize_detectors(vector<Car>& cars, int L)
{
    int minimum_detectors = 0;
    int interval_begin = 0, interval_end = 0;
    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) { return a.overspeed_begin < b.overspeed_begin; });
    for (auto& car : cars) if (car.will_overspeed && car.overspeed_end == INF) car.overspeed_end = L;
    for (auto& car : cars)
    {
        if (!car.will_overspeed) continue;
       // cout << "Overspeed interval: " << car.overspeed_begin << " to " << car.overspeed_end << endl;
        if (car.overspeed_begin > interval_end)
        {
            minimum_detectors++;
            interval_begin = car.overspeed_begin;
            interval_end = car.overspeed_end;
            //cout << "New interval: " << interval_begin << " to " << interval_end << endl;
            continue;
        }
        interval_begin = car.overspeed_begin;
        if (car.overspeed_end < interval_end) interval_end = car.overspeed_end;
        //cout << "Modified interval: " << interval_begin << " to " << interval_end << endl;        
    } 
    return minimum_detectors;  
}

void loop()
{
    int n, m, L, V;
    cin >> n >> m >> L >> V;
    vector<Car> cars(n);
    vector<int> detectors(m);
    for (int i = 0; i < n; i++)
    {
        int d, v, a;
        cin >> d >> v >> a;
        cars[i] = Car(d, v, a);
    }
    for (int i = 0; i < m; i++)
        cin >> detectors[i];
    //cout << "Read complete." << endl;
    int count_overspeed = calc_v(cars, detectors, V);
    int minimum_detectors = minimize_detectors(cars, L);
    cout << count_overspeed << " " << n - minimum_detectors << endl;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) loop();
    return 0;
}