using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) 
            return true;

        int low = 1, high = num/2;
        int mid;

        while(low<=high) {
            mid = low + (high-low)/2;

            if(mid == num/mid && num%mid==0)
                return true;

            if(mid > num/mid)   
                high = mid-1;
            else                
                low = mid+1; 
        }

        return false;
    }
};