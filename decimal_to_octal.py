num = int(input("Enter a decimal number: "))
if num == 0:
    print("Octal = 0")
else:
    octal = ""
    while num > 0:
        octal = str(num % 8) + octal
        num //= 8
    print("Octal =", octal)
