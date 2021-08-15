# CODE_C

## 1 代码规范

---

### 1.1

```c
#define BUF_SIZE 1024       // 宏定义全部大写,下划线分隔
const int ARRAY_LEN 265     // 常量全部大写,用下划线分隔

/*
变量命名要有意义
变量名尽量不缩写 
作用域越大, 名字可以越长 
*/
                            // 注释对齐
char* my_name = nullptr;    // 变量全部小写用下划线分隔
int g_flag;                 // 全局变量 g_xxx

class FileManage{           // 类名大驼峰                         
privite:                    // 函数名一般用动宾，变量名一般用名词
    string m_name;          // 成员变量 m_xxx    

public:
    bool isFind;            // 布尔变量应写成谓词
    static string s_name;   // 静态变量 s_xxx 
    string getName();       // 小驼峰
    bool isExsit();
}

```

### 1.2常用描述

```c
类型            对应描述          
最大值             Max                
最小值             Min             
初始化             Ini           
求和               Sum 
添加               Add  
删除               Del
更新               Upd
获取               Get
设置               Set
密码               Pwd
```

## 2 常见错误

---

### 2.1 Segmentation Fault

```c
// 1). 空指针访问
char* p = NULL;
printf("%c",*p);    //错误
*p = 'a';           //错误

//  2). 指针指向非法区域的写操作(数组越界)
char* p = malloc(100);
p += 1000;
*p = 'a'; //错误

// 3). 常量空间被破坏
char *p = "Quanwei";
p[1] = 'q'; // 修改常量空间, 错误

```
