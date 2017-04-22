import java.util.*;
import java.io.*;
import java.math.*;

public class D{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        ArrayList<Integer> pencils = new ArrayList<Integer>();
        for(int i = 0; i < N; i++){
            pencils.add(sc.nextInt());
        }
        Collections.sort(pencils);
        
        int sum = 0;
        for(int i = N - 1; i >= N - K; i--){
            sum += pencils.get(i);
        }
        System.out.println(sum);
    }
}
