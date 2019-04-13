import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	static BigInteger one = new BigInteger ("1");
	static BigInteger two = new BigInteger ("2");
	static BigInteger zero = new BigInteger ("0");

	static int judge(BigInteger a){
		BigInteger L=zero, R = a, M;
		while(R.compareTo(L) >= 0){
			M = (L.add(R).divide(two));
			int ans = M.multiply(M).compareTo(a);
			if(ans == 0) return 1;
			else if(ans > 0 ) R = M.subtract(one);
			else L=M.add(one);
		}
		return 0;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
    	BigInteger n, m;
        while(T!=0) {
        	T--;
        	n = in.nextBigInteger();
        	m = n.multiply(n.subtract(one)).divide(two);
        	int ans1 = 0, ans2 = 0;

        	ans1 = judge(n); ans2 = judge(m);

        	if(ans1 == 1 && ans2 == 1)
        		System.out.println("Arena of Valor");
        	else if(ans1 == 1 && ans2 == 0)
        		System.out.println("Hearth Stone");
        	else if(ans1 == 0 && ans2 == 1)
        		System.out.println("Clash Royale");
        	else
        		System.out.println("League of Legends");
        }
    }
}


//System.out.format("zzzzz  %d %d\n", n, m);
//System.out.format("sadad  %d %d\n", ans1, ans2);

/*
BigInteger add(BigInteger other) 
BigInteger subtract(BigInteger other) 
BigInteger multiply(BigInteger other) 
BigInteger divide(BigInteger other) 
BigInteger mod(BigInteger other) 
int compareTo(BigInteger other) 
static BigInteger valueOf(long x) 
*/
