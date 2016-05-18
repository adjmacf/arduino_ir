import socketserver
import http.server
import os
import time

#setup port and hander
PORT = 8080


message = """
<form action="/" method="POST">
<button type="submit" style="width: 100%; height: 99%; font-size: 80; font-family: sans-serif">pause</button>
</form>
"""


# HTTPRequestHandler class
class testHTTPServer_RequestHandler(http.server.BaseHTTPRequestHandler):
 
  # GET
	def do_GET(self):
		# Send response status code
		self.send_response(200)

		# Send headers
		self.send_header('Content-type','text/html')
		self.end_headers()

		# Send message back to client
		# Write content as utf-8 data
		self.wfile.write(bytes(message, "utf8"))
		return
		
	def do_POST(self):
		# do important stuff
		os.system("xdotool key space")
		self.send_response(200)
		
		# send headers
		self.send_header('Content-type', 'text/html')
		self.end_headers()
		
		#write form again
		self.wfile.write(bytes(str(time.time()) + message, "utf-8"))
		return




httpd = http.server.HTTPServer(("", PORT), testHTTPServer_RequestHandler)

print("Serving on port", PORT)
httpd.serve_forever()
