# server.py

from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

def add_one(x):
    return x + 1

def square_and_add(x, y):
    return x ** 2 + y

def reverse_string(s):
    return s[::-1]

server = SimpleXMLRPCServer(('localhost', 8000),
                            requestHandler=RequestHandler)
server.register_introspection_functions()

server.register_function(add_one, 'add_one')
server.register_function(square_and_add, 'square_and_add')
server.register_function(reverse_string, 'reverse_string')

print("Server is ready to accept requests...")
server.serve_forever()
