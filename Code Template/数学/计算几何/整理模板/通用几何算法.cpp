//ŷ������  �� + �� = �� + 2 ��ƽ��ͼ��
//���˶���  �� + �� = �� + 2 ������ͼ��
const double eps = 1e-8;
const double PI = acoss(-1.0);
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}

struct Point {
    double x, y;
    Point(){}
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const {
        return Point(x - b.x, y - b.y);
    }
    //���
    double operator ^(const Point &b)const {
        return x * b.y - y * b.x;
    }
    //���
    double operator *(const Point &b)const {
        return x * b.x + y * b.y;
    }
    //��ԭ����ת�Ƕ�B������ֵ������x,y�ı仯
    void transXY(double B) {
        double tx = x, ty = y;
        x = tx * cos(B) - ty * sin(B);
        y = tx * sin(B) + ty * cos(B);
    }
};
//Line�Ķ���
struct Line {
    Point s, e;
    double k;
    Line(){}
    Line(Point _s, Point _e) {
        s = _s; e = _e;
        k = atan2(e.y - s.y,e.x - s.x);
    }
    //��ֱ���ཻ�󽻵�
    //��һ��ֵΪ0��ʾֱ���غϣ�Ϊ1��ʾƽ�У�Ϊ0��ʾ�ཻ��Ϊ2���ཻ
    //ֻ�е�һ��ֵΪ2ʱ�������������
    pair<int, Point> operator &(const Line &b)const {
        Point res = s;
        if (sgn((s - e) ^ (b.s - b.e)) == 0) {
            if (sgn ((s - b.e) ^ (b.s - b.e)) == 0)
                return make_pair(0, res);//�غ�
            else return make_pair(1, res);//ƽ��
        }
        double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return make_pair(2, res);
    }
};
//��������
double dist(Point a, Point b) {
    return sqrt((a - b) * (a - b));
}
//�ж��߶��ཻ
bool inter(Line l1,Line l2)
{
    return
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s)) <= 0 &&
        sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s)) <= 0;
}
//�ж�ֱ�ߺ��߶��ཻ
bool Seg_inter_line(Line l1, Line l2) {//�ж�ֱ��l1���߶�l2�Ƿ��ཻ
    return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}
//�㵽ֱ�ߵľ���
//����Ϊresult,�ǵ㵽ֱ������ĵ�
Point PointToLine(Point P, Line L) {
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    result.x = L.s.x + (L.e.x - L.s.x) * t;
    result.y = L.s.y + (L.e.y - L.s.y) * t;
    return result;
}
//�㵽�߶εľ���
//���ص㵽�߶����
Point NearestPointToLineSeg(Point P, Line L) {
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    if (t >= 0 && t <= 1) {
        result.x = L.s.x + (L.e.x - L.s.x) * t;
        result.y = L.s.y + (L.e.y - L.s.y) * t;
    }
    else {
        if (dist(P, L.s) < dist(P, L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
}
//�����������
//��ı�Ŵ�0~n-1
double CalcArea(Point p[], int n) {
    double res = 0;
    for (int i = 0; i < n; i++)
        res += (p[i] ^ p[(i+1)%n]) / 2;
    return fabs(res);
}
//�жϵ����߶���
bool OnSeg(Point P, Line L) {
    return
    sgn((L.s - P) ^ (L.e - P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
//�жϵ���͹�������
//���γ�һ��͹�������Ұ���ʱ������(�����˳ʱ��������<0��Ϊ>0)
//��ı�ţ�0~n-1
//����ֵ
//-1������͹�������
//0������͹����α߽���
//1���жϵ���͹�������
int inConvexPoly(Point a, Point p[], int n) {
    for (int i = 0; i < n; i++) {
        if (sgn((p[i] - a) ^ (p[(i+1)%n] - a)) < 0) return -1;
        else if (OnSeg(a, Line(p[i], p[(i+1)%n]))) return 0;
    }
    return 1;
}
//�жϵ�������������
//���߷���poly[]�Ķ�����Ҫ���ڵ���3����ı��0~n-1
//����ֵ
//-1:����͹�������
//0������͹����α߽���
//1:�жϵ���͹�������
int inPoly(Point p, Point poly[], int n) {
    int cnt;
    Line ray, side;
    cnt = 0;
    ray.s = p;
    ray.e.y = p.y;
    ray.e.x = -100000000000.0;//-INF��ע��ȡֵ��ֹԽ��
    for (int i = 0; i < n; i++) {
        side.s = poly[i];
        side.e = poly[(i+1)%n];
        if (OnSeg(p, side)) return 0;
        //���ƽ�����򲻿���
        if (sgn(side.s.y - side.e.y) == 0) continue;
        if (OnSeg(side.s ,ray)) {
            if (sgn(side.s.y - side.e.y) > 0) cnt++
        }
        else if (OnSeg(side.e, ray)) {
            if (sgn(side.e.y - side.s.y) > 0) cnt++;
        }
        else if (inter(ray, side)) cnt++;
    }
    if (cnt % 2 == 1) return 1;
    else return -1;
}
//�ж�͹�����
//�����߱�
//�������˳ʱ�����Ҳ��������ʱ�����
//��ı��1~n-1
bool isconvex(Point poly[], int n) {
    bool s[3];
    memset(s, false, sizeof(s));
    for (int i = 0; i < n; i++) {
        s[sgn((poly[(i+1)%n] - poly[i]) ^ (poly[(i+2)%n] - poly[i])) + 1] = true;
        if (s[0] && s[2]) return false;
    }
    return true;
}
