# Initialize sets A and B
A = { 'a', 'b', 'c', 'd', 'e', 'f' }
B = { 'c', 'd', 'f', 'h', 'j', 'k' }

print('A = ', sorted(A))
print('B = ',sorted(B))
print(' ')
#Block 1: computes and prints out the set A - B

AminusB = set()
for element in A:   # this line runs through every element in A
    if not(element in B): #A - B is the set of elements that are in A and are not in B
        AminusB.add(element) # Add it AminusB every element in A if the element is also not in B
        
print('A - B = ', sorted(AminusB))
print(' ')
        
#Block 2: put your code here to compute B minus A

BminusA = set()
for element in B:   # this line runs through every element in A
    if not(element in A): #A - B is the set of elements that are in A and are not in B
        BminusA.add(element) # Add it AminusB every element in A if the element is also not in B
                
print('B - A = ', sorted(BminusA))
print(' ')

#Block 3: put your code here to compute the symmetric difference of A and B
#Hint: you may need two loops

AsymdiffB = set()
for elementa in A:
    for elementb in B:
        if (not(elementb in A)):
            AsymdiffB.add(elementb)
    if (not(elementa in B)):
        AsymdiffB.add(elementa)

print('Symmetric Difference of A and B = ', sorted(AsymdiffB))
