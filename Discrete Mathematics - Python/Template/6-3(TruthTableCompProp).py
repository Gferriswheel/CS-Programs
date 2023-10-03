# Block 1: prints out the rows of a truth table for a compound which has two variables, p and q
print('p    q    not(p and q) or not p')  # This is a header line that labels the columns
# The loop runs through every possible truth assignment for p and q
for p in (True, False):
    for q in (True, False):
        print(p, q, not(p and q) or not p) 

print('\n') # Put a blank line between tables.

# Block 2: put your code here to print out a truth table for ((not(p) or q) and p).
print('p    q    (not(p) or q) and p')  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
        print(p, q, (not(p) or q) and p) 
        
print('\n') # Put a blank line between tables.
            
# Block 3: put your code here to print out a truth table for (not(p and r) or not(q)).
# Hint: the proposition has 3 variables. You will have to add a loop to create a truth table with 3 variables
print('p    q    r    not(p and r) or not(q)')  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
        for r in (True, False):
            print(p, q, r, (not(p and r) or not(q)))
