import java.util.*;
import java.io.*;
import java.math.*;

public class candy{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashMap<String, Integer> candies = new HashMap<String, Integer>();
        for (int i = 0; i < N; i++) {
            candies.put(sc.next(), sc.nextInt());
        }
        String rec = sc.next();
        String str = "";
        int count = 0;
        for(int i = 0; i < rec.length(); i++){
            str += rec.charAt(i);
            if(candies.get(str) != null){
                count += candies.get(str);
                str = "";
            }
        }
        System.out.println(count);
    }
}
