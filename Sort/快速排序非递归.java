package test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class test01 {
	public static void sort(int []array,int start,int end){
		if(start<end){
			Stack<Integer> startStack = new Stack<Integer>();
			Stack<Integer> endStack = new Stack<Integer>();
			
			startStack.push(start);
			endStack.push(end);
			
			while(startStack.size()>0 && endStack.size()>0){
				int tempStart = startStack.pop();
				int tempEnd = endStack.pop();
				
				if(tempStart<tempEnd){
					int povit = tempStart;
					int left = tempStart;
					int right = tempEnd;
					
					while(left<right){
						while(left <right && left !=povit &&array[left] <= array[povit]){
							left++;
						}
						if(left < right){
							swap(array,left,povit);
							povit = left;
						}
						while(left<right && right != povit &&array[right] >= array[povit]){
							right--;
						}
						if(left<right){
							swap(array, right, povit);
							povit = right;
						}
					}
					startStack.push(tempStart);
					startStack.push(left+1);
					endStack.push(left -1);
					endStack.push(tempEnd);
				}
			}
		}
	}

	//½»»»
	private static void swap(int[] array, int left, int povit) {
		int temp = array[left];
		array[left] = array[povit];
		array[povit] = temp;
	}
	
	public static void main(String[] args) {
		int [] array = {5,9,3,8};
		sort(array, 0, array.length-1);
		
		System.out.println(Arrays.toString(array));
	}
}
