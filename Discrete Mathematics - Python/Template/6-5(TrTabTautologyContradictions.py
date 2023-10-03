# Block 1
# Prints out the rows of a truth table for "not((p and q) or not p)" which has two variables, p and q
# An extra message is printed for every truth assignment that makes "not((p and q) or not p)" True.
print("p    q    not((p and q) or not p)")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
            print( p, q, not((p and q) or not p), end = '' ) # end = '' supresses the newline
            if ((not((p and q) or not p)) == True):
                print("  <-- True. Therefore, not a contradiction.", end = '') # Extra message
            print(" ") # put a newline to start a new row of the truth table
        

print(" ") # Put a blank line between outputs.

# Block 2
# Prints out the rows of a truth table for "not((p and q) or not p)" which has two variables, p and q
# An extra message is printed for every truth assignment that makes "not((p and q) or not p)" True.
print("p    q    not(p or q) and q")  # This is a header line that labels the columns
for p in (True, False):
    for q in (True, False):
            print(p, q, not(p or q) and q, end = '' ) 
            if ((not(p or q) and q) == True):
                print("  <-- True. Therefore, not a contradiction.", end = '' )  # Extra message
            print(" ")
                
print(" ") # Put a blank line between outputs.            

# Block 3
# Put your code here that prints out the truth table for "not(q and not p) or p"
# Print an extra message for every truth assignment found showing that "not(q and not p) or p" is not a tautology.
print("p    q    not(q and not p) or p")
for p in (True, False):
    for q in (True, False):
        print(p, q, not(q and not p) or p, end = '' ) 
        if ((not(q and not p) or p) == False):
                print("  <-- False. Therefore, not a tautology.", end = '' )  # Extra message
        print(" ")
                
print(" ") # Put a blank line between outputs.

# Block 4
# Put your code here that prints out the truth table for "not(q and p) or p"
# Print an extra message for every truth assignment found showing that "not(q and p) or p" is not a tautology.
print("p    q    not(q and p) or p")
for p in (True, False):
    for q in (True, False):
        print(p, q, not(q and p) or p, end = '' ) 
        if ((not(q and p) or p) == False):
            print("  <-- False. Therefore, not a tautology.", end = '' )  # Extra message
        print(" ")
                
