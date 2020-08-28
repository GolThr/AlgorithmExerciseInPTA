import java.util.Scanner;

class CommonOrder {
    static StringBuffer s1;// save string1
    static StringBuffer s2;// save string2
    static StringBuffer s3;// save commom string   
    CommonOrder(String str1,String str2)
    {
        s1=new StringBuffer(str1);
        s2=new StringBuffer(str2);
        s3=new StringBuffer();
    }		
    
    /* 你编写的subsequenceOrder()函数的代码将被嵌在这里  */
    void subsequenceOrder(){
        String x = new String(s2);
        String y = new String(s1);
        int m = x.length();
        int n = y.length();
        int[][] c = new int[m+1][n+1];

        for (int i = 0; i < m+1; i++) {
            c[i][0] = 0;
        }
        for (int i = 0; i < n+1; i++) {
            c[0][i] = 0;
        }

        int[][] path = new int[m+1][n+1];
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if(x.charAt(i-1) == y.charAt(j-1)){
                    c[i][j] = c[i-1][j-1] + 1;
                }else if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    path[i][j] = 1;
                }else{
                    c[i][j] = c[i][j-1];
                    path[i][j] = -1;
                }
            }
        }
        PrintLCS(path,x,m,n);
    }


    public static void PrintLCS(int[][]b,String x,int i,int j){
        if(i == 0 || j == 0){
            return;
        }

        if(b[i][j] == 0){
            PrintLCS(b,x,i-1,j-1);
            s3.append(x.charAt(i-1));
            //System.out.printf("%c",x.charAt(i-1));
        }else if(b[i][j] == 1){
            PrintLCS(b,x,i-1,j);
        }else{
            PrintLCS(b,x,i,j-1);
        }
    }
    /*************************************************/

    StringBuffer getCommonString(){
        return s3;
    }
}

public class Main{
    public static void main(String[] args) {
       String X = null,Y = null;       
       Scanner sc=new Scanner(System.in);
       if(sc.hasNext()) X=sc.nextLine();
       if(sc.hasNext()) Y=sc.nextLine();
       CommonOrder co=new CommonOrder(X,Y);
       co.subsequenceOrder();
       StringBuffer str=co.getCommonString();
       System.out.println(str+" "+str.length());
    }
}