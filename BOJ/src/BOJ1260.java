import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ1260 {
	static int[][] c;
	static boolean[] visit;
	static int n,m,v;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		v = sc.nextInt();
		
		c = new int[n+1][n+1];
		visit = new boolean[n+1];
		
		int t1,t2=0;
		for(int i=1; i<=m; i++) {
			t1 = sc.nextInt();
			t2 = sc.nextInt();
			c[t1][t2] = c[t2][t1] = 1;
		}
		dfs(v);
		System.out.println();
		for(int i=0; i<=n; i++) {
			visit[i]=false;
		}
		bfs(v);
	
		sc.close();
	}
	
	static void bfs(int i) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(i);
		visit[i] = true;
		
		while(!q.isEmpty()) {
			int tmp = q.poll(); //제거
			System.out.print(tmp+" ");
			for(int k=1; k<=n; k++) {
				if(c[tmp][k]==1 && visit[k]==false) {
					q.offer(k);
					visit[k] = true;
				}
			}
		}
		
	}
	static void dfs(int i) {
		visit[i] = true;
		System.out.print(i+" ");
		for(int j=1; j<=n; j++) {
			if(c[i][j]==1 && visit[j]==false) {
				dfs(j);
			}
		}
		
	}
}
