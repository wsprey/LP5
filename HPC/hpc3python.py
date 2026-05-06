import numpy as np

# User input in one line
arr = list(map(int, input("Enter elements: ").split()))

# Convert list to numpy array
arr = np.array(arr)

# Operations
minimum = np.min(arr)
maximum = np.max(arr)
total = np.sum(arr)
average = np.mean(arr)

# Display Results
print("\nArray :", arr)
print("Minimum :", minimum)
print("Maximum :", maximum)
print("Sum :", total)
print("Average :", average)
