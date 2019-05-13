inline int sign(const double &a) {return a < -EPS ? -1 : a > EPS;}
inline double newSqrt(const double &x) {return x < 0 ? 0 : sqrt(x);}
struct Point {
   double x, y;
   Point() {}
   Point(double _x, double _y) : x(_x), y(_y) {}
   Point operator+(const Point&p) const { return Point(x + p.x, y + p.y); }
   Point operator-(const Point&p) const { return Point(x - p.x, y - p.y); }
   Point operator*(double d) const { return Point(x * d, y * d); }
   Point operator/(double d) const { return Point(x / d, y / d); }

   bool operator<(const Point&p) const {
     int c = sign(x - p.x);
     if (c) return c == -1;
     return sign(y - p.y) == -1;
   }

   double dot(const Point&p) const { return x * p.x + y * p.y; }  //点积叉积
   double det(const Point&p) const { return x * p.y - y * p.x; }

   Point rotAlpha(const double &alpha, const Point &o = Point(0, 0)) const { // 顺时针方向旋�