import java.io.*;

public class Main {
    public static void main(String[] args) throws java.io.IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String a = in.readLine();
        int c = Integer.parseInt(a);//meter
        int result;
        
        if(c<100){
            result=0;
            System.out.println(String.format("%02d", result));
        }else if(c>=100 && c<=1000){
            result=c/100;
            System.out.println(String.format("%02d", result));
        }else if(c>=1000 && c<=5000){
            result=c/100;
            System.out.println(result);
        }else if(c>=6000 && c<=30000){
            result=c/1000+50;
            System.out.println(result);
        }else if(c>=35000 && c<=70000){
            result=(c/1000-30)/5+80;
            System.out.println(result);
        }else{
            result=89;
            System.out.println(result);
        }
    }
}