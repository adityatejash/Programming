import numpy as np
import pandas as pd

x = np.array([2,4,6,8])
y = np.array([8,16,28,32])

m = (y[-1] - y[0]) / (x[-1] - x[0])
c = y[0] - m * x[0]

y_pred = m * x + c

a = y - y_pred          
b = a**2

y_mean = np.mean(y)

c_mean = y - y_mean
d = c_mean**2

# Create DataFrame
df = pd.DataFrame({
    "x": x,
    "y": y,
    "y_pred": y_pred,
    "(y - y_pred)": a,
    "(y - y_pred)^2": b,
    "y - y_mean": c_mean,
    "(y - y_mean)^2": d
})

print(df)

R2 = 1 - (np.sum(b) / np.sum(d))
print(f"R^2 = {R2}")

Adj_R2 = 1 - ( (1-R2) * (len(x) - 1) / (len(x) - 1 - 1))
print(f"Adj_R^2 = {Adj_R2}")


# print(np.sum(b), np.sum(d))