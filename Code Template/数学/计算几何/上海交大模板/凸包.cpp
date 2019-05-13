vector<Point> convexHull(vector<Point> ps) {
  int n = ps.size(); if (n <= 1) return ps;
  sort(ps.begin(), ps.end());
  vector<Point> qs;
  for (int i = 0; i < n; qs.push_back(ps[i++]))
    while (qs.size() > 1 && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0) qs.pop_back();
      for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--]))
         while ((int)qs.size() > t && crossOp(qs[(int)qs.size()-2],qs.back(),ps[i]) <= 0) qs.pop_back();
          qs.pop_back(); return qs;
}

double convexDiameter(const vector<Point>&ps) { 
      int n = ps.size(), is = 0, js = 0;
      for (int i = 1; i < n; ++i) {
        if (ps[i].x > ps[is].x) is = i;
        if (ps[i].x < ps[js].x) js = i;
      }
      double maxd = (ps[is] - ps[js]).abs();
      int i = is, j = js;
      do {
        if ((ps[(i + 1) % n] - ps[i]).det(ps[(j + 1) % n] - ps[j]) >= 0) (++j) %= n;
        else (++i) %= n;
        maxd = max(maxd, (ps[i] - ps[j]).abs());
      }while (i != is || j != js);
      return maxd;
}
