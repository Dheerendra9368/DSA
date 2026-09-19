class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestx=-1;
        int nearesty=-1;
        if(x2<xCenter) nearestx=x2;
        else if(x1>xCenter) nearestx=x1;
        else nearestx=xCenter;
        if(y2<yCenter) nearesty=y2;
        else if(y1>yCenter) nearesty=y1;
        else nearesty=yCenter;
        int dx=nearestx-xCenter;
        int dy=nearesty-yCenter;
        return dx*dx+dy*dy<=radius*radius;
    }
};