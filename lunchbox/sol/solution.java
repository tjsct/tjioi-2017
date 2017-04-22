import java.util.*;
import java.io.*;
import java.math.*;

public class lunchbox{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int x_0 = sc.nextInt();
        int y_0 = sc.nextInt();
        for(int i = 0; i < N; i++){
            String query_direction = sc.next();
            int query_distance = sc.nextInt();
            if(query_direction.equals("N")){
                y_0 += query_distance;
            }
            if(query_direction.equals("S")){
                y_0 -= query_distance; 
            }
            if(query_direction.equals("E")){
                x_0 += query_distance;
            }
            if(query_direction.equals("W")){
                x_0 -= query_distance;
            }
        }
        System.out.println(x_0 + " " + y_0);
    }
}
