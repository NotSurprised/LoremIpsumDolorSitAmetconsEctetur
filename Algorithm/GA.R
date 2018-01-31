library("GA")

#Q1-----------------------------
evalFunc <- function(x) {
  current_solution_weight <- abs(11 * sum(x) - 150)
    return(-current_solution_weight)
}

GAmodel <- rbga.bin(size = 30, popSize = 100, iters = 100, mutationChance = 0.01, 
                    evalFunc = evalFunc)
cat(summary(GAmodel))
plot(GAmodel)

plot(GAmodel$best,type="b")


#Q2-------------------------------------------

Rastrigin <- function(x, y)
{
  -(21.5 + x*sin(4*pi*x) + y*sin(20*pi*y))
}
x <- seq(-3,12,0.1)
y <- seq(4.1,5.8,0.1)
f <- outer(x, y, Rastrigin)

GA <- ga(type = "real-valued", fitness = function(x) -Rastrigin(x[1], x[2]),
         min = c(-3, 4.1), max = c(12,5.8),
         popSize = 50, maxiter = 500)
GAAnsQ2 = summary(GA)
GAAnsQ2$solution
GAAnsQ2$fitness
plot(GA)





