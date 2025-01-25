# MNIST Neural Network
The MNIST database is a large database of handwritten digits that is commonly used for training various image processing systems. The database is also widely used for training and testing in the field of machine learning. 

![First](https://upload.wikimedia.org/wikipedia/commons/b/b1/MNIST_dataset_example.png)

Neural Network is an algorithm that is trained to solve complex nonlinear problem X->Y. In our case, X is an image (an array of pixels) and Y is 
image label (number 0-9). The algorithm works as multiple functions tied together. More about the functions in `task.pdf`

![Second](https://i.imgur.com/SILb1bP.png)

### Modes for output
1. A list of weights for the selected neuron.
2. Weighted sum listing for selected Neuron and loaded picture.
3. Listing the value of the ReLU activation function for the selected input value.
4. Listing the calculated values of the Softmax function.
5. Index listing of the largest element in the array (Findmax).
6. Listing the loaded image of the digit.
7. Listing the classification result of the loaded digit image.
More on how to setup gcc and on how to get results from individual categories in the `task.pdf`

There is also bonus Python script I used for generating text files from digits I draw. If you decide to use your own digits, you have to realize the neural network was not trained on them so the results might not be perfect.

**Z2 2023/24**

