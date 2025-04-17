#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
    int x;
    int y;
    bool operator == (const Point &other) const
    {
        return (x == other.x) && (y == other.y);
    }
};

int orientation(const Point &a, const Point &b, const Point &c)
{
    // compute the orientaiton of the two sides whether
    // clockwise (-1) or counter clockwise(1). Point a is anchor point
    Point vector1 = {b.x - a.x, b.y - a.y};
    Point vector2 = {c.x - a.x, c.y - a.y};

    int cross_product = vector1.x*vector2.y - vector1.y*vector2.x;
    
    // return the cross product as 1 is the rotation is counter clockwise
    return cross_product > 0 ? 1 : -1;
}

bool cw(const Point &a, const Point &b, const Point &c, bool include_collinear)
{   
    // this function takes in 3 points and retuns if there are being rotation
    // in the clockwise direction. If they are all collinear (o = 0), we will consider
    // them as being rotation clockwise

    int o = orientation(a, b, c);
    return (o < 0) || (include_collinear && o == 0);
}

bool isCollinear(const Point &a, const Point &b, const Point &c)
{
    return orientation(a, b, c) == 0;
}

void convexHull(std::vector<Point> &points, const bool &include_collinear)
{
    // first find the bottommost point. If two points are tied for y, then the 
    // point with the least x coordinate is chosen
    auto min_point_ptr = std::min_element(points.begin(), points.end(), 
                                          [](const Point &a, const Point &b)
                                          {return std::make_pair(a.y, a.x) < std::make_pair(b.y, b.x);});
    Point p0 = *min_point_ptr;

    // sort the points now relative to the p0 in the increasing order of polar
    // angles 
    std::sort(points.begin(), points.end(), 
             [&p0](const Point &a, const Point &b)
             {
                int o = orientation(p0, a, b);

                if (o == 0)
                {
                    // when the points are collinear, we need to use the sort
                    // based on the distance
                    return std::pow(p0.x - a.x, 2) + std::pow(p0.y - a.y, 2) < 
                           std::pow(p0.x - b.x, 2) + std::pow(p0.y - b.y, 2);
                }
                return o < 0;
             });
    
    // after sorting the points based on the polar, we need to sort the collinear
    // points in the order of farther to nearest from p0
    if (include_collinear)
    {
        int i = (int)points.size() - 1;
        while(i >= 0 && orientation(p0, points[i], points.back()))
        {
            std::reverse(points.begin() + (i+1), points.end());
            i--;
        }
    }
    
    // Define a stack to push the convex hull points
    std::vector<Point> convex_hull;
    for (int i=1; i < points.size(); i++)
    {
        // Here the idea is simple, we constantly check if the last three points
        // pushed in the stack, form a clock wise roation and if not, we pop the 
        // lastest added point and keep checking cw(previous, current, next) and
        // if not cw, reject the current point

        while(convex_hull.size() > 1 && 
             !(cw(convex_hull[convex_hull.size()-2], convex_hull.back(), points[i], include_collinear)))
        {
            convex_hull.pop_back();
        }
        convex_hull.push_back(points[i]);
    }

    if(!include_collinear && convex_hull.size() == 2 && convex_hull[0] == convex_hull[0])
    {
        convex_hull.pop_back();
    }

    for (const auto &pt : convex_hull)
    {
        std::cout << "(" << pt.x << ", " << pt.y << ")" << "\n";
    }
}

int main()
{   
    std::vector<Point> points{{0, 3}, {1, 1}, {2, 2}, {4, 4}, 
                             {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    
    convexHull(points, false);
    
    return 0;
}