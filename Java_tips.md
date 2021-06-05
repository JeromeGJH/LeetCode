# Java

String[].length
String.length()

### Comparator
`compare()`返回值为正数，交换位置。
```
Arrays.sort(nums, new Comparator<int[]>(){ //<>中为比较的元素
  public int compare(int[] arr1, int[] arr2){
    if(arr1[0] == arr2[0]){
      return arr2[1] - arr1[1];
    }else{
      return arr1[0] - arr2[0];
    }
  }
}); 
```
