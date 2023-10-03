# Initializing functions and sets 
Bin3 = {'000', '001', '010', '011', '100', '101', '110', '111'}
Bin4Odd = {'0001', '0010', '0100', '0111', '1000', '1011', '1101', '1110'} # The number of 1's is odd
Bin4Even = {'0000', '0011', '0101', '0110', '1001', '1010', '1100', '1111'} # The number of 1's is even

def f(input):     # Removes the second bit from the string.
    out = ''
    index = 0
    for c in input:
        if (index != 1):
            out += c
        index += 1
    return(out)
    
def g(input):  # Adds a 0 to the end of the string
    return(input + '0')
    
def h(input):  # Adds a 0 to the end of the string if the number of 1's is even and adds a 1 if the number of 1's is odd
    count = input.count('1')
    if (count % 2 == 0):
        return(input + '0')
    else:
        return(input + '1')
        
# Block 1:
# This function takes as input a function func, a domain set D, and a target set T 
# A boolean value is returned indicating whether the function func has a well defined inverse
#  
# Add one line of code to print out which elements in the target set are mapped to by 0 or more than one domain element.
# To make sure your output matches the test cases use the line:
# print('There are ' + str(count) + ' inputs from the domain that map to ' + y + ' in the target')
def hasInverse(func, D, T):  
    hasInv = True
    for y in sorted(T):  # T is sorted to make sure the output matches. The code should work correctly for any order of T.
        # This loop counts the number of elements from the domain that func maps to y
        count = 0  # count will store the number of domain elements seen so far that map to y. 
        for x in D: 
            if (func(x) == y):
             count = count + 1  # An element is found that reaches this particular y. Increment the count.
        if (count != 1):  # If there are zero or more than one element that maps to y, then the inverse of func does not extist.
            hasInv = False        # the flag hasInv can never be set back to True
            print('There are ' + str(count) + ' inputs from the domain that map to ' + y + ' in the target')
    return(hasInv)
    
# The following lines determine whether functions have a valid inverse for different domains and targets
# If you have written your code correctly in Block 1, these lines should output the correct text
if (hasInverse(f, Bin4Odd, Bin3)):
    print('f: Bin4Odd -> Bin3 has an inverse')
else:
    print('f: Bin4Odd -> Bin3 does not have an inverse')
print(' ')
    
if (hasInverse(f, Bin4Even, Bin3)):
    print('f: Bin4Even -> Bin3 has an inverse')
else:
    print('f: Bin4Even -> Bin3 does not have an inverse')
print(' ')
    
if (hasInverse(g, Bin3, Bin4Even)):
    print('g: Bin3 -> Bin4Even has an inverse')
else:
    print('g: Bin3 -> Bin4Even does not have an inverse')
print(' ')

if (hasInverse(h, Bin3, Bin4Even)):
    print('h: Bin3 -> Bin4Even has an inverse')
else:
    print('h: Bin3 -> Bin4Even does not have an inverse')
print(' ')
    
# Block 2:
# This function should return the correct value for the inverse of func on the given input
def inverse(func, D, T, input):  
    if (hasInverse(func, D, T) == False):
        return('ERROR: The function does not have an inverse')
    if ((input in T) == False):
        return('ERROR: The input is not in the target set')
    # Add your code here to return the correct value for the inverse of func on the given input
    inverse = [x for x in D if func(x) == input]
    return(inverse[0])
    
# The following lines compute the inverse of functions on different inputs
# If you have written your code correctly in Block 2, these lines should output the correct text
print('The inverse of f:Bin4Odd->Bin3 on input 011 is ' +  inverse(f, Bin4Odd, Bin3, '011'))
print(' ')

print('The inverse of f:Bin4Even->Bin3 on input 001 is ' +  inverse(f, Bin4Even, Bin3, '001'))
print(' ')

print('The inverse of h:Bin3->Bin4Even on input 1001 is ' +  inverse(h, Bin3, Bin4Even, '1001'))
    