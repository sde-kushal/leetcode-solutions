using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(maxDoubles > 0 && target > 1) {
            if(target%2 == 0) {
                target /= 2;
                maxDoubles -= 1;
            }
            else    target -= 1;

            moves += 1;
        }

        return moves + target - 1;
    }
};