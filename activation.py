import numpy as np

def sigmoid(x: float):
    return 1/(1 + np.exp(x))

def tanh(x: float):
    return np.tanh(x)

def step(x: float):
    return 1 if x > 0 else 0
