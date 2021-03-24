import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    // Complete the solve function below.
    static String solve(int d, int k) {

    long count=0;

    for(long i=0;i<Math.sqrt(d);i++)

    {

        long p=(long)Math.sqrt((long)d-i*i);

        if((p*p+i*i)==d)

        {

            count+=4;

        }

    }


    if(k>=count)

    {

        return "possible";

    }

    return "impossible";

}


    

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] dk = scanner.nextLine().split(" ");

            int d = Integer.parseInt(dk[0]);

            int k = Integer.parseInt(dk[1]);

            String result = solve(d, k);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
