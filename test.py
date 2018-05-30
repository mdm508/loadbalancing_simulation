from random import randint
L = [randint(2,6) for i in range(4)]
print(L)
s = False
count = 1
while s != 'q':
    print("Round " + str(count))
    for i in range(len(L)):
        if count % L[i] == 0:
            print(i+1)
    s = input("q to quit")
    print()
    count += 1

        