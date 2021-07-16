import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_dash(x):
    return x * (1 - x)

def error_cost(exp, got, _in):
    err = exp - got
    adj = err * sigmoid_dash(got)

    return np.dot(_in.T, adj)

def mean_error_function(output, real):
    return 1/len(output) * np.sum((output - real) ** 2, axis=0)
