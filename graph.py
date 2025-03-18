import matplotlib.pyplot as plt
import pandas as pd

# Load CSV data
data = pd.read_csv("sorting_time.csv")

# Plot

plt.plot(data['Array Size'], data['Time'], label="Time Complexity")



plt.xlabel('Array Size')
plt.ylabel('Time')
plt.title('Sort')
plt.legend()
plt.grid(True)
plt.show()

# import pandas as pd
# import numpy as np
# import matplotlib.pyplot as plt

# # Read data from CSV file
# df = pd.read_csv("sorting_time.csv")  # Ensure 'data.csv' is in the same directory

# # Extract x values (input sizes)
# x = df["Array Size"]

# # Compute time complexities
# y_n = x/1000  # O(n)
# y_nlogn = (x * np.log2(x))/10000  # O(n log n)
# y_n2 = (x/1000) ** 2  # O(n²)

# # Plot the functions
# plt.figure(figsize=(8, 5))
# plt.plot(x, y_n,  color='g', label="O(n)")
# plt.plot(x, y_nlogn,   color='b', label="O(n log n)")
# plt.plot(x, y_n2,  color='r', label="O(n²)")
# plt.plot(df['Array Size'], df['Time'], label="Time Complexity")

# # Labels and title
# plt.xlabel("Input Size (n)")
# plt.ylabel("Operations")
# plt.title("Comparison of Time Complexities")
# plt.legend()
# plt.grid()

# # Show the plot
# plt.show()

