Horners Algorithm is a method to approximate the roots of polynomials described in 1819.
Let's look at the following equation to understand how this method works:

    2x^3 - 6x^2 + 2x -1 @ 3 would return 5 

This polynomial can also be evaluated as ((2x - 6) x + 2) x -1). We initialize our variable value as the first
coefficient, in this case 2. Then we multiply this result with x, the position we are seeking, and add the next 
coefficient. 

So the polynomial equation we used as an example above evalues to 5 as follows:
2*3 + (-6) = 0 
0*3 + 2 = 2
2*3 + (-1) = 5 <-- this is our result 

To run this application:

$application x a b c d . . . . . n 
# x is the value of x in the polynomial equation 
# a,b,c,...,n is the polynomial function 

$application 2 2 0 3 1 
# the polynomial function we are evaluating is 2x^3 + 3x + 1 
# this returns 23 