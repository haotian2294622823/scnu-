# 操作系统原理（B）实验指导书

## 实验一：Linux开发环境熟悉
1. **Linux文件系统结构熟悉**  
   - Linux目录结构，基本文件操作命令。

2. **Linux 常用命令的使用**  
   - Linux 系统基本操作（启动与退出、文件和目录操作、文档备份与压缩、联机帮助等）：
     - `login`, `logout`, `exit`, `halt`, `shutdown`
     - `pwd`, `cd`, `mkdir`, `rmdir`, `cat`, `cp`, `mv`, `rm`, `ls`, `chmod`, `find`, `grep`, `more`, `sort`, `gzip`, `unzip`, `tar`, `rpm`, `man`, `info`, `--help`

3. **Vi / Emacs等编辑软件的使用**

4. **gcc、g++、gdb 命令的使用**  
   - 开发调试环境。

### 实验检查内容：
- 运行10个以上命令，并解释其含义。
- 用vi编写一个C语言程序，演示gcc编译过程并运行。

---

## 实验二：进程同步与互斥
1. **进程同步与互斥控制**  
   - 读者写者、一家人吃苹果橘子、哲学家就餐（原码阅读与系统编程级）。

### 实验检查内容：
- 编写C语言程序，模拟完成读者写者问题、苹果橘子问题或哲学家就餐问题，使用gcc编译并运行。

---

## 实验三：处理机调度
1. **作业调度算法**  
   - 先来先服务、短作业优先、最高响应比优先。

2. **进程调度算法**  
   - 最短剩余时间优先、时间片轮转、优先数调度。

### 实验检查内容：
- 编写C语言程序，模拟完成一种调度算法，输出各个作业的周转时间和平均周转时间、带权周转时间和平均带权周转时间。

---

## 实验四：虚拟内存管理
1. **局部性原理演示**  
   - 数组清零（操作系统观察级）。

2. **页面置换算法模拟演示**  
   - 模拟页面置换算法（FIFO/LRU/OPT）。

### 实验检查内容：
- 编写C语言程序，模拟页面置换算法，使用gcc编译并运行。
