import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ5430 {
	static BufferedReader br;
	static BufferedWriter bw;
	static StringTokenizer st;
	static String p;
	static int n = 0;
	static int[] x;
	static int[] tmp;
	static int flag;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			p = br.readLine();
			n = Integer.parseInt(br.readLine());
			x = new int[n];
			tmp = new int[n];
			String s[];
			flag = 0;
			s = br.readLine().replaceAll("[\\[\\]]", "").split(",");
			int j = 0;
			for (j = 0; j < n; j++) {
				x[j] = Integer.parseInt(s[j]);
			}
			bw.write(func());
		}
		bw.close();
		br.close();
	}

	static String func() {
		StringBuilder sb = new StringBuilder();
		int head = 0, tail = n - 1, ptr = head, count=0;
		

		for (int m = 0; m < p.length(); m++) {
			switch (p.charAt(m)) {
			case 'R':
				count++;
				if (ptr == head)
					ptr = tail;
				else
					ptr = head;
				break;

			case 'D':
				try {
					x[ptr] = 0;
				} catch (Exception e) {
					return "error\n";
				}
				if (ptr == head)
					ptr = ++head;
				else if (ptr == tail)
					ptr = --tail;
				break;
			default:
				break;
			}
		}

		sb.append("[");

		if (count % 2 == 0) {
			for (int k = head; k <= tail; k++) {
				if (k == tail)
					sb.append(x[k]);
				else
					sb.append(x[k] + ",");
			}
		} else {
			for (int k = tail; k >= head; k--) {
				if (k == head)
					sb.append(x[k]);
				else
					sb.append(x[k] + ",");
			}
		}
		sb.append("]\n");
		return sb.toString();
	}
}