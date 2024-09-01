def run_file_methods(file_path: str = 'README.md'):
    file = open(file_path, 'r')             # 'r': read, 'a': append, 'w': write, 'x': create
    file.close()	                        # Closes the file
    file.detach()	                        # Returns the separated raw stream from the buffer
    file.fileno()	                        # Returns a number that represents the stream, from the operating system's perspective
    file.flush()	                        # Flushes the internal buffer
    file.isatty()	                        # Returns whether the file stream is interactive or not
    file.read(size = -1)                    # Returns the file content, size (optional)
    file.readable()	                        # Returns whether the file stream can be read or not
    file.readline(size = -1)	            # Returns one line from the file, size (optional)
    file.readlines(hint = -1)	            # Returns a list of lines from the file, hint (optional)
    file.seek(offset = 0)	                # Change the file position, offset (optional)
    file.seekable()	                        # Returns whether the file allows us to change the file position
    file.tell()	                            # Returns the current file position
    file.truncate(size = -1)	            # Resizes the file to a specified size, size (optional)
    file.writable()	                        # Returns whether the file can be written to or not
    file.write(byte = 'text')	            # Writes the specified string to the file
    file.writelines(list = ['x', 'y'])      # Writes a list of strings to the file