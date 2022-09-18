# 第三章作业

### 2.1  {$Z,+$} 是否为群？若是，验证其满足群定义；若不是，说明理由。(其中 $Z$ 为整数集)

{$Z,+$} **是群**

1. ∀ $a_1$, $a_2$ ∈ $Z$，($a_1$ + $a_2$ ∈ $Z$), 因此满足**封闭性**
2. ∀ $a_1$, $a_2$, $a_3$ ∈ $Z$，(($a_1$+$a_2$)+$a_3$ = $a_1$+$(a_2$+$a_3$)), 因此满足**结合律**
3. ∃ 0∈$Z$, s.t. ∀ $a$∈$Z$, 0+$a$=$a$+0=$Z$, 因此满足**幺元**
4. ∀ $a$∈$Z$, ∃ $-a$∈$Z$, s.t. $a$+($−a$)=0, 因此满足**逆**

{$Z,+$}满足以上四条性质，因此**是群**

### 2.2  {$N,+$} **是否为群？若是，验证其满足群定义；若不是，说明理由。(其中 $N$ 为自然数集)

{$N,+$} **不是群**

$∀n ∈ N$ 无法找到其逆$n^{-1}$, 使得 $n+n^{-1}=0$ , 不满足逆的性质

### 2.3  解释什么是阿贝尔群。并说明矩阵及乘法构成的群是否为阿贝尔群。

阿贝尔群是有着群运算符合交换律性质的群，因此阿贝尔群也被称为交换群。它由自身的集合 $G$ 和二元运算 $*$ 构成。它除了满足一般的群公理，即运算的结合律、$G$ 有单位元、所有 $G$ 的元素都有逆元之外，还满足交换律公理。

设 $<G,*>$ *是一个群，$<G,*>$* 是阿贝尔群的充要条件是对任意的 $a,b∈G$ ,有 $( a * b ) * ( a * b ) = ( a * a ) * ( b * b )$   。对于矩阵的乘法，并不满足交换律，所以对于矩阵及乘法构成的群不是阿贝尔群。

### 3  **验证向量叉乘的李代数性质**

**1、封闭性**
$a$ ∈ $R^3$ , $b$ ∈ $R^3$ , $a$$\times$$b$ ∈$R^3$ 

满足封闭性

**2、双线性**

($\lambda_1$$a$ + $\lambda_2$$b$) $\times$$c$= $\lambda_1$ $a$$\times$$c$ + $\lambda_2$ $b$$\times$$c$

$c$$\times$ ($\lambda_1$$a$ + $\lambda_2$$b$) = $\lambda_1$ $c$$\times$$a$ + $\lambda_2$ $c$$\times$$b$ 

满足双线性

**3、自反性**
$a$$\times$$a$ = 0

满足自反性

**4、雅可比等价**
($a$$\times$($b$$\times$$c$)) + ($b$$\times$($c$$\times$$a$)) + (c$\times$(a$\times$b)) $\\$ =$b$($a$$\cdot$$c$) - $c$($a$$\cdot$$b$) + $c$($b$$\cdot$$c$) - $a$($b$$\cdot$$c$) + $a$($c$$\cdot$$b$) - $b$($c$$\cdot$$a$) $\\$=0

满足雅可比恒等式

以上四条性质均满足

### 4  **推导 $SE(3)$ 的指数映射**

式（2）推导过程：

![无标题3.png](%E7%AC%AC%E4%B8%89%E7%AB%A0%E4%BD%9C%E4%B8%9A%206ab7a2afa7cc4fffb24184fc2d5794ee/%25E6%2597%25A0%25E6%25A0%2587%25E9%25A2%25983.png)

式（3）推导过程：

![无标题2.png](%E7%AC%AC%E4%B8%89%E7%AB%A0%E4%BD%9C%E4%B8%9A%206ab7a2afa7cc4fffb24184fc2d5794ee/%25E6%2597%25A0%25E6%25A0%2587%25E9%25A2%25982.png)

### 5  请你证明 $SO(3)$ 伴随的性质

参考了题目中给出的链接

[https://math.stackexchange.com/questions/2190603/derivation-of-adjoint-for-so3](https://math.stackexchange.com/questions/2190603/derivation-of-adjoint-for-so3)

![真实伴随.png](%E7%AC%AC%E4%B8%89%E7%AB%A0%E4%BD%9C%E4%B8%9A%206ab7a2afa7cc4fffb24184fc2d5794ee/%25E7%259C%259F%25E5%25AE%259E%25E4%25BC%25B4%25E9%259A%258F.png)

### 6.1  旋转点对旋转的导数。请分别通过左、右扰动的方式，计算：$\frac{\partial{Rp}}{\partial{R}}$*.*

思路：左扰动已在课程中推过了，只需推一遍右扰动，原理与左扰动相似，其中使用了 $R^TR=I$和 $SO(3)$ 的伴随性质 $***R***$exp($p$^)$***R^T***$ = exp(($Rp$)^).

![so3右扰动111.png](%E7%AC%AC%E4%B8%89%E7%AB%A0%E4%BD%9C%E4%B8%9A%206ab7a2afa7cc4fffb24184fc2d5794ee/so3%25E5%258F%25B3%25E6%2589%25B0%25E5%258A%25A8111.png)

### 6.2  旋转的复合。请分别通过左、右扰动的方式，计算：$*\frac{\partial \ln(R_1R_2)^{\vee}}{\partial R_1}$.*和：$*\frac{\partial \ln(R_1R_2)^{\vee}}{\partial R_2}$.*

**左扰动**

$\frac{\partial \ln(R_1R_2)^{\vee}}{\partial R_1}$

$=\lim\limits_{\varphi\to0}\frac{ln(exp(\varphi^{\land})R_1R_2)^{\vee}-ln(R_1R_2)^{\vee}}{\varphi}$

$\approx\lim\limits_{\varphi\to0}\frac{J_l(ln(R_1R_2)^\vee)^{-1}\varphi+ln(R_1R_2)^{\vee}-ln(R_1R_2)^{\vee}}{\varphi}$

$=\lim\limits_{\varphi\to0}\frac{J_l(ln(R_1R_2)^\vee)^{-1}\varphi}{\varphi}$

$=J_l(ln(R_1R_2)^\vee)^{-1}$

同理可得：$\frac{\partial \ln(R_1R_2)^{\vee}}{\partial R_2}=J_l(ln(R_1R_2)^\vee)^{-1}$

**右扰动**

$\frac{\partial \ln(R_1R_2)^{\vee}}{\partial R_1}$

$=\lim\limits_{\varphi\to0}\frac{ln(R_1R_2exp(\varphi^{\land}))^{\vee}-ln(R_1R_2)^{\vee}}{\varphi}$

$\approx\lim\limits_{\varphi\to0}\frac{J_r(ln(R_1R_2)^\vee)^{-1}\varphi+ln(R_1R_2)^{\vee}-ln(R_1R_2)^{\vee}}{\varphi}$

$=J_r(ln(R_1R_2)^\vee)^{-1}$

同理可得：$\frac{\partial \ln(R_1R_2)^{\vee}}{\partial R_2}=J_r(ln(R_1R_2)^\vee)^{-1}$

### 7.1  事实上，$T_{WC}$ **的平移部分即构成了机器人的轨迹。它的物理意义是什么？为何画出 $***T_{WC}**$* 的平移部分就得到了机器人的轨迹？

平移部分表明了在不同时间机器人坐标系的原点在空间中的位置，而机器人坐标系代表了机器人的位姿，所以 $T_{WC}$ 的平移部分可以表示机器人的位置变化轨迹

### 7.2  请你完成数据读取部分的代码，然后书写 CMakeLists.txt 以让此程序运行起来。

![task7.png](%E7%AC%AC%E4%B8%89%E7%AB%A0%E4%BD%9C%E4%B8%9A%206ab7a2afa7cc4fffb24184fc2d5794ee/task7.png)

### 8  我为你准备了 code/ground-truth.txt 和 code/estimate.txt 两条轨迹。请你根据上面公式，实现 RMSE的计算代码，给出最后的 RMSE 结果。作为验算，参考答案为：2.207。

![task80.png](%E7%AC%AC%E4%B8%89%E7%AB%A0%E4%BD%9C%E4%B8%9A%206ab7a2afa7cc4fffb24184fc2d5794ee/task80.png)