#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

namespace ann {
	class NeuralNetwork;
	class Layer;
	class Neuron;

	class NeuralNetwork {
		std::vector<Layer> layers;
	public:
		NeuralNetwork(std::initializer_list<size_t> layerNeuronCounts);
		void fit(size_t epochs, std::string& trainPath);
	};

	class Layer {
		std::vector<Neuron> neurons;
		double_t bias;
	public:
		Layer(size_t numberOfNeurons, bool isInput = false);
		void setInputLayer(std::vector<double_t>& inputs);
		void printWeights();
		void printBias();
	};

	class Neuron {
		double_t weight;
		double_t output;
	public:
		Neuron(double_t weight_);
		double_t relu(double_t input);
		void calculateOutput(std::vector<Neuron>& inputs, double_t bias);
		double_t getWeight();
		void setOutput(double_t output_);
	};
}