import java.util.Scanner;
import java.util.ArrayList;
import java.lang.StringBuilder;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        int length = sc.nextInt();
        int hintnum = sc.nextInt();

        ArrayList<Integer> array = new ArrayList<Integer>();
        char moji[] = new char[100];

        StringBuilder sb = new StringBuilder("");
        for(int i=0;i<hintnum;i++){
          array.add(sc.nextInt());
          moji[i] = sc.nextLine().charAt(1);
        }
        for(int i=0;i<length;i++){
           sb.append("*");
        }

        for(int i=0;i<hintnum;i++){
          sb.setCharAt((array.get(i))-1, moji[i]);
          sb.setCharAt(length-(array.get(i)), moji[i]);
        }

       	System.out.println(sb.toString());

    }
}