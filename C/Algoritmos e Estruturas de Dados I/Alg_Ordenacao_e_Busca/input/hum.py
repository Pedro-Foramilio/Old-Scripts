f = open("OrdenaNumeros7.txt", "w")
f.write("1000\n")
for i in range(1000, 0, -1):
    f.write(str(i)+"\n")
f.close()