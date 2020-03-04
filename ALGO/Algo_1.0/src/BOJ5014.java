import java.io.FileInputStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 
public class BOJ2644 {
    static int[][] arr;
    static boolean[] visited;
    static int[] total;
    static int x;
    static int y;
 
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        arr = new int[N + 1][2];  
        visited = new boolean[N + 1];  
        total = new int[N + 1];       
        x = sc.nextInt();     
        y = sc.nextInt();      
 
        
        int K = sc.nextInt();
        for (int i = 1; i <= K; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }
        System.out.println(BFS(x, N));
    }
 
    public static int BFS(int x, int N) {
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(x);
    
        while (!q.isEmpty()) {
            int nextX = q.poll();
            visited[nextX] = true;
            for (int i = 0; i < N; i++) {
                if (arr[i][0] == nextX && !visited[arr[i][1]]) {
                    q.add(arr[i][1]);
                    total[arr[i][1]] = total[arr[i][0]] + 1;
                } else if (arr[i][1] == nextX && !visited[arr[i][0]]) {
                    q.add(arr[i][0]);
                    total[arr[i][0]] = total[arr[i][1]] + 1;
                }
            }
            if (!q.isEmpty() && q.peek() == y) {
                return total[y];
            }
 
        }
        return -1;
    }
}