import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1463 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int[] arr;
	static int count = 0;
	static int x;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));

		x = Integer.parseInt(br.readLine());
		arr = new int[x + 1];
		for (int i = 0; i < x + 1; i++)
			arr[i] = 0;
		bw.write(Integer.toString(func(x)));
		bw.close();
	}

	static int func(int n) {
		if (n == 1)
			return 0;
		if (arr[n] > 0)
			return arr[n];
		arr[n] = func(n - 1) + 1;
		if (n % 2 == 0 && arr[n / 2] + 1 < arr[n]) {
			arr[n] = func(n / 2) + 1;
		}

		if (n % 3 == 0 && arr[n / 3] + 1 < arr[n]) {
			arr[n] = func(n / 3) + 1;
		}
		return arr[n];
	}

}
