import java.io.*;

public class Main {
    public static void main(String[] args) throws java.io.IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//        System.out.println(“文字列を入力してください。”);
        String a = in.readLine();
        String b = in.readLine();
        int c = Integer.parseInt(a);
        int d = Integer.parseInt(b);
//        System.out.println(Math.abs(c-d));
        System.out.println(c-d);
    }
}