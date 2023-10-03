# initialize sets Set1, Set2, and Set3
Set1 = {'a', 'b', 'c'}
Set2 = {'*', '+'}
Set3 = {'A', 'B', 'C', 'D'}

#Block 1: lists the elements in the Cartesian Product Set1 x Set2
for x in sorted(Set1):
    for y in sorted(Set2):
        print( '(' + x + ',' + y + ')' )
        
print('\n')

#Block 2: Put your code here to list the elements in the Cartesian Product Set2 x Set1
for y in sorted(Set2):
    for x in sorted(Set1):
        print( '(' + y + ',' + x + ')' )
print('\n')
    
#Block 3: Put your code here to list the elements in the Cartesian Product Set1 x Set2 x Set3
for x in sorted(Set1):
    for y in sorted(Set2):
        for z in sorted(Set3):
            print( '(' + x + ',' + y + ',' + z + ')' )
print('\n')
