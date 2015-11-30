import java.util.Scanner;
import java.util.ArrayList;
import java.lang.StringBuilder;
import java.nio.ByteBuffer;


public class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String arg = sc.nextLine();
        StringBuilder sb = new StringBuilder(arg);

        int firstColon = sb.indexOf(":");//0,1,2,3,4番目
        int lastColon = sb.lastIndexOf(":");
        int firstConma = sb.indexOf(",");
        int lastPar = sb.lastIndexOf("}");

        int a = Integer.parseInt(sb.substring(firstColon+1,firstConma));
        int b = Integer.parseInt(sb.substring(lastColon+1,lastPar));

        int[] result = new int[32];
        int[] ketaage = new int[32];
        int bin = 1;
        int bin_nxt = 2;
        for(int i =0;i<32-1;i++){

           // int tempA  = a & (int)Math.pow(2,i);
           // int tempB  = b & (int)Math.pow(2,i);

           int tempA  = a & bin;
           int tempB  = b & bin;


           if(tempB==tempA && tempA==bin){
             ketaage[i+1] = bin_nxt;
             result[i] = ketaage[i];
           }else{
            ketaage[i+1] = 0;
                if(ketaage[i]==(int)Math.pow(2,i)){
                    if( (tempA ^ tempB) == bin){
                        ketaage[i+1] = bin_nxt;
                        result[i]=0;
                    }else{
                      result[i]=ketaage[i];
                    }
                }else{
                  result[i]= (tempA ^ tempB);
                }
           }
           bin = bin << 1;
           bin_nxt = bin_nxt << 1;
           // System.out.println(result);
        }
        // System.out.println("a+b:"+(a+b));
        int src =0;
        for(int i =0;i<32;i++){
          src|=result[i];
        }

        System.out.println(src);
      }
}