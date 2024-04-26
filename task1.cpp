#include <iostream>
#include <cmath>

using namespace std;

class Line
{
    public:


        class Point
        {
        public:

        double x;
        double y;

        /*double distance(Point point)
        {
            double distance;
            distance = sqrt(pow(point.x-x, 2)+pow(point.y-y, 2));
            return distance;
        }*/
        friend istream& operator>>(istream& is, Point& p)
        {
            is >> p.x >> p.y;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Point& p)
        {
            os << "x: " << p.x << ", y: " << p.y;
            return os;
        }

        /*void dist(int size)
        {
            Point *dyn_points = new Point [size];
            for(int i=0; i<size; i++)
            {
                cout<<"Enter the number "<<i+1<<":";
                cin>>dyn_points[i];
            }

            double sum = 0;

            for(int i=1; i<size; i++)
            {
                double distance = sqrt(pow(dyn_points[i].x-dyn_points[i-1].x, 2)+pow(dyn_points[i].y-dyn_points[i-1].y, 2));
                sum += distance;
            }

            cout<<"Sum of distances between points is "<<sum<<endl;

            delete []dyn_points;
            dyn_points = nullptr;
        }*/
        };  
    
    void length(int size)
        {
            Point *dyn_points = new Point [size];
            for(int i=0; i<size; i++)
            {
                cout<<"Enter the number "<<i+1<<":";
                cin>>dyn_points[i];
            }

            double sum = 0;

            for(int i=1; i<size; i++)
            {
                double distance = sqrt(pow(dyn_points[i].x-dyn_points[i-1].x, 2)+pow(dyn_points[i].y-dyn_points[i-1].y, 2));
                sum += distance;
            }

            cout<<"Sum of distances between points is "<<sum<<endl;

            delete []dyn_points;
            dyn_points = nullptr;
        }

};


int main()
{
    /*Point a;
    Point b;

    a.x = 5;
    a.y = 10;

    b.x = 7;
    b.y = 12;*/

    //cout<<a.distance(b);
    Line line;

    int n;
    cout<<"Enter the number of points:";
    cin>>n;
    line.length(n);
}

