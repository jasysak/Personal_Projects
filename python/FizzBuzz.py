# The 'seminal' FizzBuzz problem
# from -50 to 100...in python. 
# Almost too easy...it works!
printed = 0
i = -50
while i <=100: 
    if (i % 3 == 0) and (i % 5 ==0): 
        print("FizzBuzz")
        printed = 1
    if (i % 3 == 0) and (printed <> 1):
        print("Fizz")
    if (i % 5 == 0) and (printed <> 1):
        print("Buzz")
    else:
        print (i)
    i += 1
# eof
