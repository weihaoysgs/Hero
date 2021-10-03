# HLL Super Hero
Hll 2022 Super Hero 


- [x] 模块检测任务
- [x] 串口 1 DMA 双缓冲接收
- [x] 遥控器任务初步完成
- [x] 增加并完成 CAN1 数据解析任务
- [x] 增加并完成 CAN2 数据解析
- [x] 增加机器人模式
- [x] 增加遥控器进一步的数据解析
- [ ] 改进 printf
- [x] 云台角度控制
- [ ] can 发送队列
- [x] 蜂鸣器任务
- [x] 云台发射电机速度初步设置
- [x] 底盘基本运动控制
- [ ] 陀螺仪数据读取
- [ ] 卡尔曼滤波数据解析
- [ ] 裁判系统数据读取解析
- [ ] 自瞄任务
- [ ] ui 界面
- [ ] 显示屏




## Problem

- [ ] 注意最好不要在任务中接收 CAN 的数据，经测试会卡死，但也不一定，只是我出现了这个问题

- [ ] <DAPLink:Overflow>
- [ ] 出现了莫名其妙的 undefined reference to Rc_Ctrl_t ，虽然后面不报了，但仍没找出 bug

- [x] CAN 在使用 HAL 库的时候，如果不接收 CAN 的数据，会出现任务卡死

  ```c++
  HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, can2_rx_header, can2_rxd_data_buffer);
  ```
  **`该问题已解决，由于语法出错，在接收函数中传入了一个空地址导致该错误的发生`**

- [ ] 注意不要在中断中随便打印数据，否则可能会造成死锁。

  



