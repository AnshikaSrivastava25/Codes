# define the function needed: add, sub, mul, div
# print option to the user
# ask for values
# call the functions
# while loop to continue the program until the user wants to exit

def add(a, b):
    answer = a + b
    print(str(a) + " + " + str(b) + " = " + str(answer) + "\n")
    
def sub(a, b):
    answer = a - b
    print(str(a) + " - " + str(b) + " = " + str(answer)+ "\n")
    
def mul(a, b):
    answer = a * b
    print(str(a) + " * " + str(b) + " = " + str(answer)+ "\n")
    
def div(a, b):
    answer = a / b
    print(str(a) + " / " + str(b) + " = " + str(answer)+ "\n")
    
while True:    
    print("1. Addition")
    print("2. subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        print("Addition")
        a = int(input("input first number:"))
        b = int(input("input second number:"))
        add(a, b)
        
    elif choice =="2":
        print("Subtraction")
        a = int(input("input first number:"))
        b = int(input("input second number:"))
        sub(a, b)
        
    elif choice =="3":
        print("muliplication")
        a = int(input("input first number:"))
        b = int(input("input second number:"))
        mul(a, b)       
            
    elif choice =="4":
        print("division")
        a = int(input("input first number:"))
        b = int(input("input second number:"))
        div(a, b)   
        
    elif choice =="5":
        print("Prgram ended")
        quit()   