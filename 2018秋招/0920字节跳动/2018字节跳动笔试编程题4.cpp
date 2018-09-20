/*

*/

#include <iostream>

using namespace std;

long long fac(int x) {  
    long long f = 1;  
    for(int i=1;i<=x;i++)  
        f*=i;  
    return f;  
} 

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    long long  res = fac(m+n+k) / (fac(n) * fac(m) * fac(k));
    cout << res << endl;
    return 0; 
}