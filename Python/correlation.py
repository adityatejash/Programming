import numpy as np
import pandas as pd

x = np.array([-6, 2, 0.2, 7, -4])
y = np.array([6.4, 4.7, 8, 2, 3.4])

a = x - np.mean(x)
b = a**2

c = y - np.mean(y)
d = c**2

df = pd.DataFrame({
    "x" : x,
    "y" : y,
    "x - x_mean" : a,
    "(x - x_mean)^2" : b,
    "y - y_mean" : c,
    "(y - y_mean)^2" : d,
})

print(df.round(2))
print(f"x_mean = {np.mean(x).round(2)}")
print(f"y_mean = {np.mean(y).round(2)}")

numerator = np.sum(a * c)
denominator = np.sqrt(np.sum(b) * np.sum(d))

correlation = numerator / denominator
print(f"Correlation (r) = {correlation}")