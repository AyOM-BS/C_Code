// #define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <math.h>

// 计算n！之和（循环）
// int main ()
// {
//     int ret = 0;
//     int sum = 0;
//     for (int n = 1; n <= 3; n++)
//     {
//         ret = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             ret *= i;
//         }
//         sum += ret;
//     }
//     printf ("%d\n",sum);
//     return 0;
// }

// 优化算法，用循环计算n！之和
// int main ()
// {
//     int ret = 1;
//     int sum = 0;
//     for (int i = 1; i <= 3; i++)
//     {
//         ret *= i;
//         sum += ret;
//     }
//     printf ("%d\n",sum);
//     return 0;
// }

// 函数递归计算n！
// int fav (int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     else if (n > 0)
//         return fav(n-1) * n;
//     else
//     {
//         printf("输入非法\n");
//         return 0;
//     }
// }
// int main()
// {
//     int n = 3;
//     int r = fav(n);
//     printf("%d\n",r);
//     return 0;
// }

// 递归按顺序打印出数字的每一位
// int sequence(int n)
// {
//     if (n > 9)
//     {
//         sequence(n/10);
//     }
//     printf("%d ",n % 10);
// }
// int main()
// {
//     int n = 0;
//     scanf ("%d",&n);
//     int r = sequence(n);
//     return 0;
// }

// 递归计算斐波那契数列第n项
// int F(int n)
// {
//     if (n <= 2)
//     {
//         return 1;
//     }
//     else
//     {
//         return F(n-1)+F(n-2);
//     }
// }
// int main ()
// {
//     int n = 0;
//     scanf ("%d",&n);
//     int r = F(n);
//     printf("%d\n",r);
//     return 0;
// }

// 循环计算斐波那契数列第n项
// int main ()
// {
//     int n = 0;
//     int an = 0;
//     int bn = 0;
//     int cn = 0;
//     scanf ("%d",&n);
//     if (n <= 2)
//     {
//         an = 1;
//     }
//     else
//     {
//         cn = 1;
//         bn = 1;
//         for (int i = 3; i <= n; i++)
//         {
//             an = bn + cn;
//             cn = bn;/*cn=bn在前，防止把an既赋给bn，又赋给cn*/
//             bn = an;
//         }
//     }
//     printf ("%d\n",an);
//     return 0;
// }

// 递归计算青蛙跳台阶方法数
// int jump(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     else if (n == 2)
//     {
//         return 2;
//     }
//     else
//     {
//         return jump(n-1) + jump(n-2);
//     }
// }
// int main ()
// {
//     int n = 0;
//     scanf ("%d",&n);
//     int a = jump(n);
//     printf("%d\n",a);
//     return 0;
// }

// 递归计算汉诺塔问题步数
// int tower(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 2*tower(n-1) + 1;
//     }
// }
// int main ()
// {
//     int n = 0;
//     scanf ("%d",&n);
//     int a = tower(n);
//     printf ("%d\n",a);
//     return 0;
// }

// 用操作符交换两个数的值
// int main ()
// {
//     int a = 0;
//     int b = 0;
//     scanf ("%d%d",&a,&b);
//     a = a ^ b;
//     b = a ^ b;/* a^b^b = a^0 = a */
//     a = a ^ b;/* a^b^a = a^a^b = b */
//     printf ("a = %d\nb = %d\n",a,b);
//     return 0;
// }

// 计算一个数二进制形式下1的个数
// int main ()
// {
    // int n = 0;
    // int a = 0;
    // int sum = 0;
    // scanf ("%d",&n);
    // while (n)
    // {
    //     a = n % 2;
    //     n /= 2;
    //     if (a == 1)
    //     sum++;
    // }
    // printf ("%d\n",sum);
    // 只能计算正数
    //改进使得负数也可计算
    // int n = 0;
    // int r = 0;
    // int sum = 0;
    // scanf ("%d",&n);
    // for (int i = 0; i < 32; i++)
    // {
    //     r = n & 1;
    //     if (r == 1)
    //     {
    //         sum++;
    //     }
    //     n >>= 1;
    // }
    // printf ("%d\n",sum);
    // 计算太慢
    // 加快效率
    // int n = 0;
    // int sum = 0;
    // while (n)
    // {
    //     n = n & (n - 1);
    //     // n = 13 = 1101
    //     // n-1 = 1100
    //     // n = n & (n-1) = 1100  1101最右边的1被换为0
    //     // n-1 = 1011
    //     // n = n & (n-1) = 1000  1100最右边的1被换为0
    //     // n-1 = 0111
    //     // n = n & (n-1) = 0000  1000最右边的1被换为0
    //     // end
    //     sum++;
    // }
    // printf ("%d\n",sum);
    // return 0;
// }

// 把13的二进制第5位换成1再换成0
// int main ()
// {
//     int n = 13;
//     // 补00000000000000000000000000001101 把第5位换成1，就是把补码第5位换成0 
//     // 补00000000000000000000000000011101 换后数字为29
//     // 1的补码为00000000000000000000000000000001
//     // 按位或有1就为1
//     // n |= (1 << 4)
//     // 1 << 4 补码00000000000000000000000000010000
//     // n |= (1 << 4) 补码00000000000000000000000000011101
//     int k = 0;
//     scanf ("%d",&k);
//     n |= (1 << (k-1));
//     printf("%d\n",n);
//     // 补00000000000000000000000000011101 把第5位的数字换位0
//     // 补11111111111111111111111111101111 用按位与有0就为0
//     // 接下来要得到11111111111111111111111111101111
//     // 移位操作符只能添加0
//     // 所以进行取反操作0000000000000000000000000010000
//     // 所以11111111111111111111111111101111 = ~(1 << 4)
//     n &= ~(1 << (k-1));
//     printf("%d\n",n);
//     return 0;
// }

// 用指针打印1-10(1)
// int main ()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int* p = &arr[0];
//     for (int i = 0; i < 10; i++)
//     {
//         printf ("%d ",*(p+i));
//     }
//     return 0;
// }

// 用指针打印1-10(2)
// int main ()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int* p = &arr[0];
//     while (p <= &arr[9])
//     {
//         printf ("%d ",*p);
//         p++;
//     }
//     return 0;
// }

// 计数器模拟实现strlen
// size_t my_strlen(const char* p)// 防止数据被篡改
// {
//     int count = 0;
//     assert (*p != NULL);// 防止传过来的是空指针
//     while (*p != '\0')
//     {
//         count++;
//         p++;
//     }
//     return count;
// }
// int main ()
// {
//     char arr[] = "abcdef";
//     size_t len = my_strlen(arr);
//     printf ("%zu\n",len);
//     return 0;
// }

// 交换两个数
// void swap(int*pa,int*pb)
// {
//     int c = *pa;
//     *pa = *pb;
//     *pb = c;
// }
// int main()
// {
//     int a = 0;
//     int b = 0;
//     scanf("%d%d",&a,&b);
//     swap(&a,&b);
//     printf("%d %d",a,b);
//     return 0;
// }

// 冒泡排序
// void rank (int arr[],int sz)
// {
//     int count = sz;
//     while (count)
//     {
//         for (int i = 0; i <sz-1; i++)
//         {
//             if (arr[i] > arr[i+1])
//             {
//                 int a = arr[i];
//                 arr[i] = arr[i+1];
//                 arr[i+1] = a;
//             }
//             else
//             {}
//         } 
//         count--;
//     }
// }//效率过低
// 减去排好之后的无效次数
// void rank (int arr[],int sz)
// {
//     int count = sz;
//     int flag = 1;
//     while (count)
//     {
//         flag = 1;
//         for (int i = 0; i <sz-1; i++)
//         {
//             if (arr[i] > arr[i+1])
//             {
//                 flag = 0;
//                 int a = arr[i];
//                 arr[i] = arr[i+1];
//                 arr[i+1] = a;
//             }
//             else
//             {}
//         } 
//         if (flag == 1)
//         {
//             break;
//         }
//         count--;
//     }
// }
// void print(int* p,int sz)
// {
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ",*(p+i));
//     }
// }
// int main ()
// {
//     int arr[10] = {9,8,7,6,5,4,3,2,1,0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     rank(arr,sz);
//     print(arr,sz);
//     return 0;
// }

// 指针数组模拟二维数组
// int main()
// {
//     int arr1[] = {1,2,3,4,5};
//     int arr2[] = {2,3,4,5,6};
//     int arr3[] = {3,4,5,6,7};
//     int* arr[] = {arr1,arr2,arr3};
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             printf ("%d ",arr[i][j]);
//         }
//         printf ("\n");
//     }
//     return 0;
// }

// 二维数组传参的本质
// void print (int(*p)[5],int x,int y)// *p表示传过来的是指针，[5]表示第一行有5个元素
// {
//     for (int i = 0; i < x; i++)
//     {
//         for (int j = 0; j < y; j++)
//         {
//             printf ("%d ",*( *(p + i) + j) );
//             // p+i表示行的地址，*(p+i)（*p的形式）表示第i行的地址，再+j表示第j个的地址，最后*表示具体值
//         }
//         printf ("\n");
//     }
// }
// int main ()
// {
//     int arr[3][5] = {1,2,3,4,5,1,3,5,7,9,2,4,6,8,0};
//     print(arr,3,5);// 二维数组传参传的是第一行的一维数组的地址
//     return 0;
// }

// 用函数指针数组和转移表制作计算器
// int ADD (int x,int y)
// {
//     return x+y;
// }
// int SUB (int x,int y)
// {
//     return x-y;
// }
// int MUL (int x,int y)
// {
//     return x*y;
// }
// int DIV (int x,int y)
// {
//     return x/y;
// }
// void math(int (**parr) (int,int))
// // int (*) (int,int)函数指针，parr是名称，*代表parr是个指针，用来指int (*) (int,int)类型
// {
//     int input = 0;
//     do
//     {
//         printf ("------------------------\n");
//         printf ("-----1.add  2.sub-------\n");
//         printf ("-----3.mul  4.div-------\n");
//         printf ("---------0.exit---------\n");
//         printf ("------------------------\n");
//         scanf ("%d",&input);
//         if (input >= 1 && input <= 4)
//         {
//             int x,y;
//             printf ("please input 2 numbers to complete the computation\n");
//             scanf ("%d%d",&x,&y);
//             int r = parr[input](x,y);
//             printf ("%d\n",r);
//         }
//         else if (input == 0)
//         {
//             printf("success to exit.");
//         }
//         else
//         {
//             printf ("fail to input,please input it within 0 to 4 again.\n");
//         }
//     } while (input);    
// }
// int main ()
// {
//     int (*parr[4]) (int,int) = {NULL,ADD,SUB,MUL,DIV};// 函数指针数组
//     math(parr);// 作为数组传参的形参只需要写数组名
//     return 0;
// }

// 用回归函数制作计算器
// int ADD (int x,int y)
// {
//     return x+y;
// }
// int SUB (int x,int y)
// {
//     return x-y;
// }
// int MUL (int x,int y)
// {
//     return x*y;
// }
// int DIV (int x,int y)
// {
//     return x/y;
// }
// void calculate (int (*p) (int,int))
// {
//     int x = 0;
//     int y = 0;
//     printf("2 num\n");
//     scanf("%d%d",&x,&y);
//     int r = p(x,y);
//     printf ("%d\n",r);
// }
// void math()
// {
//     int input = 0;
//     do
//     {
//         printf ("------------------------\n");
//         printf ("-----1.add  2.sub-------\n");
//         printf ("-----3.mul  4.div-------\n");
//         printf ("---------0.exit---------\n");
//         printf ("------------------------\n");
//         scanf ("%d",&input);
//         switch (input)
//         {
//         case 1:
//             calculate(ADD);
//             break;
//         case 2:
//             calculate(SUB);
//             break;
//         case 3:
//             calculate(MUL);
//             break;
//         case 4:
//             calculate(DIV);
//             break;
//         case 0:
//             printf("exit\n");
//             break;
//         default:
//             printf ("again\n");
//             break;
//         }
//     } while (input);    
// }
// int main ()
// {
//     math();
//     return 0;
// }

// qsort的应用(1)给数字排序
// void qsort((void *_Base,指向要排序数组的第一个元素
// size_t _NumOfElements,元素个数
// size_t _SizeOfElements,第一个元素的大小
// int (*_PtFuncCompare)(const void *p1, const void *p2)))排序规则
// p1 > p2 return正数
// p2 > p1 return负数
// p1 == p2 return0
// int compare(const void*p1,const void*p2)
// {
//     return *(int*)p1 - *(int*)p2;
// }
// void print(int* p,int sz)
// {
//     for(int i = 0; i < sz; i++)
//     {
//         printf("%d ",*(p+i));
//     } 
// }
// int main ()
// {
//     int arr[] = {9,8,7,6,5,4,3,2,1,0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     qsort (arr,sz,sizeof(arr[0]),compare);
//     print (arr,sz);
//     return 0;
// }

// qsort的应用(2)给人物按年龄或名字首字母排序!!!
// struct member
// {
//     char name[20];
//     int age;
// };
// int cmpage(const void*p1,const void*p2)
// {
//     return (*(struct member*)p1).age - (*(struct member*)p2).age;
//     return ((struct member*)p1)->age - ((struct member*)p2)->age;
// }
// int cmpname(const void*p1,const void*p2)
// {
//     return -(strcmp((*(struct member*)p2).name,(*(struct member*)p1).name));
//     return -(strcmp((*(struct member*)p2).name,(*(struct member*)p1).name));
// }
// int main()
// {
//     struct member mygo[3] = {{"yomiya",26},{"tateishi",25},{"hayashi",24}};
//     int sz = sizeof(mygo) / sizeof(mygo[0]);
//     qsort(mygo,sz,sizeof(mygo[0]),cmpage);
//     qsort(mygo,sz,sizeof(mygo[0]),cmpname);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%s %d\n",mygo[i].name,mygo[i].age);
//     }
//     return 0;
// }

// 冒泡排序模拟实现qsort!!!!!
// struct member
// {
//     char name[20];
//     int age;
// };
// void swap(char*p1,char*p2,size_t size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         char a = *p1;
//         *p1 = *p2;
//         *p2 = a;
//         p1++;
//         p2++;
//     }// 假如交换的是两个整形，一共要交换四个字节，这里的size就是4，p1与p2是这两个整形的第一个单元格的地址，交换完后+1在进行交换，一共交换4次就可以完成整形的交换
//     // 至于取char*作为强制转换类型，是因为char*+-整数，就跳过该整数所对的字节数，如char*+1就跳过1个字节
// }
// // int cmpage(const void*p1,const void*p2)
// // {
// //     return ((struct member*)p1)->age - ((struct member*)p2)->age;
// // }
// int cmpname(const void*p1,const void*p2)
// {
//     return -(strcmp((*(struct member*)p2).name,(*(struct member*)p1).name));
// }
// void bubble_qsort (void*base,size_t num,size_t size,int(*cmpname)(const void*,const void*))
// {
//     for (int i = 0; i < num-1; i++)
//     {
//         int flag = 1;
//         for (int j = 0; j < num-1; j++)
//         {
//             if (cmpname((char*)base+j*size,(char*)base+(j+1)*size) > 0)
//             {
//                 flag = 0;
//                 swap((char*)base+j*size,(char*)base+(j+1)*size,size);
//             }
//             else
//             {}
//         }
//         if (flag == 1)
//         {
//             break;
//         }
//     }
// }
// int main()
// {
//     struct member mygo[3] = {{"yomiya",26},{"tateishi",25},{"hayashi",24}};
//     int sz = sizeof(mygo) / sizeof(mygo[0]);
//     // bubble_qsort(mygo,sz,sizeof(mygo[0]),cmpage);
//     bubble_qsort(mygo,sz,sizeof(mygo[0]),cmpname);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%s %d\n",mygo[i].name,mygo[i].age);
//     }
//     return 0;
// }

// 数组与指针练习概念理解
// int main ()
// {
//     int arr[4];
//     printf("%zu\n",sizeof(arr));// 16
//     printf("%zu\n",sizeof(arr + 0));// 8
//     printf("%zu\n",sizeof(*arr));// 4
//     printf("%zu\n",sizeof(arr + 1));// 8
//     printf("%zu\n",sizeof(arr[1]));// 4
//     printf("%zu\n",sizeof(&arr));// 8
//     printf("%zu\n",sizeof(*&arr));// 16
//     printf("%zu\n",sizeof(&arr + 1));// 8
//     printf("%zu\n",sizeof(&arr[0]));// 8
//     printf("%zu\n",sizeof(&arr[0] + 1));// 8
//     char arr[6] = {'a','b','c','d','e','f'};
//     printf("%zu\n",sizeof(arr));// 6
//     printf("%zu\n",sizeof(arr+0));// 8
//     printf("%zu\n",sizeof(*arr));// 1
//     printf("%zu\n",sizeof(arr[1]));// 1
//     printf("%zu\n",sizeof(&arr));// 8
//     printf("%zu\n",sizeof(&arr+1));// 8
//     printf("%zu\n",sizeof(&arr[0]+1));// 8
//     printf("%d\n",strlen(arr));// 未知数
//     printf("%d\n",strlen(arr+0));// 未知数
//     printf("%d\n",strlen(*arr));// 崩溃
//     printf("%d\n",strlen(arr[1]));// 崩溃
//     printf("%d\n",strlen(&arr));// 未知数
//     printf("%d\n",strlen(&arr+1));// 未知数
//     printf("%d\n",strlen(&arr[0]+1));// 未知数
//     int arr[3][4] = {0};
//     printf("%zu\n",sizeof(arr[3]));
//     arr[3]不会越界sizeof只是让编译器提取arr[3]的类型(int[4]类型)，不会去访问内存
//     return 0;
// }

// 指针运算(1)
// int main ()
// {
//     int a[5] = {1,2,3,4,5};
//     int* p = (int*)(&a + 1);
//     // &a+1本来是int(*)[5]类型，与int*不匹配
//     printf ("%d %d",*(a+1),*(p-1));
//     // 转换成int*类型后p-1就是将地址左移一个整形的地址
//     return 0;
// }

// 指针运算(2)
// int main()
// {
//     int a[3][2] = {(0,1),(2,3),(4,5)};
//     // 逗号表达式从左行右执行，结果取决于最后一个表达式
//     // 所以int a[3][2] = {1,3,5};
//     int* p = a[0];
//     printf ("%d",p[0]);
//     return 0;
// }

// 指针运算(3)
// int main()
// {
//     int a[5][5];
//     int(*p)[4];
//     p = (int(*)[4])a;
//     printf("%p %d",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);
//     return 0;
// }

// 指针运算(3)
// int main()
// {
//     char* c[] = {"enter","new","point","first"};
//     char** cp[] = {c+3,c+2,c+1,c};
//     char*** cpp = cp;
//     printf("%s\n",**++cpp);
//     printf("%s\n",*--*++cpp+3);
//     printf("%s\n",*cpp[-2]+3);
//     printf("%s\n",cpp[-1][-1]+1);
//     return 0;
// }

// 小写字母变大写
// int main()
// {
//     char a[] = "I am a student";
//     int sz = sizeof(a)/sizeof(a[0]);
//     for (int i = 0; i < sz-1; i++)
//     {
//         if (islower(a[i]))
//         {
//             // a[i] -= 32;// A与a的ASCII码差32
//             a[i] = toupper(a[i]);
//         }
//     }
//     printf("%s",a);
//     return 0;
// }

// strlen陷阱
// int main ()
// {
//     if(strlen("abc")-strlen("abcdef")>0)// size_t类型接受无符号整数3-6=-3会被当成一个很大的正数
//     {
//         printf(">");
//     }
//     else
//     {
//         printf("<=");
//     }
//     return 0;
// }

// 递归实现strlen
// size_t str(char* p)
// {
//     if (*p != '\0')
//     {
//         return 1+str(p+1);
//     }
//     else
//     {
//         return 0;
//     }
// }
// size_t str(char* p)
// {
//     static int i = 0;// 如果没有static，那么每次i都会变为0，并不会保留下来
//     if (*p != '\0')
//     {
//         i++;
//         str(p+1);
//     }
//     return i;
// }
// int main()
// {
//     char a[] = "abcdef";
//     size_t r = str(a);
//     printf("%zu",r);
//     return 0;
// }

// 模拟实现strcpy
// char* copy(char*p2,const char*p1)//const防止arrr1被修改
// {
//     char* ori = p2;
//     if(*p1 != '\0')
//     {
//         *p2 = *p1;
//         copy(p2+1,p1+1);
//     }
//     else
//     {
//         *p2 = *p1;
//     }
//     return ori;
// }
// char* copy(char*p2,const char*p1)//const防止arrr1被修改
// {
//     char* ori = p2;
//     assert(p2 && p1);// 防止有空指针
//     while(*p1 != '\0')
//     {
//         *p2 = *p1;
//         p2++;
//         p1++;
//     }
//     if (*p1 == '\0')
//     {
//         *p2 = *p1;
//     }
//     return ori;
// }
// 改进
// char* copy(char*p2,const char*p1)//const防止arrr1被修改
// {
//     char* ori = p2;
//     assert(p2 && p1);// 防止有空指针
//     while(*p2++ = *p1++)
//     /* 
//         (*p2++ = *p1++)
//         就是先取出p1付给p2
//         判断结果是否为0（'\0'的ASCII码值为0）
//         然后p1++，p2++
//         循环
//     */
//     {
//         ;
//     }
//     return ori;
// }
// int main()
// {
//     char arr1[] = "abcdef";
//     char arr2[10];
//     copy(arr2,arr1);
//     printf("%s",arr2);
//     return 0;
// }

// 模拟实现strcat
// char* cat(char* p1,const char* p2)
// {
//     char* ret = p1;
//     while(*p1)
//     {
//         p1++;
//     }
//     while(*p1++ = *p2++)
//     {
//         ;
//     }
//     return ret;
// }
// int main()
// {
//     char arr1[20] = "hello";
//     char arr2[] = "world";
//     cat(arr1,arr2);
//     printf("%s",arr1);
//     return 0;
// }

// 模拟实现strcmp
// int cmp(const char* p1,const char* p2)
// {
//     while(*p1 == *p2)
//     {
//         p1++;
//         p2++; 
//         if (*p1 == '\0')
//         {
//             return 0;
//         }
//     }
//     if (*p1 > *p2)
//     return 1;
//     else
//     return -1;
// }
// int main ()
// {
//     char arr1[] = "abcdef";
//     char arr2[] = "abd";
//     int r = cmp(arr1,arr2);
//     printf("%d",r);
//     return 0;
// }

// 模拟实现strstr!!!
// char* str (const char* p1,const char* p2)
// {
//     const char* pp1;
//     const char* pp2;
//     const char* pp = p1;// 避免移动p1地址
//     if (*p2 == '\0')// 不能直接写*p2，会逻辑颠倒
//     {
//         return (char*)p1;// c语言规定空字符串是任意字符串的子串
//     }
//     while (*pp)
//     {
//         pp1 = pp;
//         pp2 = p2;
//         while (*pp1 == *pp2)
//         {
//             pp1++;
//             pp2++;
//             if (*pp2 == '\0')
//             {
//                 break;
//             }
//             else if (*pp1 == '\0')
//             {
//                 break;
//             }
//         }
//         if (*pp2 == '\0')// 没有else，如果有的话只要第一轮没有找到，就会直接结束
//         {
//             return (char*)pp;
//         }
//         pp++;
//     }
//     return NULL;// 找不到的情况
// }
// int main ()
// {
//     char arr1[] = "abcdefgh";
//     char arr2[] = "efg";
//     char* p = str(arr1,arr2);
//     if (p != NULL)
//     {
//         printf("%s",p);
//     }
//     else
//     {
//         printf("找不到");
//     }
//     return 0;
// }

// strtok的使用
// int main ()
// {
//     char arr1[] = "1950881007@qq.com";
//     char arr2[] = "@.";
//     char* p = strtok(arr1,arr2);
//     printf ("%s\n",p);
//     p = strtok (NULL,arr2);// NULL代指上次使用的arr1
//     printf ("%s\n",p);
//     p = strtok (NULL,arr2);
//     printf ("%s\n",p);
//     p = strtok (NULL,arr2);
//     printf ("%s\n",p);
//     return 0;
// }
// 简化
// int main ()
// {
//     char arr1[] = "1950881007@qq.com";
//     char arr2[] = "@.";
//     for (char* p = strtok(arr1,arr2); p != NULL; p = strtok (NULL,arr2);)
//     {
//         printf("%s\n",p);
//     }
//     return 0;
// }

// memcpy的使用
// int main()
// {
//     int arr1[] = {1,2,3,4,5,6,7,8,9,10};
//     int arr2[20] = {0};
//     int sz = sizeof(arr1)/sizeof(arr1[0]);
//     memcpy(arr2,arr1,20);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ",arr2[i]);
//     }
//     return 0;
// }

// memcpy的模拟实现
// void* mcpy(void*p2,void*p1,size_t num)
// {
//     void* p =p2;
//     while (num--)
//     {
//         *(char*)p2 = *(char*)p1;
//         p2 = (char*)p2 + 1;// void*类型不能+-
//         p1 = (char*)p1 + 1;
//     }
//     return p;
// }
// int main ()
// {
//     int arr1[] = {1,2,3,4,5,6,7,8,9,10};
//     int arr2[20] = {0};
//     int sz = sizeof(arr1)/sizeof(arr1[0]);
//     mcpy(arr2,arr1,20);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ",arr2[i]);
//     }
//     return 0;
// }

// memmove的模拟实现
// void* mmove(void*p2,void*p1,size_t num)
// {
//     void* p =p2;
//     if (p2 < p1)
//     {// 从前向后复制
//         while (num--)
//         {
//             *(char*)p2 = *(char*)p1;
//             p2 = (char*)p2 + 1;// void*类型不能+-
//             p1 = (char*)p1 + 1;
//         }
//     }
//     else
//     {// 从后向前复制
//         // p2 = (char*)p2 + num;
//         // p1 = (char*)p1 + num;
//         while(num--)
//         {
//             // p2 = (char*)p2 - 1;// 要先-1再赋值
//             // p1 = (char*)p1 - 1;
//             // *(char*)p2 = *(char*)p1;
//             // 简化
//             *((char*)p2+num) = *((char*)p1+num);
//         }
//     }
//     return p;
// }
// int main ()
// {
//     int arr1[] = {1,2,3,4,5,6,7,8,9,10};
//     int arr2[20] = {0};
//     int sz = sizeof(arr1)/sizeof(arr1[0]);
//     mmove(arr1+2,arr1,20);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ",arr1[i]);
//     }
//     return 0;
// }

// memcmp的使用
// char内字符的替换
// int main()
// {
//     char arr[] = "hello world";
//     memset(arr,'#',5);
//     printf("%s",arr);
//     return 0;
// }
// int的批量清零
// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7};
//     memset(arr,0,28);
//     for (int i = 0; i < 7; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

// 设计程序判断是大端字节序存储还是小端字节序存储
// int main ()
// {
//     int a = 1;
//     // 0x 00 00 00 01
//     int* p = &a;
//     if (*(char*)p == 1)
//     {
//         printf("小端");
//         // 0x 01 00 00 00
//     }
//     else 
//     {
//         printf("大端");
//         // 0x 00 00 00 01
//     }
//     return 0;
// }

// char陷阱(1)
// int main ()
// {
//     char a[1000];
//     // 只能存储-128~127的数
//     for (int i = 0; i < 1000; i++)
//     {
//         a[i] = -i-1;
//         // -1 -2 -3 -4 -5 -6 -7 -8.......-126 -127 -128.........-999 -1000
//         // -1存储11111111 -2存储11111110 -3存储11111101 ...... -128存储10000000
//         // -129存储01111111 即为1 -130存储01111110...... -255存储00000001 -256存储00000000
//     }
//     printf ("%d",strlen(a));// strlen在a中找\0就是数字0 对应-256 在此之前有255个数
//     return 0;
// }

// char陷阱(2)
// int main ()
// {
//     unsigned char i = 0;
//     for (i = 0; i <= 255; i++)
//     {
//         printf("hello world");
//     }
//     return 0;
// }// 陷入死循环 无符号char范围0~255 i <= 255恒成立

// 浮点数的不精确存储
// int main ()
// {
//     if (0.2 + 0.1 == 0.3)
//     // 0.2 = 0.001100110011 = 1.100*2^(-3)
//     // 0 01111101 10011001100110011001100
//     // 0.1 = 0.000110011001 = 1.100*2^(-4)
//     // 0 01111100 10011001100110011001100
//     // 0.3 = 0.010011001100 = 1.001*2^(-2)
//     // 0 01111110 00110011001100110011001
//     {
//         printf("==");
//     }
//     else
//     {
//         printf("!=");
//     }
//     return 0;// 输出!=
// }

// 结构体传参
// struct code
// {
//     int arr[10];
//     int num;
// };
// // void print1 (struct code c)// 传值调用
// // {
// //     for (int i = 0; i < 5; i++)
// //     {
// //         printf("%d ",c.arr[i]);
// //     }
// //     printf("\n%d",c.num);
// // }
// void print2 (struct code* p)
// {
//     for (int i = 0; i < 6; i++)
//     {
//         printf("%d ",p->arr[i]);
//     }
//     printf("\n%d",p->num);
// }
// int main ()
// {
//     struct code c = {{1,2,3,4,5,6},100};
//     // print1(c);// 传值调用
//     print2(&c);
//     return 0;
// }

// 动态内存管理避免内存泄漏
// void get (char** p)// 用二级指针来接收str的地址
// {
//     *p = (char*)malloc(100);// *p = &str
// }
// 或者返回地址
// char* get (char* p)
// {
//     return (char*)malloc(100);
// }
// void test()
// {
//     char* str = NULL;
//     // get(&str);// 传str的地址，用二级指针，才能达到修改str的目的
//     str = get(str);
//     strcpy(str,"go mygo");
//     printf(str);
//     free(str);// 释放堆区申请的空间
//     str = NULL;
// }
// int main ()
// {
//     test();
//     return 0;
// }

// 野指针与改正
// char* get ()
// {
//     char p[] = "mygo desu";
//     return p;
// }
// void test()
// {
//     char* str = NULL;
//     str = get();// p在出get函数后已经销毁，str与p指向的地址相同，但p对应的char []已经销毁没有内容，即str是野指针
//     printf(str);
// }
// 改正(1)
// char* get ()
// {
//     static char p[] = "mygo desu";
//     return p;
// }
// void test()
// {
//     char* str = NULL;
//     str = get();
//     printf(str);
// }
// 改正(2)
// char* get ()
// {
//     char* p = (char*)malloc(10);
//     return p;
// }
// void test()
// {
//     char* str = NULL;
//     str = get();
//     strcpy(str,"mygo desu");
//     printf(str);
// }
// int main()
// {
//     test();
//     return 0;
// }

// 打印a~z
// 法1
// int main ()
// {
//     for (char ch = 'a'; ch <= 'z';ch++)// char ch = 'a'等价于char ch = 97
//     {
//         printf("%c",ch);
//     }
//     return 0;
// }
// 法2
// int main()
// {
//     for (char ch = 'a'; ch <= 'z'; ch++)
//     {
//         fputc(ch,stdout);
//     }
//     return 0;
// }

// 以字符串形式打印结构体中的内容
// struct s
// {
//     char name[20];
//     int age;
//     float score;
// };
// int main()
// {
//     struct s s1 = {"zhangsan",20,66.6f};
//     char arr[30];
//     sprintf(arr,"%s %d %.2f",s1.name,s1.age,s1.score);
//     fprintf(stdout,"%s",arr);
//     return 0;
// }

// 用预定义符号打印文件名，时间
// int main ()
// {
//     printf("%s\n",__FILE__);
//     printf("%d\n",__LINE__);
//     printf("%s\n",__DATE__);
//     printf("%s\n",__TIME__);
//     printf("%d\n",__STDC__);
//     return 0;
// }

// 摄氏温度转华氏温度
// int main()
// {
//     float c = 0;
//     printf("请输入摄氏温度：\n");
//     scanf("%f",&c);
//     float f = 0;
//     f = 1.8*c + 32;
//     printf("该摄氏温度所对的华氏温度是%.1f\n",f);
//     return 0;
// }

// 输出一个数的各位数字
// 逆序输出
// int main()
// {
//     int a=0 ,b=0;
//     printf("请输入一个数：\n");
//     scanf("%d",&a);
//     while(1)
//     {
//         if (a)
//         {
//             b = a % 10;
//             printf("%d ",b);
//             a /= 10;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return 0;
// }
// 顺序输出(1)
// int main()
// {
//     char arr[10];
//     fgets(arr,10,stdin);
//     int i = 0;
//     while (1)
//     {
//         if(arr[i])
//         {
//             printf("%c ",arr[i]);
//             i++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return 0;
// }
// 顺序输出(2)--循环
// int main()
// {
//     int a = 0, b = 0;
//     printf("number\n");
//     scanf("%d",&a);
//     int div = 1;
//     while (a / div > 10)
//     {
//         div *= 10;
//     }
//     while (a)
//     {
//         printf("%d ",a / div);
//         a %= div;
//         div /= 10;
//     }
//     return 0;
// }
// 顺序输出(3)--递归
// void print (int a)
// {
//     if(a >= 10)
//     {
//         print(a/10);
//     }
//     printf("%d ",a%10);
// }
// int main ()
// {
//     int a = 0;
//     scanf("%d",&a);
//     print(a);
//     return 0;
// }

// switch判断等级
// int main()
// {
//     float grade = 0;
//     scanf("%f",&grade);
//     switch ((int)grade/10)
//     {
//     case 10 :
//         printf("A\n");
//         break;
//     case 9 :
//         printf("B\n");
//     case 8 :
//         printf("C\n");
//         break;
//     case 7 :
//         printf("D\n");
//     default:
//         printf("E\n");
//         break;
//     }
//     return 0;
// }

// 判断三条边能不能构成三角形
// int main()
// {
//     float a,b,c;
//     scanf("%f%f%f",&a,&b,&c);
//     if(a+b > c && a+c > b && b+c >a)
//     {
//         printf("true");
//     }
//     else
//     {
//         printf("flase");
//     }
// }

// 求连续数字的和
// int main()
// {
//     int n = 0;
//     int sum = 0;
//     scanf ("%d",&n);
//     for(int i = 1; i <= n; i++)
//     {
//         sum += i;
//     }
//     printf("%d",sum);
//     return 0;
// }

// 输出偶数和三的倍数
// int main ()
// {
//     int n,i;
//     scanf("%d",&n);
//     for(i = 1; i <= n; i++)
//     {
//         if(i % 2 == 0)
//         {
//             printf ("%d ",i);
//         }
//         else
//         {}
//     }
//     printf("\n");
//     for(i = 1; i <= n; i++)
//     {
//         if(i % 3 == 0)
//         {
//             printf("%d ",i);
//         }
//         else
//         {}
//     }
//     return 0;
// }

// 判断一个数是不是素数
// int main()
// {
//     int n = 0;
//     int sum = 2;
//     int i = 0;
//     int flag = 1;
//     scanf ("%d",&n);
//     for (i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             printf("flase");
//             flag = 0;
//             break;
//         }
//     }
//     if (flag)
//     {
//         printf("true");
//     }
//     return 0;
// }

// 打印出斐波那契数列的前20项
// 创建数组
// int main ()
// {
//     int arr[21] = {0,1,1};
//     for(int i = 2; i <= 20; i++)
//     {
//         arr[i] = arr[i-1] + arr[i-2];
//     }
//     for(int i = 1; i <= 20; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }
// 不使用数组
// int main ()
// {
//     int a=1, b=1;
//     int c = 0;
//     printf ("%d %d ",a,b);
//     for(int i = 3; i <= 20; i++)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         printf("%d ",c);
//     }
// }

// 打印九九乘法表
// int main()
// {
//     for(int i = 1; i <= 9; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             printf("%d*%d = %d  ",i,j,i*j);   
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 在有5个数的数组中求最大值最小值和均值
// int getmax (int arr[5])
// {
//     int max = arr[0];
//     for(int i = 1; i < 5; i++)
//     {
//         if(arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }
// int getmin (int arr[5])
// {
//     int min = arr[0];
//     for(int i = 1; i < 5; i++)
//     {
//         if(arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }
// int getaverage (int arr[5])
// {
//     int sum = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         sum += arr[i];
//     }
//     return sum/5;
// }
// int main()
// {
//     int arr[5] = {5,6,8,2,4};
//     int max = getmax(arr);
//     int min = getmin(arr);
//     int average = getaverage(arr);
//     printf("max = %d, min = %d, average = %d",max,min,average);
//     return 0;
// }

// 反转数组元素
// 创建新数组
// void turn(int arr[5])
// {
//     int arr1[5] = {0};
//     for (int i = 0; i < 5; i++)
//     {
//         arr1[i] = arr[i];
//     }
//     for(int i = 0; i < 5; i++)
//     {
//         arr[i] = arr1[4-i];
//     }
// }
// int main()
// {
//     int arr[5] = {1,2,3,4,5};
//     turn(arr);
//     for(int i = 0; i < 5; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }
// 不创建新数组
// void turn (int arr[5])
// {
//     int left = 0;
//     int right = 4;
//     for (int i = 0; i < (5-1)/2; i++)
//     {
//         int a = arr[left];
//         arr[left] = arr[right];
//         arr[right] = a;
//         left++;
//         right--;   
//     }
// }
// int main()
// {
//     int arr[5] = {2,3,4,5,6};
//     turn(arr);
//     for(int i = 0; i < 5; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

// 找出1-100内的素数
// void isprime(int arr[100])
// {
//     for(int i = 1; i <= 100; i++)
//     {
//         for(int j = 2; j*j <= i; j++)
//         {
//             if (i%j == 0)
//             {
//                 arr[i-1] = 0;
//                 break;
//             }
//         }
//     }
// }
// void print(int arr[100])
// {
//     for(int i = 0; i < 100; i++)
//     {
//         if(arr[i])
//         {
//             printf("%d ",i+1);
//         }
//     }
// }
// int main()
// {
//     int arr[100] = {0};
//     for (int i = 1; i < 100; i++)
//     {
//         arr[i] = 1;
//     }
//     isprime(arr);
//     print(arr);
//     return 0;
// }

// 输出一串字符串中大写字母，小写字母和数字的个数
// int upper_count(char s[],int sz)
// {
//     int upper = 0;
//     for(int i = 0; i < sz; i++)
//     {
//         if(s[i] <= 'Z' && s[i] >= 'A')
//         {
//             upper++;
//         }
//     }
//     return upper;
// }
// int lower_count(char s[],int sz)
// {
//     int lower = 0;
//     for(int i = 0; i < sz; i++)
//     {
//         if(s[i] <= 'z' && s[i] >= 'a')
//         {
//             lower++;
//         }
//     }
//     return lower;
// }
// int digit_count(char s[],int sz)
// {
//     int digit = 0;
//     for(int i = 0; i < sz; i++)
//     {
//         if(s[i] <= '9' && s[i] >= '0')
//         {
//             digit++;
//         }
//     }
//     return digit;
// }
// int main()
// {
//     char s[10];
//     fgets(s,9,stdin);
//     int sz = strlen(s);
//     int upper = upper_count(s,sz);
//     int lower = lower_count(s,sz);
//     int digit = digit_count(s,sz);
//     printf("%d %d %d",upper,lower,digit);
//     return 0;
// }
