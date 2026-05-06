# User Input
data = list(map(int, input("Enter data points: ").split()))

k = int(input("Enter number of clusters: "))

# Create empty clusters
clusters = [[] for _ in range(k)]

# Simple Parallel Style Clustering
for i in range(len(data)):
    clusters[i % k].append(data[i])

# Display Clusters
print("\nClusters:")

for i in range(k):
    print("Cluster", i + 1, ":", clusters[i])