#include <iostream>
#include <vector>
using namespace std;

int calaNumberOfWays(int index, int n, bool flag) {
    // Base Case
    if(index == n+1) return 1;
    
    int ans = 0;
    // Place zero
    ans += calaNumberOfWays(index + 1, n, false);
    // Place One
    if(flag == false) {
        ans += calaNumberOfWays(index + 1, n, true);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << calaNumberOfWays(1, n, false);
    return 0;
}
