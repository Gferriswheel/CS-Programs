# Initializing functions and sets
D1 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23}
D2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
T1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13}
T2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13}

def f(input):  
    return (input - 1)//2 # a//b returns the floor of a divided by b
    
# Block 1: Tests whether f: D1 -> T1 is a valid function
fIsValid = True  # Assume that f: D1 -> T1 is valid until proven otherwise
for x in D1:
    if ((f(x) in T1) == False):
        fIsValid = False  # If an x in the domain is found where f(x) is not in the target, then f is not valid.
                          # The flag fIsValid can never be set back to true.
if (fIsValid):
    print('The function f: D1 -> T1 is valid.')
else:
    print('The function f: D1 -> T1 is not valid.')
print(' ')
    
# Block 2: Give a block of code that tests whether f: D1 -> T2 is a valid function
fIsValid = True  # Assume that f: D1 -> T1 is valid until proven otherwise
for x in D1:
    if ((f(x) in T2) == False):
        fIsValid = False  # If an x in the domain is found where f(x) is not in the target, then f is not valid.
                          # The flag fIsValid can never be set back to true.
if (fIsValid):
    print('The function f: D1 -> T2 is valid.')
else:
    print('The function f: D1 -> T2 is not valid.')
print(' ')
    
#Block 3: Tests whether f: D1 -> T1 is one-to-one.
fIsOneToOne = True #Assume f: D1 -> T1 is one-to-one until proven otherwise

for x1 in D1:
    for x2 in D1:  # These two nested loops check every pair of elements from the domain
        if ( (x1 != x2) and (f(x1) == f(x2)) ): # If f maps two distinct elements to the same output, then f is not one-to-one
            fIsOneToOne = False               # The flag fIsOneToOne can never be set back to True
        
if (fIsOneToOne):
    print('The function f: D1 -> T1 is one-to-one.')
else:
    print('The function f: D1 -> T1 is not one-to-one.')
print(' ')
    
#Block 4: Add your code here to test if the function f: D2 -> T1 is one-to-one
fIsOneToOne = True #Assume f: D2 -> T1 is one-to-one until proven otherwise
for x1 in D2:
    for x2 in D2:  # These two nested loops check every pair of elements from the domain
        if ( (x1 != x2) and (f(x1) == f(x2)) ): # If f maps two distinct elements to the same output, then f is not one-to-one
            fIsOneToOne = False               # The flag fIsOneToOne can never be set back to True
        
if (fIsOneToOne):
    print('The function f: D2 -> T1 is one-to-one.')
else:
    print('The function f: D2 -> T1 is not one-to-one.')
print(' ')

    
#Block 5: Tests whether f: D1 -> T1 is onto.
#Add a line of code that outputs every y in the target that is not reached by f from an element in the domain.
#Use this line to make sure your output matches the test cases: print('The element ' + str(y) + ' in the target is not reached.')

fIsOnto = True  #Assume f is onto until proven otherwise.

for y in T1:  #This loop checks whether each y in the target is reached by an element in the domain.
    yIsReached = False  #Start by assuming that element y is not reached
    for x in D1:
        if (f(x) == y):
            yIsReached = True  #An element is found that reaches this particular y.
    if (yIsReached == False):  #If no element in D reaches y, then y is not reached..
        print("The element ", y , "in the target is not reached.")
        fIsOnto = False        #the flag fIsOnto can never be set back to True
        
if (fIsOnto):
    print('The function f is onto.')
else:
    print('The function f is not onto.')
    
