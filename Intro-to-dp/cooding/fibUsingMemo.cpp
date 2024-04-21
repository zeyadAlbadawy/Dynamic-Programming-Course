#include <iostream>
#include <vector>
using namespace std;
vector<int> memo;

int calcFib(int n) {
    // Base Case
    if(n <= 2) return 1; 
    if(memo[n] != -1) return memo[n];
    // Recursive Case
    return memo[n] = calcFib(n-1) + calcFib(n-2);
}
int main() {
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    cout << calcFib(n);

}