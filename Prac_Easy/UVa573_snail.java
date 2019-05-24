import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class TestClass {
	
	public static void main (String [] abc) throws Exception  {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s;
		while ((s=br.readLine())!=null) {
			StringTokenizer st=new StringTokenizer(s);
			double targetH=Double.parseDouble(st.nextToken());
			if (targetH==0) {
				break;
			}
			double U=Double.parseDouble(st.nextToken());
			double D=Double.parseDouble(st.nextToken());
			double F=Math.max(0.0,U*(Double.parseDouble(st.nextToken())/100.0)); 
			double currH=0.0;
			
			int day=0;
			while (currH<=targetH && currH>=0.0) {
				day++;
				currH=currH+U;
				if (currH>targetH) {
					break;
				}
				currH=currH-D;
				U=Math.max(0, U-F);
			}
			
			if (currH>targetH) {
				System.out.println("success on day "+(day));
			} else {
				System.out.println("failure on day "+day);
			}
		}
	}
}
