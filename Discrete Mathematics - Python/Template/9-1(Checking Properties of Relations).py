import math

# Initializing relations and domains
D1 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21}
D2 = {1.1, 2.3, 4.1, 4.7, 5.2, 6.4, 7.7, 10.1, 13.4}

def f(x, y):  
    return (y/x == y//x) # a//b returns the floor of a divided by b
    
def g(x, y):  
    if (x > y):
        x, y = y, x
    for z in range(x, y+1):
        if ((y/z == y//z) and (x/z == x//z) and (z != 1)):
            return(False)
    return (True)
    
def h(x, y):  
    return (math.floor(x) <= math.floor(y)) 
    
def r(x, y):
    R = [[9,7],[9,5],[9,3],[9,1],[7,5],[7,3],[7,1],[5,3],[3,1]]
    return([x,y] in R)
    

    
# Block 1: Tests whether relation f on domain D1 is reflexive
# Assume that f on domain D1 is reflexive until proven otherwise
fIsReflexive = True
for x in D1:
    if (f(x, x) == False):
        fIsReflexive = False  # An x in the domain is found where f(x, x) is not in the relation
                              # The flag fIsReflexive can never be set back to true.
        print('The element ' + str(x) + ' is not related to itself under f')

if (fIsReflexive):
    print('The relation f on domain D1 is reflexive.')
else:
    print('The relation f on domain D1 is not reflexive.')
print(' ')
    
# Block 2: Tests whether relation g on domain D1 is anti-reflexive
# Assume that g on domain D1 is reflexive until proven otherwise
# Use the following line if an element is reached showing that g is not anit-reflexive on D1:
# print('The element ' + str(x) + ' is related to itself under g')
gIsAntiReflexive = True
# Put your code here to test if g on domain D1 is anti-reflexive
for x in D1:
    if (f(x, x) == True):
        gIsAntiReflexive = False  # An x in the domain is found where f(x, x) is not in the relation
                              # The flag fIsReflexive can never be set back to true.
        print('The element ' + str(x) + ' is related to itself under g')
        break


if (gIsAntiReflexive):
    print('The relation g on domain D1 is anti-reflexive.')
else:
    print('The relation g on domain D1 is not anti-reflexive.')
print(' ')

# Block 3: Tests whether relation g on domain D1 is symmetric
# Run the code and observe the output. You do not need to add any code in Block 3
# Assume that g on domain D1 is symmetric until proven otherwise
gIsSymmetric = True
for x in D1:
    for y in D1:
        if (x <= y): # We only need to check each pair once, so we will check only when x <= y
            if ((g(x,y)==True and g(y,x)==False) or (g(x,y)==False and g(y,x)==True)):
                gIsSymmetric = False  # An x, y in the domain is found where g(x,y) and g(y,x) are not the same
                                    # The flag gIsAntiReflexive can never be set back to true.
                print('The pair (' + str(x) + ',' + str(y) + ') shows that g is not symmetric')


if (gIsSymmetric):
    print('The relation g on domain D1 is symmetric.')
else:
    print('The relation g on domain D1 is not symmetric.')
print(' ')

# Block 4: Tests whether relation h on domain D2 is anti-symmetric
# Assume that h on domain D2 is symmetric until proven otherwise
# Use the following line if a pair is reached showing that h is not anit-symmetric on domain D2:
# print('The pair (' + str(x) + ',' + str(y) + ') shows that h is not anti-symmetric')
hIsAntiSymmetric = True
# Put your code here to test if h on domain D2 is anti-symmetric
for x in D2:
    for y in D2:
        if (x <= y): # We only need to check each pair once, so we will check only when x <= y
            if (h(x,y) and h(y,x) and x != y):
                hIsAntiSymmetric = False  
                print('The pair (' + str(x) + ',' + str(y) + ') shows that h is not anti-symmetric')
                break
    if not hIsAntiSymmetric:
        break    

if (hIsAntiSymmetric):
    print('The relation h on domain D2 is anti-symmetric.')
else:
    print('The relation h on domain D2 is not anti-symmetric.')
print(' ')

# Block 5: Tests whether relation f on domain D1 is transitive
# Assume that f on domain D1 is transitive until proven otherwise
# Note that each triple (x,y,z) must be tested in every possible order 
# Use the following line if a triple is reached showing that f is not transitive on domain D1:
# print('The triple (' + str(x) + ',' + str(y) + ',' + str(z) + ') shows that f is not transitive')
fIsTransitive = True
# Put your code here to test if f on domain D1 is transitive
for x in D1:
    for y in D1:
        for z in D1:
            if (f(x,y) and f(y,z) and not f(x,z)):
                fIsTransitive = False
                print('The triple (' + str(x) + ',' + str(y) + ',' + str(z) + ') shows that f is not transitive')
                break
        if not fIsTransitive:
            break    


if (fIsTransitive):
    print('The relation f on domain D1 is transitive.')
else:
    print('The relation f on domain D1 is not transitive.')
print(' ')

# Block 6: Tests whether relation r on domain D1 is transitive
# Assume that r on domain D1 is transitive until proven otherwise
# Note that each triple (x,y,z) must be tested in every possible order 
# Use the following line if a triple is reached showing that r is not transitive on domain D1:
# print('The triple (' + str(x) + ',' + str(y) + ',' + str(z) + ') shows that r is not transitive')
rIsTransitive = True
# Put your code here to test if r on domain D1 is transitive
for x in D1:
    for y in D1:
        for z in D1:
            if (r(x,y) and r(y,z) and not r(x,z)):
                rIsTransitive = False
                print('The triple (' + str(x) + ',' + str(y) + ',' + str(z) + ') shows that r is not transitive')
                break
        if not fIsTransitive:
            break    

                
if (rIsTransitive):
    print('The relation r on domain D1 is transitive.')
else:
    print('The relation r on domain D1 is not transitive.')
print(' ')

