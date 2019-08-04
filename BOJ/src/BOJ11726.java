import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ2579 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int[] arr;
	static int[] dp;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		arr = new int[n+1];
		dp = new int[n+1];
		for(int i=1; i<n+1; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		dp[1] = arr[1];
		if(n>=2) dp[2] = dp[1]+arr[2];
		
		for(int i=3; i<=n; i++) {
			dp[i] = Math.max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
			
		}
		
		bw.write(Integer.toString(dp[n]));
		
		bw.flush();
		bw.close();
	}

}
