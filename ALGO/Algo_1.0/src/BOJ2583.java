import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class BOJ2583 {
	
	static int[][] arr;
	static int m;
	static int n;
	static int count[];
	static int num;
	static int dx[] = {0,0,-1,1};
	static int dy[] = {1,-1,0,0};
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		arr = new int[m][n];
		count= new int[1000];
		int t = sc.nextInt();
		
		for(int i=0; i<t; i++) {
			int t1 = sc.nextInt();
			int t2 = sc.nextInt();
			int t3 = sc.nextInt();
			int t4 = sc.nextInt();
			for(int j=t1; j<t3; j++) {
				for(int k=t2; k<t4; k++) 
					arr[k][j] = -1;
			}
		}
		num=1;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(arr[i][j]==0) {
					DFS(i, j, num);
					num++;
				}
			}
		}
		
		System.out.println(num-1);
		Arrays.sort(count, 1, num);
		for(int i=1; i<num; i++)
			System.out.print(count[i]+" ");
		
	}
	
	static void DFS(int i, int j, int num) {
		arr[i][j] = num;
		count[num]++;
		
		for(int k=0; k<4; k++) {
			if(i+dx[k]>=0 && i+dx[k]<m && j+dy[k]>=0 && j+dy[k]<n) {
				if(arr[i+dx[k]][j+dy[k]]==0) {
					DFS(i+dx[k], j+dy[k], num);
				}
			}
		}
	}
	
}
