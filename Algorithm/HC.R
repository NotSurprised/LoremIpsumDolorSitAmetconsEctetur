HC = function(len,evalF,iter,Nneighbor)
{
  result = data.frame("No" =integer(),"best" = integer(),"mean" = double())
  current_sol = sample(0:1,size = len,replace =T)
  #print(paste("init : ",current_sol))
  current_eval = evalF(current_sol)
  #print(paste("init_eval : ",current_eval))
  result = rbind(result,c(1,current_eval,current_eval/1))
  for(i in 2:iter)
  {
    tempMax = 0
    temp_NewSOL = current_sol
    bc_list = sample(1:len,size=Nneighbor,replace=F)
    for(j in 1:Nneighbor)
    {
      b_change = bc_list[j]
      new_sol = current_sol
      new_sol[b_change] = !new_sol[b_change]
      new_eval = evalF(new_sol)
      if(new_eval >= tempMax)
      {
        temp_NewSOL = new_sol
        tempMax = new_eval
      }
    }
    if(tempMax >= current_eval)
    {
      current_sol = temp_NewSOL
      current_eval = evalF(current_sol)
    }
    result = rbind(result,c(i, current_eval,(sum(result[,2])+current_eval)/i ))
  }
  colnames(result) = c("No","best","mean")
  
  return(result)
}

BinToDec <- function(x) 
  sum(2^(which(rev(unlist(strsplit(as.character(x), "")) == 1))-1))



#Q1----------------------------------------
evalFuncQ1 <- function(x) {
  abs(11 * sum(x) - 150)
}

Q1HC = HC(len = 30,evalF = evalFuncQ1,iter = 300,Nneighbor = 30)
plot(Q1HC$best,type="b")
plot(Q1HC$mean,type="b")

#Q2----------------------------------------

evalFuncQ2 <- function(x)
{
  x1 = BinToDec(x[1:18])/10000  -3
  x2 = BinToDec(x[19:33])/10000 +4.1 
  if(x1 < -3 | x1 > 12.1)
    return(0)
  else if(x2 < 4.1 | x2 > 5.8)
    return(0)
  return(21.5 + x1*sin(4*pi*x1) + x2*sin(20*pi*x2))
}

Q2HC = HC(len = 30,evalF = evalFuncQ2,iter =1000,Nneighbor = 30)

plot(Q2HC$best,type="b")
#plot(Q2HC$mean,type="b")







