import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ9095 {
	static BufferedReader br;
	static BufferedWriter bw;
	static int[] arr;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		arr = new int[12];
		arr[1]=1;
		arr[2]=2;
		arr[3]=4;
		for(int i=0; i<t; i++) {
			int n = Integer.parseInt(br.readLine());
			int j=4;
			while(j<=n) {
				arr[j] = arr[j-1]+arr[j-2]+arr[j-3];
				j++;
			}
		bw.write(Integer.toString(arr[n])+"\n");
		}
		bw.flush();
		bw.close();
	}

}
