#define 整形 int
#define 数组 vector
#define 排序 sort
#define 类 class
#define 解决方案 Solution
#define 公开 public
#define 找到最接近的元素 findClosestElements
#define 开头 begin()
#define 结尾 end()
#define 大小 size()
#define 糯米循环 for
#define 循环 while
#define 变大一点 ++
#define 告诉你吧 return

类 解决方案 {
公开:
    数组<整形> 找到最接近的元素(数组<整形>& 数列, 整形 目标个数, 整形 目标值) {
        整形 左 = 0, 右 = 数列.大小 - 目标个数;
        循环(左 < 右){
            整形 中 = (左 + 右) / 2;
            if(目标值 - 数列[中] > 数列[中 + 目标个数] - 目标值){
                左 = 中 + 1;
            }else{
                右 = 中;
            }
        }
        告诉你吧 数组<整形>(数列.开头 + 左, 数列.开头 + 左 + 目标个数);
    }
};
