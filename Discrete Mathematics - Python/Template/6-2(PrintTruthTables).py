# Block 1: prints out the rows of a truth table for two variables p and q

print('p    q')  # This is a header line that labels the columns
# The loop runs through every possible truth assignment for p and q
for p in (True, False):
    for q in (True, False):
        print(p, q) 

print('\n') # Put a blank line between tables.

# Block 2: prints out the rows of a truth table for three variables p, q, and r

print('p    q     r')  # This is a header line that labels the columns
# The loop runs through every possible truth assignment for p, q, and r
for p in (True, False):
    for q in (True, False):
        for r in (True, False):
            print(p, q, r) 
            
print('\n') # Put a blank line between tables.
            
# Block 3 put your code here for a truth table with four variables
print('p    q     r     w')  # This is a header line that labels the columns
# The loop runs through every possible truth assignment for p, q, and r
for p in (True, False):
    for q in (True, False):
        for r in (True, False):
            for w in (True, False):
                print(p, q, r, w) 
