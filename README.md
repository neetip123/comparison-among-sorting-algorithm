# comparison-among-sorting-algorithm
Comparison of various sorting algorithms will be done based on • the number of comparisons that it makes • execution time
# Task
Initially, you need to implement some of the sorting algorithms. Those are mentioned in the subsequent part. These
algorithms need to be run on various input sizes. For each input size, the data needs to be generated randomly. On the
same input data, all the algorithms must be run a fixed number of times. For all these different runs on the same input
data, the number of comparisons and execution time need to be recorded. The average of these will have to be used for
comparison purpose. For better visualization, the average number of comparisons and execution times will have to be
plotted using gnuplot tool.
One will use the following command in a linux shell to analyze the performance of various sorting techniques

$ ./testsort -i <min_size> -x <max_size> -s <step_size> -a <avg> -t [bubble merge heap
quickR quickM quick3M] -o <out_filename> -g <plot_script_file_name>
