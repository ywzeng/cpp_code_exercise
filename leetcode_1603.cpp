class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        ceil_big = big;
        ceil_medium = medium;
        ceil_small = small;
    }
    
    bool addCar(int carType) {
        switch(carType) {
            case 1:
                return cur_big < ceil_big ? ++cur_big : false;
            case 2:
                return cur_medium < ceil_medium ? ++cur_medium : false;
            case 3:
                return cur_small < ceil_small ? ++cur_small : false;
            default:
                break;
        }
        return false;
    }

private:
    int cur_big = 0, cur_medium = 0, cur_small = 0;
    int ceil_big, ceil_medium, ceil_small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
