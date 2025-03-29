#define BIG 1
#define MEDIUM 2
#define SMALL 3
using namespace std;

class ParkingSystem {
private:
    int big, medium, small;

public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;    
        this->medium = medium;    
        this->small = small;    
    }
    
    bool addCar(int carType) {
        if(carType == BIG) {
            if(!this->big) return false;
            this->big -= 1;
        }
        else if(carType == MEDIUM) {
            if(!this->medium) return false;
            this->medium -= 1;
        }
        else if(carType == SMALL) {
            if(!this->small) return false;
            this->small -= 1;
        }
        return true;
    }
};