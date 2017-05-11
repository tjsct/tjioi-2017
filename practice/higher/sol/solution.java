import java.util.Scanner;

class higher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt();
        if (a >= b) {
            System.out.println("LARRY");
        } else {
            System.out.println("KEVIN");
        }
    }
}

