import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ7576 {
	static int[][] map;
	static boolean[][] visit;
	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };
	static int n, m;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		map = new int[n][m];
		visit = new boolean[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		
		bfs();
		sc.close();
	}

	static void bfs() {
		Queue<Integer> qx = new LinkedList<Integer>();
		Queue<Integer> qy = new LinkedList<Integer>();
		int x, y, max=0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					qx.add(i);
					qy.add(j);
				}
			}
		}

		while (!qx.isEmpty() && !qy.isEmpty()) {
			x = qx.poll();
			y = qy.poll();

			visit[x][y] = true;

			for (int k = 0; k < 4; k++) {
				int _x = x + dx[k];
				int _y = y + dy[k];

				if (_x >= 0 && _y >= 0 && _x < n && _y < m) {
					if (map[_x][_y] == 0 && visit[_x][_y] == false) {
						qx.add(_x);
						qy.add(_y);
						visit[_x][_y] = true;
						map[_x][_y] = map[x][y] + 1;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					System.out.println(-1);
					return;
				}
				max = Math.max(max, map[i][j]);
			}
		}
		System.out.println(max-1);
	}
}
