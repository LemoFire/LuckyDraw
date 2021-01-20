# LuckyDraw

一个多功能抽奖器，能自定义奖品信息、名称、抽奖人数等数据，可循环抽取，并能将抽奖数据保记录在本地文件内

#### 程序流程图

![flowchart](https://github.com/LemoFire/LuckyDraw/raw/main/doc/flowchart.png)

#### 程序说明

- 开始界面输入 1.2.3 选择要进入的功能，1 为定义奖品的各种信息，包括奖项名称、奖品名称、抽奖人数、奖项数量，输入后前三个信息会记录到日志文件及二进制 dat 文件；3 为读取上一次存储的奖品信息数据；2 为抽奖功能，抽奖依据为 1 所定义的数据或 3 读取到的数据，若未进行 1 或者 3 直接选 2（全局变量 definitionflag==0），直接回到主选单。
  奖项设置最大为 20 个

- 定义奖项名称、奖品名称、抽奖人数、奖项数量的结构体 `prize`：成员对应有： `char prize_name[20][20], goods_name[20][20];int prize_people[20];int num;`（所有数据定义在头文件 struct.h 中）

- 日志存放在 info.txt 文件，奖项数据记录保存在 info.dat 中；

- 采用模块化程序设计方法来实现，即 main()显示主菜单、调用相关函数实现相应功能，起主控作用。

### 程序运行截图及说明

- 欢迎界面

![1](https://github.com/LemoFire/LuckyDraw/raw/main/doc/1.png)

- 定义奖品信息界面

![2](https://github.com/LemoFire/LuckyDraw/raw/main/doc/2.png)

- 抽奖界面，接下来关闭程序重新打开

![3](https://github.com/LemoFire/LuckyDraw/raw/main/doc/3.png)

- 直接选 2 提示未定义，重新选择

![4](https://github.com/LemoFire/LuckyDraw/raw/main/doc/4.png)

- 按 3 读取上次的信息，并可以开始抽奖

![5](https://github.com/LemoFire/LuckyDraw/raw/main/doc/5.png)

- 抽奖正常

![6](https://github.com/LemoFire/LuckyDraw/raw/main/doc/6.png)

- 若定义抽奖人数小于最大奖项的奖项数目或者输入 0，提示错误

![7](https://github.com/LemoFire/LuckyDraw/raw/main/doc/7.png)

- 记事本数据记录正常

![8](https://github.com/LemoFire/LuckyDraw/raw/main/doc/8.png)
