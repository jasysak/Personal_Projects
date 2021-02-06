# Super basic anagram test using ord()
# not particularly well coded, but it does work
string1 = "happy"
string2 = "yppah"
sum1 = sum2 = 0
for x in string1:
    sum1 = sum1 + ord(x)
for y in string2:
    sum2 = sum2 + ord(y)
if sum1 == sum2:
    print("YES")
else:
    print("NO")
