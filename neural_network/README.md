# 🧠 Neural Network Implementation

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Neural Network](https://img.shields.io/badge/Type-Feedforward-green.svg)](https://en.wikipedia.org/wiki/Feedforward_neural_network)
[![Backpropagation](https://img.shields.io/badge/Training-Backpropagation-orange.svg)](https://en.wikipedia.org/wiki/Backpropagation)

> **A complete neural network implementation from scratch in pure C** - No external libraries, just mathematics and code.

## 🎯 Overview

This neural network implementation demonstrates the mathematical principles behind artificial intelligence, built entirely from first principles. It successfully solves complex problems including XOR, parity detection, pattern recognition, and function approximation.

## 🏗️ Architecture

```
Input Layer → Hidden Layer(s) → Output Layer
     ↓              ↓              ↓
  Weights &      Activation    Final Output
   Biases       Functions
```

### 📁 File Structure

```
neural_network/
├── 🎯 main.c              # XOR problem demonstration
├── 🔧 network.c           # Network management
├── 📊 layer.c             # Layer operations
├── 🧮 perceptron.c        # Individual neurons
├── 📈 activation.c        # Activation functions
├── 📉 loss.c              # Loss functions
├── 🛠️ utils.c             # Utility functions
└── 📋 h*.h               # Header files
```

## 🚀 Quick Start

### Compilation
```bash
# Basic XOR demonstration
gcc -o nn *.c -lm
./nn
```

### Expected Output (XOR Problem)
```
Epoch 0, loss: 1.191543
Epoch 1000, loss: 0.009373
Epoch 2000, loss: 0.003428
Epoch 3000, loss: 0.002064
Epoch 4000, loss: 0.001468
Epoch 5000, loss: 0.001136
Epoch 6000, loss: 0.000925
Epoch 7000, loss: 0.000780
Epoch 8000, loss: 0.000673
Epoch 9000, loss: 0.000592
Epoch 9999, loss: 0.000528

Predictions:
[0.000000, 0.000000] → [0.012636] ✓
[0.000000, 1.000000] → [0.989050] ✓
[1.000000, 0.000000] → [0.989139] ✓
[1.000000, 1.000000] → [0.011417] ✓
```

## ⚙️ Technical Features

### 🔧 Network Configuration
```c
LayerConfig configs[] = {
    {input_size, hidden_neurons, SIGMOID},
    {hidden_neurons, output_size, SIGMOID}
};
```

### 📈 Activation Functions
- **Sigmoid**: `σ(x) = 1/(1 + e^(-x))`
- **ReLU**: `f(x) = max(0, x)`
- **Tanh**: `f(x) = tanh(x)`

### 📉 Loss Functions
- **MSE**: Mean Squared Error
- **RMSE**: Root Mean Squared Error

### 🎯 Weight Initialization
- **Xavier/Glorot**: `limit = √(6/input_size)`
- **Random**: Uniform distribution `[-limit, limit]`

## 📊 Performance Metrics

| Test Case | Network Depth | Accuracy | Convergence |
|-----------|---------------|----------|-------------|
| AND | 2 layers | 100% | ~2000 epochs |
| OR | 2 layers | 100% | ~2000 epochs |
| XOR | 2 layers | 100% | ~2000 epochs |
## 🔬 Mathematical Foundation

### Forward Propagation
```
z = Wx + b
a = σ(z)
```

### Backpropagation
```
δ = ∂L/∂a × σ'(z)
∂W = δ × x^T
∂b = δ
```

### Weight Update
```
W = W - α × ∂W
b = b - α × ∂b
```

## 🛠️ Key Improvements Made

1. **Fixed Sigmoid Derivative**: Proper pre-activation calculation
2. **Xavier Initialization**: Better weight distribution
3. **Optimized Learning Rate**: Faster convergence
4. **Modular Design**: Extensible architecture
5. **Comprehensive Testing**: Multiple problem domains

## 🎓 Learning Outcomes

This implementation demonstrates:
- **Mathematical Understanding**: Deep learning from first principles
- **C Programming Mastery**: Memory management, modular design
- **Algorithm Implementation**: Backpropagation, gradient descent
- **Problem Solving**: Complex pattern recognition
- **Software Engineering**: Clean, maintainable code

## 🔧 Compilation Notes

The `-lm` flag links the math library for:
- `sin()`, `cos()` - Trigonometric functions
- `exp()` - Exponential (sigmoid activation)
- `sqrt()` - Square root (Xavier initialization)
- `pow()` - Power functions
- `fabs()` - Absolute value (error calculation)

## 📋 TODO & Future Enhancements

- [ ] **Mini-batch Processing**
  - [ ] Mini-batch gradient descent implementation
  - [ ] Dynamic batch size handling

- [ ] **Loss Functions**
  - [ ] Binary cross-entropy loss
  - [ ] Categorical cross-entropy loss

- [ ] **Advanced Layers**
  - [ ] 2D Convolution layer
  - [ ] Batch normalization layer
  - [ ] Flatten layer (conv → dense)

- [ ] **GPU Acceleration**
  - [ ] CUDA support for matrix operations
  - [ ] GPU memory management

- [ ] **Datasets**
  - [ ] MNIST digit recognition implementation

---

**"Understanding neural networks at the mathematical level is the key to mastering artificial intelligence."** 🧠✨