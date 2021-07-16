import numpy as np

weights = [
    np.random.uniform(-0.5, 0.5, (10, 5)),
    np.random.uniform(-0.5, 0.5, (5, 10))
]

bias = [
    np.zeros((10, 1)),
    np.zeros((5, 1))
]

rate = 0.01 
epochs = 5

for Epoch in range(1, epochs + 1):
    highest = 0
    print(f"{Epoch=}")

    # TODO
