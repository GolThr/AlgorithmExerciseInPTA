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
    
    public void subsequenceOrder() {
        int i = 0, j = 0, top = 0;
        int s[] = new int[s1.length() + s2.length()];
        int c[][] = new int[s1.length() + 1][s2.length() + 1];
        int b[][] = new int[s1.length() + 1][s2.length() + 1];
        for(i = 1; i <= s1.length(); i++){
            for(j = 1; j <= s2.length(); j++){
                if(s1.charAt(i - 1) == s2.charAt(j - 1)){
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = 1;
                }else if(c[i - 1][j] >= c[i][j - 1]){
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 2;
                }else{
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 3;
                }
            }
        }
        i = s1.length(); j = s2.length();
        while(b[i][j] != 0){
            if(b[i][j] == 2){
                i--;
            }else if(b[i][j] == 3){
                j--;
            }else if(b[i][j] == 1){
                s[top++] = i - 1;
                i--; j--;
            }
        }
        while(top != 0){
            s3.append(s1.charAt(s[--top]));
        }
    }

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