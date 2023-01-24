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
		NeuralNetwork(std::initializer_list<size_t>);
		void fit(size_t, std::string&);
	};

	class Layer {
		std::vector<Neuron> neurons;
		double_t bias;
	public:
		Layer(size_t, bool);
		void setInputLayer(std::vector<double_t>&);
		void printWeights();
		void printBias();
	};

	class Neuron {
		double_t weight;
		double_t output;
	public:
		Neuron(double_t);
		double_t relu(double_t);
		void calculateOutput(std::vector<Neuron>&, double_t);
		double_t getWeight();
		void setOutput(double_t);
	};
}