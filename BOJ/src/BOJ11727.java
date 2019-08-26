import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ11727 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int arr[];

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		arr = new int[n + 1];
		DP(n);
		bw.write(Integer.toString(arr[n]));
		bw.flush();
		bw.close();
	}

	static void DP(int n) {
		arr[0] = 1;
		arr[1] = 1;

		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] * 2;
			arr[i] %= 10007;
		}
	}

}
