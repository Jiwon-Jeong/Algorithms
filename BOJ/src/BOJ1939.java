import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
 
public class BOJ1939 {
 
    static boolean check(List<Weight>[] a, int limit, int start, int end, boolean [] b) {
        if(b[start])
            return false;
        b[start] = true;
        if(start == end)
            return true;
        for(Weight v : a[start]) {
            if(v.g >= limit) {  
                if(check(a, limit, v.v, end, b)){ 
                    return true;
                }
            }
        }
        
        return false;
    }
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); 
        int m = scan.nextInt();
        List<Weight> [] a = (List<Weight> []) new ArrayList[n+1];
 
        for(int i=1; i<=n; i++)
            a[i] = new ArrayList<>();
 
        int max = 0;
        for(int i=0; i<m; i++) {
            int v1 = scan.nextInt();
            int v2 = scan.nextInt();
            int g = scan.nextInt();
            a[v1].add(new Weight(v2, g));
            a[v2].add(new Weight(v1, g));
            max = Math.max(g, max);
        }
        int tx = scan.nextInt();
        int ty = scan.nextInt();
 
 
 
        int start = 1;
        int end = max;
        int ans = 0;
        while(start<=end) {
            boolean []b = new boolean[n+1];
            int mid = (start+end)/2;
            if(check(a, mid, tx, ty, b)) {
                start = mid+1;
                ans = Math.max(ans, mid);
            }
            else
                end = mid-1;
        }
        System.out.println(ans);
    }
 
}
class Weight{
    int v;
    int g;
 
    public Weight(int v, int g) {
        this.v = v;
        this.g = g;
    }
}
 
