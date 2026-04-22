arr = []
print("Enter 5 numbers:")
for i in range(5):
    num = int(input())
    arr.append(num)
smallest = arr[0]
for i in arr:
    if i < smallest:
        smallest = i
print("Smallest number =", smallest)
