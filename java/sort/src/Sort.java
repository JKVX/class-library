import java.io.File;
import java.util.Arrays;

public class Sort{
    public static void insertSort(int a[]){
        insertSort(a,1);
    }
    public static void shellSort(int a[],int dk){
        while(dk>=1){
            insertSort(a,dk);
            dk=dk/2;
        }
    }
    public  static void selectSort(int a[]){
        int left=0;
        int right=a.length-1;
        while(left<right){
            int min=Integer.MAX_VALUE;
            int minLocation=-1;
            for(int i=left;i<=right;i++){
                if(min>a[i]){
                    min=a[i];
                    minLocation=i;
                }
            }
            switchValue(a,left,minLocation);
            left++;
            print(a);
        }
    }
    public  static  void main(String args[]){
        int[] a = {3,1,5,5,2,4,9,6};
        //insertSort(a,1);
        //shellSort(a,8);
        selectSort(a);
    }
    private  static  void print(int[] a){
        System.out.println(Arrays.toString(a));
    }
    private  static  void switchValue(int []a,int leftLocation,int rightLocation){
        int temp=a[leftLocation];
        a[leftLocation]=a[rightLocation];
        a[rightLocation]=temp;
    }
    private static void insertSort(int a[],int dk)
    {
        for(int i=dk;i<a.length;i++){
            if(a[i]<a[i-dk]){
                int j=i;
                while(j>dk-1&&a[j]<a[j-dk]){
                    int temp=a[j];
                    a[j]=a[j-dk];
                    a[j-dk]=temp;
                    j--;
                }
            }
        }
        print(a);
    }
}
