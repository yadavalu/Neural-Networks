import numpy as np

def neuron(input: list, weight: list, bias: list, activation):
    return activation(sum(
        i[0] * i[1] + i[2] for i in zip(input, weight, bias)
    ))
