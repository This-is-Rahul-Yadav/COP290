README:
Upon execution, the program will wait for the user to type one of 11 possible commands below and display the appropriate result on the screen itself.
After displaying the result the program awaits the next instruction. In this way many commands can be run before the program stops.
To end the program the quit command must be called. In case the command keyword (the first word) is entered incorrectly or incase the number of parameters
passed is incorrect an error message pop up and the syntax for all commands is diplayed. The following commands are available:

convolution_withoutpadding input_matrix.txt input_matrix_numrows kernel_matrix.txt kernel_matrix_numrows

convolution_withpadding padsize input_matrix.txt input_matrix_numrows kernel_matrix.txt kernel_matrix_numrows

convolution_withoutpadding_matrixmul input_matrix.txt input_matrix_numrows kernel_matrix.txt kernel_matrix_numrows

convolution_withpadding_matrixmul padsize input_matrix.txt input_matrix_numrows kernel_matrix.txt kernel_matrix_numrows

relu input_matrix.txt input_matrix_numrows

tanh input_matrix.txt input_matrix_numrows

average_pooling input_matrix.txt input_matrix_numrows size

max_pooling input_matrix.txt input_matrix_numrows size

sigmoid input_vector.txt input_vector_size

softmax input_vector.txt input_vector_size

quit
