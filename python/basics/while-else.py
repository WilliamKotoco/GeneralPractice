string = "HaruZeroDoisW"
i = 0

while (i < len(string)):
    if (string[i].isdigit()):
        break
    print(string[i])
    i+=1
else: # executes when the loop runs entirely 
    print("Nao tinha numero no nome")


