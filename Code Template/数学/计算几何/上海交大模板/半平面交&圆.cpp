struct Circle {
  Point o; double r;
  bool contain(const Circle &that, const int &c) const {
    return sign(r - (o - that.o).abs() - that.r) > c;
  }
  bool disjuct(const Circle &that, const int &c) const { // c=0 为严格 , c=-1 为不严格,
    return sign((o - that.o).abs() - r - that.r) > c;
  }
};

bool isCL(Circle a, Point l1, Point l2, Point &p1, Point &p2) { // 求圆与直线的交点，包含相切,
    if (sign(distPL(a.o, l1, l2) - a.r) > 0) return false;
    Point o2 = a.o + (l2 - l1).rot90(); o2 = isSS(a.o, o2, l1, l2);
    double t = newSqrt(a.r * a.r - (o2 - a.o).abs2());
    p1 = o2 + (l2 - l1).unit() * t, p2 = o2 - (l2 - l1).unit() * t;
    return true;
}

bool isCC(Circle a, Circle b, Point &p1, Point &p2) { // 求圆与圆的交点，包含相切，假设无重圆,
    if (a.contain(b, 0) || b.contain(a, 0) || a.disjuct(b, 0)) return false;
    double s1 = (a.o - b.o).abs();
    double s2 = (a.r * a.r - b.r * b.r) / s1;
    double aa = (s1 + s2) / 2, bb = (s1 - s2) / 2;
    Point mm = (b.o - a.o) * (aa / (aa + bb)) + a.o;
    double h = newSqrt(a.r * a.r - aa * aa);
    Point vv = (b.o - a.o).unit().rot90() * h;
    p1 = mm + vv, p2 = mm - vv;
    return true;
}

bool contain(vector<Point> polygon, Point p) { // 判断点 p 是否被 多边形包含，包括落在边界上,
    int ret = 0, n = polygon.size();
    for(int i = 0; i < n; ++ i) {
        Point u = polygon[i], v = polygon[(i + 1) % n];
        if (inSeg(u, v, p)) return true;
        if (sign(u.y - v.y) <= 0) swap(u, v);
        if (sign(p.y - u.y) > 0 || sign(p.y - v.y) <= 0) continue;
        ret += sign((v - p).det(u - p)) > 0;
    }
    return ret & 1;
}

vector<Point> convexCut(const vector<Point>&ps, Point q1, Point q2) { // 用半平面 (q1,q2) 的逆时针方向去切凸多边形,
    vector<Point> qs; int n = ps.size();
    for (int i = 0; i < n; ++i) {
        Point p1 = ps[i], p2 = ps[(i + 1) % n];
        int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
        if (d1 >= 0) qs.push_back(p1);
        if (d1 * d2 < 0) qs.push_back(isSS(p1, p2, q1, q2));
    }
    return qs;
}
