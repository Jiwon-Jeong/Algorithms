import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ11053 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int arr[];
	static int length[];
	static int max;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		arr = new int[n];
		length = new int[n];
		
		String s[] = br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(s[i]);
		}
		DP(n);
		bw.write(Integer.toString(max));
		bw.flush();
		bw.close();
	}
	
	static void DP(int n) {
		max=0;
		length[0] =1;
		for(int i=0; i<n; i++) {
			length[i] = 1;

			for(int j=0; j<i; j++) {
				if(arr[j]<arr[i] && length[j]+1 > length[i]) {
					length[i] = length[j]+1;
				}
			}
			
			if(max<length[i]) max = length[i];

		}
	}
}
