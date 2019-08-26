import java.util.Scanner;

public class BOJ11052 {
	static int w[];
	static int dp[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		w = new int[n+1];
		dp = new int[n+1];
		for(int i=1; i<=n; i++) {
			w[i] = sc.nextInt();
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				dp[i] = Math.max(dp[i], dp[i-j]+w[j]);
			}
		}
		
		System.out.println(dp[n]);
		
		sc.close();
	}

}
