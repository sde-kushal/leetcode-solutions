using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        // halfGridSquares(t) = no of squares in n*n grid in one side of the diagonal = n(n-1)/2
        // without_borders = t + n - n - n + 1 = t - n + 1
        // ans = 4*without_borders + 1 + (n-1)*4
        // ans = 4t + 1

        long long halfGridSquares = n%2 == 0 ? (long long)(n/2)*(n-1) : (long long)n*((n-1)/2);
        return 4*halfGridSquares + 1;   
    }
};