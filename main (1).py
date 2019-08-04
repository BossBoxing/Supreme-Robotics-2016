#Lab 2_3 ข้อ 3
x = int(input("Enter your money amount: "))
count_1000 = 0
count_500x = 0
count_100x = 0
count_50x = 0
count_20x = 0
count_10x = 0
count_5x = 0
count_2x = 0
count_1x = 0

print("Processing...")

count_1000 = int(x / 1000)
x = x - (1000*count_1000)
count_500 = int(x / 500)
x = x - (500*count_500)
count_100 = int(x / 100)
x = x - (100*count_100)
count_50 = int(x / 50)
x = x - (50*count_50)
count_20 = int(x / 20)
x = x - (20*count_20)
count_10 = int(x / 10)
x = x - (10*count_10)
count_5 = int(x / 5)
x = x - (5*count_5)
count_2 = int(x / 2)
x = x - (2*count_2)
count_1 = int(x / 1)
x = x - (1*count_10)


print("You will receive: ")
print("1000 x ",count_1000)
print("500 x ",count_500)
print("100 x ",count_100)
print("50 x ",count_50)
print("20 x ",count_20)
print("10 x ",count_10)
print("5 x ",count_5)
print("2 x ",count_2)
print("1 x ",count_1)



