
try:
    n = 20
    control = 0
    percent = round(n*100/control,1)
    print("You've gone through",percent,"% of your life")
except ValueError:
    print("You must number")
except ZeroDivisionError:
    print("Division by zero")
except:
    print("Errror")