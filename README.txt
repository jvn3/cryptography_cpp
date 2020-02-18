This program is built on this following criteria- 

-r = perform rot13 substitution.
-g = generate a random caesar cipher dictionary
-e = encrypt using the caesar cipher
-d = decrypt using the caesar cipher

For -r, there is an optional second argument. If provided, it is the name of the file to read from. If it is not provided, the program reads from standard input. The output is be generated to the standard output.

For -g, the dictionary is printed to the standard output. Each plaintext letter maps to a unique ciphertext letter, and that no letter maps to itself.

For both -e and -d there is a required second argument, which is the filename of the dictionary. If the second argument is missing, it prints the message NO DICTIONARY GIVEN, and stop. If the dictionary cannot open for any reason, the program prints the filename followed by a space and DICTIONARY COULD NOT BE OPENED, then stop. If the program finds a case where the dictionary does not contain a two-letter pair, it prints FORMATTING ERROR followed by a space and the entry that you read, and stop. If it finds a case where a ciphertext is duplicated, the program prints DUPLICATE CIPHERTEXT L, where L is the duplicated letter, and stop.  If it finds a plaintext that maps to the same letter in ciphertext, the program prints MAPPING ERROR L, where L is the plaintext letter, and stop. If it finds a case where the dictionary is not in alphabetical order, the program prints MISSING LETTER L, where L is the missing letter, and stop.

Both -e and -d support an optional third argument, which is the file to read from. If it is not provided, the program reads from standard input. The output is generated to the standard output. If a filename is provided but the file cannot open for any reason, the program prints the filename followed by a space and FILE COULD NOT BE OPENED, then stop.
