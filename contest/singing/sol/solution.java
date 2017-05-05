import java.util.*;
import java.io.*;
import java.math.*;

public class singing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int i = 0; i <= N; i++){
            if (N <= i * (i+1) / 2){
                System.out.println(i);
                break;
            }
        }
    }
}
