class ParkingSystem {
public:
int car[3];
    ParkingSystem(int big, int medium, int small) {
        car[0]=big;
        car[1]=medium;
        car[2]=small;
        
    }
    
    bool addCar(int carType) {
        if(carType==1 and car[0]>0){
            car[0]--;
            return 1;
            
        }
        else if(carType==2 and car[1]>0){
            car[1]--;
            return 1;
        }
        else if(carType==3 and car[2]>0)
        {
            car[2]--;
            return 1;
        }else
        return 0;
        
    }
};
