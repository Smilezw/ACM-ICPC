import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void  main(String args[]){
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigInteger n;
        int m;
        while(cin.hasNext()) {
          m = cin.nextInt();
          n = cin.nextBigInteger();
          BigInteger l = BigInteger.ZERO;
          BigInteger r = BigInteger.ONE;
          while(r.pow(m).compareTo(n) != 1) {      // r^m <= n
              l = r;
              r = r.multiply(BigInteger.valueOf(2));
          }
          while(l.add(BigInteger.valueOf(1)).compareTo(r) == -1) {   // l + 1 <= r
              BigInteger mid = (l.add(r)).divide(BigInteger.valueOf(2));
              if(mid.pow(m).compareTo(n) != 1) {   // mid ^ m <= n
                  l = mid;
              } else {
                  r = mid;
              }
          }
          BigInteger ans;
          if(r.pow(m).compareTo(n) != 1) {
              ans = r;
          } else {
              ans = l;
          }
          System.out.println(ans);
        }
    }
}
