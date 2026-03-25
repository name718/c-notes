/*
 * 文件名：01_types_variables.c
 * 学习目标：
 * 1. 理解 C 中常见基本类型
 * 2. 学会定义变量、常量，并使用 sizeof
 * 3. 理解“类型声明后，为什么还能给它赋其他类型的值”
 *
 * 核心知识点：
 * - 常见类型：char、int、float、double
 * - 变量定义与初始化
 * - const 修饰只读变量
 * - sizeof 用于查看类型或变量占用的字节数
 * - C 会发生很多“隐式类型转换”
 * - C 没有内建 string 类型，字符串通常用 char 数组表示
 *
 * 易错点：
 * - 不要想当然认为 int 一定是 4 字节，标准没有强制写死，只是常见实现如此
 * - sizeof 的结果类型是 size_t，打印时常用 %zu
 * - 变量有了类型，不代表只能接收“完全同类型”的值；很多时候编译器会自动转换
 * - 自动转换不一定报错，但可能丢精度、截断数据，甚至只给警告
 *
 * 面试考点：
 * - 基本类型大小是否固定？答：和编译器、平台有关
 * - float 和 double 区别？答：double 通常比 float 占更多字节、精度更高、能表示的数值范围通常也更大
 * - const 是“真正常量”还是“只读变量”？答：更准确地说是只读对象
 * - char 为什么既能存 'A' 又能存 1？答：因为 char 本质上是整数类型的一种
 * - C 里有没有 string 类型？答：没有，通常用 char 数组或 char * 表示字符串
 */

#include <stdio.h>

int main(void)
{
    /*
     * char 本质上是“整数类型”，不是“只能存字符”的特殊容器。
     * 在很多系统里，'A' 对应的编码值通常是 65。
     *
     * 所以：
     * - char grade = 'A';   合法
     * - grade = 1;          也合法
     *
     * 原因：
     * - 'A' 是字符常量，但底层本质是一个整数编码值
     * - 1 也是整数
     * - 把 int 赋给 char 时，编译器会尝试自动转换
     *
     * 什么时候可能报错或报警告？
     * - 如果赋的值超出 char 能表示的范围，可能出现警告、截断，结果还可能依赖平台
     * - 例如：char c = 1000; 这类写法通常就不推荐
     *
     * 重点：
     * - C 语言检查的是“类型规则”，不是“业务语义”
     * - 变量名叫 grade，编译器并不会因此强制你只能放 'A'、'B'
     */
    char grade = 'A';
    grade = 1;
    int age = 20;
    age = '1212';

    /*
     * float 和 double 的区别：
     * 1. float 通常占 4 个字节，double 通常占 8 个字节
     * 2. double 精度通常更高，能保存更多有效数字
     * 3. 小数字面量默认是 double，所以这里写 175.5f，明确表示这是 float 字面量
     */
    float height = 175.5f;
    double weight = 68.75;
    const int days_per_week = 7;

    /*
     * 类型声明后，能不能赋值成其他类型？
     * 答：很多时候“可以”，因为 C 会做隐式类型转换。
     *
     * 例如：
     * - int n = 3.14;        可以，但小数部分会丢失，n 变成 3
     * - double d = 10;       可以，10 会自动转成 10.0
     * - char c = 97;         可以，常见环境下对应字符 'a'
     * - float f = 1.23;      可以，但 1.23 默认是 double，会发生 double -> float 转换
     *
     * 那什么时候报错？
     * 1. 类型根本不兼容时，可能报错
     *    例如把一个数组直接赋值给另一个数组：
     *    char a[10] = "hi";
     *    char b[10];
     *    b = a;      // 错误，数组不能整体赋值
     *
     * 2. 修改 const 变量，通常会报错
     *    const int x = 10;
     *    x = 20;     // 错误，只读对象不能修改
     *
     * 3. 某些危险转换，编译器可能不给“错误”，只给“警告”
     *    例如：
     *    int n = 3.99;       // 可能警告：从 double 转 int，精度丢失
     *    char c = 1000;      // 可能警告：值超范围
     *
     * 为什么有时不报错，只报 warning？
     * - 因为 C 语言本身允许很多转换
     * - 编译器认为“这也许是程序员故意这么写的”
     * - 所以它常常只提醒你“有风险”，而不是强行禁止
     */

    /*
     * C 没有 string 这种内建类型。
     * C 里的“字符串”通常是：
     * 1. char 数组
     * 2. 指向字符的指针
     *
     * 下面这个写法里：
     * - "Alice" 是字符串字面量
     * - name 是一个字符数组
     * - 编译器会把字符串内容复制到数组里，并在结尾补一个 '\0'
     * - '\0' 是字符串结束标记
     */
    char name[] = "Alice";

    /*
     * grade 当前已经被改成 1。
     * 用 %d 打印时，把它当整数看；
     * 用 %c 打印时，把它当字符看。
     *
     * 因为 1 对应的是不可打印控制字符，所以 %c 的显示效果可能不明显。
     */
    printf("grade 作为整数输出 = %d\n", grade);
    printf("grade 作为字符输出 = %c\n", grade);
    printf("age = %d\n", age);
    printf("height = %.1f\n", height);
    printf("weight = %.2lf\n", weight);
    printf("days_per_week = %d\n", days_per_week);
    printf("name = %s\n", name);

    /*
     * sizeof 的作用：
     * - sizeof 用来计算“类型”或“变量”在内存中占多少字节
     * - 输出结果的单位是“字节（byte）”
     * - %zu 用来打印 sizeof 的结果，因为 sizeof 的结果类型通常是 size_t
     *
     * 例如：
     * - sizeof(char) 结果通常是 1，单位是 1 字节
     * - sizeof(name) 计算的是整个字符数组占多少字节，不是“字符个数的概念”那么简单
     */
    printf("sizeof(char) = %zu 字节\n", sizeof(char));
    printf("sizeof(int) = %zu 字节\n", sizeof(int));
    printf("sizeof(float) = %zu 字节\n", sizeof(float));
    printf("sizeof(double) = %zu 字节\n", sizeof(double));
    printf("sizeof(name) = %zu 字节\n", sizeof(name));

    return 0;
}
