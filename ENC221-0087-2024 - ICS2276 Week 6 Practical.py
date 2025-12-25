import random

# Create an array of 20 random integers between 1 - 100
original_array = [random.randint(1, 100) for _ in range(20)]

# Initialize two empty arrays for sorting
even_values = []
odd_values = []

# Loop through the original array and sort the numbers
for num in original_array:
    if num % 2 == 0:
        even_values.append(num)
    else:
        odd_values.append(num)

# Display results
print("Original Array:", original_array)
print("-" * 30)
print(f"Even Array ({len(even_values)} items):", even_values)
print(f"Odd Array  ({len(odd_values)} items):", odd_values)