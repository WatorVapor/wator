# wator
Deep Learning Base On CephFS.

Train Visual Cortex V1.

用无标签数据初级视觉皮层简单训练方法。  

－》已知是简单皮层细胞只对线段倾斜的有感应。  
 －》对每个功能住来说，简单细胞数量有限。  
  －》每个简单细胞对应感应的倾斜角应该是有个刻度范围。  
   －》180度除简单皮层细胞的个数就是，这个刻度A。  

无标签的任意一张图片。  
任意切出倾斜检测候补大小切出来一块。（16x16？）  
 －》如果他能 引起一个简单细胞激活。  
  －》把它旋转刻度A，必定引起对应另一个倾斜角的简单细胞被激活。  
   －》旋转完180度。必定所有简单细胞都被激活一次。  

？初始训练：  
 －》人工制作的图像进行阶段图形。（RGB）  
 －》人工制图像一色图像（RGB）  


训练网络：  
 输入层  
   16x16图像。  
 第一层  
  4x4 视网膜神经节细胞 On／Off模拟  
 第二层   
   全链接网络。
 输出  
   倾斜数。或者 无倾斜（抑制，无边缘）。  

训练过程：  
 －》一张有倾斜图片的第一次前传播的结果是。  
   ［1，0，0，0，0］  
 －》本图片的一次翻转的后。期望的结果。  
   ［0，1，0，0，0］  

单神经元训练的方法：  
 神经元的输出尽量进行二级化。  
 训练的过程就是，调整权值，使输出值其远离神经元的激活阀值。  
 
 -------------------------
 输入层阀值训练  
  下一层需要的信息量来调整输出1的数量。  
   比如下层需要3x3矩阵，本层节点接受上层的矩阵大小为3x3的话。  
   本层的阀值需要在9x9的整体，来调整每个节点的阀值。 
   调整的方法目标，是产生【false，true】的稀疏矩阵。  
    如果下层需要线检查，每条线表达需要3个像素  
     9x9的整体上最多产生3个true  
 -------------------------
 隐藏层训练  
  记忆每次输入的【false，true】矩阵，类似相同的输入  
   大量出现类似矩阵的时候作为一个3x3 的【false，true】。  
   对于每一个输入类别。进行累计计数。  
   3x3的话。2的9此方类别。进行累计。  
     累计的数量作为这个类型数据的权值。  
      例如 做成以下的数组  
       【000000000】-》计数  
       【000000111】-》计数    
       【111000000】-》计数     
       【101010101】-》计数     
      多个数组，再组合生出下一级数据。  
      下一级数据，也用稀疏矩阵来限定，输出数据的量。  
 
解决大小图像分段问题。    
多层输出层:   
 1.每层都连接到最终输出层，从优实际意义层开始，每层都连接到输出，层数无限制，知道最终结果的矩阵校园输出矩阵的大小  
 2.输出层有一个Convolution层，和全连接层组层。  
 

V1输出层建立的问题：  
 1.按照记忆的最多的filter开始，对输入进行计算输出，如果不能生成，下一层的矩阵能的贯穿partern，继续以次数少的filter进行计算。 
   直到无法生产贯穿filter为止。
 2.如果可以生产一个输出层的贯穿partern，记录所有，输入的激活的filer。作为一个特征值。
 
 
