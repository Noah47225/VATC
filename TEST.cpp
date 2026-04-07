#include "plane.h"
include <cmath>

void Plane::makeTurn(double waypointX, double waypointY)
{
    //find the heading needed to get to the waypoint
    
    
    void findDeparturePoints(float& theta1, float& theta2)
    {
        double dx = waypointX - rect.x;
        double dy = waypointY - rect.y;
        
        //find radius
        double radiusOfTurn = std::pow(speed,2)/(32.174 * std::tan(heading * M_PI / 180.0));
        double turnRate = speed / radiusOfTurn;
        //find centers
        double xc = x
        double yc = y+radiusOfTurn;
        //find where the tangent of the waypint heading line meats the circle
        radiusOfturn = std::sqrt(std::pow((waypointX-xc),2) + std::pow((waypointY-yc),2));
        //find distance between the center and the waypoint 
        // Returns the two departure angles (radians) on the circle
        
        double L  = std::sqrt(dx * dx + dy * dy);
        //find the heading to the waypoint
        double phi   = std::atan2(dy, dx);
        double alpha = std::acos(radiusOfTurn / L);
 
        double  theta1 = phi + alpha;
        double theta2 = phi - alpha;
    }
 
    
    void pickBestDeparture(float centerX, float centerY, float radius, bool travelCCW){
        float theta1, theta2;
        findDeparturePoints(centerX, centerY, radius, theta1, theta2);
 
        auto arcDist = [&](float from, float to) -> float {
            float d = travelCCW ? (to - from) : (from - to);
            d = std::fmod(d, 2.0f * M_PI);
            if (d < 0) d += 2.0f * M_PI;
            return d;
        };
 
        return arcDist(currentAngle, theta1) < arcDist(currentAngle, theta2) ? theta1 : theta2;
    }
};
    void moveAroundCircle(float centerX, float centerY, float radius, float speed)
    {
        float currentAngle = std::atan2(y - centerY, x - centerX);
        float newAngle     = currentAngle + speed;
 
        x = centerX + radius * std::cos(newAngle);
        y = centerY + radius * std::sin(newAngle);
    }





   













    
    
    


