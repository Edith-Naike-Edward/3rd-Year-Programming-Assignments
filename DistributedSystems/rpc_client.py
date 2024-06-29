# client.py

import xmlrpc.client

proxy = xmlrpc.client.ServerProxy("http://localhost:8000/RPC2")

# Call the first procedure
result1 = proxy.add_one(5)
print("Result of add_one:", result1)

# Call the second procedure
result2 = proxy.square_and_add(2.5, 3)
print("Result of square_and_add:", result2)

# Call the third procedure
result3 = proxy.reverse_string("hello")
print("Result of reverse_string:", result3)
