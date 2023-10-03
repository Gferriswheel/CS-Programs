# Block 1: Comditional Operation
# Given truth values for p and q, the function returns the truth value for p -> q
# p is the hypothesis and q is the conclusion
def implies(p, q):
    if (p and q):
        return True
    if (p and not q): # The conditional operation is false if only if the hypothesis is true and the conclusion is false
        return False
    if (not p and q):
        return True  
    if (not p and not q):
        return True  
        
# Block 2
# Prints out the rows of a truth table for "not(p -> q)" and "p or not(q)"
# A message is printed for every truth assignment that makes the two propositions have different truth values.
print("p    q    not(p -> q) (p or not(q))")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
            print( p, q, "   ", not(implies(p, q)), "      ", p or not(q), end = '' )   # some white space added to line up columns
            if ( (not(implies(p, q))) != (p or not(q)) ):
                print("  <-- Different truth values. Therefore, not logically equivalent.", end = '') 
            print(" ")
        

print(" ") # Put a blank line between outputs.

# Block 3
# Prints out the rows of a truth table for "not(p -> q)" and "p and not(q)"
# A message is printed for every truth assignment that makes the two propositions have different truth values.
print("p    q    not(p -> q) (p and not(q))")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
            print( p, q, "   ", not(implies(p, q)), "      ", p and not(q), end = '' )   # some white space added to line up columns 
            if ( (not(implies(p, q))) != (p and not(q)) ):
                print("  <-- Different truth values. Therefore, not logically equivalent.", end = '') 
            print(" ")
        

print(" ") # Put a blank line between outputs.

# Block 4
# Put your code here to print out the rows of a truth table for "(p or q) -> r" and "(p -> r) and (q -> r)"
# A message should be printed for every truth assignment that makes the two propositions have different truth values.
print("p    q    r    ((p or q) -> r)   ((p -> r) and (q -> r))")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
        for r in (True, False):
            print( p, q, r, "   ", implies(p or q, r), "      ", implies(p, r) and implies(q, r), end = '' )   # some white space added to line up columns 
            if ( (implies(p or q, r)) != (implies(p, r) and implies(q, r)) ):
                print("  <-- Different truth values. Therefore, not logically equivalent.", end = '') 
            print(" ")
print(" ") # Put a blank line between outputs.

# Block 5
# Put your code here to print out the rows of a truth table for "(p and q) -> r" and "(p -> r) and (q -> r)"
# A message should be  printed for every truth assignment that makes the two propositions have different truth values.
print("p    q    r    ((p and q) -> r)   ((p -> r) and (q -> r))")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
        for r in (True, False):
            print( p, q, r, "   ", implies(p and q, r), "      ", implies(p, r) and implies(q, r), end = '')   # some white space added to line up columns 
            if ( (implies(p and q, r)) != (implies(p, r) and implies(q, r)) ):
                print("  <-- Different truth values. Therefore, not logically equivalent.", end = '') 
            print(" ")
