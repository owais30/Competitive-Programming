import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	
	public static void main (String [] abc) throws Exception  {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s;
		int Case=1;
		while ((s=br.readLine())!=null && !s.equals("0 0")) {
			StringTokenizer st=new StringTokenizer(s);
			int n=Integer.parseInt(st.nextToken());
			int p=Integer.parseInt(st.nextToken());
			
			for (int i=0;i<n;i++)		br.readLine();
			
			String CarName="";
			int CarReqCount=0;
			double CarPrice=0.0;
			
			for (int i=0;i<p;i++) {
				String currName=br.readLine();
				st=new StringTokenizer(br.readLine());
				double currPrice=Double.parseDouble(st.nextToken());
				int currReqCount=Integer.parseInt(st.nextToken());
				for (int j=0;j<currReqCount;j++) br.readLine();
				
				if (currReqCount>CarReqCount || (currReqCount==CarReqCount && CarPrice>currPrice)) {
					CarName=currName;
					CarReqCount=currReqCount;
					CarPrice=currPrice;
				}
			}
			
			if (Case > 1) System.out.println();
			
			System.out.println("RFP #"+(Case++)+"\n"+CarName);
		}
	}
}
