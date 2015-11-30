import java.util.Scanner;
 
public class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        double deg = sc.nextDouble() / 10;//まず角度を小数点ありに直す
        double dis = sc.nextDouble() / 60;//風速の計算、取得できるのは1分間の距離->秒速に直す
        
        dis = Math.round(dis*10)/10.0;//小数第2位を四捨五入10.62->106.2->106->10.6
        
        String dir = "N";
        
        int W = 0;
        String[] dirs = {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
        double[] angleRanges = {11.25,
        					            33.75,
                              56.25,
                              78.75,
                              101.25,
                              123.75,
                              146.25,
                              168.75,
                              191.25,
                              213.75,
                              236.25,
                              258.75,
                              281.25,
                              303.75,
                              326.25,
                              348.75};
        double[] diss = {0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8,
                         13.9, 17.2, 20.8, 24.5, 28.5, 32.7};
        
        //風速について
        for(int i = diss.length - 1; i >= 0; i--){
            if(dis >= diss[i]){//大きいものから、その風速を超えれば、disに風速の数値(i)を入れる。
                dis = i;
                break;
            }
        }
 
        if((int)dis == 0){//風速が0のときは特殊出力
            System.out.println("C 0");
            return;
        }
 
        //角度について
        for(int i = 0; i <angleRanges.length; i++){//風向きは16段階
            if(deg < angleRanges[i]){//小さい角度から順にそれよりもdegが小さければ
                dir = dirs[i];//方角のStringにあっているものを代入(一番近い角度が入ったことになるので)
                break;//直後でbreak;
            }
        }
        
        System.out.println(dir+" "+(int)dis);
        return;
    }
}