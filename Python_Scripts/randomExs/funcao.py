def funcao(x:float)->float:
    if x <= 1:
        return 1
    elif x <=5:
        return x
    elif x <= 10:
        return x**2
    return x**3

def main():
    inputs = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100]
    outputs = [funcao(x) for x in inputs]
    for i in range(len(inputs)):
        print(f"f({inputs[i]}) = {outputs[i]}", end=", ")

main()