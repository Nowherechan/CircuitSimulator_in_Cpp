# Internals

Here is a brief description of how we simulate a circuit.
See the book Electronic Circuit and System Simulation Methods by
Pillage, et al for more information.
这里简单介绍一下我们是如何模拟电路的。
更多信息请参见Pillage等人的《电子电路和系统仿真方法》一书。

Basically, we create a matrix.  Each row in the matrix represents
a node in the circuit.  The matrix equation looks like A x = B
where x is a vector containing the voltages of each node.  B
represents the net current in or out of each node, and should be
all zeroes by Kirchoff's current law, unless there is a current
source somewhere.
基本上，我们创建一个矩阵。 矩阵中的每一行代表电路中的一个节点。 矩阵方程看起来像A x = B，其中x是一个包含每个节点电压的向量。 B代表每个节点的净电流，根据基尔霍夫电流定律，它应该全部为零，除非某个地方有电流源。

If you have a resistor, you want Vb-Va=IR or Vb/R - Va/R = I.  So
the net current out of node b and into node a depends on the voltage
Vb and Va.  You add matrix elements -1/R and 1/R at rows a and b
and columns a and b to reflect this.  (See CirSim.stampResistor()).
Then after adding all resistors to the matrix, you solve for x, and
that gives you the voltage at each node, and from that you can
derive the currents through each element.  We leave out node 0, the
ground node, because the matrix would be singular otherwise (there
would be an infinite number of solutions, because all nodes can be
shifted up or down by the same voltage).
如果你有一个电阻，你希望Vb-Va=IR或Vb/R-Va/R=I。因此，从节点b出来和进入节点a的净电流取决于电压Vb和Va。你在行a和b以及列a和b添加矩阵元素-1/R和1/R以反映这一点。 (见CirSim.stampResistor()）。
然后在矩阵中加入所有的电阻后，求解x，就可以得到每个节点的电压，然后就可以得出通过每个元素的电流。我们不考虑节点0，即接地节点，因为否则矩阵将是奇异的（会有无限多的解决方案，因为所有节点都可以通过相同的电压向上或向下移动）。

To implement a current source of current I, we simply subtract I from
row a of the right side vector, and add I to row b.  This
represents a flow of current I from a to b. (CirSim.stampCurrentSource())
要实现一个电流I的电流源，我们只需从右侧向量的a行减去I，然后在b行加上I。

We need to add additional rows to the matrix to implement voltage
sources.  Each voltage source needs an additional row to enforce
the voltage constraint, and also an additional element in x (and
an extra matrix column) to solve for the current (since we have no other
way to obtain it).  For a voltage source with voltage Vs across
nodes a and b, the voltage constraint equation is Vb-Va = Vs.  To express
that as a row in the matrix, you add matrix elements 1
and -1 in the extra row at columns b and a, and set the corresponding
element of the right side (B) to Vs.  Also, to represent a flow of
current I from node a to b, we add matrix elements 1 to -1 in rows
a and b in the extra column.  (CirSim.stampVoltageSource())
Now when solving for x, we get the voltage at each node, and the
current through each voltage source.
我们需要在矩阵中添加额外的行来实现电压源。 每个电压源需要一个额外的行来执行电压约束，以及x中的一个额外元素（和一个额外的矩阵列）来求解电流。额外的矩阵列）来解决电流问题（因为我们没有其他方法来获得它）。因为我们没有其他方法来获得它）。)  对于一个电压源，在节点a和b上的电压为Vs,电压约束方程是Vb-Va = Vs。矩阵中的一行，你可以将矩阵元素1 和-1，并在b列和a列的额外一行设置相应的 右侧（B）的相应元素为Vs。电流I从节点a流向b，我们在行中添加矩阵元素1到-1 a和b的额外列中。 (CirSim.stampVoltageSource())
现在，当求解x时，我们得到每个节点的电压，以及通过每个电压源的电流。

When simulating inductors, the current state changes over time.
We use a small timestep value to step through time iteratively to
simulate the circuit.  We treat an inductor as a current source in
parallel with a resistor.  The current source has current equal to
the current through the inductor at a particular time.  The resistor
represents resistance to changes in current, and the resistance
value is proportional to the inductance.  So for each time step,
we solve the equation, get the new current, and then update
the current source value.  (We just need to change the right
side for this, not the matrix.)
在模拟电感器时，电流状态随时间变化。我们使用一个小的时间步长值，通过时间迭代的方式来仿真电路。 我们把电感器当作一个与电阻并联的电流源。与一个电阻并联。 该电流源的电流等于在某一特定时间通过电感器的电流。 电阻器代表对电流变化的阻力，而阻力值与电感成正比。 因此，对于每一个时间步骤。我们解决这个方程，得到新的电流，然后更新 电流源的值。 (我们只需要改变右边的 右侧，而不是矩阵。)

This is numerical integration, and there are several ways to do it.
There's forward Euler which we don't use.  There's backward Euler which is 
more stable than forward Euler.  And there is trapezoidal which
is more accurate than backward Euler but less stable.  You can select
either trapezoidal or backward Euler.  Trapezoidal will give you
better accuracy for something like an LRC circuit or a filter, but
backward Euler will give you better stability (much less oscillation)
if an inductor is suddenly switched on or off.  To implement these
in our inductors, we simply choose different values for the resistor
and the current through the current source, depending on which
method is being used.
这就是数值积分，有几种方法可以做到。
有一种我们不使用的正向欧拉法。 还有一种后向欧拉，它是比前向欧拉更稳定。 还有一种是梯形法，它比后向欧拉更精确，但不太稳定。 你可以选择梯形或后向欧拉。 梯形会给你更好的精度，但后向欧拉法会给你提供更好的精度，如LRC电路或过滤器。后向欧拉会给你更好的稳定性（更少的振荡）。如果一个电感器突然被打开或关闭。 为了实现这些 在我们的电感器中，我们只需选择不同的电阻值 和通过电流源的电流选择不同的值，这取决于使用哪种 方法。

To simulate capacitors, you could simulate it as a voltage source
in series with a resistor.  But this would require two extra rows
in the matrix.  Instead, we simulate it as a current source in
parallel with a resistor.  The resistor value is inversely proportional
to the capacitance, because large capacitors can store more charge
(accept more current flow) without a large change in voltage.  The
current from the current source flows in a loop through the resistor
and this simulates the charge on the capacitor.  This current changes
after each timestep, like the inductor.  After each step, we get
the new voltage and current and update the current source appropriately.
为了模拟电容器，你可以把它模拟成一个电压源和一个电阻串联起来。 但这将需要在矩阵中增加两行矩阵中的两行。 相反，我们把它模拟成一个与电阻并联的电流源。与一个电阻并联。 电阻器的值与电容成反比。与电容成反比，因为大电容可以储存更多的电荷 (接受更多的电流)，而电压不会有大的变化。 来自电流源的电流以循环方式流经电阻这模拟了电容器上的电荷。 这个电流在每个时间段后会发生变化 在每一个时间步长后发生变化，就像电感器一样。 每一步之后，我们得到 新的电压和电流，并适当地更新电流源。

For nonlinear devices the matrix must be solved iteratively.  For example,
a diode has current that is an exponential function of the voltage.
For that we start with a given voltage and linearize the diode's
response at that point, so we can represent it in the matrix.  We find
the tangent line to the diode's response curve at that voltage,
and that line can be expressed as a resistance (depending on the
slope of the line) and a current source (depending on its height).
After solving the matrix, we get a new voltage across the diode, and we
compare it with the old voltage to see if it's nearly the same.  If
not, then we have to calculate a new linearization and create a new
matrix.  This continues until it converges on a value that is nearly
the same as the previous one.
对于非线性设备，矩阵必须被迭代求解。 比如说。一个二极管的电流是电压的指数函数。 对于这一点，我们从一个给定的电压开始，并将二极管在该点的响应线性化。
响应，所以我们可以在矩阵中表示它。 我们找到 二极管在该电压下的响应曲线的切线。这条线可以表示为一个电阻（取决于线的斜率 该线可以表示为一个电阻（取决于线的斜率）和一个电流源（取决于其高度）。 求解矩阵后，我们得到一个新的二极管上的电压，然后我们 我们将其与旧的电压进行比较，看看它是否几乎相同。 如果 如果不是，那么我们必须计算一个新的线性化，并创建一个新的矩阵。 这样继续下去，直到它收敛在一个几乎与前一个相同的值上。与前一个值相同。

When simulating diodes and transistors, we have to be careful to limit the
changes in voltage at each iteration.  Since the response is an
exponential function, we could easily end up with an enormous current.
The linearization could be too large to represent accurately in the
matrix.
在模拟二极管和晶体管时，我们必须注意限制每次迭代时的电压变化。 由于响应是一个指数函数，我们很容易就会出现巨大的电流。线性化可能太大，无法在矩阵中准确表示。

Nonlinear devices require iteration, which requires us to create a new
matrix and fully solve it at least once per timestep.  If there are no
nonlinear devices, we don't need to do this.  The matrix doesn't
change, only the right side.  We can partially solve this matrix
beforehand, by doing an LU factorization.  This saves a lot of time
for large linear circuits, so we do this whenever possible.
We call CircuitElm.nonLinear() for each element when analyzing the circuit
to see if we need to do the extra work.
非线性设备需要迭代，这就要求我们创建一个新的矩阵，并在每个时间段至少完全解决一次。 如果没有非线性设备，我们就不需要这样做。 矩阵不会改变，只有右边会改变。 我们可以事先通过做LU因子化来部分解决这个矩阵。 这对大型线性电路来说可以节省很多时间，所以我们尽可能地这样做。在分析电路时，我们对每个元素调用CircuitElm.nonLinear()，看看是否需要做LU因子化。以了解我们是否需要做这些额外的工作。

When analyzing a circuit, we call stamp() for each CircuitElm to
create the matrix.  This creates the circuit elements that don't
change.  Then for each time step, we call doStep().  This modifies
the right side as needed (for linear elements) or modifies the
matrix further (for nonlinear elements).  doStep() should also
check to see if we are within convergence limits and set the
converged flag to false if not.
当分析一个电路时，我们为每个CircuitElm调用stamp()来创建矩阵。 这将创建不会改变的电路元素。 然后对于每个时间步长，我们调用doStep()。 这将根据需要修改右侧（对于线性元素）或进一步修改矩阵（对于非线性元素）。doStep()还应该检查我们是否在收敛限制之内，如果没有，则将收敛标志设置为假。

