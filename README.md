# Algorithms
**A curated collection of elegant algorithms.**

*Here you’ll find cool algorithms that offer fascinating solutions to computational problems, complete with the math behind them, plus pseudocode and code implementations.*

---

## 1. Monte Carlo Integration  

Suppose we want to compute an integral, which don't have a closed form answer. Then we can use a numerical method such as, Monte Carlo simulation which uses random sampling to approximate the value. A major advantage of this method is that the convergence rate does not get worsen exponenstially with increased dimensions.

Here, we looking at the most basic form of Monte Carlo integration with **uniform sampling**, using the two-dimensional space \( \mathbb{R}^2 \). This approach can be easily generalized to higher dimensions.

### Basic Idea  

The key idea is to bound the desired integral (an area in \( \mathbb{R}^2 \)) within a region whose area is easy to compute. 
1. Treat the bounding region as the sample space
2. Sample \( N \) points uniformly within sample space
3. Count the fraction \( r \) of points that fall inside the desired integral's region
4. Compute the desired area/integral using the formula:  
\[
\text{Approximation} = r \cdot (\text{area of bounding region})
\]

By the **law of large numbers**, the computed value converges to the true value as \( N \) increases. The error decreases proportionally to \( \frac{1}{\sqrt{N}} \), which can be derived easily.

### Pseudocode  

BEGIN
    REPEAT
        Generate N random points in the bounding region
        Count the fraction r of points inside the target region
        Compute the integral approximation: r * (area of bounding region)
    UNTIL error is within error bars
    OUTPUT the result
END

### Example

**Approximate \( \pi \) using this method.**  
Hint: Consider the function:  

\[
f(x, y) =
\begin{cases} 
1 & \text{if } x^2 + y^2 \leq r^2, \\ 
0 & \text{otherwise}
\end{cases}
\]

The desired area (of the quarter-circle) is proportional to \( \pi r^2 \). Use a square of side \( 2r \) as the bounding region.  

###### Ans: [In C](./monte_carlo_integration/example.c)

### Further Reading 
[Monte Carlo Integration](https://cs.dartmouth.edu/~wjarosz/publications/dissertation/appendixA.pdf)

---