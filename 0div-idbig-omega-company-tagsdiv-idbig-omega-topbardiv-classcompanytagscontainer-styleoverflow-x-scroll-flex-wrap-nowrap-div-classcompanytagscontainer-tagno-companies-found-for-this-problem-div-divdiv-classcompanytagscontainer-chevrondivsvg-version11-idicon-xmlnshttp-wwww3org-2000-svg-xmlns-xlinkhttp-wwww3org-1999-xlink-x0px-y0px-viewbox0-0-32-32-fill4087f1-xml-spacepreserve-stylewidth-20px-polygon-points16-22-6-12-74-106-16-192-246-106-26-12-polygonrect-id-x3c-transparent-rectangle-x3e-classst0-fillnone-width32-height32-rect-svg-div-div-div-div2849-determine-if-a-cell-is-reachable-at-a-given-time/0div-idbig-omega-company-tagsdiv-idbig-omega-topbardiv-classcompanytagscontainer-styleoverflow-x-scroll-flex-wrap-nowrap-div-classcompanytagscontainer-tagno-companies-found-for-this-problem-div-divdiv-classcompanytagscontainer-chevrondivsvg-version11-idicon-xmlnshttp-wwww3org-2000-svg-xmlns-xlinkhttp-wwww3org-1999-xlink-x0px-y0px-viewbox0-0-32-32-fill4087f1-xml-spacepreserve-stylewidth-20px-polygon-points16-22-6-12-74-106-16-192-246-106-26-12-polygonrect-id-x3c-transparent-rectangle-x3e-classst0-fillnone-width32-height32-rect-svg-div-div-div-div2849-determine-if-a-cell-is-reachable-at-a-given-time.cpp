class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx &&fy==sy && t==1)
        {
            return false;
        }
        int diffx=abs(fx-sx);
        int diffy=abs(fy-sy);
        int maxd=max(diffx,diffy);
        if(t<maxd)
        {
            return false;
            
        }
        return true;
    }
};