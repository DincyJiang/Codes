/*

*/

#include <iostream>
#include <vector>
#define maxx 1000005
using namespace std;

vector<int> prime(maxx, 0);
vector<int> p(maxx, 0);

void init() { //素数筛
    int k=0;
    for(int i=2;i<=maxx;i++)
        if(!prime[i]) {
            p[k++]=i;
            for(int j=2*i;j<=maxx;j+=i)
                prime[j]=1;
        }
}

int main() {
    init();
    int n;
    cin >> n;
    int sum=1;
    for(int i = 0; p[i] <= n; i++)
        for(int j = p[i]; j <= n; j *= p[i])
            sum = max(sum,j);

    cout << sum*2 << endl;
    return 0;
}