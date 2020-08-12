import cs50

# Input integer between 1 and 8 (inclusive)
while True:
    x = cs50.get_int("Height: ",)
    if x >= 1 and x <= 8:
        break

# Main print function


def main():
    for i in range(x):
        for j in range(x - 1 - i):
            printSpace()
        for k in range(i + 1):
            printHash()
        print(" " * 2, end="")
        for l in range(i + 1):
            printHash()
        print("")

# Print space


def printSpace():
    print(" ", end="")

# Print hash


def printHash():
    print("#", end="")


if __name__ == "__main__":
    main()
