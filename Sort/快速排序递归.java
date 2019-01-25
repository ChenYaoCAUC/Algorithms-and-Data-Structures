package test;

public class test {

	public static void main(String[] args) {
		int [] a={12,20,5,16,15,1,30,45,23,9,8,7,40,80,130,22,39};
		int start = 0;
		int end = a.length-1;
		sort(a,start,end);
		for(int i=0;i<a.length;i++){
			System.out.print(a[i]+"  ");
		}
		
		
	}

	//以第一个值为基准值
	private static void sort(int[] a, int low, int high) {
		int start = low;
		int end = high;
		int key = a[low];
		
		while(end>start){
			//先从后边判断
			while(end>start&&a[end]>=key){
				end--;
			}
			if(a[end]<=key){
				int temp = a[end];
				a[end] = a[start];
				a[start] = temp;
			}
			//从前边判断
			while(end>start && a[start]<=key){
				start++;
			}
			if(a[start]>=key){
				int temp = a[start];
				a[start] = a[end];
				a[end] = temp;
			}
			
			if(start>low) sort(a,low,start-1);
			if(end<high) sort(a,end+1,high);
		}
		
	}

}
