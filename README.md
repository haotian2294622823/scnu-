

##  操作系统原理（B）实验指导书

#实验一  Linux开发环境熟悉
操作系统实验环境熟悉（Linux操作命令、Linux/Windows平台编程工具）
1.Linux文件系统结构熟悉（操作系统使用级）
 Linux目录结构，基本文件操作命令
2.Linux 常用命令的使用（操作系统使用级）
 Linux 系统基本操作（启动与退出、文件和目录操作、文档备份与压缩、联机帮助等）
 （login, logout, exit, halt, shutdown, pwd, cd, mkdir, rmdir, cat, cp, mv, rm, ls, chmod, find, grep, more, sort, gzip, unzip, tar, rpm, man, info, --help ）
3.Vi / Emacs等编辑软件的使用（操作系统使用级）
4.gcc 、g++、 gdb 命令的使用（开发调试环境）（操作系统使用级）
实验检查内容：
（1）运行10个以上命令，并解释其含义
（2）用vi编写一个C语言程序，内容不限，演示gcc编译过程并运行.
#实验二  进程同步与互斥
 1进程同步与互斥控制（读者写者、一家人吃苹果橘子、哲学家就餐）（原码阅读与系统编程级）
 参考：	学习通 3.3 进程互斥、3.4 进程同步、3.5 经典互斥与同步问题
 实验检查内容：编写C语言程序，模拟完成读者写者问题，或者苹果橘子问题，或者哲学家就餐问题，使用gcc编译并运行。
 【若自行设计问题并实现同步与互斥，可加分】
#实验三  处理机调度
 1.作业调度算法（先来先服务、短作业优先、最高响应比优先）
 参考：	 学习通 5.2 作业与作业调度
2.进程调度算法（最短剩余时间优先、时间片轮转、优先数调度）
 参考：	 学习通 5.3 进程调度
 实验检查内容：编写C语言程序，指定N个作业的到达时间、运行时间等信息，模拟完成一种调度算法，输出各个作业的周转时间和平均周转时间、带权周转时间和平均带权周转时间。
【若拓展实现两道批处理，可加分】
【若自行设计合理的调度算法，可加分】
#实验四.虚拟内存管理
1.局部性原理演示（数组清零）（操作系统观察级）
参考：  学习通 6.5 缺页中断与页面置换算法
2.页面置换算法模拟演示（算法仿真实现级）
参考：  学习通 6.5 缺页中断与页面置换算法
实验检查内容：编写C语言程序，模拟页面置换算法（FIFO/LRU/OPT），使用gcc编译并运行。
【若自行设计合理的页面置换算法，可加分】
