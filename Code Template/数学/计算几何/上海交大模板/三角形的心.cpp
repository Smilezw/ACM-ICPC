// ����Ĳ��� point a,b,c; �����ζ���
double area(point a,point b,point c) { return(fabs(det(b-a,c-a))/2); }// ���

point barycenter(point a,point b,point c){ //����
  return point ( (a.x+b.x+c.x)/3.0, (a.y+b.y+c.y)/3.0 );
}

point orthocenter(point a,point b,point c) { //����
  double dx,dy,d=(c.x-b.x)*(c.y-a.y)-(c.x-a.x)*(c.y-b.y);
  dx = (a.y*(c.y-b.y)+a.x*(c.x-b.x))*(c.y-a.y)-(b.y*(c.y-a.y)+b.x*(c.x-a.x))*(c.y-b.y);
  dy = (c.x-b.x)*(b.y*(c.y-a.y)+b.x*(c.x-a.x))-(c.x-a.x)*(a.y*(c.y-b.y)+a.x*(c.x-b.x));
  return point(dx/d, dy/d);
}

int circumcenter(point a,point b,point c) {  // ���ģ�ֱ��������������
  double A = dist(b,c), B = dist(a,c), C = dist(a,b);
  double P = (SQR(A) + SQR(B) + SQR(C))/2.0;
  double Q = 1.0/(1/(P-SQR(A)) + 1/(P-SQR(B)) + 1/(P-SQR(C)));
  double R = sqrt(P-Q)/2; //R Ϊ���Բ�뾶����Ҫʱ���ã������ɾȥ
  double d1 = Q/(P-SQR(A)),d2 = Q/(P-SQR(B)),d3 = Q/(P-SQR(C));
  return (1-d1)/2.0*a + (1-d2)/2.0*b + (1-d3)/2.0*c;
}

point incenter(point a,point b,point c) {
  double A = dist(b,c),B = dist(a,c), C = dist(a,b);
  double r = 2*area(a,b,c)/(A+B+C); //r Ϊ����Բ�뾶����Ҫʱ���ã������ɾȥ
  return point( (A*a.x + B*b.x + C*c.x)/(A+B+C), (A*a.y + B*b.y + C*c.y)/(A+B+C) );
}
