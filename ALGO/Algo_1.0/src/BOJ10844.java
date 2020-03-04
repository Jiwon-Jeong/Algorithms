import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ10844 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int arr[][];
	static int cnt = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		arr = new int[n][10];
		arr[0][0] = 0;
		for (int i = 1; i < 10; i++) {
			arr[0][i] = 1;
		}

		DP(n);
		for (int j = 0; j < 10; j++)
			cnt = (cnt + arr[n - 1][j])%1000000000;
		bw.write(Integer.toString(cnt));
		bw.flush();
		bw.close();

	}

	static void DP(int n) {

		if (n == 1)
			return;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (j == 0)
					arr[i][j] = arr[i - 1][1] % 1000000000;
				else if (j == 9)
					arr[i][j] = arr[i - 1][8] % 1000000000;
				else
					arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1])%1000000000;
			}
		}
	}

}
