class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = (hour % 12) * 30.0 + minutes * 0.5;
        double min_angle = minutes * 6.0;
        
        double diff = abs(hour_angle - min_angle);
        
        return min(diff, 360.0 - diff);
    }
};