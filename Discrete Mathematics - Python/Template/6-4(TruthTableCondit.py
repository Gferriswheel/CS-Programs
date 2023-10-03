# Block 1
# Given truth values for p and q, the function returns the truth value for p -> q
# p is the hypothesis and q is the conclusion
def implies(p, q):
    if (p and q):
        return True
    if (p and not q): # The conditional operation is false if and only if the hypothesis is true and the conclusion is false
        return False
    if (not p and q):
        return True  
    if (not p and not q):
        return True  
        
# Block 2
# Block 2 prints the rows of a truth table for (p -> q) which has two variables, p and q
print("p    q    p -> q")  # This is a header line that labels the columns
# The loop runs through every possible truth assignment for p and q
for p in (True, False):
    for q in (True, False):
        print(p, q, implies(p, q)) 
        
print(" ") # Put a blank line between tables.

# Block 3
# Block 3 prints the truth table for (not(p) -> q)
print("p    q    not(p) -> q")  # This is a header line that labels the columns
# The loop runs through every possible truth assignment for p and q
for p in (True, False):
    for q in (True, False):
        print(p, q, implies(not(p),q)) 

print(" ") # Put a blank line between tables.

# Block 4
# Put your code here to print the truth table for (p -> not(q))
print("p    q    p -> not(q)")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
        print(p, q, implies(p,not(q))) 
print(" ") # Put a blank line between tables.

# Block 5
# Put your code here to print the truth table for not(p -> q)
# Hint: think carefully about the order that the operations are applied in not(p -> q)
# Make sure your Python expression applies the operations in the same order.
print("p    q    not(p -> q)")  # This is a header line that labels the columns
# 
for p in (True, False):
    for q in (True, False):
        print(p, q, not(implies(p,q)))
print(" ") # Put a blank line between tables.

# Block 6
# Put your code here to print the truth table for (p -> not(r)) or not(q)
print("p    q     r    (p -> not(r)) or not(q)")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
        for r in (True, False):
            print(p, q, r, implies(p, not(r)) or not(q))
