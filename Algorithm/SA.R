library(GenSA)

Q1 = function(x) {
  -abs(11 * round(x) - 150)
}

lowerQ1 <- 0
upperQ1 <- 30

Q1SA <- GenSA(par = 1,lower = lowerQ1, upper = upperQ1, fn = Q1,
            control=list(verbose=TRUE))

plot(-Q1SA$trace.mat[,"function.value"],type="b")
Q1SA[c("value","par","counts")]
bestQ1 = Q1SA$trace.mat[,"current.minimum"]
plot(-bestQ1,type="b")

#----------------------------

Q2<- function(x,y) {
  -(21.5 + x*sin(4*pi*x) + y*sin(20*pi*y))
}


set.seed(5487) 

paramsQ2 = c(7,4.2)
fnQ2 = function(params) Rastrigin(params[1],params[2])
lowerQ2 <- c(-3, 4.1)
upperQ2 <- c(12.1,5.8)
outQ2 <- GenSA(par =paramsQ2,lower = lowerQ2, upper = upperQ2, fn = fnQ2,
             control=list(verbose=TRUE))
plot(outQ2$trace.mat[,"function.value"],type="b")
outQ2[c("value","par","counts")]

bestQ2 = outQ2$trace.mat[,"current.minimum"]
plot(bestQ2,type="b")
