#include "obj.h"  
class Plane : public GameObject {
public:
    double x;
    double y;
    double heading;
    double altitude;
    double speed;
    double waypointX; 
    double waypointY; 

    Plane(double x, double y, double heading, double altitude, double speed)
        : GameObject(x, y, 50.0, 50.0),
          x(x),
          y(y),
          heading(heading),
          altitude(altitude),
          speed(speed),
          currentBank(currentBank)
    {
    }

    void goToWaypoint(Plane& plane);
    void render(SDL_Renderer* renderer);
};
