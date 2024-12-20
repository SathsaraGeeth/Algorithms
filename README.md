# Algorithms
**A curated collection of elegant algorithms.**

*Here you’ll find cool algorithms that offer fascinating solutions to computational problems, complete with the math behind them, plus pseudocode and code implementations.*

---

## 1. Monte Carlo Integration  

Suppose we want to compute an integral, which doesn't have a closed-form answer. Then we can use a numerical method such as Monte Carlo simulation, which uses random sampling to approximate the value. A major advantage of this method is that the convergence rate does not worsen exponentially with increased dimensions.

Here, we are looking at the most basic form of Monte Carlo integration with **uniform sampling**, using the two-dimensional space <code>&#x211D;<sup>2</sup></code>. This approach can be easily generalized to higher dimensions.

### Basic Idea  

The key idea is to bound the desired integral (an area in <code>&#x211D;<sup>2</sup></code>) within a region whose area is easy to compute. 
1. Treat the bounding region as the sample space  
2. Sample <code>N</code> points uniformly within the sample space  
3. Count the fraction <code>r</code> of points that fall inside the desired integral's region  
4. Compute the desired area/integral using the formula:  
   <br><code>Approximation = r * (area of bounding region)</code>

By the **law of large numbers**, the computed value converges to the true value as <code>N</code> increases. The error decreases proportionally to <code>1 / sqrt(N)</code>, which can be derived easily.

### Pseudocode  

1. **BEGIN**
2. **REPEAT**
3. Generate N random points in the bounding region
4. Count the fraction \( r \) of points inside the target region
5. Compute the integral approximation: \( r \times \text{(area of bounding region)} \)
6. **UNTIL** error is within error bars
7. **OUTPUT** the result
8. **END**

### Example  

**Approximate <code>&#x3C0;</code> using this method.**  
Hint: Consider the function:  

<pre>
f(x, y) =
    1, if x<sup>2</sup> + y<sup>2</sup> ≤ r<sup>2</sup>
    0, otherwise
</pre>

The desired area (of the quarter-circle) is proportional to <code>&#x3C0; r<sup>2</sup></code>. Use a square of side <code>2r</code> as the bounding region.  

###### Ans: [In C](./monte_carlo_integration/example.c)

### Further Reading  
[Monte Carlo Integration](https://cs.dartmouth.edu/~wjarosz/publications/dissertation/appendixA.pdf)

---
