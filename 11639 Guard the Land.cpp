#include <iostream>
#include <vector>
using namespace std;


int calcArea(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (y2 - y1);
}


void findIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, 
                      int& ix1, int& iy1, int& ix2, int& iy2, bool& hasIntersection) {
   
    ix1 = max(x1, x3);
    iy1 = max(y1, y3);
    ix2 = min(x2, x4);
    iy2 = min(y2, y4);
    
    
    hasIntersection = (ix1 < ix2 && iy1 < iy2);
}

int main() {
    int n;
    cin >> n;
    
    
    vector<int> stronglySecured(n);
    vector<int> weaklySecured(n);
    vector<int> unsecured(n);
    
   
    for (int night = 0; night < n; night++) {
        
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
       
        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        
        
        int area1 = calcArea(x1, y1, x2, y2);
        int area2 = calcArea(x3, y3, x4, y4);
        
        
        int ix1, iy1, ix2, iy2;
        bool hasIntersection;
        findIntersection(x1, y1, x2, y2, x3, y3, x4, y4, ix1, iy1, ix2, iy2, hasIntersection);
        
        if (hasIntersection) {
            stronglySecured[night] = calcArea(ix1, iy1, ix2, iy2);
        } else {
            stronglySecured[night] = 0;
        }
        
        
        weaklySecured[night] = area1 + area2 - 2 * stronglySecured[night];
        
        
        const int TOTAL_LAND_AREA = 10000; 
        unsecured[night] = TOTAL_LAND_AREA - (stronglySecured[night] + weaklySecured[night]);
    }
    
    
    for (int night = 0; night < n; night++) {
        cout << "Night " << night + 1 << ": " 
             << stronglySecured[night] << " " 
             << weaklySecured[night] << " " 
             << unsecured[night] << endl;
    }
    
    return 0;
}