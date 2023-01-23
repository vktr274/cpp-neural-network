#pragma once

#include <vector>

namespace ann {
	class NeuralNetwork {
		std::vector<Layer> layers;
	public:
		NeuralNetwork(std::initializer_list<size_t>);
		void fit(size_t);
	};

	class Layer {
		std::vector<Neuron> neurons;
		double_t bias;
	public:
		Layer(size_t);
	};

	class Neuron {
		double_t weight;
		double_t output;
	public:
		Neuron(double_t);
		double_t relu(double_t);
		double_t calculateOutput(std::vector<Neuron>&, double_t);
	};
}