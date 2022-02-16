class ParkingSystem {
private:
    int big;
    int medium;
    int small;
public:
    ParkingSystem(int b, int m, int s) {
        big = b;
        medium = m;
        small = s;
    }
    
    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (big > 0) {
                    big--;
                    return true;
                } else {
                    return false;
                }
                break;
            case 2:
                if (this->medium > 0) {
                    medium--;
                    return true;
                } else {
                    return false;
                }
                break;
            case 3:
                if (small > 0) {
                    small--;
                    return true;
                } else {
                    return false;
                }
                break;
            default:
                return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */