import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ1932 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int[][] dp;
	static int sum=0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		dp = new int[n+1][n+1];
		dp[0][1] = 0;
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				dp[i][j] = sc.nextInt();
				if(j==1)
					dp[i][j] = dp[i-1][j]+dp[i][j];
				else if(i==j)
					dp[i][j] = dp[i-1][j-1] + dp[i][j];
				else
					dp[i][j] = Math.max(dp[i-1][j-1], dp[i-1][j])+dp[i][j];
			
				if(sum<dp[i][j])
					sum = dp[i][j];
			}
		}
		System.out.println(sum);
	
	}
}
