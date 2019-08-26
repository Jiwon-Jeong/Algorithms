import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 
public class BOJ9019 {
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int tc = scan.nextInt();
        
        while(tc-- > 0) {
            int n = scan.nextInt();
            int m = scan.nextInt();
            String [] command = new String[10000];
            boolean [] visited = new boolean[10000];
            Queue<Integer> q = new LinkedList<>();
            
            visited[n] = true;
            q.add(n);
            Arrays.fill(command, "");
            
            while(!q.isEmpty() && !visited[m]) {
                int now = q.poll();
                int D = (2*now) % 10000;
                int S = (now == 0) ? 9999 : now-1 ;
                int L = (now % 1000) * 10 + now/1000;
                int R = (now % 10) * 1000 + now/10;    
                
                System.out.println(L+" "+R);
                if(!visited[D]) {
                    q.add(D);
                    visited[D] = true;
                    command[D] = command[now]+"D";
                }
                if(!visited[S]) {
                    q.add(S);
                    visited[S] = true;
                    command[S] = command[now]+"S";
                }
                if(!visited[L]) {
                    q.add(L);
                    visited[L] = true;
                    command[L] = command[now]+"L";
                }
                if(!visited[R]) {
                    q.add(R);
                    visited[R] = true;
                    command[R] = command[now]+"R";
                }
            }
            System.out.println(command[m]);
        }
    }
 
}
